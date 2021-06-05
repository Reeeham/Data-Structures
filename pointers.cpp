#include<iostream>
using namespace std;

int main()
{

    int x = 20;
    cout << x << endl;
    //int *ptr = &x;
    //*ptr  = 25; //x will be changed from 20 to 25
    int *ptr = new int(20);
    cout << *ptr;
    return 0;
}
