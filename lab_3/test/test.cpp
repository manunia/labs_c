// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h> 
#include <stdlib.h>

class rational_number {
	int numerator;//числитель
	int denominator;
public:
	void set_numerator(int n) { numerator = n; }
	void set_denominator(int d) { denominator = d; }
	int get_numerator();
	int get_denominator();

	//конструктор копирования
	rational_number(const rational_number &r) {
		std::cout << "\nКонструктор копирования\n";
	}

	rational_number(int n=0, int d=0) {
		std::cout << "\nОбычный конструктор\n";
		this->numerator = n;
		this->denominator = d;
	}
	//перегрузка операции приведения типов
	operator float () {
		return (float) numerator / denominator;
	}
	//перегрузка операции деления на рац. число
	friend rational_number operator/ (rational_number& r1, rational_number& r2);

	//перегрузка операции деления на целое число
	friend rational_number operator/ (rational_number& r1, int x);

	//перегрузка операции сравнения с рац. числом
	friend bool operator> (rational_number& r1, rational_number& r2);

	//перегрузка операции сравнения с целым числом
	friend bool operator> (rational_number& r1, int x);

	~rational_number(){
		std::cout << "\nДеструктор\n";
	}
	
};

rational_number operator/ (rational_number& r1, rational_number& r2){
	std::cout << "\nОперация деления рац.числа на другое рац.число\n";
	rational_number res(r1.numerator * r2.denominator, r1.denominator * r2.numerator);
	return  (res);
	std::cout << "\n";
	system("pause");
}

rational_number operator/ (rational_number& r1, int x) {
	std::cout << "\nОперация деления рац.числа на целое число\n";
	rational_number res(r1.numerator, r1.denominator * x);
	return  (res);
	std::cout << "\n";
	system("pause");
}

bool operator> (rational_number& r1, rational_number& r2) {
	std::cout << "\nОперация сравнения рац.числа с другим рац. числом\n";
	if ((float)r1 > (float)r2) {
		std::cout << "r1>r2\n";
		system("pause");
		return true;
	}
	else
	{
		std::cout << "r1<r2\n";
		system("pause");
		return false;	
	}
}

bool operator> (rational_number& r1, int x) {
	std::cout << "\nОперация сравнения рац.числа с целым числом\n";
	if ((float)r1 > (float)x) {
		std::cout << "r1>x\n";
		system("pause");
		return true;
	}
	else
	{
		std::cout << "r1<x\n";
		system("pause");
		return false;
	}
	std::cout << "\n";
}

//метод ввода с клавиатуры
int enter_num() {
	int x;
	std::cout << "Введите число: ";
	std::cin >> x;
	return x;
}

//вывод рационального числа
void print_r_num(int n, int d) {
	std::cout << "\nРациональное число в виде дроби\n";
	std::cout << n ;
	std::cout << "/";
	std::cout << d;
	std::cout << "\n";
	system("pause");
}
//вывод числа с плавающей точкой
void print_float(float value) {
	std::cout << "\nЧисло с плавающей точкой\n";
	std::cout << value;
	std::cout << "\n";
	system("pause");
}

int rational_number::get_numerator()
{
	return numerator;
}

int rational_number::get_denominator()
{
	return denominator;
}

int main()
{
	setlocale(LC_ALL, "rus");
	char menu;
	rational_number r1, r2, res;
	int x;
	
	 do { 
		system("CLS");              
		puts("1. Операция деления рац.числа на другое рац.число");        
		puts("2. Операция деления рац.числа на целое число");        
		puts("3. Операция сравнения рац.числа с другим рац. числом");        
		puts("4. Операция сравнения рац.числа с целым числом");
		puts("5. Рациональное число в виде дроби");
		puts("6. Число с плавающей точкой");
		puts("7. Exit");
		menu = getchar();        
		switch (menu) { 
			case '1': 
				r1 = rational_number ();
				r1.set_numerator(enter_num());
				r1.set_denominator(enter_num());
				r2 = rational_number ();
				r2.set_numerator(enter_num());
				r2.set_denominator(enter_num());
				//operator/(r1, r2);
				std::cout << "\nРезультат деления рац.числа на другое рац.число\n";
				print_float(operator/(r1, r2));
				break;               
			case '2': 
				r1 = rational_number (enter_num(), enter_num());
				x = enter_num();
				res = operator/(r1, x);
				std::cout << "\nРезультат деления рац.числа на целое число\n";
				print_float(res);
				break;               
			case '3': 
				r1 = rational_number(enter_num(), enter_num());
				r2 = rational_number(enter_num(), enter_num());
				std::cout << "\nРезультат сравнения рац.числа с другим рац.числом\n";
				res = operator>(r1, r2);				
				break;               
			case '4': 
				r1 = rational_number(enter_num(), enter_num());
				x = enter_num();
				std::cout << "\nРезультат сравнения рац.числа с целым числом\n";
				res = operator>(r1, x);
				break;
			case '5':
				r1 = rational_number();
				r1.set_numerator(enter_num());
				r1.set_denominator(enter_num());
				print_r_num(r1.get_numerator(), r1.get_denominator());
				break;
			case '6':
				r1 = rational_number(enter_num(), enter_num());
				print_float(r1);
		} 
	 } while (menu != '7');

	return 0;
}


