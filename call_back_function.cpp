#include <iostream>
using namespace std;
typedef void (*Callbackfunc1)(int* a, int* b);      //定义函数指针
typedef bool (*Callbackfunc2)(int a, int b);

void mySwap(int *a, int *b);
bool myCompare(int a, int b);

//Callbackfunc1 swapxyy = &mySwap;
//Callbackfunc2 comparexyy = &myCompare;
void printSmall(int a, int b, Callbackfunc2 callbacktest);  //利用函数指针

int main()
{
    int a,b;
    cin >> a >> b;
    printSmall(a, b, &myCompare);             //回调函数
}

void printSmall(int a, int b, Callbackfunc2 callbacktest){
    if(callbacktest(a, b) == true)
        cout << a;
    else
        cout << b;
}

void mySwap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
    cout << "mySwap" << endl;
}

bool myCompare(int a, int b){
    if (a<b)
        return true;
    else
        return false;
}
