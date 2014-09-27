


#ifndef EMITTER_HEADER
#define EMITTER_HEADER


template <typename Obj, typename Par>
class Emitter
{
    public :
    virtual Obj* createConst(const Par&) const = 0;
    virtual Obj* create(Par&) const = 0;
};



#endif

