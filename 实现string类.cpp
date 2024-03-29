#include <bits/stdc++.h>
using namespace std;
class String
{
public:
    String(const char *str = nullptr);
    String(const String &str);
    ~String();

    int size() const;
    const char *c_str() const;
    char &operator[](int n) const;
    String operator+(const String &str) const;
    bool operator==(const String &str) const;
    String &operator+=(const String &str);
    String &operator=(const String &str);
    friend ostream &operator<<(ostream &os, const String &str);

private:
    int len;
    char *data;
};
String::String(const char *str)
{
    if (str == nullptr)
    {
        len = 0;
        data = new char[1];
        *data = '\0';
    }
    else
    {
        len = strlen(str);
        data = new char[len + 1];
        strcpy(data, str);
    }
}
String::String(const String &str)
{
    len = str.size();
    data = new char[len + 1];
    strcpy(data, str.c_str());
}
String::~String()
{
    len = 0;
    delete[] data;
}

String &String::operator+=(const String &str)
{
    len += str.size();
    char *newc = new char[len + 1];
    strcpy(newc, data);
    strcat(newc, str.c_str());
    delete[] data;
    data = newc;
    return *this;
}
char &String::operator[](int n) const
{
    if (n >= len)
    {
        return data[len - 1];
    }
    return data[n];
}
bool String::operator==(const String &str) const
{
    if (len != str.size())
    {
        return false;
    }
    return strcmp(data, str.c_str()) ? false : true;
}
int String::size() const
{
    return len;
}
String &String::operator=(const String &str)
{
    if (this == &str)
    {
        return *this;
    }
    delete[] data;
    len = str.size();
    data = new char[len + 1];
    strcpy(data, str.c_str());
    return *this;
}
const char *String::c_str() const
{
    return data;
}
ostream &operator<<(ostream &os, const String &str)
{
    os << str.c_str();
    return os;
}
String String::operator+(const String &str) const
{
    String news;
    news.len = len + str.size();
    news.data = new char[news.len + 1];
    strcpy(news.data, data);
    strcat(news.data, str.c_str());
    return news;
}

int main()
{
    String s = "0";
    s += "123";
    String b = "0123";
    String d = b + s + b;
    cout << d << endl;
    if (s == b)
    {
        cout << "333" << endl;
    }
    cout << s << b << endl;
    cout << s.size() << endl;
    cout << s << endl;
    cout << s[6] << endl;
    return 0;
}
