

#ifndef STATEMENT_HEADER
#define STATEMENT_HEADER

#include "database.hpp"
#define SELECT_ALL_FROM(TABLE) "SELECT * FROM " TABLE
#define CONTINUE_STEPS false

namespace sql3
{

	class Statement
	{
		public :

		Statement();
		Statement(Database& target, const char *query, int maxSize = -1, bool* noError = nullptr);

		// each function is basically an indirect call of prepareStatementIn(target, query, maxSize, modifiedStatement)
		bool prepareIn(Database& target, const char *query, int maxSize = -1);
		bool prepareIn(sqlite3* target, const char *query, int maxSize, std::ostream* err);

		bool step(bool* noError = nullptr);													// selects the next column, returns false is there isn't any
		bool makeAllSteps();
		bool reset(bool doResetBindings = false);						// returns to the first line
		bool resetBindings();											// deletes all bindings
		const char* getQuery();

		bool bindInt(int i, int value);
		bool bindDouble(int i, double value);							// binds the argument(s) n°[i] with [value]
		bool bindNull(int i);
		bool bindText(int i, const char* value, int size = -1);

		int columnByte(int i) const;									// give the value (if it's in the asked format)
		int columnByte16(int i) const;									// of the element n°[i] of the selected column
		int columnInt(int i) const;
		double columnDouble(int i) const;
		const unsigned char* columnText(int i) const;
		const char* columnStandardText(int i) const;

		bool checkColumn(int i) const;							    	// throw an exception if (i > columnCount)
		int columnCount() const;

		void erase();													// must be called after all statements are erased
		~Statement();

//		const unsigned char* columnText16(int i) const;
//      bool prepareSelectAllIn(Database& target, const char *table, int sizeTableName = -1);
//		void bindText16(int i, const char* value, int size = -1, void(*)(void*) = SQLITE_STATIC); // does what ??

		private :

		bool testCode(int sqlCode, char origin, const char* query, std::ostream* err) const;

		sqlite3_stmt* p_stmt;
		std::ostream* p_err;      // use-a
		bool m_prepared;
	};
}


#endif

/*

Essential :

sql3Statement
{
	public :

	void prepareIn(Database& target, const char *query, int maxSize = -1);
	bool step();
	void reset(bool doResetBindings = false);
	void erase();

	void bindInt(int i, int value);
	void bindDouble(int i, double value);
	void bindText(int i, const char* value, int size);
	void bindNull(int i);
};


const sql3Statement
{
	int             columnInt(int i);
	double          columnDouble(int i);
	char*           columnText(int i);
    unsigned char*  columnText(int i);
    char*           columnStandardText(int i);
	int             columnCount();
};


*/

/*

Binding system :
Each argument is numbered and replaced with a value (depending on the function).
The arguments are written with on of those formats :
? / ?n / :str / @str / $str ;
Where n is the number of the argument (must be between 1 and 999), and str its name.
Arguments (save for ?n) are indexed with their place in the string, the first from the left being n°1, the second from the left n°2...
Two arguments with the same name also have the same index.

*/
