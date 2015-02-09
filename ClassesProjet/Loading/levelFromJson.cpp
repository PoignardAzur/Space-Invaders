

#include "levelFromJson.h"


void loadFromJSON(BasicSpaceLevel* l, const json::Value* value)
{
    json::Value waveList; waveList = findMember(value, "waveList").m;

    for (auto p = waveList.Begin(); p != waveList.End(); ++p)
    {
        AbsWave* wave = loadFromJSON(*p);

        if (wave)
        l->addWave(wave);
    }
}


AbsWave* loadFromJSON(const json::Value* value)
{
    AbsWave* wave;

    json::Value waveType; waveType = value->FindMember("type", )findMember(value, );

    if (waveType == value->End())
    throw "Wave has no type";

    std::string waveTypeName = waveType->GetString();

    if (waveTypeName == "Void")
    {

    }
}

















