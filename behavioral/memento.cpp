#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Memento
{
private:
    int num;
    friend class Number;
public:
    Memento(int num_):num(num_){}
};

class Number
{
private:
    int num;
public:
    Number(int num_):num(num_){}
    void incr()
    {
        num++;
    }
    void decr()
    {
        num--;
    }
    void print()
    {
        cout<<num<<endl;
    }
    Memento writeMemento() const
    {
        Memento mem(num);
        return mem;
    }
    void readMemento(const Memento& mem)
    {
        num=mem.num;
    }
};

class Command
{
private:
    Number *num;
    void (Number:: *func)() ;
public:
    Command(){}
    Command(Number &num_, void (Number:: *func_)()):num(&num_),func(func_){}
    void execute()
    {
        (num->*func)();
    }
};


int main()
{
    vector<Command> cmds;
    vector<Memento> mems;
    int curidx = 0;
    Number n(0);
    char c;
    do{
        cin>>c;
        switch(c)
        {
            case 'i':
                cmds.resize(curidx);
                cmds.emplace_back(n,&Number::incr);
                mems.push_back(n.writeMemento());
                curidx++;
                cmds.back().execute();
                n.print();
                break;
            case 'd':
                cmds.resize(curidx);
                cmds.resize(curidx);
                cmds.emplace_back(n,&Number::decr);
                mems.push_back(n.writeMemento());
                curidx++;
                cmds.back().execute();
                n.print();
                break;
            case 'u':
                if(curidx == 0)
                    break;
                n.readMemento(mems.back());
                mems.pop_back();
                curidx--;
                n.print();
                break;
            case 'r':
                if(curidx == static_cast<int>(cmds.size()))
                    break;
                mems.push_back(n.writeMemento());
                cmds[curidx].execute();
                curidx++;
                n.print();
                break;     
        }
    }while(c!='q');
    return 0;
}
