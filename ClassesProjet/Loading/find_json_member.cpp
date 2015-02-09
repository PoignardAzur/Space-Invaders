

#include "find_json_member.h"


typedef json_value_function jvf;


std::string errorMessageCantFind(const std::string& adress, const std::string& name)
{
    std::string message = "Cannot find member ";
    message += adress;
    message += " in ";
    message += name;
    throw message.c_str();
}

std::string errorMessageIncorrect(const std::string& adress, const std::string& name, const std::string& message)
{
    std::string completeMessage = "Member ";
    completeMessage += adress;
    completeMessage += " of ";
    completeMessage += name;
    completeMessage += " ";
    completeMessage += message;
    throw completeMessage.c_str();
}



jvf findMember(const json::Value& value, const std::string& internalAddress, const std::string& name, JSON_FLAGS isMatch, bool ouputEntireAddress)
{
    std::string usedName = (name == "") ? DEFAULT_MAIN_JSON_NAME : name;

    size_t pt = internalAddress.find('.');

    if (pt == std::string::npos)
    {
        if (internalAddress == "")
        {
            if (! isMatchWithFlag(value, isMatch))
            throw (usedName + " does not match " + jsonFlagsDescription(isMatch) + " like it should").c_str();

            return jvf(value, internalAddress);
        }

        else
        {
            assert(value.IsObject());
            auto p = value.FindMember(internalAddress.c_str());

            if (p == value.MemberEnd())
            throw errorMessageCantFind(internalAddress, usedName);

            if (! isMatchWithFlag(p->value, isMatch))
            throw errorMessageIncorrect(internalAddress, usedName, "does not match " + jsonFlagsDescription(isMatch) + " like it should").c_str();

            // else

            if (ouputEntireAddress)
            usedName += "." + internalAddress;

            else
            usedName = internalAddress;

            return jvf(p->value, usedName);
        }


    }

    else
    {
        std::string memberName = internalAddress.substr(0, pt);
        auto p = value.FindMember(memberName.c_str());

        if (p == value.MemberEnd())
        throw errorMessageCantFind(memberName, usedName).c_str();

        if (! p->value.IsObject())
        throw errorMessageIncorrect(memberName, usedName, "should be an object").c_str();

        if (ouputEntireAddress)
        memberName = usedName + "." + memberName;

        return findMember(p->value, internalAddress.substr(pt + 1), memberName, isMatch, ouputEntireAddress);
    }
}



jvf findMember(const json::Value& value, size_t i, const std::string& name, JSON_FLAGS isMatch)
{
    std::string usedName = (name == "") ? DEFAULT_MAIN_JSON_NAME : name;

    if (i >= value.Size())
    throw ("Element " + std::to_string(i) + "is out of range of array " + usedName + " (size : " + std::to_string(value.Size()) + ")").c_str();

    usedName += "[" + std::to_string(i) + "]";

    if (! isMatchWithFlag(value[i], isMatch))
    throw (usedName + " does not match " + jsonFlagsDescription(isMatch) + " like it should").c_str();

    return jvf(value[i], usedName);
}



bool isMatchWithFlag(const json::Value& value, JSON_FLAGS flags)
{
    if (flags == NO_JSON)
    return false;

    if (flags == NULL_JSON && !value.IsNull())
    return false;

    if (flags == NOT_NULL_JSON && value.IsNull())
    return false;

    if (flags == BOOL_JSON && !value.IsBool())
    return false;

    if (flags == STR_JSON && !value.IsString())
    return false;

    if (flags == ARRAY_JSON && !value.IsArray())
    return false;

    if (flags == OBJECT_JSON && !value.IsObject())
    return false;

    if (flags == REAL_JSON && !value.IsDouble())
    return false;

    if (flags == INT_JSON && !(value.IsNumber() && !value.IsDouble()))
    return false;

    if (flags == NUMBER_JSON && !value.IsNumber())
    return false;

    if (flags == CONTAINER_JSON && !(value.IsArray() || value.IsObject()))
    return false;

    return true;
}

std::string jsonFlagsDescription(JSON_FLAGS flags)
{
    std::string d;

    if (flags == ANY_JSON)
    return "ANY JSON";

    if (flags == NULL_JSON)
    d += "NULL";

    if (flags == BOOL_JSON)
    d += "BOOL |";

    if (flags == STR_JSON)
    d += "STR |";

    if (flags == CONTAINER_JSON)
    d += "CONTAINER__";

    if (flags == ARRAY_JSON)
    d += "ARRAY |";

    if (flags == OBJECT_JSON)
    d += "OBJECT |";

    if (flags == NUMBER_JSON)
    d += "NUMBER__";

    if (flags == REAL_JSON)
    d += "REAL |";

    if (flags == INT_JSON)
    d += "INT |";

    if (flags == NO_JSON)
    return "NO JSON";

    if (flags == NOT_NULL_JSON)
    return "NOT NULL";

    return d.substr(0, d.size() - 2);
}



json_value_function::json_value_function(const json::Value& v, const std::string& name) : m(v), m_name(name)
{

}

json_value_function json_value_function::f(JSON_FLAGS isMatch)
{
    return findMember(m, "", m_name, isMatch, false);
}

json_value_function json_value_function::f(const std::string& internalAddress, JSON_FLAGS isMatch, bool ouputEntireAddress)
{
    return findMember(m, internalAddress, m_name, isMatch, ouputEntireAddress);
}

json_value_function json_value_function::f(size_t i, JSON_FLAGS isMatch)
{
    return findMember(m, i, m_name, isMatch);
}

