/*15. Создать класс Angle для работы с углами на плоскости, задаваемыми величиной в
градусах и минутах. Обязательно должны быть реализованы: перевод в радианы,
приведение к диапазону 0-360, увеличение и уменьшение угла на заданную величину,
получение синуса, сравнение углов*/
//Кузьмин Дмитрий, 91г.

#include "pch.h"
#include <iostream>
#include <math.h>
#include <conio.h>
#define M_PI       3.14159
#include <string>

using namespace std;

class Angle
{
private:
	int _gradusy, _minute;

public:



	void Init()
	{
		_gradusy = 0;
		_minute = 0;
	}

	int getGradusy() { return _gradusy; }
	int getMinute() { return _minute; }
	void setGradusy(int gradus) { _gradusy = gradus; }
	void setMinute(int min) { _minute = min; }

	void removeRoughs()
	{
		_minute += _gradusy * 60;
		_gradusy = _minute / 60;
		_minute = _minute % 60;
	}

	void setAngle()
	{
		int x;
		cout << "Градусов = ";
		cin >> x;
		setGradusy(x);
		cout << "Минут = ";
		cin >> x;
		setMinute(x);
		this->removeRoughs();
	}

	void increaseAngle(Angle a)
	{
		_gradusy += a.getGradusy();
		_minute += a.getMinute();
		this->removeRoughs();
	}

	void decreaseAngle(Angle a)
	{
		_gradusy -= a.getGradusy();
		_minute -= a.getMinute();
		this->removeRoughs();
	}

	double getRadians() const
	{
		return (_gradusy + _minute / 60.)*M_PI / 180.;
	}

	void DisplayRad() const
	{
		cout << "\nЗначение угла: " << "\nРадиан = " << this ->getRadians() << "\n\n";
	}

	void intoRange()
	{
		if (_minute < 0)
		{
			_gradusy--;
			_minute += 60;
		}
		if (_gradusy > 0)_gradusy = _gradusy % 360;
		else _gradusy = _gradusy % 360 + 360;
	}

	double sinA() const
	{
		return sin(this->getRadians());
	}

	void Display() const
	{
		cout << "\nЗначение угла: " << "\nГрадусов = " << _gradusy << "\nМинут = " << _minute << "\n\n";
	}

	/*friend int angleCmp(Angle &a1, Angle &a2)
	{
		int m1 = a1.getMinute() + a1.getGradusy() * 60;
		int m2 = a2.getMinute() + a2.getGradusy() * 60;
		if (m1 < m2) return -1;
		else if (m1 > m2) return 1;
		else return 0;
	}*/

	Angle operator+(Angle N);
	Angle operator-(Angle N);
	bool operator>(Angle N);
	bool operator<(Angle N);
	bool operator==(Angle N);
};

Angle Angle::operator+(Angle N)
{
	Angle R;
	R.Init();
	R._gradusy = _gradusy + N._gradusy;
	R._minute = _minute + N._minute;
	R.removeRoughs();
	return R;
}

Angle Angle::operator-(Angle N)
{
	Angle R;
	R.Init();
	R._gradusy = _gradusy - N._gradusy;
	R._minute = _minute - N._minute;
	if ((R._gradusy < 0) or (R._minute < 0))
		R.intoRange();
	return R;
}

bool Angle::operator>(Angle N) 
{
	if (_gradusy > N._gradusy) return true;
	else
		if ((_gradusy == N._gradusy) && (_minute > N._minute)) return true;
	return false;
}

bool Angle::operator<(Angle N)
{
	if (_gradusy > N._gradusy) return false;
	else
		if ((_gradusy == N._gradusy) && (_minute > N._minute)) return false;
	return true;
}

bool Angle::operator==(Angle N)
{
	if ((_gradusy == N._gradusy) && (_minute == N._minute)) return true;
	return false;
}

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
	cout << "1 - Ввести угол" << endl;
	return InputSize("0 - выйти из программы", 0, 1);
}

int SelectSubMenuItem(void)
{
	cout << "1 - Задать новый угол" << endl;
	cout << "2 - Вывести угол на экран" << endl;
	cout << "3 - Приведение к диапазону 0-360" << endl;
	cout << "4 - Увеличение угла на заданную величину" << endl;
	cout << "5 - Уменьшение угла на заданную величину" << endl;
	cout << "6 - Вывести радианы угла на экран" << endl;
	cout << "7 - Вывести синус угла на экран" << endl;
	cout << "8 - Сложить данный угол с другим углом" << endl;
	cout << "9 - Вычесть из данного угла другой угол" << endl;
	cout << "10 - Сравнение углов" << endl;
	return InputSize("0 - вернуться назад", 0, 10);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int MenuItem = -1;
	int PodMenu;
	while (MenuItem != 0)
	{
		MenuItem = SelectMenuItem();
		switch (MenuItem)
		{
		case 1: Angle d1;
				d1.Init();
				cout << "Введите значения для первого угла\n";
				d1.setAngle();
				d1.Display();
				PodMenu = SelectSubMenuItem();
				while (PodMenu != 0)
				{ 
					switch (PodMenu)
					{
					case 1: cout << "\nВведите значения для нового угла\n";
						d1.setAngle();
						d1.Display();
						break;
					case 2: cout << "\nЗначение угла\n";
						d1.Display();
						break;
					case 3:
						d1.intoRange();
						d1.Display();
						break;
					case 4: cout << "\nДобавить значение в угол\n";
						Angle a;
						a.setAngle();
						d1.increaseAngle(a);
						d1.Display();
						break;
					case 5: cout << "\nМинус значение для угла\n";
						Angle aa;
						aa.setAngle();
						d1.decreaseAngle(aa);
						d1.Display();
						break;
					case 6: cout << "\nРадианы для угла:\n";
						d1.DisplayRad();
						break;
					case 7:
						cout << "\nСинус угла = " << d1.sinA() << "\n";
						break;
					case 8: Angle d2;
						cout << "Введите значения для второго угла\n";
						d2.setAngle();
						d1 = d1 + d2;
						cout << "Угол после сложения\n";
						d1.Display();
						break;
					case 9: Angle d3;
						cout << "Введите значения для второго угла\n";
						d3.setAngle();
						d1 = d1 - d3;
						cout << "Угол после вычитания\n";
						d1.Display();
						break;
					case 10: Angle a1, a2;
						cout << "Введите значения для первого угла\n";
						a1.setAngle();
						cout << "Введите значения для второго угла\n";
						a2.setAngle();
						if (a1 == a2) cout << "Первый и второй углы равны\n";
						else
						if (a1 < a2) cout << "Первый угол меньше второго";
						else
						if (a1 > a2) cout << "Первый угол больше второго\n";
						break;

					}
					PodMenu = SelectSubMenuItem();
				}
		}
	}

	return 0;
}
