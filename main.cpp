#include "include/include.hpp"

//step1:多项式的系数：从低次到高次

double a[] = {
    4.90000000000000, -23.8000000000000, -3.70000000000000, 1};

//step2:把数组转换成vector
vector<double>
    coeff = list2vector(a, sizeof(a) / sizeof(a[0]));
//step3:把vector转换成多项式
Poly<double> f(coeff);

int main()
{
    root_isolation(f);

    return 0;
}
