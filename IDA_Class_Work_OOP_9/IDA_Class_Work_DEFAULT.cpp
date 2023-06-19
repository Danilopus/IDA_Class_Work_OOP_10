#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>
#include "Service_functions.h"
#include "MyClass.h"
#include "Fraction.h"
//#include <array>

/*
class MyClass
{
public:
	MyClass(int a)
	{
		if (a >= 0)
		{
			data.reserve(a);
			this->intit();
		}
	}
	// const obj - создание конст объекта чтобы ничего в нем не менять
	// const в методе - чтобы не вносить изменения в операнды и вообще нигде
	int operator + (const MyClass obj) const
	{
		int result{};
		for (size_t i = 0; i < obj.data.size(); i++)
		{
			result += obj.data[i];
		}
		for (size_t i = 0; i < obj.data.size(); i++)
		{
			result += this->data[i];
		}
		return result;
	}



private:
	std::vector <int> data;
	void intit()
	{
		for (size_t i = 0; i < data.capacity(); i++)
		{
			data.push_back(i + 1);
		}
	}
};
*/

// Class Work 19.06.2023 -------------------------------------------

// Новый преподаватель:
// Владислав Цыбарт

// срез знаний:
// 
// 1 - идиомы ООП: инкапсуляция / наследование / полиморфизм

// 2 - состав классов

// 3 - модификаторы доступа

// 4 - типы конструкторов


//Task 1 EXPLICIT
void Task_1()
{
	//explicit - для исключения неявных преобразований, которые могут быть неожиданными для пользователя
	
	MyClass a(5);
	//MyClass a(1e3);
	MyClass b(7);
	std::cout <<"a+b " << a + b;
	//std::cout << "\na+7 " << a + 7;

}
//Task 2 Перегрузка унарных операторов
void Task_2()
{
	int num = 9;
	std::cout << num++;
	std::cout << ++num;

	//Integer num2 = 9;
	
	//Integer num2.units = 9;
	Integer num2;
	num2.units = 9;

	num2++;

	Integer num3(num2++++++);

	Integer num4(--num2);
}

void Task_3() // Перегрузка унарных операторов
{
//Вариант хранения объектов класса Fraction в векторе объектов вне класса (из точки вызова, с передачей указателя на этот вектор)
std::vector <Fraction*> Available_fractions;
//static std::vector<Fraction*> Available_fractions;
//Fraction fraction_1(5, 7, Available_fractions), fraction_2(7,19, Available_fractions);
Fraction fraction_1 = *new Fraction(5, 7, Available_fractions);
Fraction fraction_2 = *new Fraction(7, 19, Available_fractions);

do
{
	system("cls");
	std::cout << "***\tFraction class demo\n";
	fraction_1.ShowAvailableFractions(Available_fractions);
	std::cout << "\n";
	fraction_1.ShowMethods();
	std::cout << "choose a method: ";
	int action = Get_Int_Positive();

	//fraction_1.ShowAvailableFractions();
	//fraction_1.ShowAvailableFractions(Available_fractions);

	std::cout << "\nchoose operands:";
	std::cout << "\nchoose fraction 1: ";
	int fraction_index_1 = Get_Int_Positive();
	std::cout << "choose fraction 2: ";
	int fraction_index_2 = Get_Int_Positive();

	fraction_index_1--;
	fraction_index_2--;

	Fraction Operand_1 = *Available_fractions[fraction_index_1];
	Fraction Operand_2 = *Available_fractions[fraction_index_2];




	//переработанный блок операций с использованием перегрузки арифметических операторов
	switch (action)
	{
		//case 1: Available_fractions[fraction_index_1]->Add(*Available_fractions[fraction_index_2], Available_fractions); break;
		//case 1: Available_fractions.push_back(result_fraction); break;
	case 1: Available_fractions.push_back(Operand_1 + Operand_2); break;
		//case 2: Available_fractions[fraction_index_1]->Subtract(*Available_fractions[fraction_index_2], Available_fractions); break;
	case 2: Available_fractions.push_back(Operand_1 - Operand_2); break;
		//case 3: Available_fractions[fraction_index_1]->Multiply(*Available_fractions[fraction_index_2], Available_fractions); break;
	case 3: Available_fractions.push_back(Operand_1 * Operand_2); break;
		//case 4: Available_fractions[fraction_index_1]->Divide(*Available_fractions[fraction_index_2], Available_fractions); break;
	case 4: Available_fractions.push_back(Operand_1 / Operand_2); break;
	}
	std::cout << "\nresult - > ";
	Available_fractions[Available_fractions.size() - 1]->ShowValues();

	std::cout << "\n\nEsc - for exit, any key to continue";
} while (_getch() != 27);
Fraction::Memory_Clean(Available_fractions);
//сам вектор std::vector<Fraction*> Available_fractions вроде должен быть уничтожен автоматически, т.к. находится в стэке (мне так кажется)
}

// MAIN ------- MAIN ------- MAIN ------- MAIN ------- MAIN --------
int main()
{
srand(time(NULL));
		
Task_1();
Task_2();
Task_3();





std::cout << "\n\n";
system("pause");	
}

