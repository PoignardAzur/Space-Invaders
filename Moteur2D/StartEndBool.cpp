


#include "StartEndBool.h"




StartEnd::StartEnd(bool nValue) : m_value(true), m_lastValue(true)
{}

inline bool StartEnd::value()
{
    return m_value;
}

inline bool StartEnd::started()
{
    return m_value && (!m_lastValue);
}

inline bool StartEnd::ended()
{
    return (!m_value) && (!m_lastValue);
}

inline bool StartEnd::changed()
{
    return m_value != m_lastValue;
}

bool StartEnd::update(bool nValue)
{
    m_lastValue = m_value;
    m_value = nValue;

    return started();
}

bool StartEnd::operator()(bool nValue)
{
    return update(nValue);
}


