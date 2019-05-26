// test_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <math.h>
#include <stdio.h>
#include <locale.h>
using namespace std;

struct product {
	int k;
	double price;
	product* next;
};

class Queue {
public:
	product* begin;
	Queue() { begin = NULL; }
	~Queue() { //while (begin)take(); 
	}

	void add()
	{
		product* temp = new product, * temp1 = begin;
		cout << "Введите количество товара" << endl;
		cin >> temp->k;
		cout << "Введите цену товара:" << endl;
		cin >> temp->price;
		temp->next = NULL;
		if (begin)
		{
			while (temp1->next)temp1 = temp1->next;
			temp1->next = temp;
		}
		else begin = temp;
	}

	void print()
	{
		product* temp = begin;;
		if (begin)
		{
			cout << " Количество товара = " << temp->k << " По цене = " << temp->price << endl;
			temp = temp->next;
			while (temp)
			{
				cout << " Количество товара = " << temp->k << " По цене = " << temp->price << endl;
				temp = temp->next;
			}
			cout << endl;
		}
		else cout << "Склад пуст" << endl;
	}

	product* pop_front() {
		product* item;
		item = begin;
		if (begin) 
			begin = begin->next;
		else cout << "Склад пуст" << endl;
		return item;
	}
};




int main()
{
	setlocale(LC_ALL, "RUS");
	int i, fl = 1;
	Queue q;
	double x = 0, mnog = 0;
	product temp;
	while (fl)
	{

		cout << "Интерфейс" << endl;
		cout << "1 добавить товар" << endl;
		cout << "2 Продать товар" << endl;
		cout << "3 Вывести состояние склада" << endl;
		cout << "0 выход" << endl;
		cin >> i;
		system("cls");
		if (i == 0) { fl--; }
		if (i == 1) { q.add(); }
		if (i == 2) { q.pop_front(); }
		if (i == 3) { q.print(); }

		mnog = 0;
	}

	return 0;
}

