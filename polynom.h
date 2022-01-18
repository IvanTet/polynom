#ifndef POLYNOM_H
#define POLYNOM_H
#include <vector>

using namespace std;

class Polynom
{
public:
    Polynom();

    //Коэффициенты полинома:
    vector<int>coefficients;

    //Степень полинома:
    int degree = 0;

    //Конструктор класса:
    Polynom(int count);

    //Перегрузка оператора "квадратные скобки" ([]):
    int operator[](int position);

    //Перегрузка оператора "скобки" (()):
    int operator ()(int var);

    //Перегрузка оператора сложения (+):
    Polynom operator+(Polynom obj);

    //Перегрузка оператора сложения с присваиванием (+=):
    Polynom operator+=(Polynom obj);

    //Перегрузка оператора вычитания (-):
    Polynom operator-(Polynom obj);

    //Перегрузка оператора вычитания с присваиванием (-=):
    Polynom operator-=(Polynom obj);

    //Перегрузка оператора умножения (*):
    Polynom operator *(Polynom& obj);

    //Перегрузка оператора умножения с присваиванием (*=):
    Polynom operator *=(Polynom& obj);

    //Перегрузка оператора деления (/):
    Polynom operator /(Polynom& obj);

    //Перегрузка оператора деления с присваиванием (/=):
    Polynom operator /=(Polynom &obj);
};

#endif // POLYNOM_H
