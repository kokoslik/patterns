#include <iostream>
using namespace std;

class IntList
{
private:
    class Node
    {
    public:
        int num;
        Node *next;
        Node(int num_,Node *next_=nullptr):num(num_),next(next_){}
        ~Node()
        {
            if(next!=nullptr)
                delete next;
            cout<<"deleted"<<endl;
        }
    };
    Node *head;
public:
    explicit IntList():head(nullptr){}
    ~IntList()
    {
        if(head!=nullptr)
            delete head;
        cout<<"deleted"<<endl;
    }
    void add(int i)
    {
        head = new Node(i, head);
    }
    class Iterator
    {
    private:
        IntList::Node* nd;
    public:
        Iterator(IntList::Node* nd_):nd(nd_){}
        void operator++(int)
        {
            nd=nd->next;
        }
        bool operator!=(Iterator it)
        {
            return it.nd!=nd;
        }
        int& operator*()
        {
            return nd->num;
        }
    };
    Iterator begin()
    {
        return Iterator(head);
    }
    Iterator end()
    {
        return Iterator(nullptr);
    }
};

int main()
{
    IntList a;
    a.add(3);
    a.add(2);
    a.add(1);
    a.add(5);
    for(auto it = a.begin();it!= a.end(); it++)
        cout<<*it<<endl;
    return 0;
}
