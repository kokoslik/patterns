#include <iostream>
#include <sstream>
using namespace std;

class Logger
{
protected:
    stringstream str;
    Logger(){};
public:
    template<class T>
    stringstream& operator <<(T info)
    {
        str<<info;
        return str;
    }
    void printLog() const
    {
        cout<<"LOG START"<<endl;
        cout<<str.str();
        cout<<"LOG END"<<endl;
    }
    static Logger& getInstance()
    {
        static Logger log;
        return log;
    };
    Logger(const Logger&) = delete;
    Logger(const Logger&&) = delete;
};

void somefunc()
{
    Logger &l=Logger::getInstance();
    //do something
    l<<"Logging from somefunc"<<endl;
}

int main()
{
    Logger &l=Logger::getInstance();
    l<<"This goes to log"<<endl<<"And this too!"<<endl;
    somefunc();
    l<<"Returned from somefunc"<<endl;
    l.printLog();
    return 0;
}
