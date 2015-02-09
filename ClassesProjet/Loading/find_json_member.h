

#include <string>
#include "../SpaceInvaders/rapidjson/document.h"//#include "../../rapidjson/document.h"

#define DEFAULT_MAIN_JSON_NAME "MAIN"


#define JSON_FLAGS int

#define ANY_JSON 0
#define NULL_JSON 1
#define BOOL_JSON 2
#define STR_JSON 3
#define CONTAINER_JSON 4
#define ARRAY_JSON 5
#define OBJECT_JSON 6
#define NUMBER_JSON 7
#define REAL_JSON 8
#define INT_JSON 9
#define NO_JSON 10
#define NOT_NULL_JSON 11


namespace json = rapidjson;

class json_value_function
{
    public :

    json_value_function(const json::Value& v, const std::string& name);

    json_value_function f(JSON_FLAGS isMatch);
    json_value_function f(const std::string& internalAddress, JSON_FLAGS isMatch = ARRAY_JSON, bool ouputEntireAddress = true);
    json_value_function f(size_t i, JSON_FLAGS isMatch = CONTAINER_JSON);

    const json::Value& m;

    private :
    std::string m_name;
};

json_value_function findMember(const json::Value& value, const std::string& internalAddress, const std::string&
name = "", JSON_FLAGS isMatch = ARRAY_JSON, bool ouputEntireAddress = true);

json_value_function findMember(const json::Value& value, size_t i, const std::string& name = "", JSON_FLAGS isMatch = CONTAINER_JSON);

bool isMatchWithFlag(const json::Value& value, JSON_FLAGS flags);
std::string jsonFlagsDescription(JSON_FLAGS flags);



