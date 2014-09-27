

#include "statement.hpp"


namespace sql3
{

    bool createDatabaseFromFile(Database& db, std::istream &commandFile, const char* dbName, std::ostream* err, bool multilineQueries)
    {
        Statement stmt;
        std::string lineStr;
        std::string queryStr;

        bool end = false;

        if (!dbName)        // if the adress of the database isn't given, we get it from the first line of the command file
        {
            std::getline(commandFile, lineStr);
            dbName = lineStr.c_str();
        }

        bool noError = db.open(dbName, SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE, err); // if the database didn't open, the following loops aren't used

        while (std::getline(commandFile, lineStr) && (!end) && noError) // adds all lines of the file until either the end of the file or the keyword "#END"
        {
                if (lineStr.substr(0,4) == "#END")
                end = true;

                else if (lineStr.substr(0,2) != "//")  // skips the commented lines
                queryStr += lineStr;

                if (!multilineQueries)                  // if all lines are considered as a single query
                queryStr += ";";
        }

        std::string::size_type start_query = 0;
        std::string::size_type end_query;
        std::string query;

        while (start_query != std::string::npos && noError)    //continue until all queries of the string are executed or there is an error
        {
            end_query = queryStr.find_first_of(';', start_query);
            query = queryStr.substr(start_query, end_query);

            if (db.prepare(query.c_str(), query.size(), stmt))    // returns true if sql3_prepare didn't return an error
            {
                noError = stmt.makeAllSteps();
            }

            else
            noError = false;
            noError = noError;
            start_query = end_query;

            if (start_query != std::string::npos)
            start_query ++;                             // else the "cursors" stay on the same ';' over and over
        }

        return noError;
    }
}


