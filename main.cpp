/**
* Яковлев Денис Михайлович (С)
* Создание класса "комплексное число"
* Дано: класс "комплексных чисел"
* Задача: осуществить все операции "комплексных чисел" с помощью класса
*/


#include <iostream>
#include<cmath>
#include<algorithm>
#include<sstream>
#include<string>
#include"Complex_Test.h"
#include "triangle.h"
using namespace std;

int main()
{

    test_getValue();
    test_unarOperator();
    test_assignment();
    test_binOperator();
    test_inoutOperator();

    return 0;
}
