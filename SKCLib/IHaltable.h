#ifndef IHALTABLE_INCLUDED
#define IHALTABLE_INCLUDED
#include "skc.h"

namespace skc{
    class IHaltable{
    public:
        virtual void PowerUp() = 0;
        virtual void PowerDown() = 0;
        virtual void HaltFor(long mili)=0;
        virtual void HaltUntil()=0;
    };
}


#endif // IHALTABLE_INCLUDED
