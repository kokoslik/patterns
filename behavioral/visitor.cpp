#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

class Visitor
{
public:
    virtual void visit(const class Dog &) const = 0;
    virtual void visit(const class Cat &) const = 0;
    virtual ~Visitor() = default;
};

class Pet
{
protected:
    string name;
public:
    Pet(const char* name_):name(name_){}
    virtual void accept(const Visitor&) const = 0;
    virtual ~Pet() = default;
};

class Dog: public Pet
{
public:
    Dog(const char *s):Pet(s){}
    virtual void accept(const Visitor &vis) const override
    {
        vis.visit(*this);
    }
    void bark() const
    {
        cout<<name<<" barks."<<endl;
    }
};

class Cat: public Pet
{
public:
    Cat(const char *s):Pet(s){}
    virtual void accept(const Visitor &vis) const override
    {
        vis.visit(*this);
    }
    void meow() const
    {
        cout<<name<<" meows."<<endl;
    }
};

class ActionVisitor: public Visitor
{
public:
    virtual void visit(const Dog& dog) const override
    {
        dog.bark();
    }
    virtual void visit(const Cat& cat) const override
    {
        cat.meow();
    }
};

int main()
{
    vector< unique_ptr<Pet> > pets;
    pets.emplace_back(new Cat("Tom"));
    pets.emplace_back(new Dog("Rex"));
    pets.emplace_back(new Cat("Lucifer"));
    ActionVisitor vis;
    for(const auto& i:pets)
    {
        i->accept(vis);
    }
    return 0;
}
