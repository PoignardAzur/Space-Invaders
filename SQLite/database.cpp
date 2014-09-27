

#include "statement.hpp"
#include <sstream>


sql3::Database::Database()
{}

sql3::Database::Database(const char* filename, int flags, const char *zVFS)
{
	open(filename, flags, zVFS);
}

sql3::Database::Database(std::istream &commandFile, const char* dbName)
{
    createFromFile(commandFile, dbName);
}


void sql3::Database::open(const char* filename, int flags, const char *zVFS)
{
//	int errorCode = sqlite3_open_v2(filename, &p_database, flags, zVFS);
	testCode(sqlite3_open_v2(filename, &p_database, flags, zVFS));
}

void sql3::Database::createFromFile(std::istream &commandFile, const char* dbName)
{
    Statement stmt;
    std::string str;
    std::string str02;
    int line = 0;
    bool end = false;

    if (dbName == 0)
    {
        std::getline(commandFile, str);
        dbName = str.c_str();
    }

    open(dbName, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE);

    try
    {

        while (std::getline(commandFile, str) && (!end) )
        {
            if (str.size() > 1)
            {
                if (str.substr(0,3) == "END")
                end = true;

                else if (str.substr(0,2) != "//")
                {
                    prepare(str.c_str(), str.size(), stmt);
                    stmt.makeAllSteps();
                }
            }

            line ++;

        }
    }

    catch (const char* error)
    {
        std::string errorText;
        std::stringstream(errorText) << "Error line " << line << " : " << std::endl << error;
        error = errorText.c_str();
        throw;
    }
}


void sql3::Database::prepare(const char *query, int maxSize, Statement& modifiedStmt)
{
	modifiedStmt.prepareIn(p_database, query, maxSize);
}

void sql3::Database::prepare(const char *query, int maxSize, sqlite3_stmt*& modifiedStmt)
{
	prepareStatementIn(p_database, query, maxSize, modifiedStmt);
}

void sql3::Database::prepareSelectAll(const char *table, int sizeTableName, Statement& modifiedStmt)
{
	modifiedStmt.prepareIn(p_database, SELECT_ALL_FROM(table).c_str());
}
void sql3::Database::close()
{
	sqlite3_close_v2(p_database);
	p_database = 0;
}

sql3::Database::~Database()
{
	close();
}


void sql3::Database::testCode(int sqlCode)
{
	testErrorCode(sqlCode);
}




namespace sql3
{

    void prepareStatementIn(sqlite3* target, const char *query, int maxSize, sqlite3_stmt*& modifiedStmt)
    {
    //	int errorCode = sqlite3_prepare_v2(&target, query, maxSize, &modifiedStmt, 0);
        testErrorCode(sqlite3_prepare_v2(target, query, maxSize, &modifiedStmt, 0));
    }


    void testErrorCode(int sqlCode)
    {
        if (sqlCode != SQLITE_OK)
        {
            throw sqlite3_errstr(sqlCode);
        }
    }



}




