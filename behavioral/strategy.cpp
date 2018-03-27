#include <iostream>
#include <cmath>
using namespace std;

class InterpStrategy
{
public:
    virtual ~InterpStrategy() = default;
    virtual double interpolate(double a, double b, double i) const = 0;
};

class Interpolator
{
private:
    double a,b;
    InterpStrategy *strategy;
public:
    explicit Interpolator(double a_, double b_, InterpStrategy *strategy_):a(a_),b(b_),strategy(strategy_){};
    double operator()(double i) const
    {
        return strategy->interpolate(a,b,i);
    }
};



class MeanInterpStrategy: public InterpStrategy
{
public:
    virtual double interpolate(double a, double b, double i) const override
    {
        return (1.0-i)*a+i*b;
    }
};

class GeomInterpStrategy: public InterpStrategy
{
public:
    virtual double interpolate(double a, double b, double i) const override
    {
        return pow(a,1.0-i)*pow(b,i);
    }
};

int main()
{
    GeomInterpStrategy geom;
    MeanInterpStrategy mean;
    Interpolator in1(1,2,&mean), in2(1,2,&geom);
    cout<<in1(0.5)<<' '<<in2(0.5)<<endl;
    return 0;
}
