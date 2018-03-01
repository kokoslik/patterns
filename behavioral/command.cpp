#include <iostream>
#include <vector>
#include <map>
using namespace std;

class VectorWrapper
{
private:
    vector<int> vec;
public:
    VectorWrapper() = default;
    void push_back()
    {
        cout<<"Enter number: ";
        int a;
        cin>>a;
        vec.push_back(a);
    }
    void pop_back()
    {
        vec.pop_back();
    }
    void back()
    {
        cout<<vec.back()<<endl;
    }
    void print()
    {
        for(int i: vec)
            cout<<i<<' ';
        cout<<endl;
    }
};

class Command
{
public:
    typedef void(VectorWrapper::*Action)();
    Command(VectorWrapper* vec_, Action act_):vec(vec_),act(act_){}
    void execute()
    {
        (vec->*act)();
    }
private:
    VectorWrapper* vec;
    Action act;
};

int main()
{
    map <string, Command::Action> cmd{{"push_back",&VectorWrapper::push_back},{"pop_back",&VectorWrapper::pop_back},{"back",&VectorWrapper::back},{"print", &VectorWrapper::print}};
    VectorWrapper vec;
    string str;
    while(true)
    {
        cin>>str;
        if(str=="quit")
            break;
        if(cmd.find(str)!=cmd.end())
        {
            Command comm(&vec, cmd[str]);
            comm.execute();
        }
    }
    return 0;
}
