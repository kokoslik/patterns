#include <iostream>
#include <memory>
#include <string>
using namespace std;

class PetPrototype
{
public:
    virtual ~PetPrototype() = default;
    virtual PetPrototype* clone() const
    {
        return new PetPrototype(*this);
    }
    virtual string getName() const
    {
        return "Pet";
    }
};

class DogPrototype: public PetPrototype
{
public:
    virtual PetPrototype* clone() const override
    {
        return new DogPrototype(*this);
    }
    virtual string getName() const override
    {
        return "Dog";
    }
};

class CatPrototype: public PetPrototype
{
public:
    virtual PetPrototype* clone() const override
    {
        return new CatPrototype(*this);
    }
    virtual string getName() const override
    {
        return "Cat";
    }
};

class Owner
{
protected:
    PetPrototype* pet;
public:
    ~Owner()
    {
        delete pet;
    }
    Owner(const PetPrototype& p)
    {
        pet=p.clone();
    }
    void print() const
    {
        cout<<"I have a "<<pet->getName()<<endl;
    }
};

int main()
{
    CatPrototype cat;
    DogPrototype dog;
    PetPrototype pet;

    Owner po(pet),doo(dog),co(cat);
    po.print();
    doo.print();
    co.print();
    return 0;
}
