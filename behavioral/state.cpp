#include <iostream>
#include <memory>
#include <string>
using namespace std;

class NumState;

class Number
{
private:
    int num = 0;
    unique_ptr<NumState> state;
public:    
    void ChangeState(NumState*);
    void setNum(int i){num=i;}
    int getNum() const{return num;}
    Number();
    void process(string s);
};

class NumState
{
public:
    virtual ~NumState() = default;
    virtual void process(Number* num, string s) = 0;
};

class NumPlusState: public NumState
{
public:
    virtual void process(Number* num, string s) override;
};
class NumEnterState: public NumState
{
public:
    virtual void process(Number* num, string s) override;
};
class NumPrintState: public NumState
{
public:
    virtual void process(Number* num, string s) override;
};

class NumCmdState: public NumState
{
public:
    virtual void process(Number* num, string s) override
    {
        if(s=="enter")
            num->ChangeState(new NumEnterState);
        else if(s=="plus")
            num->ChangeState(new NumPlusState);
        else if(s=="print")
            num->ChangeState(new NumPrintState);            
    }
};

void NumEnterState::process(Number* num, string s)
{
    num->setNum(stoi(s));
    num->ChangeState(new NumCmdState);
}

void NumPlusState::process(Number* num, string s)
{
    num->setNum(num->getNum()+stoi(s));
    num->ChangeState(new NumCmdState);
}

void NumPrintState::process(Number* num, string s)
{
    cout<<num->getNum()<<endl;
    num->ChangeState(new NumCmdState);
}
    
Number::Number():state(new NumCmdState){}
void Number::ChangeState(NumState* st)
{
    state.reset(st);
}
void Number::process(string s)
{
    state->process(this,s);
}



int main()
{
    Number num;
    string s;
    do{
        cin>>s;
        num.process(s);
    }while(s!="q");
    return 0;
}
