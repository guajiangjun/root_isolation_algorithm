#include "include/include.hpp"
int main()
{
    double a[] = {-18,
                  -9,
                  -16,
                  95,
                  25,
                  25,
                  -16,
                  6,
                  85,
                  14,
                  -53,
                  82,
                  51,
                  22,
                  84,
                  58,
                  73,
                  -2,
                  -1,
                  50,
                  -33,
                  73,
                  -46,
                  92,
                  66,
                  60,
                  -85,
                  77,
                  90,
                  -14,
                  46,
                  27,
                  -56,
                  24,
                  0,
                  -74,
                  68,
                  -1,
                  35,
                  59,
                  26,
                  58,
                  39,
                  -81,
                  -7,
                  47,
                  -72,
                  -87,
                  -88,
                  -88,
                  68,
                  87,
                  -74,
                  39,
                  85,
                  -46,
                  68,
                  -46,
                  -46,
                  -7,
                  77,
                  -36,
                  -40,
                  -55,
                  -81,
                  -87,
                  55,
                  -89,
                  2,
                  58,
                  76,
                  -37,
                  -54,
                  2,
                  63,
                  -1,
                  59,
                  3,
                  25,
                  -81,
                  -84,
                  -83,
                  3,
                  -60,
                  -22,
                  -82,
                  0,
                  40,
                  -85,
                  -74,
                  -58,
                  22,
                  -85,
                  -70,
                  -6,
                  99,
                  20,
                  12,
                  -99,
                  -9,
                  53,
                  75,
                  -3,
                  -15,
                  5,
                  -72,
                  -67,
                  81,
                  17,
                  -95,
                  30,
                  72,
                  62,
                  50,
                  -57,
                  30,
                  -15,
                  -59,
                  19,
                  4,
                  -89,
                  -31,
                  49,
                  -50,
                  6,
                  -57,
                  95,
                  41,
                  46,
                  0,
                  -99,
                  94,
                  -12,
                  26,
                  -55,
                  -73,
                  56,
                  -67,
                  3,
                  96,
                  -10,
                  -78,
                  47,
                  -10,
                  -41,
                  -83,
                  -40,
                  -39,
                  -75,
                  3,
                  39,
                  -94,
                  20,
                  34,
                  79,
                  -64,
                  79,
                  65,
                  50,
                  77,
                  -60,
                  75,
                  51,
                  -71,
                  -87,
                  23,
                  -72,
                  -23,
                  -37,
                  -67,
                  94,
                  27,
                  87,
                  -8,
                  31,
                  -53,
                  45,
                  -86,
                  39,
                  27,
                  81,
                  -95,
                  99,
                  66,
                  57,
                  39,
                  -75,
                  -66,
                  -75,
                  -21,
                  -14,
                  -65,
                  41,
                  -39,
                  -32,
                  90,
                  -96,
                  58,
                  -3,
                  69,
                  87,
                  -99,
                  -10,
                  -76,
                  -94,
                  -1,
                  23,
                  -32,
                  -19,
                  26,
                  -58,
                  34,
                  14,
                  -98,
                  98,
                  -78,
                  15,
                  49,
                  -6,
                  29,
                  -36,
                  -94,
                  -65,
                  53,
                  -21,
                  66,
                  21,
                  86,
                  -54,
                  4,
                  -17,
                  22,
                  51,
                  5,
                  -36,
                  88,
                  -5,
                  -33,
                  -21,
                  -21,
                  -70,
                  -37,
                  49,
                  96,
                  -38,
                  28,
                  -51,
                  24,
                  -8,
                  50,
                  10,
                  28,
                  86,
                  -27,
                  57,
                  -12};

    vector<double> coeff = list2vector(a, sizeof(a) / sizeof(a[0]));
    Poly<double> f(coeff);
    test(f);

    return 0;
}

//实验(1)
//Poly<double> f(vector<double>{-0.01, 1});
//实验(2)
//Poly<double> f(vector<double>{-0.006, 0.11, -0.6, 1}); //表示f(x)= -0.006+ 0.11x - 0.6x^2 + x^3
//实验(3)x^3 - 0.06x^2 + 0.0011x - 6*10^{-6}
//Poly<double> f(vector<double>{-6e-6, 0.0011, -0.06, 1});
//实验(4)
//Poly<double> f(vector<double>{0,-2.673e-6, 2.673001161,-1.16099709,-2.910001, 1});
//实验(5)
//Poly<double> f(vector<double>{1e-10, -1.111e-6, 0.0011211, -0.1111, 1});
