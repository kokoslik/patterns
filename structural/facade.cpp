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

class Cat: public Pet
{
public:
    virtual string getName() const override
    {
        return "Cat";
    }
};

class Dog: public Pet
{
public:
    virtual string getName() const override
    {
        return "Dog";
    }
};

class Facade
{
private:
    Dog dog;
    Cat cat;
public:
    void print() const
    {
        cout<<dog.getName()<<" and "<<cat.getName()<<" are friends."<<endl;;
    }
};

int main()
{
    Facade f;
    f.print();
    return 0;
}
