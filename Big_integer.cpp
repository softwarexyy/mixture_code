/***************** This is used to compute with big integer ***************/
/****************** addtion and mulpulation *******************************/


string add(string& num1, string& num2)
{
    string res;
    int i;
    int size = num1.size()>num2.size() ? (num1.size()+1) : (num2.size()+1);
    for (i=0; i<size; i++)
        res.push_back('0');     //所有位初始化为'0'

    for (i=0; i<num1.size() && i<num2.size(); i++)
    {
        int temp = res[i]-'0' + num1[i]-'0' + num2[i]-'0';
        res[i] = temp%10 + '0';
        res[i+1] = temp/10 + '0';
    }
    if (i==num1.size())    //num1完毕
    {
        for (i; i<num2.size(); i++)
        {
            int temp = res[i]-'0' + num2[i]-'0';
            res[i] = temp%10 + '0';
            res[i+1] = temp/10 + '0';
        }
    }
    else                    //num2完毕
    {
        for (i; i<num1.size(); i++)
        {
            int temp = res[i]-'0' + num1[i]-'0';
            res[i] = temp%10 + '0';
            res[i+1] = temp/10 + '0';
        }
    }

    if (res[size-1] == '0')
        res.erase(res.end()-1);

    return res;
}
