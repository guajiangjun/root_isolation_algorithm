#pragma once

#include "includeSTL.hpp"
#include "Interval.hpp"
template <typename T> //T表示多项式的系数的数据类型
class Poly
{

private:
    vector<T> poly;
    int degree;

public:
    //构造函数（用一个vector初始化进行构造） test ok!
    Poly(const vector<T> &m_poly = vector<T>(1))
    {
        poly = m_poly;
        for (int i = poly.size() - 1; i >= 1; i--)
        {
            if (poly[i] == 0)
            {
                poly.pop_back();
            }
            else
            {
                break;
            }
        }
        degree = poly.size() - 1;
    }

#pragma region 返回i次项的系数（[] 可以修改和() 不可以修改），返回多项式的次数[test ok !]
    //返回x^i的系数（可以修改）
    T &operator[](int i)
    {
        return poly[i];
    }
    //返回x^i的系数（不可以修改）
    T operator()(int i) const
    {
        return poly[i];
    }
    //返回多项式的次数
    int getDegree() const
    {
        return degree;
    }
    vector<T> getCoeff() const
    {
        return poly;
    }
#pragma endregion

#pragma region 多项式加等test ok !，减等test ok !，乘等todo
    //多项式加等 test ok!
    Poly<T> &operator+=(const Poly &f)
    {
        if (degree >= f.getDegree()) //degree >= degree(f)
        {
            for (int i = 0; i <= f.getDegree(); i++)
                poly[i] += f(i);
        }
        else //degree < degree(f)
        {
            for (int i = 0; i <= degree; i++)
                poly[i] += f(i);
            for (int i = degree + 1; i <= f.getDegree(); i++)
                poly.push_back(f(i));
        }
        degree = poly.size() - 1;
        return *this;
    }
    //多项式减等 test ok!
    Poly<T> &operator-=(const Poly &f)
    {
        if (degree >= f.getDegree())
        {
            for (int i = 0; i <= f.getDegree(); i++)
                poly[i] -= f(i);
        }
        else //degree < degree(f)
        {
            for (int i = 0; i <= degree; i++)
                poly[i] -= f(i);
            for (int i = degree + 1; i <= f.getDegree(); i++)
                poly.push_back(-f(i));
        }
        degree = poly.size() - 1;
        return *this;
    }

#pragma endregion

#pragma region 计算f(x) test ok !, 计算f(I)
    //计算f(x) test ok!
    T eval(T x) const
    {
        T re = poly[degree];
        for (int i = degree; i >= 1; i--)
        {
            re *= x;
            re += poly[i - 1];
        }
        return re;
    }
    Interval eval(const Interval &I) const
    {
        Interval re(poly[degree], poly[degree]);
        for (int i = degree; i >= 1; i--)
        {
            re *= I;
            re += poly[i - 1];
        }
        return re;
    }

#pragma endregion

#pragma region 计算f的导数 test ok !
    // 计算f的导数 test ok!
    Poly<T> diff() const
    {
        if (poly.size() <= 1)
            return Poly();
        vector<T> a;
        for (int i = 0; i < degree; i++)
        {
            a.push_back((i + 1) * poly[i + 1]);
        }
        return Poly<T>(a);
    }

#pragma endregion
};
//输出多项式 test ok!
template <typename T>
ostream &operator<<(ostream &out, const Poly<T> f)
{
    out << f(0);
    for (int i = 1; i <= f.getDegree(); i++)
    {
        if (f(i) == 0)
        {
            continue;
        }
        else if (f(i) > 0)
        {
            out << "+" << f(i) << "x^{" << i << "}";
        }
        else
        {
            out << "-" << (-f(i)) << "x^{" << i << "}";
        }
    }
    return out;
}

/*
#pragma region 多项式加，减，乘
template <typename T>
Poly<T> operator+(const Poly<T> &f, const Poly<T> &g)
{
    Poly<T> h = f;
    h += g;
    return h;
}
template <typename T>
Poly<T> operator-(const Poly<T> &f, const Poly<T> &g)
{
    Poly<T> h = f;
    h -= g;
    return h;
}
#pragma endregion

#pragma region 判断两个多项式是否相同

#pragma endregion

#pragma region 取正，取负
template <typename T>
Poly<T> operator-(const Poly<T> &f)
{
    Poly<T> re;
    re -= f;
    return re;
}
#pragma endregion
*/