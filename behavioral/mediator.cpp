#include <iostream>
#include <string>
#include <memory>
#include <vector>
using namespace std;

class Pet;

class PetMediator
{
public:
    virtual ~PetMediator() = default;
    virtual void getAngry(const Pet *pet) const = 0;    
};

class Pet
{
protected:
    const PetMediator *med;
    string name;
public:
    Pet(const char * name_,PetMediator* med_): med(med_), name(name_){}
    virtual void react() const = 0;
    virtual void getAngry() const
    {
        cout<<name<<" is angry."<<endl;
        med->getAngry(this);
    }
    virtual ~Pet() = default;
};

class Cat: public Pet
{
public:
    Cat(const char* name, PetMediator *med):Pet(name,med){}
    virtual void react() const override
    {
        cout<<name<<" meows."<<endl;
    }
};

class Dog: public Pet
{
public:
    Dog(const char* name, PetMediator *med):Pet(name,med){}
    virtual void react() const override
    {
        cout<<name<<" barks."<<endl;
    }
};

class MyPetMediator: public PetMediator
{
private:
    vector<unique_ptr<Pet>> pets;
public:
    MyPetMediator()
    {
        pets.emplace_back(new Cat("Lisa",this));
        pets.emplace_back(new Cat("Tom",this));
        pets.emplace_back(new Dog("Rex",this));
        pets.emplace_back(new Dog("Scooby",this));
    }
    virtual void getAngry(const Pet *pet) const override
    {
        if(pet == pets[0].get() || pet == pets[1].get())
        {
            pets[2]->react();
            pets[3]->react();
        }
        else
        {
            pets[0]->react();
            pets[1]->react();
        }
    }
    void makeAngry(int i) const
    {
        pets[i]->getAngry();
    }
};

int main()
{
    MyPetMediator med;
    med.makeAngry(0);
    return 0;
}
