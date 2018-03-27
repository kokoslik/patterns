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

class Dog: public Pet
{
public:
    virtual string getName() const override
    {
        return "Dog";
    }
};

class PetDecorator: public Pet
{
private:
    unique_ptr<Pet> inner;
public:
    PetDecorator(Pet* inner_):inner(inner_){};
    virtual string getName() const
    {
        return inner->getName();
    }
};

class IamPetDecorator: public PetDecorator
{
public:
    IamPetDecorator(Pet* inner):PetDecorator(inner){};
    virtual string getName() const
    {
        return "I'm a "+PetDecorator::getName();
    }
};

class GoodPetDecorator: public PetDecorator
{
public:
    GoodPetDecorator(Pet* inner):PetDecorator(inner){};
    virtual string getName() const
    {
        return "very good "+PetDecorator::getName();
    }
};

int main()
{
    unique_ptr<Pet> pet(new IamPetDecorator(new GoodPetDecorator(new Dog)));
    cout<<pet->getName()<<endl;
    return 0;
}
