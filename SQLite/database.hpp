
#ifndef DATABASE_HEADER
#define DATABASE_HEADER

#include "sqlite3.h"
#include <iostream>
#include <functional>

#define RUNNING_STATEMENT 0
#define PREPARING_STATEMENT 1
#define OPENING_DATABASE 2
#define USING_INCORRECT_STATEMENT 3
#define BINDING_STATEMENT 4
#define OTHER_SQL3_ERROR 10


namespace sql3
{
	class Statement;

	class Database
	{
		public :

		Database(std::ostream* err = &std::cerr);
		explicit Database(const char* filename, int flags = SQLITE_OPEN_READWRITE, std::ostream* err = &std::cerr, bool* noError = nullptr, const char *zVFS = nullptr);
		// simply calls open(filename, flags, err, zVFS)

		bool open(const char* filename, int flags = SQLITE_OPEN_READWRITE, std::ostream* err = &std::cerr, const char *zVFS = nullptr);
		// don't touch zVFS, that's pointless
        bool isOpen() const;

		bool prepare(const char *query, int maxSize, Statement& modifiedStmt);
        // both just call prepareStatementIn(target, query, maxSize, modifiedStatement, err)

		bool executeQuery(const char *query, int maxSize = -1);
		// executes the query without using a statement

		void close();
		~Database();

//		Database(const char* filename, bool utf16);
//		bool open(const char* filename, bool utf16);
//		bool open16(const char* filename);

//		bool prepare16()


		private :

        bool testCode(int sqlCode, char origin, const char* query, std::ostream* err);

		sqlite3* p_database;      // has-a
		std::ostream* p_err;      // use-a
	};

    bool createDatabaseFromFile(Database& db, std::istream &commandFile, const char* dbName = nullptr, std::ostream* err = &std::cerr, bool multilineQueries = false);

    bool execute(Statement* modifiedStmt);      // makes all steps of the statement, then deletes it, even if there is an error.
    bool execute(Database& db, std::function<void(const Statement&, unsigned int)> f, const char *query, int maxSize = -1);

	bool prepareStatementIn(sqlite3* target, const char *query, int maxSize, sqlite3_stmt*& modifiedStmt, std::ostream* err);
	// maxSize will be automatically calculated if -1 is entered, but should still be provided if possible to slightly improve performances
	bool testErrorCode(int sqlCode, char origin, const char* query, std::ostream* err);
}


/*

class sql3::Database
{
	public :

	Database();
	void open(const char* filename, int flags = SQLITE_OPEN_READWRITE, const char *zVFS = 0);
	void close();

	void prepare(const char *query, int maxSize, Statement& modifiedStmt);
	void prepareSelectAll(const char *table, int maxSize, Statement& modifiedStmt);
};


*/


#endif

