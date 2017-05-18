#include <iostream>
#include <string>
#include <random>
using namespace std;

class StringBuilder
{
public:
    virtual void buildLetter() = 0;
    virtual void buildNumber() = 0;
    string getString() const
    {
        return s;
    }
    virtual ~StringBuilder(){};
protected:
    string s;
};

class RandomStringBuilder : public StringBuilder
{
public:
    virtual void buildLetter() override
    {
        uniform_int_distribution<char> distribution('a','z');
        s+=distribution(generator);
    }
    virtual void buildNumber() override
    {
        uniform_int_distribution<char> distribution('0','9');
        s+=distribution(generator);
    }
private:
    random_device generator;
};

class ConsequentStringBuilder : public StringBuilder
{
public:
    virtual void buildLetter() override
    {
        s+=letter;
        if(letter!='z')
            letter++;
        else
            letter='a';
    }
    virtual void buildNumber() override
    {
        s+=number;
        if(number!='9')
            number++;
        else
            number='0';
    }
private:
    char letter='a';
    char number='0';
};

class Client
{
private:
    StringBuilder *builder;
public:
    void setBuilder(StringBuilder *builder)
    {
        this->builder=builder;
    }
    void constructString()
    {
        builder->buildLetter();
        for(int i=0;i<3;i++)
            builder->buildNumber();
        for(int i=0;i<2;i++)
            builder->buildLetter();
        for(int i=0;i<2;i++)
            builder->buildNumber();
    }
};


int main()
{
    RandomStringBuilder rb;
    ConsequentStringBuilder cb;
    Client c;
    c.setBuilder(&rb);
    c.constructString();
    cout<<rb.getString()<<endl;
    c.setBuilder(&cb);
    c.constructString();
    cout<<cb.getString()<<endl;
    return 0;
}
