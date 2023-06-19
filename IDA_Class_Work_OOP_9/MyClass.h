#pragma once

#include <iostream>
#include <vector>

class MyClass
{
public: 
	explicit MyClass(int a)
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
		for (size_t i = 0; i < data.size(); i++)
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

class Integer
{
public:
	int units;
	//префиксная форма ++variable
	Integer operator ++()
	{
		units = +1;
		return *this;
	}
	Integer operator --()
	{
		units = +1;
		return *this;
	}
	//постфиксная форма variable--

	Integer operator --(int)
	{
		Integer result;
		result.units = units;
		units = -1;
		return result;
	}
	Integer operator ++(int)
	{
		Integer result;
		result.units = units;
		units = +1;
		return result;
	}

};

