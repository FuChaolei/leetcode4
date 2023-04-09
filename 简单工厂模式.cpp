#include <bits/stdc++.h>
using namespace std;
class AbstractFruit
{
public:
    virtual void ShowName() = 0;
};
class Apple : public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "苹果" << endl;
    }
};
class Banana : public AbstractFruit
{
public:
    virtual void ShowName()
    {
        cout << "香蕉" << endl;
    }
};
class Factory
{
public:
    static AbstractFruit *CreateFruit(string s)
    {
        if (s == "apple")
        {
            return new Apple;
        }
        else if (s == "banana")
        {
            return new Banana;
        }
        return nullptr;
    }
};

int main()
{
    Factory *factory = new Factory;
    AbstractFruit *fruit = factory->CreateFruit("apple");
    fruit->ShowName();
    fruit = factory->CreateFruit("banana");
    fruit->ShowName();
    delete fruit;
    delete factory;
    fruit = nullptr;
    factory = nullptr;
    return 0;
}
