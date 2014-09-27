

#include "statement.hpp"



sql3::Database::Database(std::ostream* err)
{
    p_err = err;
}

sql3::Database::Database(const char* filename, int flags, std::ostream* err, bool* noError, const char *zVFS)
{
    if (noError)
	*noError = open(filename, flags, err, zVFS);

	else
    open(filename, flags, err, zVFS);
}

bool sql3::Database::open(const char* filename, int flags, std::ostream* err, const char *zVFS)
{
    p_err = err;
	return testCode(sqlite3_open_v2(filename, &p_database, flags, zVFS), OPENING_DATABASE, nullptr, err);
}

bool sql3::Database::isOpen() const
{
    return p_database != nullptr;
}


bool sql3::Database::prepare(const char *query, int maxSize, Statement& modifiedStmt)
{
	return modifiedStmt.prepareIn(p_database, query, maxSize, p_err);
}

bool sql3::Database::executeQuery(const char *query, int maxSize)
{
    Statement stmt(*this, query, maxSize);
    return stmt.makeAllSteps();
}


void sql3::Database::close()
{
	sqlite3_close_v2(p_database);
	p_database = nullptr;
}

sql3::Database::~Database()
{
	close();
}


bool sql3::Database::testCode(int sqlCode, char origin, const char* query, std::ostream* err)
{
	return testErrorCode(sqlCode, origin, query, err);
}




namespace sql3
{

    bool prepareStatementIn(sqlite3* target, const char *query, int maxSize, sqlite3_stmt*& modifiedStmt, std::ostream* err)
    {
        return testErrorCode(sqlite3_prepare_v2(target, query, maxSize, &modifiedStmt, nullptr), PREPARING_STATEMENT, query, err);
    }


    bool testErrorCode(int sqlCode, char origin, const char* query, std::ostream* e)
    {
        if (sqlCode != SQLITE_OK && sqlCode != SQLITE_ROW)
        {
            std::ostream& err = *e;

            if (origin == RUNNING_STATEMENT)
            err << "Error encountered when running the statement";

            if (origin == PREPARING_STATEMENT)
            err << "Error encountered when preparing the statement";

            if (origin == OPENING_DATABASE)
            err << "Error encountered opening the database";

            if (origin == USING_INCORRECT_STATEMENT)
            err << "Error encountered dealing with the corrupted statement";

            if (origin == BINDING_STATEMENT)
            err << "Error encountered binding elements to the statement";


            if (query)
            err << " :" << std::endl << query;

            err << std::endl << "Reason given : " << sqlite3_errstr(sqlCode) << std::endl << std::endl;


            return false;
        }

        return true;
    }


    bool execute(Statement* modifiedStmt)
    {
        bool noError = modifiedStmt->makeAllSteps();
        delete modifiedStmt;
        return noError;
    }

    bool execute(Database& db, std::function<void(const Statement&, unsigned int)> f, const char *query, int maxSize)
    {
        sql3::Statement stmt(db, query, maxSize);
        unsigned int i = 0;
        bool noError = true;

        while (stmt.step(&noError) == CONTINUE_STEPS && noError)
        {
            f(stmt, i);
            i++;
        }

        return noError;
    }

}





