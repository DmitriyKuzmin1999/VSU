/* 15. Дана матрица, содержащая как положительные, так и отрицательные элементы.
   Удалить все ее столбцы, содержащие только положительные элементы. */
// Кузьмин Дмитрий 91 г.

#include "pch.h"
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;





int InputSize(const char *txt, int min, int max)
{
	int ArrSize;
	cout << txt << endl; //вывод вопроса на экран
	cin >> ArrSize;
	while ((ArrSize < min) || (ArrSize > max)) //пока число num не попадает в диапозон [min..max] 
	{
		cout << "Недопустимое значение, введите еще раз:" << endl;
		cin >> ArrSize;
	}
	return ArrSize;
}

int SelectMenuItem(void)
{
	cout << "Выберите один из пунктов меню:" << endl;
	cout << "1 - ввод матрицы" << endl;
	cout << "2 - результирующая матрица" << endl;
	return InputSize("0 - выйти из программы", 0, 3);
}

int SelectSubMenuItem(void)
{
	cout << "1 - Ввод матрицы из консоли" << endl;
	cout << "2 - Ввод матрицы из файла" << endl;
	return InputSize("0 - вернуться назад", 0, 2);
}


int** CreateMatr(int n, int m)
{
	int **A; //создаём матрицу введённой размерности
	A = new int *[n]; //через массив указателей
	for (int i = 0; i < n; i++) {
		A[i] = new int[m];
	}
	return A;
}

void InputMatrSizeFile(ifstream &in, int* n, int* m)
{
	if (in.is_open())
	{
		in >> *n;
		in >> *m;
	}
}

void InputMatrFile(int** A, ifstream &in, int n, int m)
{
	if (in.is_open())
	{
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				in >> A[i][j];

	}
}

void InputMatr(int** A, int n, int m)//ф-ция заполнения матрицы через консоль
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> A[i][j];
		}
	}
}

void OutputMatrFile(int** A, int n, int m)
{
	ofstream fout;
	fout.open("C:\\Users\\Кузя\\Desktop\\Output.txt");
	if (fout.is_open())
	{

		fout << n << endl << m << endl;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				fout << setw(3) << A[i][j] << "   ";
			}
			fout << endl;
		}
	}
	fout.close();
}

void OutputMatr(int** A, int n, int m)//ф-ция вывода матрицы в консоль
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << setw(3) << A[i][j] << "   ";
		}
		cout << endl;
	}
	cout << endl;
}

void Task(int** A, int n, int m)
{
	bool *ResMas = new bool[0];
	ResMas = new bool[m];
	int **matrOut = new int*[0];
	int om = 0;
	bool OK;
	for (int j = 0; j < m; j++)
	{
		OK = true;
		int i = 0;
		while (OK && (i < n))
		{
				if (A[i][j] <= 0) OK = false;
				i++;
				
		}
		if (!OK) {
			ResMas[j] = false;
			om++;
		}
		else {
			ResMas[j] = true;
		}
		
	}
	matrOut=CreateMatr(n, om);
	cout << endl << endl;
	int jo = 0;
	for(int z = 0; z < m; z++)
	{
		if (!ResMas[z])
		{
			for (int i = 0; i < n; i++)
			{
				matrOut[i][jo] = A[i][z];
			}
			jo++;
		}
	}
	OutputMatr(matrOut, n, om);
	OutputMatrFile(matrOut, n, om);
	delete[]matrOut;
	
}

int main()
{
	setlocale(LC_ALL, "Russian");//Подключаем русский язык
	ifstream fin;
	fin.open("C:\\Users\\Кузя\\Desktop\\Input.txt");
	int **matrIn = new int*[0];
	int **matrOut = new int*[0];
	int NSizeIn;
	int MSizeIn;
	int MenuItem = -1;
	int PodMenu;
	while (MenuItem != 0)
	{
		MenuItem = SelectMenuItem();
		switch (MenuItem)
		{
		case 1: PodMenu = SelectSubMenuItem();
			switch (PodMenu)
			{
			case 1: delete[]matrIn;
				NSizeIn = InputSize("Введите количество строк", 0, 10);
				MSizeIn = InputSize("Введите количество столбцов", 0, 10);
				matrIn = CreateMatr(NSizeIn, MSizeIn);
				cout << "Введите " << (NSizeIn * MSizeIn) << " элементов: " << endl;
				InputMatr(matrIn, NSizeIn, MSizeIn);
				cout << endl << "Введённая матрица:" << endl << endl;
				OutputMatr(matrIn, NSizeIn, MSizeIn);
				break;
			case 2: delete[]matrIn;
				InputMatrSizeFile(fin, &NSizeIn, &MSizeIn);
				matrIn = CreateMatr(NSizeIn, MSizeIn);
				InputMatrFile(matrIn, fin, NSizeIn, MSizeIn);
				cout << endl << "Введённая матрица:" << endl << endl;
				OutputMatr(matrIn, NSizeIn, MSizeIn);
				break;
			}
			break;
			case 2:
				Task(matrIn, NSizeIn, MSizeIn);
				
		}
	}
	delete[]matrIn;
	fin.close();
	return 0;
}
