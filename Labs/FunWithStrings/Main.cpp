#include <string>
#include <iostream>

using namespace std;

void func(string aString)
{
    cout << "func: " << aString << endl;
    aString += " Modified";
    cout << "func: " << aString << endl;
}


int main()
{
    string s1;
    string s2;
    s1 = "Hello ";
    func(s1);

    s2 = "World";
    auto cptr = "C string";
    auto cppstr = "C++ string"s;

    cout << "[" << s1 << s2 << "]\n";

    string big = s1 + s2 + cptr + cppstr;
    cout << big << endl;
    string s3 = "Hello ";
    if (s1 == s3) cout << "s1 is equal to s3";
}
