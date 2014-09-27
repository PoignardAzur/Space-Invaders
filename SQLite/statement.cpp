

#include "statement.hpp"


sql3::Statement::Statement()
{
    p_stmt = nullptr;
}

sql3::Statement::Statement(Database& target, const char *query, int maxSize, bool* noError)
{
    p_stmt = nullptr;

    if (noError)
    *noError = prepareIn(target, query, maxSize);

    else
    prepareIn(target, query, maxSize);
}

bool sql3::Statement::prepareIn(Database& target, const char *query, int maxSize)
{
	return target.prepare(query, maxSize, *this);
}

bool sql3::Statement::prepareIn(sqlite3* target, const char *query, int maxSize, std::ostream* err)
{
    p_err = err;
	return prepareStatementIn(target, query, maxSize, p_stmt, err);
}


bool sql3::Statement::resetBindings()
{
	return testCode(sqlite3_clear_bindings(p_stmt), USING_INCORRECT_STATEMENT, getQuery(), p_err);
}

bool sql3::Statement::reset(bool doResetBindings)
{
	if (doResetBindings)
	{
	    if (!resetBindings())
        return false;
	}

	return testCode(sqlite3_reset(p_stmt), USING_INCORRECT_STATEMENT, getQuery(), p_err);
}

bool sql3::Statement::step(bool* noError)
{
	int resultCode = sqlite3_step(p_stmt);

	if (resultCode == SQLITE_DONE)
	return !CONTINUE_STEPS;

	if (resultCode == SQLITE_ROW)
	return CONTINUE_STEPS;

/// else

    if (noError)
    *noError = testCode(resultCode, RUNNING_STATEMENT, getQuery(), p_err);

	return !CONTINUE_STEPS;
}


bool sql3::Statement::makeAllSteps()
{
    bool noError = true;

    while (step(&noError) == CONTINUE_STEPS && noError);;

    return noError;
}


const char* sql3::Statement::getQuery()
{
    return sqlite3_sql(p_stmt);
}



bool sql3::Statement::bindInt(int i, int value)
{
	return testCode(sqlite3_bind_int(p_stmt,i,value), BINDING_STATEMENT, getQuery(), p_err);
}

bool sql3::Statement::bindDouble(int i, double value)
{
	return testCode(sqlite3_bind_double(p_stmt,i,value), BINDING_STATEMENT, getQuery(), p_err);
}

bool sql3::Statement::bindNull(int i)
{
	return testCode(sqlite3_bind_null(p_stmt,i), BINDING_STATEMENT, getQuery(), p_err);
}


bool sql3::Statement::bindText(int i, const char* value, int size)
{
	return testCode(sqlite3_bind_text(p_stmt, i, value, size, SQLITE_STATIC), BINDING_STATEMENT, getQuery(), p_err);
}

/*
bool sql3::Statement::bindText16(int i, const char* value, int size)
{
	return testCode(sqlite3_bind_text16(p_stmt,i,value, size, SQLITE_STATIC), BINDING_STATEMENT, getQuery(), p_err);
}
*/

int sql3::Statement::columnByte(int i) const
{
	checkColumn(i);
	return sqlite3_column_bytes(p_stmt, i);
}

int sql3::Statement::columnByte16(int i) const
{
	checkColumn(i);
	return sqlite3_column_bytes16(p_stmt, i);
}

int sql3::Statement::columnInt(int i) const
{
	checkColumn(i);
	return sqlite3_column_int(p_stmt, i);
}

double sql3::Statement::columnDouble(int i) const
{
	checkColumn(i);
	return sqlite3_column_double(p_stmt, i);
}

const unsigned char* sql3::Statement::columnText(int i) const
{
	checkColumn(i);
	return sqlite3_column_text(p_stmt, i);
}

const char* sql3::Statement::columnStandardText(int i) const
{
	return reinterpret_cast<const char*>(columnText(i));
}


int sql3::Statement::columnCount() const
{
	return sqlite3_column_count(p_stmt);
}

bool sql3::Statement::checkColumn(int i) const
{
	if (i > columnCount())
	{
        (*p_err) << "Error : asked column is out of range";
        return false;
	}

/// else
	return true;
}


void sql3::Statement::erase()
{
	if (p_stmt)
	testCode(sqlite3_finalize(p_stmt), USING_INCORRECT_STATEMENT, nullptr, p_err);

	p_stmt = nullptr;
}

sql3::Statement::~Statement()
{
	erase();
}

bool sql3::Statement::testCode(int sqlCode, char origin, const char* query, std::ostream* err) const
{
	return testErrorCode(sqlCode, origin, query, err);
}



