#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Component
{
protected:
    string name;
public:
    Component(string name_):name(name_){};
    virtual ~Component(){};
    virtual void ls(int level = 0) const = 0;
};

class File: public Component
{
public:
    File(string name):Component(name){};
    virtual void ls(int level = 0) const
    {
        for(int i=0;i<level;i++)
            cout<<"    ";
        cout<<name<<endl;
    }
};

class Directory: public Component
{
private:
    vector<Component*> children;
public:
    Directory(string name):Component(name){};
    virtual void ls(int level = 0) const
    {
        for(int i=0;i<level;i++)
            cout<<"    ";
        cout<<name<<endl;
        for(Component* i:children)
            i->ls(level+1);
    }
    void addChild(Component* child)
    {
        children.push_back(child);
    }

};

int main()
{
    Directory home("home"), kokos("kokos"), user1("user1");
    File shared("shared"), film1("film1"), film2("film2"),data("data");
    home.addChild(&kokos);
    home.addChild(&user1);
    home.addChild(&shared);
    kokos.addChild(&film1);
    kokos.addChild(&film2);
    user1.addChild(&data);
    home.ls();
    return 0;
}
