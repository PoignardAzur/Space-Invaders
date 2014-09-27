

#include "statement.hpp"


sql3::Statement::Statement()
{

}

sql3::Statement::Statement(Database& target, const char *query, int maxSize)
{
    prepareIn(target, query, maxSize);
}

void sql3::Statement::prepareIn(Database& target, const char *query, int maxSize)
{
	target.prepare(query, maxSize, *this);
}

void sql3::Statement::prepareIn(sqlite3* target, const char *query, int maxSize)
{
	prepareStatementIn(target, query, maxSize, p_stmt);
}

void sql3::Statement::prepareSelectAllIn(Database& target, const char *table, int sizeTableName)
{
	prepareIn(target, SELECT_ALL_FROM(table).c_str());
}

void sql3::Statement::resetBindings()
{
	testCode(sqlite3_clear_bindings(p_stmt));
}

void sql3::Statement::reset(bool doResetBindings)
{
	if (doResetBindings)
	resetBindings();

	testCode(sqlite3_reset(p_stmt));
}

bool sql3::Statement::step()
{
	int resultCode = sqlite3_step(p_stmt);

	if (resultCode == SQLITE_DONE)
	return true;

	if (resultCode == SQLITE_ROW)
	return false;

/// else
	testCode(resultCode);
	return true;
}


void sql3::Statement::makeAllSteps()
{
    while (!step());
}


void sql3::Statement::bindInt(int i, int value)
{
	testCode(sqlite3_bind_int(p_stmt,i,value));
}

void sql3::Statement::bindDouble(int i, double value)
{
	testCode(sqlite3_bind_double(p_stmt,i,value));
}

void sql3::Statement::bindNull(int i)
{
	testCode(sqlite3_bind_null(p_stmt,i));
}


void sql3::Statement::bindText(int i, const char* value, int size)
{
	testCode(sqlite3_bind_text(p_stmt,i,value, size, SQLITE_STATIC));
}

/*
void sql3::Statement::bindText16(int i, const char* value, int size)
{
	testCode(sqlite3_bind_text16(p_stmt,i,value, size, SQLITE_STATIC));
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

void sql3::Statement::checkColumn(int i) const
{
	if (i > columnCount())
	throw "Error : asked column is out of range";
}

void sql3::Statement::erase()
{
	if (p_stmt)
//	sqlite3_finalize(p_stmt);
	testCode(sqlite3_finalize(p_stmt));
	p_stmt = 0;
}

sql3::Statement::~Statement()
{
	erase();
}

void sql3::Statement::testCode(int sqlCode) const
{
	testErrorCode(sqlCode);
}



