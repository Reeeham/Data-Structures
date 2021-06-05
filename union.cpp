#include <iostream>
using namespace std;

union box  //stores last value only in the memory in the all values of the same data type
{
    double weight;
    double height;

};


int main()
{
    box b1;
    b1.weight = 20;
    b1.height = 30;

    cout << b1.weight << endl;
    cout << b1.height;

    return 0;
}
