#include <iostream>
#include <string>
using namespace std;

class Expression
{
public:
    virtual ~Expression() = default;
    virtual double eval() = 0;
};

class Number: public Expression
{
private:
    double num;
public:
    explicit Number(double num_): num(num_){}
    virtual double eval() override
    {
        return num;
    }
};

class Plus: public Expression
{
private:
    Expression *left, *right;
public:
    Plus(Expression* left_, Expression* right_):left(left_),right(right_){}
    virtual double eval() override
    {
        return left->eval()+right->eval();
    }
    ~Plus()
    {
        delete left;
        delete right;
    }
};

class Mult: public Expression
{
private:
    Expression *left, *right;
public:
    Mult(Expression* left_, Expression* right_):left(left_),right(right_){}
    virtual double eval() override
    {
        return left->eval()*right->eval();
    }
    ~Mult()
    {
        delete left;
        delete right;
    }
};

int main()
{
    Expression *expr = new Mult(new Plus(new Number(2),new Number(3)),new Number(6));
    cout<<"Answer: "<<expr->eval()<<endl;
    delete expr;
    return 0;
}
