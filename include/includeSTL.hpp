#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <ctime>//用于程序计时
using namespace std;
//以列表的形式输出vector
template <typename T>
ostream &operator<<(ostream &out, const vector<T> &a)
{
    out << "[" << a[0];
    for (int i = 1; i < a.size(); i++)
    {
        out << "," << a[i];
    }
    out << "]";
    return out;
}
//绝对值函数
double myabs(double a)
{
    if (a > 0)
    {
        return a;
    }
    else
    {
        return -a;
    }
}
double min(double a, double b)
{
    return a > b ? b : a;
}
double max(double a, double b)
{
    return a > b ? a : b;
}
//把vector反转
template <typename T>
vector<T> reverse(const vector<T> &a)
{
    vector<T> re(a.size());
    for (int i = 0; i < re.size(); i++)
    {
        re[i] = a[re.size() - 1 - i];
    }
    return re;
}
//把数组转换成vector
vector<double> list2vector(const double *a, int length)
{

    vector<double> re;
    for (int i = 0; i < length; i++)
    {
        re.push_back(a[i]);
    }
    return re;
}
