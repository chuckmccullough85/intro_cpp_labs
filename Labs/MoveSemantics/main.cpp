#include <iostream>
using namespace std;

class Light
{
public:
    Light() { cout << "Light()" << endl; }
    Light(const Light &other) { cout << "Light(const Light &other)" << endl; }
    Light(Light &&other) { cout << "Light(Light &&other)" << endl; }
    Light &operator=(const Light &other)
    {
        cout << "Light &operator=(const Light &other)" << endl;
        return *this;
    }
    Light &operator=(Light &&other)
    {
        cout << "Light &operator=(Light &&other)" << endl;
        return *this;
    }
};

Light getLight()
{
    return Light();
}

int main()
{
    Light a;                // Light()
    Light b = a;            // Light(const Light &other)
    Light c(a);             // Light(const Light &other)
    // we would expect move constructor here,
    // but the compiler is allowed to optimize it away
    Light d (getLight());   // Light() - compiler optimization
    Light e (move(getLight()));   // move constructor
    a = d;                  // Light &operator=(const Light &other)
    b = getLight();         // move assignment
    return 0;
}