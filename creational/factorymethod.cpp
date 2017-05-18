#include <iostream>
#include <memory>
#include <string>
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

class PetOwner
{
protected:
    Pet* pet;
    virtual Pet* newPet() const
    {
        return new Pet;
    }
public:
    void print()
    {
        pet=newPet();
        cout<<"I have a "<<pet->getName()<<endl;
    }
    virtual ~PetOwner()
    {
        delete pet;
    }

};

class CatOwner: public PetOwner
{
protected:
    virtual Pet* newPet() const override
    {
        return new Cat;
    }
};

class DogOwner: public PetOwner
{
protected:
    virtual Pet* newPet() const override
    {
        return new Dog;
    }
};

int main()
{
    unique_ptr<PetOwner> pm(new PetOwner), dm(new DogOwner), cm(new CatOwner);
    pm->print();
    dm->print();
    cm->print();
    return 0;
}
