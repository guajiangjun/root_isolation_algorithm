#pragma once
#include "Interval.hpp"
#include "Poly.hpp"
//判断0是否在f(I)中
bool if_0_In_(const Poly<double> &f, const Interval &I)
{
    return ifIn(0, f.eval(I));
}
//计算f在区间I中的实根隔离区间，并将这些区间添加到vector<Interval> result中
//delta表示两个实根之间的距离大于delta，epsilon表示如果区间长度小于epsilon，就不再进行计算了
void root_isolation(const Poly<double> &f, Interval I, vector<Interval> &result, double delta = 1e-100, double epsilon = 1e-100)
{
    //表示如果区间长度小于epsilon，就不再进行计算了
    if (I.getLength() < epsilon)
    {
        return;
    }
    //如果0不在f(I)中，则f在I中一定没有实根，故对于区间I不做任何处理
    if (if_0_In_(f, I) == false)
    {
        return;
    }
    //如果0在f(I)中，则f在I中可能有实根
    else
    {
        double a = I(0), b = I(1);
        if (f.eval(a) == 0)
        {
            result.push_back(Interval(a, a));
            a += delta;
        }
        if (f.eval(b) == 0)
        {
            result.push_back(Interval(b, b));
            b -= delta;
        }
        if ((f.eval(a) * f.eval(b) < 0) && (if_0_In_(f.diff(), Interval(a, b)) == false))
        {
            result.push_back(Interval(a, b));
            return;
        }
        else
        {
            root_isolation(f, Interval(a, (a + b) / 2), result);
            root_isolation(f, Interval((a + b) / 2, b), result);
            return;
        }
    }
}
void root_isolation(const Poly<double> &f1)
{

    vector<Interval> result;

    clock_t startTime, endTime;
    startTime = clock(); //计时开始

    //f(x)在区间(-1,1)中的实根隔离区间
    root_isolation(f1, Interval(-1, 1), result);

    //f(x)在区间(-1,1)外的实根隔离区间
    Poly<double> f(reverse(f1.getCoeff()));
    vector<Interval> result2;
    root_isolation(f, Interval(-1, 1), result2);
    for (int i = 0; i < result2.size(); i++)
    {
        result2[i] = reverse(result2[i]);
    }

    endTime = clock(); //计时结束
    cout << "f(x)=" << f1 << endl
         << endl;
    cout << "f(x)在区间(-1,1)中的实根隔离区间为：" << endl;
    cout << result << endl
         << endl;
    cout << "f(x)在区间(-1,1)外的实根隔离区间为：" << endl;
    cout << result2 << endl
         << endl;
    cout << "The run time is: " << (double)(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
    return;
}
