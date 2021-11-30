#include <iostream>
#include <cmath>

using namespace std;


float getX()
{
	float x;
	while (true)
	{
		cout << "Введите X: ";
		cin >> x;
		if (abs(x) <= 1) break;
		cout << "X должен принадлежать отрезуку [-1;1]. Попробуйте свова." << endl;
	}
	return x;
}

int getN()
{
	int n;
	while (true)
	{
		cout << "Введите N: ";
		cin >> n;
		if (n >= 0) break;
		cout << "N должен быть положительным. Попробуйте свова." << endl;
	}
	return n;
}

float getE()
{
	float e;
	while (true)
	{
		cout << "Введите E: ";
		cin >> e;
		if (e >= 0) break;
		cout << "E должен быть положительным. Попробуйте свова." << endl;
	}
	return e;
}

void calculationSum(float e, float x, int &n, float &sum, float &lastElement)
{
	float pastSum = 0, preLastElement = 0;
	int fac1 = 1, fac2 = 1, nOne = -1, i = 0, j = 0, k = n;

	lastElement = 0;
	n++;

	while (i <= k || e != 0)
	{
		if (i > 0)
		{
			fac1 *= i;
			fac2 *= ++j * ++j;
		}


		preLastElement = pow(nOne, i - 1) * fac2 / ((2 * i - 1) * fac1 * fac1 * pow(4, i++));
		if (e != 0 and abs(preLastElement) <= e) break;
		else n++;

		lastElement = preLastElement;
		sum += lastElement;
	}
}

float calculationError(float sum, float x)
{
	return abs(sum - sqrt(1 + x));
}

char compare(float a, float b)
{
	float e = 0.001;
	if (b - a > e) return 60;
	else if (a - b > e) return 62;
	else return 61;
}

void firstInputAndOutput()
{
	float x, sum = 0, lastElement;
	int n;

	x = getX();
	n = getN();

	calculationSum(0, x, n, sum, lastElement);

	cout << "Частичная сумма ряда равна: " << sum << endl;
	cout << "Aбсолютная погрешность полученного результата равна: " << calculationError(sum, x) << endl;
	cout << "Aбсолютная погрешность " << compare(calculationError(sum, x), abs(lastElement)) << " " << abs(lastElement) << " (обсалютная величина последниго элемента, включенного в частичную сумму ряда)" << endl;
}

void secondInputAndOutput()
{
	float x, e, sum = 0, lastElement;
	int n = 0;

	x = getX();
	e = getE();

	calculationSum(e, x, n, sum, lastElement);

	cout << "Сумма всех элементов ряда, больших чем Е, равна: " << sum << endl;
	cout << "Количество все элементов ряда, больших чем Е, равна: " << n << endl;

	calculationSum(e / 10, x, n, sum, lastElement);

	cout << "Сумма всех элементов ряда, больших чем Е/10, равна: " << sum << endl;
	cout << "Количество все элементов ряда, больших чем Е/10, равна: " << n << endl;
}

void menu()
{
	while (true)
	{
		float check;
		cout << "Хотите произвести расчет? (произвести расчет для первого задания: 1, произвести расчет для второго задания: 2, непроизводить расчет: 0) ";
		cin >> check;

		if (check == 0) break;
		else if (check == 1) firstInputAndOutput();
		else if (check == 2) secondInputAndOutput();
		else
		{
			cout << "Введено не коректное значение, попробуйте снова" << endl;
		}
	}
}


int main()
{
	setlocale(0, "");
	menu();
}