#include <iostream>
#include <map>
#include <cmath>
using namespace std;

int factorial(int n)
{
    return n==0?1:factorial(n-1)*n;
}

class FactorialFly
{
private:
    long long state;
public:
    FactorialFly(int n)
    {
        state=factorial(n);
    }
    int getDigits(int base=10) const
    {
        return (int)(log((double)state)/log(base))+1;
    }
    ~FactorialFly()
    {
        cout<<"Factorial "<<state<<" deleted"<<endl;
    }
};

class FactFactory
{
private:
    map<int,FactorialFly*> pool;
public:
    FactFactory() = default;
    ~FactFactory()
    {
        for(map<int,FactorialFly*>::iterator it=pool.begin();it!=pool.end();++it)
        {
            delete it->second;
        }
    }
    const FactorialFly* getFact(int n)
    {
        if(pool.find(n)==pool.end())
            pool[n]=new FactorialFly(n);
        return pool[n];
    }
};

int main()
{
    FactFactory f;
    cout<<"Decimal"<<endl;
    for(int i=0;i<=10;i++)
    {
        const FactorialFly* ff=f.getFact(i);
        cout<<ff->getDigits()<<endl;
    }
    cout<<"Binary"<<endl;
    for(int i=0;i<=10;i++)
    {
        const FactorialFly* ff=f.getFact(i);
        cout<<ff->getDigits(2)<<endl;
    }
    return 0;
}
