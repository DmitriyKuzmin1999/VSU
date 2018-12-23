/*9. Реализовать шаблон класса список с приоритетом (PriorityList<X,Y>, где X – тип
элемента, Y – тип приоритета). Класс должен содержать методы:
Добавление элемента в список;
Получение самого приоритетного объекта;
Получение самого неприоритетного объектов;
Удаление самого приоритетного элемента;
Удаление самого неприоритетного элемента;
Поиск элемента;
Удаления произвольно элемента;
Печать списка.
*/
//Кузьмин Дмитрий, 91г.

#include "pch.h"
#include <iostream>
using namespace std;

template <typename T, typename V>
class List
{
	struct Node
	{
		T x;
		V y;
		Node* next;
	};

private:
	Node* HEAD;
	Node* TAIL;

	bool IsEmpty()
	{
		if (HEAD == NULL) return true;
		return false;
	}

public:
	List() { HEAD = NULL; TAIL = NULL; }//Конструктор

	~List()//Деструктор
	{
		while (HEAD != NULL)
		{
			Node* temp = HEAD->next;
			delete HEAD;
			HEAD = temp;
		}
	}

	void Add(T xn, V yn)//Добавление записи
	{
		Node* temp = new Node;
		temp->x = xn;
		temp->y = yn;
		if (IsEmpty())//если список пустой
		{
			temp->next = NULL;
			HEAD = temp;
			TAIL = temp;
		}
		else//если список не пустой
		{
			//Node* p = HEAD;
			if (HEAD->y < temp->y)//если приоритетность 1го меньше
			{
				temp->next = HEAD;
				HEAD = temp;
			}
			else
			{
				
				if (TAIL->y > temp->y)//если приоритетность последнего блльше
				{
					temp->next = NULL;
					TAIL->next = temp;
					TAIL = temp;

				}
				else
				{
					bool OK = false;
					Node* p = HEAD;
					while ((p->next != NULL) && !OK)
					{
						if (p->next->y < temp->y)//если нашли след элемент с меньшей приоритетностью
						{
							temp->next = p->next;
							p->next = temp;
							OK = true;
						}
						else//если не нашли, то ищем дальше
							p = p->next;
					}
					if (!OK)//если вообще не нашли элементов с меньшим приоритетом, то добавляем в конец
					{
						TAIL->next = temp;
						TAIL = temp;
						temp->next = NULL;
					}
				}
			}
		}
	}

	void AddTo()
	{
		T xn;
		V yn;
		cout << "Введите значение элемента и приоритетность\n";
		cin >> xn >> yn;
		Add(xn, yn);
	}

	void Show()//Печать списка
	{
		Node* temp = HEAD;

		while (temp != NULL)
		{
			cout << "Значение: " << temp->x << ", приоритетность: " << temp->y << "\n";
			temp = temp->next;
		}
	}

	void ShowFirst()//Печать наиболее приоритетного элемента
	{
		if (!IsEmpty())
			cout << "Значение: " << HEAD->x << ", приоритетность: " << HEAD->y << "\n";
		else
			cout << "Список пуст!\n";
	}

	void ShowLast()//Печать наименее приоритетного элемента
	{
		if (!IsEmpty())
			cout << "Значение: " << TAIL->x << ", приоритетность: " << TAIL->y << "\n";
		else
			cout << "Список пуст!\n";
	}

	void DelFirst()
	{
		if (!IsEmpty())
		{
			if (HEAD == TAIL)//Если в списке только одна запись
			{
				HEAD = NULL;
				TAIL = NULL;
			}
			else
			{
				Node* temp = HEAD;
				HEAD = temp->next;
				delete temp;
			}
		}
	}

	void DelLast()
	{
		if (!IsEmpty())
		{
			if (HEAD == TAIL)//Если в списке только одна запись
			{
				HEAD = NULL;
				TAIL = NULL;
			}
			else
			{
				Node* temp = HEAD;
				while (temp->next != TAIL)
					temp = temp->next;
				TAIL = temp;
				temp = temp->next;
				TAIL->next = NULL;
				delete temp;
			}
		}
	}

	void Seek(T xs)
	{
		Node* p = HEAD;
		bool OK = false;
		while (p != NULL)
		{
			if (p->x == xs)
			{
				cout << "Заданный элемент найден:\n" << "X = " << p->x << "; Y= " << p->y << "\n";
				OK = true;
			}
			p = p->next;
		}
		if (!OK)
			cout << "Заданный элемент не найден\n";
	}

	void SeekE()
	{
		T xn;
		cout << "\nВведите элемент, который нужно найти\n";
		cin >> xn;
		Seek(xn);
	}

	void DelEl(T xs)
	{
		Node* p = HEAD;
		bool OK = false;
		if (!IsEmpty())
		{
			if (p->x == xs)
			{
				DelFirst();
			}
			else
			{
				if (TAIL->x == xs)
				{
					DelLast();
				}
				else
				{
					while (!OK && (p->next != NULL))
					{
						if (p->next->x == xs)
						{
							p->next = p->next->next;
							p = p->next;
							delete p;
							OK = true;
						}
						p = p->next;
					}
				}
			}
			
		}
	}

	void DelE()
	{
		T xn;
		cout << "\nВведите элемент, который нужно удалить\n";
		cin >> xn;
		DelEl(xn);			
	}
};

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
	cout << "\n____________________________" << endl;
	cout << "Выберите один из пунктов меню:" << endl;
	cout << "1 - Добавить запись" << endl;
	cout << "2 - Получить наиболее приоритетную запись" << endl;
	cout << "3 - Получить наименее приоритетную запись" << endl;
	cout << "4 - Удалить наиболее приоритетную запись" << endl;
	cout << "5 - Удалить наименее приоритетную запись" << endl;
	cout << "6 - Найти заданный элемент" << endl;
	cout << "7 - Удалить заданный элемент" << endl;
	cout << "8 - Напечатать список" << endl;
	return InputSize("0 - выйти из программы", 0, 8);
}


int main()
{
	setlocale(LC_ALL, "Russian");
	int MenuItem = -1;
	List<int, int> l;

	while (MenuItem != 0)
	{
		MenuItem = SelectMenuItem();
		switch (MenuItem)
		{
		case 1: l.AddTo();
			break;
		case 2: l.ShowFirst();
			break;
		case 3: l.ShowLast();
			break;
		case 4: l.DelFirst();
			break;
		case 5: l.DelLast();
			break;
		case 6: l.SeekE();
			break;
		case 7: l.DelE();
			break;
		case 8: l.Show();
			break;
		}
	}

	return 0;
}
