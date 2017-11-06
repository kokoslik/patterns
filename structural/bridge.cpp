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

class PetInfo
{
protected:
    Pet* p;
public:
    PetInfo(Pet* p_): p(p_){};
    virtual ~PetInfo() = default;
    virtual void print() const
    {
        cout<<p->getName()<<endl;
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

class PetText:public PetInfo
{
public:
    PetText(Pet* p):PetInfo(p){};
    virtual void print() const override
    {
        cout<<"I'm a "<<p->getName()<<endl;
    }
};

int main()
{
    unique_ptr<Pet> dog(new Dog), cat(new Cat);
    unique_ptr<PetInfo> pic(new PetInfo(cat.get())), ptd(new PetText(dog.get()));
    pic->print();
    ptd->print();
    return 0;
}
