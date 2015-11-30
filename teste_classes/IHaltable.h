#ifndef IHALTABLE_H_INCLUDED
#define IHALTABLE_H_INCLUDED

class IHaltable{
public:
    virtual void PowerUp()=0;
    virtual void PowerDown()=0;
    virtual void HaltFor(long ms)=0;
    virtual void HaltUntil()=0;
};

#endif // IHALTABLE_H_INCLUDED
