/*===== on Windows ======*/

#include <iostream>
#include <ctime>
#include <windows.h>

#define SIZE 20
using namespace std;


void GetRand(){
    int n;
    while(true)         // 循环、不断得到新的随机数
    {
        n = rand()%SIZE;
        cout << n << endl;
        Sleep(500);
    }
}
int main()
{
    srand(time(NULL));  //根据时间确定随机数种子(常用方法)
    GetRand();
}
