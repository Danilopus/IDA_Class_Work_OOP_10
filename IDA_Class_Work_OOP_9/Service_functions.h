//#pragma once
#ifndef _Service_functions_h_
#define _Service_functions_h_
#include <iostream>
#include <string>
#include <windows.h>
#include <time.h>
#include <algorithm>


// Service functions prototypes ------------------------------------
int Get_Int_SA();			// String-analysis ������� ������� INTEGER
int Get_Int_Positive();		// String-Analysis ������� �������� ����� INTEGER_POSITIVE		
int Get_Int_PG();			// peek&get ������� �������� ����� INTEGER	
double Get_Dbl_SA();		// String-analysis ������� ������� DOUBLE.
double Get_Dbl_Positive();	// String-analysis ������� ������� DOUBLE_POSITIVE
double Get_Dbl_PG();		// peek&get ������� �������� ����� DOUBLE	
int Get_Random(int Range_min, int Range_max);
double Get_Random(double Range_min, double Range_max);
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max);
template <typename ANY> void Array_Console_Out(ANY arr[], int Size);


// Service functions templated definition-----------------------------
template <typename ANY> void Array_Console_Out(ANY arr[], int Size)
{
	std::cout << "\n[";
	for (int i = 0; i < Size; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b]\n";
}
template <typename ANY> void Fill_Array_with_Random(ANY arr[], int Size, ANY Range_min, ANY Range_max)
{
	for (int i = 0; i < Size; i++)
	{
		arr[i] = Get_Random(Range_min, Range_max);
	}
}


#endif