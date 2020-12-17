// Lab_06_4_2.cpp
// < Сорочак Станіслав >
// Лабораторна робота №6.4.2
// Опрацювання та впорядкування одновимірних динамічних масивів
// Варіант 24

#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>

using namespace std;

void value_elements(double* a, const int size, double Low, int High, int index, int diapazon)
{
	a[index] = Low * (rand() % (2 * High)) - diapazon;
	if (index < size - 1)
		value_elements(a, size, Low, High, index + 1, diapazon);
	else;
}
double Sum(double* a, const int size, int index, double S, int k_index)
{
	if (a[index] > 0)
	{
		for (; a[k_index] < 0; k_index--);
		for (index++; index < k_index; index++)
			S += a[index];
		index = size;
	}
	else;
	if (index < size - 1)
		return Sum(a, size, index + 1, S, k_index);
	else
		return S;
}

double Min(double* a, const int size, int index, double min)
{
	if (a[index] < min)
		min = a[index];
	if (index < size - 1)
		return Min(a, size, index + 1, min);
	else
		return min;
}

void pokazaty(double* a, const int size, int index)
{
	cout << setprecision(2) << setw(6) << a[index];
	if (index < size - 1)
		pokazaty(a, size, index + 1);
	else;
}

void pertvorennya(double* a, const int size, int index, int pp_index, double p_index, double value)
{
	value = a[index];
	if ((0 <= value && value < 1) || (-1 < value && value <= 0))
	{
		p_index = a[pp_index];
		a[pp_index] = a[index];
		a[index] = p_index;
		pp_index++;
	}
	else;
	if (index < size - 1)
		pertvorennya(a, size, index + 1, pp_index, p_index, value);
	else;
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
	int k_size;
	cout << "Ваша кількість елементів = ";
	cin >> k_size;
	cout << endl;
	const int size = k_size;
	double* a = new double[size];

	double Low = 0.01;
	int High = 200;
	int diapazon = 2;

	value_elements(a, size, Low, High, 0, diapazon);

	cout << "масив: " << endl;
	cout << endl;
	pokazaty(a, size, 0);

	cout << endl;
	cout << "мінімальний елемент = " << Min(a, size, 1, a[0]) << endl;

	double S = Sum(a, size, 0, 0, size - 1);
	if (Sum == 0)
		cout << "не існує елемнтів за умовою: " << endl;
	else
		cout << "Сума елементів масиву, за умовою: " << S << endl;

	cout << "перестановка: " << endl;
	cout << endl;
	pertvorennya(a, size, 0, 0, 0, 0);
	pokazaty(a, size, 0);

	delete[] a;
	return 0;
}

