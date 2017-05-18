#include <iostream>
#include <memory>
using namespace std;

class AProduct1
{
public:
    virtual ~AProduct1(){};
};

class AProduct2
{
public:
    virtual void interact(AProduct1* prod1) const = 0;
    virtual ~AProduct2(){};
};

class AFactory
{
public:
    virtual AProduct1* createProduct1() const = 0;
    virtual AProduct2* createProduct2() const = 0;
    virtual ~AFactory(){};
};

class Cat: public AProduct1
{};

class Dog: public AProduct2
{
public:
    virtual void interact(AProduct1* prod1) const override
    {
        cout<<typeid(*this).name()<<" chases "<<typeid(*prod1).name()<<endl;
    }
};

class Hare: public AProduct1
{};

class Fox: public AProduct2
{
public:
    virtual void interact(AProduct1* prod1) const override
    {
        cout<<typeid(*this).name()<<" kills "<<typeid(*prod1).name()<<endl;
    }
};

class PetFactory: public AFactory
{
    virtual AProduct1* createProduct1() const override
    {
        return new Cat;
    }
    virtual AProduct2* createProduct2() const override
    {
        return new Dog;
    }
};

class AnimalFactory: public AFactory
{
    virtual AProduct1* createProduct1() const override
    {
        return new Hare;
    }
    virtual AProduct2* createProduct2() const override
    {
        return new Fox;
    }
};

class Client
{
private:
    unique_ptr<AProduct1> pr1;
    unique_ptr<AProduct2> pr2;
public:
    Client(AFactory *factory):pr1(factory->createProduct1()),pr2(factory->createProduct2()){};
    void execute()
    {
        pr2->interact(pr1.get());
    }
};


int main()
{
    PetFactory pf;
    AnimalFactory af;
    Client c1(&pf),c2(&af);
    c1.execute();
    c2.execute();
    return 0;
}
