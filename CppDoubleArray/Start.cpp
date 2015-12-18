// CppDoubleArray.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "DoubleArray.h"
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	cout << "Task 1" << endl;
	DoubleArray *doubleArray = new DoubleArray(-50.2, 50.0, 4);//при помощи ГСЧ
	//DoubleArray *doubleArray = new DoubleArray(4);//Ввод с клавиатуры
	doubleArray->PrintMass();
	cout << endl;
	doubleArray->PrintMaxElement();
	cout << endl;
	doubleArray->PrintMinElement();
	cout << endl;
	cout << endl;
	
	double arithmeticMean = doubleArray->GetArithmeticMean();
	cout << "Srednee arifmeticheskoe = " << arithmeticMean << endl;
	cout << endl;

	doubleArray->RemoveElementByIndex(1);
	cout << "RemoveElementOfArray:" << endl;
	doubleArray->PrintMass();
	cout << endl;

	doubleArray->ChangeElementByIndex(9.9999, 2);
	cout << "ChangeElementByIndex:" << endl;
	doubleArray->PrintMass();

	doubleArray->~DoubleArray();
	return 0;
}

