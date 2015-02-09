

#include "load_json.h"


json::Value loadJSON_from(const char* filename)
{
    FILE* f = fopen(filename, "r");

    if (!f)
    throw ("Could not open " + std::string(filename)).c_str();

    fseek(f, 0, SEEK_END);
    int taille = ftell(f) + 1;
    fseek(f, 0, SEEK_SET);

    char buffer[taille];
    rapidjson::Document document;
    json::FileReadStream stream(f, buffer, taille);
    document.ParseStream<0>(stream);

    json::Value v;
    v = static_cast<json::Value&>(document);
    return v;
}


