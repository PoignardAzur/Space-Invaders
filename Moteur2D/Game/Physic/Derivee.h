



#ifndef HEADER_DERIVEE
#define HEADER_DERIVEE


template <typename T>
struct Derivee
{
    T value;

    Derivee()
    { }

    Derivee(const T& valeurCopiee)
    {
        value = valeurCopiee;
    }

    void deriver(T& valeurDerivee)
    {
        valeurDerivee += value;
    }

    template <typename T2>
    void deriver(T& valeurDerivee, T2 dt)
    {
        valeurDerivee += value * dt;
    }
};



#endif



