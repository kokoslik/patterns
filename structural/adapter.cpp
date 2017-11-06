#include <iostream>
#include <string>
#include <memory>
using namespace std;


class Pet
{
public:
    virtual ~Pet() = default;
    virtual string getName() const
    {
        return "Pet";
    }
};

class Cat
{
public:
    string call() const
    {
        return "Cat";
    }
};

class Dog
{
public:
    string call() const
    {
        return "Dog";
    }
};

//Class adapter
class CatCAdapter: public Pet, private Cat
{
public:
    virtual string getName() const override
    {
        return call();
    }
};

//Object Adapter
class DogOAdapter: public Pet
{
private:
    Dog* d;
public:
    DogOAdapter(Dog* d_): d(d_){};
    virtual string getName() const override
    {
        return d->call();
    }
};

int main()
{
    unique_ptr<Pet> p(new CatCAdapter());
    cout<<p->getName()<<endl;
    unique_ptr<Dog> d;
    unique_ptr<Pet> pp(new DogOAdapter(d.get()));
    cout<<pp->getName()<<endl;

    return 0;
}
