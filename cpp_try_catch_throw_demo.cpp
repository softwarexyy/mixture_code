#include <iostream>
#include <stdexcept>
using namespace std;

//自定义异常类
class my_exception  
{
private:
    unsigned int yancy_error_no;
public:
    my_exception()
    {
        yancy_error_no = 1;
    }
    my_exception(int number)
    {
        yancy_error_no = number;
    }
    show_errorno()
    {
        std::cout << "ERROR:" << yancy_error_no << std::endl;
    }
};

// 异常处理实例1 exception_demo1:
// 利用runtime_error这个标准库中的异常类，判定ab是否相同
// 如果不相同则报runtime_error并进行异常处理
int exception_demo1()
{
    int a;
    int b;
    while (cin >> a >> b)
    {
        try
        {
            if (a!=b)
                throw runtime_error("Exception!: a is not b !");
            cout << "a equals b" << endl;
            return 0;
        }
        catch(runtime_error err)
        {
            cout << err.what() << endl
                 << "Do You Want to Continue? Input 'y' or 'n' ..." << endl;
            char ch;
            cin >> ch;
            if (cin && ch == 'n')
                break;
        }
    }
    return -1;
}

//异常处理实例2: exception_demo2
//利用自定义的异常类，判定输入是否为负数
//如果是负数则进行异常判定和处理
int exception_demo2()
{
    int a;
    while (cin >> a)
    {
        try
        {
            if (a < 0)
                throw my_exception(10);
            cout << "Your input: " << a << endl;
            return 0;
        }
        catch(my_exception err)
        {
            err.show_errorno();
            cout << "需要继续输入吗？（y or n）" << endl;
            char ch;
            cin >> ch;
            if (ch == 'n')
                break;
        }
    }
    return -1;
}


int main()
{
  //exception_demo1();
  //exception_demo2();
}

/************ 以下是使用try-catch-throw的程序结构***********/

void try_catch_demo()
{
    int a;
    cin >> a;
    try
    {
        if (1/* 触发异常的条件，暂用1代替 */)
        {
            //  初始化错误类对象（可用各种exception类，包括自定义的exception类）
            throw exception(/* 初始化异常类对象参数 */);
        }

    }
    catch(exception exc)    //  将捕捉到的错误归为exc对象
    {
        //  在此进行异常处理
    }
}
