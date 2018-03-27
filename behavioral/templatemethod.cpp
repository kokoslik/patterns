#include <iostream>
#include <vector>
using namespace std;

class OperateExtremum
{
protected:
    virtual bool compare(int a,int b) const = 0;
    virtual void iter_modify(vector<int> &vec, vector<int>::iterator it) const = 0;
public:
    void operate(vector<int> &vec) const
    {
        auto extr_it = vec.begin();
        for(auto it = vec.begin();it!=vec.end();++it)
            if(compare(*extr_it,*it))
                extr_it=it;
        iter_modify(vec, extr_it);
    }
    virtual ~OperateExtremum() = default;
};

class RemoveMax: public OperateExtremum
{
protected:
    virtual bool compare(int a, int b) const override
    {
        return a<b;
    }
    virtual void iter_modify(vector<int> &vec, vector<int>::iterator it) const override
    {
        vec.erase(it);
    }
};

int main()
{
    RemoveMax rm;
    vector<int> a = {1,5,6,2,3};
    rm.operate(a);
    for(auto i:a)
        cout<<i<<' ';
    cout<<endl;
    return 0;
}
