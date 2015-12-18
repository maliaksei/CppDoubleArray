#include <time.h> // для использования функции time() в качестве параметра srand()
#include "stdafx.h"
#include "DoubleArray.h"

#pragma region DoubleArray

//Конструктор класса для заполнения массива случайными числами
DoubleArray::DoubleArray(double min, double max, int n)
{
	srand(time(0));
	count = n;//count - глобальная переменная. Нужна что бы хранить в себе количество элементов массива
	mass = new double[n];
	//заполняем массив случайными значениями
	for (int i = 0; i < n; i++)
	{
		double f = (double)rand() / RAND_MAX;
		mass[i] = min + f * (max - min);
	}
}

//Конструктор класса для заполнения массива с клавиатуры
DoubleArray::DoubleArray(int n)
{
	count = n;
	mass = new double[n];
	//заполняем массив с клавиатуры
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i + 1 << "] = ";
		cin >> mass[i];
	}
}

DoubleArray::~DoubleArray()
{
	//освобождаем память
	delete[] mass;
}

//Вывод всего массива
void DoubleArray::PrintMass()
{
	//пробегаем по массиву и выводим на экран
	for (int i = 0; i < count; i++)
	{
		cout << "a[" << i + 1 << "] = " << mass[i] << endl;
	}
}

//поиск и вывод максимального элемента массива
void DoubleArray::PrintMaxElement()
{
	//Первый элемент считаем максимальным
	double maxElement = mass[0];
	//пробегаем по массиву(уже со второго элемента)
	for (int i = 1; i < count; i++)
	{
		//сравниваем. Еслм элемент массива больше - запоминаем
		if (mass[i] > maxElement)
		{
			maxElement = mass[i];
		}
	}
	cout << "Max element massiva = " << maxElement;
}

//Логика как в предыдущем методе. Только ищем минимальный элемент
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


//удаление из массива 
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


//замена элемента массива по индексу
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

//вычисление среднего арифметического
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