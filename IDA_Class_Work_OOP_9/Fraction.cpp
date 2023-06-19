#include "Fraction.h"

//::::::::::::::::::::::::::::::Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction:: Fraction::::::::::::::::::::::::::::::
int Fraction::MaxCommonDivider(int a, int b)
{
	while (a > 0 && b > 0)
	{
		if (a > b)	a %= b;
		else		b %= a;
	}
	return a + b;
}
void Fraction::Fraction_reduction()
{
	int max_common_divider = MaxCommonDivider(abs(Get_numerator()), abs(Get_denominator()));
	Set_numerator(Get_numerator() / max_common_divider);
	Set_denominator(Get_denominator() / max_common_divider);
}
Fraction::Fraction(int A1, int A2, std::vector<Fraction*>& Available_fractions) : _numerator(A1), _denominator(A2)
{
	Available_fractions.push_back(this);
	Fraction_reduction();
}
int Fraction::ShowMethods()
{
	std::cout << "\nAvailable methods:";
	//std::cout << "\n1) Add\n2) Substract\n3) Multiply\n4) Divide\n";
	std::cout << "\n1) Add\t2) Substract\t3) Multiply\t4) Divide\n";
	//return Get_Int_Positive();
	return 0;
}
void Fraction::ShowAvailableFractions(std::vector<Fraction*> Available_fractions)
{
	std::cout << "\nAvailable fractions:";
	for (int i = 0; i < Available_fractions.size(); i++)
	{
		std::cout << "\nFraction [" << i + 1 << "] -> " << Available_fractions[i]->Get_numerator() << " / " << Available_fractions[i]->Get_denominator();
	}
}
void Fraction::Memory_Clean(const std::vector<Fraction*>& Available_fractions)
{
	for (int i = 0; i < Available_fractions.size(); i++)
		delete Available_fractions[i];
}
Fraction* Fraction::operator+(const Fraction& another_Fraction) {
	std::cout << "\n" << "var2 Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::
//Q4 ??? при объявлении Fraction* operator+(Fraction& another_Fraction) в .h все было нормально, при переносе в .cpp вдруг давай ругаться ???
//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::

/*
Fraction* operator+(Fraction& another_Fraction)
{
	std::cout << "\n" << "var3 Using member-function & overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) + (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//*/
Fraction* Fraction::Add(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)

{
	int new_numerator = _numerator * another_Fraction.Get_denominator() + another_Fraction.Get_numerator() * _denominator;
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
	return result_fraction;
}
Fraction* Fraction::Subtract(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_denominator() - another_Fraction.Get_numerator() * _denominator;
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов

	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator() - another_Fraction.Get_numerator() * _denominator);
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::Multiply(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_numerator();
	int new_denominator = _denominator * another_Fraction.Get_denominator();
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов

	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_numerator());
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_denominator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::Divide(Fraction& another_Fraction, std::vector<Fraction*>& Available_fractions)
{
	int new_numerator = _numerator * another_Fraction.Get_denominator();
	int new_denominator = _denominator * another_Fraction.Get_numerator();
	//убираем знак из знаменателя
	if (new_denominator < 0) { new_denominator = -1 * new_denominator; new_numerator = -1 * new_numerator; }
	//вариант с сокращением дроби в момент создания через вызов Fraction_reduction в конструкторе
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator, Available_fractions); // вариант с внешним вектором для хранения объектов
	//Fraction* result_fraction = new Fraction(Available_fractions); // вариант с внешним вектором для хранения объектов
	//result_fraction->Set_numerator(_numerator * another_Fraction.Get_denominator());
	//result_fraction->Set_denominator(_denominator * another_Fraction.Get_numerator());
	//Fraction_reduction();
	return result_fraction;
}
Fraction* Fraction::operator-(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator) - (another_Fraction._numerator) * (this->_denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator*(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._numerator);
	int new_denominator = (this->_denominator) * (another_Fraction._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
Fraction* Fraction::operator/(const Fraction& another_Fraction)
{
	std::cout << "\n" << "Using member-function const& overload parameter, pointer return" << "\n";
	int new_numerator = (this->_numerator) * (another_Fraction._denominator);
	int new_denominator = (this->_denominator) * (another_Fraction._numerator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}
//??? как правильно объявить friend
//Fraction* Fraction::operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2)
Fraction* operator+(const Fraction& Fraction_Operand_1, const Fraction& Fraction_Operand_2)
{
	std::cout << "\n" << "var1 Using friend-function const& overload parameter, return pointer" << "\n";
	int new_numerator = (Fraction_Operand_1._numerator) * (Fraction_Operand_2._denominator) + (Fraction_Operand_2._numerator) * (Fraction_Operand_1._denominator);
	int new_denominator = (Fraction_Operand_1._denominator) * (Fraction_Operand_2._denominator);
	Fraction* result_fraction = new Fraction(new_numerator, new_denominator);
	return result_fraction;
}