#include <time.h> // ��� ������������� ������� time() � �������� ��������� srand()
#include "stdafx.h"
#include "DoubleArray.h"

#pragma region DoubleArray

//����������� ������ ��� ���������� ������� ���������� �������
DoubleArray::DoubleArray(double min, double max, int n)
{
	srand(time(0));
	count = n;//count - ���������� ����������. ����� ��� �� ������� � ���� ���������� ��������� �������
	mass = new double[n];
	//��������� ������ ���������� ����������
	for (int i = 0; i < n; i++)
	{
		double f = (double)rand() / RAND_MAX;
		mass[i] = min + f * (max - min);
	}
}

//����������� ������ ��� ���������� ������� � ����������
DoubleArray::DoubleArray(int n)
{
	count = n;
	mass = new double[n];
	//��������� ������ � ����������
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> mass[i];
	}
}

DoubleArray::~DoubleArray()
{
	//����������� ������
	delete[] mass;
}

//����� ����� �������
void DoubleArray::PrintMass()
{
	//��������� �� ������� � ������� �� �����
	for (int i = 0; i < count; i++)
	{
		cout << "a[" << i + 1 << "] = " << mass[i] << endl;
	}
}

//����� � ����� ������������� �������� �������
void DoubleArray::PrintMaxElement()
{
	//������ ������� ������� ������������
	double maxElement = mass[0];
	//��������� �� �������(��� �� ������� ��������)
	for (int i = 1; i < count; i++)
	{
		//����������. ���� ������� ������� ������ - ����������
		if (mass[i] > maxElement)
		{
			maxElement = mass[i];
		}
	}
	cout << "Max element massiva = " << maxElement;
}

//������ ��� � ���������� ������. ������ ���� ����������� �������
void DoubleArray::PrintMinElement()
{
	double minElement = mass[0];
	for (int i = 1; i < count; i++)
	{
		if (mass[i] < minElement)
		{
			minElement = mass[i];
		}
	}
	cout << "Min element massiva = " << minElement;
}


//�������� �� ������� 
void DoubleArray::RemoveElementByIndex(int index)
{
	if (index > count - 1 || index < 0)
	{
		cout << "Index not valid!" << endl;
	}
	else{
		for (int j = index; j < count - 1; j++)
		{
			mass[j] = mass[j + 1];
		}
		count = count - 1;
	}
}


//������ �������� ������� �� �������
void DoubleArray::ChangeElementByIndex(double value, int index)
{
	if (index > count - 1 || index < 0)
	{
		cout << "Index not valid!"<< endl;
	}
	else{
		mass[index] = value;
	}
}

//���������� �������� ���������������
double DoubleArray::GetArithmeticMean()
{
	double summElements = 0.0;
	double arithmeticMean = 0.0;
	for (int i = 0; i < count; i++)
	{
		summElements += mass[i];
	}
	arithmeticMean = summElements / count;
	return arithmeticMean;
}

#pragma endregion