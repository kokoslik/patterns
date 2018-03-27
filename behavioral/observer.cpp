#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class Point2D;

class CS
{
protected:
    const Point2D& p;
public:
    CS(Point2D& p_);
    virtual void update() const = 0;
    virtual ~CS() = default;
};

class Point2D
{
private:
    double x;
    double y;
    vector<const CS*> systems;
public:
    void attachCS(const CS* cs)
    {
        systems.push_back(cs);
    }
    void update(double x_, double y_)
    {
        x=x_;
        y=y_;
        for(const CS* i:systems)
            i->update();
    }
    double get_x() const
    {
        return x;
    }
    double get_y() const
    {
        return y;
    }
};

CS::CS(Point2D& p_):p(p_)
    {
        p_.attachCS(this);
    }

class CartCS: public CS
{
public:
    CartCS(Point2D& p_):CS(p_){}
    virtual void update() const override
    {
        cout<<"Cartesian: "<<endl;
        cout<<"X = "<<p.get_x()<<endl;
        cout<<"Y = "<<p.get_y()<<endl;
    }
};

class PolarCS: public CS
{
public:
    PolarCS(Point2D& p_):CS(p_){}
    virtual void update() const override
    {
        cout<<"Polar: "<<endl;
        cout<<"R = "<<sqrt(p.get_x()*p.get_x()+p.get_y()*p.get_y())<<endl;
        cout<<"PHI = "<<180.0/M_PI*atan2(p.get_y(),p.get_x())<<endl;
    }
};

int main()
{
    Point2D a;
    PolarCS cs1(a);
    CartCS cs2(a);
    a.update(1,1);
    a.update(0,1);
    return 0;
}
