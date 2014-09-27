
#ifndef DATABASE_HEADER
#define DATABASE_HEADER

#include "sqlite3.h"
#include <iostream>

#define ID_COLUMN 0


namespace sql3
{

	class Statement;

	class Database
	{
		public :

		Database();
		Database(const char* filename, int flags = SQLITE_OPEN_READWRITE, const char *zVFS = 0);		// simply calls open(filename, flags, zVFS)
//		Database(const char* filename, bool utf16);
		Database(std::istream &commandFile, const char* dbName = 0);

		void open(const char* filename, int flags = SQLITE_OPEN_READWRITE, const char *zVFS = 0);		// don't touch zVFS, that's pointless
		void createFromFile(std::istream &commandFile, const char* dbName = 0);
//		void open(const char* filename, bool utf16);
//		void open16(const char* filename);

		void prepare(const char *query, int maxSize, Statement& modifiedStmt);							// simply calls
		void prepare(const char *query, int maxSize, sqlite3_stmt*& modifiedStmt);					// prepareStatementIn(target, query, maxSize, modifiedStatement)
		void prepareSelectAll(const char *table, int sizeTableName, Statement& modifiedStmt);
//		void prepare16

		void testCode(int sqlCode);
		void close();
		~Database();

		private :

		sqlite3* p_database;
	};

	void prepareStatementIn(sqlite3* target, const char *query, int maxSize, sqlite3_stmt*& modifiedStmt); 	// maxSize will be automatically calculated if -1 is
	void testErrorCode(int sqlCode);																			// entered, but should still be provided if possible
}																												// to slightly improve performances


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

