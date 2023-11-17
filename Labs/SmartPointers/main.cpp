#include <iostream>
#include <memory>
using namespace std;

class MyClass
{
public:
    MyClass()
    {
        cout << "MyClass created" << endl;
    }
    ~MyClass()
    {
        cout << "MyClass destroyed" << endl;
    }
    void sayHello()
    {
        cout << "Hello from MyClass" << endl;
    }
};

int main()
{
    // Unique pointer
    {
        auto up = make_unique<MyClass>();
        up->sayHello();
    }

    {
        // Shared pointer
        auto sp1 = make_shared<MyClass>();
        {
            auto sp2 = sp1;
            sp2->sayHello();
        }
        sp1->sayHello();

        // Weak pointer
        weak_ptr<MyClass> weakPtr = sp1;
        cout << "weakPtr.use_count() = " << weakPtr.use_count() << endl;
        auto sp3 = weakPtr.lock();
        cout << "weakPtr.use_count() = " << weakPtr.use_count() << endl;
        sp3->sayHello();
    }
    return 0;
}
