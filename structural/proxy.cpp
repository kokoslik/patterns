#include <iostream>
#include <string>

using namespace std;

class ASecret
{
public:
    virtual void show_secret() const = 0;
};

class Secret: public ASecret
{
private:
    string secret;
public:
    explicit Secret(string secret_):secret(secret_){}
    virtual void show_secret() const override
    {
        cout<<"Secret string: "<<secret<<endl;
    }
};

class PassSecret: public ASecret
{
private:
    ASecret* secret;
    string password;
public:
    explicit PassSecret(string secret_, string passwd): password(passwd), secret(new Secret(secret_)){}
    ~PassSecret(){delete secret;}
    virtual void show_secret() const override
    {
        string temp;
        cout<< "Enter password: ";
        cin>>temp;
        if(temp==password)
            secret->show_secret();
        else
            cout<<"Wrong password!"<<endl;
    }
};

int main()
{

    ASecret *s1 = new Secret("abracadabra"), *s2 = new PassSecret("Avada Kedavra", "pass");
    s1->show_secret();
    s2->show_secret();
    delete s1;
    delete s2;
    return 0;
}
