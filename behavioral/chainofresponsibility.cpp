#include <iostream>
using namespace std;

class Chain
{
private:
Chain* next_chain;
public:
    explicit Chain(Chain* next_ = nullptr):next_chain(next_){}
    void setNext(Chain* next_)
    {
        next_chain = next_;
    }
    virtual void handle(int a, int b) const
    {
        next_chain->handle(a,b);
    }
    virtual ~Chain() = default;
};

class CheckZero: public Chain
{
public:
    virtual void handle(int a, int b) const override
    {
        if(a==0 || b==0)
            cout<<"GCD = "<<a+b<<endl;
        else
            Chain::handle(a,b);
    }
};

class AGreaterThanB : public Chain
{
public:
    AGreaterThanB(Chain* ch): Chain(ch){};
    virtual void handle(int a, int b) const override
    {
        if(a >= b)a=a%b;
        Chain::handle(a,b);
    }
};

class BGreaterThanA : public Chain
{
public:
    BGreaterThanA(Chain* ch): Chain(ch){};
    virtual void handle(int a, int b) const override
    {
        if(b > a)b=b%a;
        Chain::handle(a,b);
    }
};

int main()
{
    Chain *x = new CheckZero(), *y = new AGreaterThanB(x), *z = new BGreaterThanA(y);
    x->setNext(z);
    int a,b;
    cin>>a>>b;
    x->handle(a,b);
    delete x;
    delete y;
    delete z;
    return 0;
}
