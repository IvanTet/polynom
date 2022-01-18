#include "polynom.h"
#include <vector>
#include <cmath>

using namespace std;

//Конструктор класса:
Polynom::Polynom(int count)
{
    degree = count;
    for(int i = 0;i<=degree;i++)
    {
        coefficients.push_back(0);
    }
}
//Перегрузка оператора "квадратные скобки" ([]):
int Polynom::operator[](int position)
{
    return this->coefficients[position];
}
//Перегрузка оператора "скобки" (()):
int Polynom::operator ()(int var)
{
    int ans = 0;
    for(int i = 0;i<=degree;i++)
    {
        ans += coefficients[i]*pow(var,i);
    }
    return ans;
}

//Перегрузка оператора сложения (+):
Polynom Polynom::operator+(Polynom obj)
{
    Polynom tmp(obj.degree);
    for(int i=0; i <= degree; i++)
    {
        tmp.coefficients[i]=coefficients[i]+obj.coefficients[i];
    }
    return tmp;
}
//Перегрузка оператора сложения с присваиванием (+=):
Polynom Polynom::operator+=(Polynom obj)
{
    return *this=*this+obj;
}
//Перегрузка оператора вычитания (-):
Polynom Polynom::operator-(Polynom obj)
{
    Polynom tmp(obj.degree);
    for(int i=0; i <= degree; i++)
    {
        tmp.coefficients[i]=coefficients[i]-obj.coefficients[i];
    }
    return tmp;
}
//Перегрузка оператора вычитания с присваиванием (-=):
Polynom Polynom::operator-=(Polynom obj)
{
    return *this=*this-obj;
}
//Перегрузка оператора умножения (*):
Polynom Polynom::operator *(Polynom& obj)
{
    Polynom tmp(degree + obj.degree);
    for(int i=0;i<=degree;i++)
    {
        for(int j=0;j<=obj.degree;j++)
        {
            tmp.coefficients[i+j]+=coefficients[i]*obj.coefficients[j];
        }
    }
    return tmp;
}
//Перегрузка оператора умножения с присваиванием (*=):
Polynom Polynom::operator *=(Polynom& obj)
{
    return *this=*this*obj;
}
//Перегрузка оператора деления (/):
Polynom Polynom::operator /(Polynom& obj)
{
    bool inAlgoritm = true;
    Polynom tmp(degree - obj.degree);
    Polynom ob_1(degree);
    Polynom ob_2(obj.degree);
    Polynom ob_4(ob_1.degree);
    for (int i = degree; i >= 0; i--)
    {
        ob_1.coefficients[i] = coefficients[i];
    }
    for (int i = obj.degree; i >= 0; i--)
    {
        ob_2.coefficients[i] = obj.coefficients[i];
    }
    double mnojnik;
    int k = 0;
    int i, j;
    while (inAlgoritm)
    {
        for (int i = obj.degree; i >= 0; i--)
        {
            ob_4.coefficients[i] = obj.coefficients[i];
        }
        if (ob_2.degree < ob_1.degree)
        {
            for (i = ob_1.degree,j = ob_2.degree; i >= 0; i--, j--)
            {
                if (j < 0)
                {
                    ob_4.coefficients[i] = 0;
                }
                else
                {
                    ob_4.coefficients[i] = ob_2.coefficients[j];
                }
            }
        }
        mnojnik = ob_1.coefficients[ob_1.degree] / ob_4.coefficients[ob_1.degree];
        tmp. coefficients[tmp.degree - k] = mnojnik;
        k++;
        for (int i = 0; i <= ob_1.degree; i++)
        {
            ob_4.coefficients[i] *= mnojnik;
        }
        for (int i = 0; i <= ob_1.degree; i++)
        {
            ob_1.coefficients[i] -= ob_4.coefficients[i];
        }
        ob_1.degree--;
        if (ob_2.degree > ob_1.degree)
        {
            inAlgoritm = false;
        }
    }
    return tmp;
}
//Перегрузка оператора деления с присваиванием (/=):
Polynom Polynom::operator /=(Polynom &obj)
{
    for(int i = 0; i<=degree-obj.degree;i++)
    {
        coefficients.pop_back();
    }
    return *this=*this/obj;
}
