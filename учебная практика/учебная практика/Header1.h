﻿#ifndef ADD_H
#define ADD_H
#define _CRT_SECURE_NO_DEPRECATE
#pragma warning(disable : 4996)
#include <iostream>
#include <math.h>
#include <cmath>
using namespace std;
double f(double x)
{
    return  3 * pow(x, 4) + 4 * pow(x, 3) - 12 * pow(x, 2) - 5;//функция
}
double df(double x)
{
    return 12 * pow(x, 3) + 12 * pow(x, 2) - 24 * x;//производная
}

double dixit(double a, double b, double eps)// метод дихотомии,фунция f(x)=0 непрерывна 
// на отрезке [a;b] и f(a)*f(b)<0.
{
    double c;
    do {
        c = (a + b) / 2.0;//находим точку c=(a+b)/2
        if (f(a) * f(c) < 0)   b = c;//если это условие выполнено,то корень лежит на [a;c]
        else if (f(b) * f(c) < 0)   a = c;//иначе корень лежит на [c;b]
        else {
            cout << "Корень не найден" << endl;//если оба условия не выполняются,то корня нет на данном промежутке
            return 0;
        }
    } while (fabs(b - a) > eps);//пока значение в функции в точке b-a больше заданной точности,
    //выполняем алгоритм нахождения с,описанный сверху
    return c;//возвращаем значение с после выполнения цикла

}
double Hord(double a, double b, double eps)//метод хорд
//разбиение отрезка [a; b] на два отрезка с помощью хорды и выборе нового отрезка от точки
//пересечения хорды с осью абсцисс до неподвижной точки, на котором
//функция меняет знак и содержит решение, причём подвижная точка
//приближается к ε - окрестности решения.
{
    while (fabs(b - a) > eps)//пока значение в функции в точке b-a больше заданной точности,
      //выполняем алгоритм,описанный ниже
    {
        a = b - (b - a) * f(b) / (f(b) - f(a));//расчет нового значения а по формуле
        b = a - (a - b) * f(a) / (f(a) - f(b));//расчет нового значения b по формуле
    }

    return b;//возвращаем b после выполнения цикла
}
double Newton(double x, double& n, double eps)//метод Ньютона
//процесс итераций состоит в том, что в качестве
//приближений к корню принимаются значения х0, х1, х2… точек пересечения
//касательной к кривой
{
    double dx;
    n = 0;
    while (1) {
        dx = f(x) / df(x);//дельта равна отношению функции к ее производной
        x = x - dx;// 
            if (fabs(dx) < eps)//если модуль производной меньше заданной точности,то останавливаем выполнение цикла
            break;
        n++;
        if (n > 100)//не более 100 итераций,иначе останавливаем работу цикла
            break;
    }
    return x;
}
double g(double x) 
{ 
    return x - 1.0 / df(x) * f(x); //сжимающее отображение
}
double Iter(double x, double b, int n, double eps)//Суть метода простых итераций состоит в расчётах новой точки x по старой точке.
//Итерации продолжаются до достижения необходимой точности решения ε.
{
    double	dx;
  
    n = 0;
    while (1) { 
        dx = g(x) - x;//дельта	
        x = g(x);	//присваиваем иксу отображение
        if (fabs(dx) < eps)
            break;
        if (n > 100)
            break;
    } return x;
}
void print_menu() {
    system("cls");  // очищаем экран
    printf("Калькулятор нелинейных уравнений\n");
    printf("Выберите способ решения нелинейного уравнения\n");
    printf("1. Метод дихотомии\n");
    printf("2. Метод хорд\n");
    printf("3. Метод Ньютона\n");
    printf("4. Метод простых итераций\n");
    printf("5. Выход\n");
    printf(">");
}

int get_variant(int count) {//выбор способа решения уравнения
    int variant;
    char s[100]; // строка для считывания введённых данных
    scanf("%s", s); // считываем строку

    // пока ввод некорректен, сообщаем об этом и просим повторить его
    while (sscanf(s, "%d", &variant) != 1 || variant < 1 || variant > count) {
        printf("Неправильный ввод. Попробуйте еще: "); // выводим сообщение об ошибке
        scanf("%s", s); // считываем строку повторно
    }

    return variant;
}
#endif