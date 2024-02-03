// Pract4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <stdio.h>

class Fraction
{
    public:
    
    double numerator;
    double denominator;

    static double Multiply(Fraction a, Fraction b)
    {
        double result = (a.numerator/a.denominator) * (b.numerator/b.denominator);
        return result;
    }

    static double Divide(Fraction a, Fraction b)
    {
        double result = (a.numerator / a.denominator) / (b.numerator / b.denominator);
        return result;
    }
};

int main()
{
    setlocale(LC_ALL, "Rus");
    FILE* file;

    Fraction firstNum, secondNum;
    std::cout << "Введите числитель первой дроби\n";
    std::cin >> firstNum.numerator;

    do
    {
    std::cout << "Введите знаменатель первой дроби\n";
    std::cin >> firstNum.denominator;
    } while (firstNum.denominator == 0);

    std::cout << "Введите числитель второй дроби\n";
    std::cin >> secondNum.numerator;

    do
    {
        std::cout << "Введите знаменатель второй дроби\n";
        std::cin >> secondNum.denominator;
    } while (secondNum.denominator == 0);


    if (fopen_s(&file, "1.txt", "w") != 0)
        std::cout <<"Файл невозможно открыть или создать"<< std::endl;
    else
    {
        double multi = Fraction::Multiply(firstNum, secondNum);
        fprintf(file, "%f/%f * %f/%f%=%f\n", firstNum.numerator,firstNum.denominator, secondNum.numerator, secondNum.denominator, multi);

        if (secondNum.numerator==0)
            fprintf(file, "%f%/%f / %f/%f= ДЕЛЕНИЕ НА НОЛЬ!!!\n", firstNum.numerator, firstNum.denominator, secondNum.numerator, secondNum.denominator);
        else
        {
            double divide = Fraction::Divide(firstNum, secondNum);
            fprintf(file, "%f/%f / %f/%f=%f\n", firstNum.numerator, firstNum.denominator, secondNum.numerator, secondNum.denominator, divide);
        }
    }
    fclose(file);


    return 0;
}
