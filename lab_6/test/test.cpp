// test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <regex>



class mystring    // Опишем базовый класс строки
{
private: 
	static int i;
protected:
	char* p;    // Указатель на char - хранит адрес динамически выделенной памяти для размещения символов строки
	int length;    // Значение типа int - хранит длину строки в байтах
public:    // Обязательные методы должны выполнять следующие действия:
	mystring() {// Конструтор без параметров
		p = new char[0];
		std::cout << "Конструтор mystring без параметров\n";
	}    
	mystring(const char* s) {  // Конструктор, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)
		length = strlen(s);
		p = new char[length + 1];
		for (int i = 0; i < length; i++)
			p[i] = s[i];
		p[length] = '\0';
		std::cout << "Конструктор mystring, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)\n";
	}  
	mystring(char c) {// Конструктор, принимающий в качестве параметра символ (char)
		p = new char[2];
		p[0] = c;
		p[1] = '\0';
		std::cout << "Конструктор mystring, принимающий в качестве параметра символ (char)\n";
	}     
	mystring(const mystring& str) {// Конструктор копирования
		i++;
		length = str.length;
		p = new char[length];
		for (int i = 0; i < length; i++) {
			p[i] = str.p[i];
		}
		std::cout << "Вызов конструктора mystring копирования: ";
		std::cout << i;
	}    
	~mystring() {// Деструктор
		if (p) delete[] p;
		std::cout << "Деструктор mystring\n";
	}    
	int get_length() { // Получение длины строки
		std::cout << "Получение mystring длины строки lenght = ";
		std::cout << length;
		std::cout << "\n";
		return length;
	}   
	void show() {// Для тестирования вывод строки на экран
		for (int i = 0; i < length; i++) {
			std::cout << p[i];
		}
		std::cout << "\n";
	}       
	mystring& operator = (const mystring& s) {
		std::cout << "\nПереопределение операции присваивания mystring\n";
		p = s.p;
		length = s.length;
		return *this;
	}
	// перевод всех символов строки (кроме цифр) в верхний регистр
	char* to_upper_case() {
		std::cout << " перевод всех символов строки mystring (кроме цифр) в верхний регистр";
		int i = 0, j = 0;
		int len = strlen(p);
		while (i < len)
		{
			if (p[i] >= 'a' && p[i] <= 'z') p[i] -= p[i] - 32;
			i++;
		}
		return p;
		
	}
	bool operator < (const mystring& s) {
		std::cout << "\nПереопределение операции сравнения mystring\n";
		if (p == s.p) return true;
		else return false;
	}

};

// Производный от строка класс строка идентификатор (_A-Za-z0-9)
class identification : public mystring
{
public:    // Обязательные методы:
	identification() {// Конструтор без параметров
		p = new char[0];
		std::cout << "Конструтор identification без параметров\n";
	}    
	identification(const char* s) {// Конструктор, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)
		int tmp = 0;
		p = new char[strlen(s) + 1];
		length = strlen(s);
		if (((s[0] >= 'A') && (s[0] <= 'Z')) || (s[0] >= 'a' && s[0] <= 'z') || (s[0] == '_'))
			for (int i = 1; i < length; i++)
			{
				if (!(((s[i] >= 'A') && (s[i] <= 'Z')) || ((s[i] >= 'a') && (s[i] <= 'z'))))
					if (!(((s[i] >= '0') && (s[i] <= '9')))) tmp++;
			}
		else
			tmp++;
		if (tmp == 0) strcpy(p, s);
		else
		{
			p[0] = '\0';
			length = 0;
		}
		std::cout << "Конструктор identification, принимающий в качестве параметра Си-строку (заканчивается нулевым байтом)\n";
	}
	
	identification(char c) {// Конструктор, принимающий в качестве параметра символ (char)
		length = 1;
		p = new char[length + 1];
		p[1] = '\0';
		p[0] = c;
		if (c >= 'A' && c <= 'Z' ||c >= 'a' && c <= 'z' || c >= '0' && c <= '9')
			p[0] = c;
		else
		{
			p[0] = '\0';
			length = 0;
		}
	
		std::cout << "Конструктор identification, принимающий в качестве параметра символ (char)\n";
	}       
	identification(const identification& str) {// Конструктор копирования
		length = str.length;
		p = new char[length];
		for (int i = 0; i < length; i++) {
			p[i] = str.p[i];
		}
		std::cout << "Вызов конструктора identification копирования: ";
	}    
	~identification() {// Деструктор
		std::cout << "Деструктор identification\n";
	}    

	identification operator=(identification id) {// Переопределим присваивание (=)
		std::cout << "\nПереопределение операции присваивания identification\n";
		p = id.p;
		length = id.length;
		return *this;
	}    
};

// Производный от строка класс комплексное число (+-0-9i)
class complex : public mystring
{
private:
	char* real;
	char* img;

public:
	complex() {// Конструтор без параметров
		real = new char[0];
		img = new char[0];
		p = new char[0];
		std::cout << "Конструтор complex без параметров\n";
	}  
	complex(const char* s) {
		length = strlen(s);
		p = new char[length + 1];
		for (int i = 0; i < length; i++)
			p[i] = s[i];
		p[length] = '\0';

		int t = 0;
		char* temp_rel, *temp_im;
		while (p[t] != 'i') {
			t++;
		}
		temp_rel = new char[t];
		temp_im = new char[length - t];
		for (int i = 0; i < t; i++) {
			temp_rel[i] = s[i];
		}
		for (int i = 0; i < length - t; i++) {
			temp_im[i] = s[i + t];
		}
		if (!isNum(temp_rel) || !isNum(temp_im)) {
			p = '\0';
		}
		real = temp_rel;
		img = temp_im;
		std::cout << "Конструктор complex, принимающий в качестве параметра Си-строку\n";
	}
	complex(const complex& str) {// Конструктор копирования
		std::cout << "Вызов конструктора complex копирования: ";
	}    
	~complex() { // Деструктор
		std::cout << "Деструктор complex\n";
	}   
	
	complex operator=(complex com) {// Переопределим присваивание (=)
		std::cout << "\nПереопределение операции присваивания complex\n";
		p = com.p;
		length = com.length;
		return *this;
	}  
	
	complex operator/(complex com) {
		std::cout << "\nПереопределение операции деления complex\n";
		int temp_b = (int)com.img;
		int temp_a = (int)com.real;
		int temp_c = (int)real;
		int temp_d = (int)img;

		int temp_rel = (temp_a*temp_c + temp_b*temp_d)/(pow(temp_c,2)+pow(temp_d,2));
		int temp_img = (temp_b * temp_c - temp_a * temp_d) / (pow(temp_c, 2) + pow(temp_d, 2));

		real = (char*)temp_rel;;
		img = (char*)temp_img;

		return *this;
	}
	complex operator!() {// Переопределим отрицание (!)
		std::cout << "\nПереопределение операции отрицания complex\n";
		if (img[0] == '+') {
			img[0] = '-';
		} else if (img[0] == '-') {
			img[0] = '+';
		}
		return *this;
	}
	//проверка на число
	bool isNum(char* s) {
		for (int i = 0; i < strlen(s); i++)
			if (s[i] < '0' || s[i] > '9')
				return false;
		return true;
	}

	void show() {// Для тестирования вывод на экран
		for (int i = 0; i < length; i++) {
			std::cout << real[i];
			
		}
		std::cout << "\n";
		
	}
};


int main()
{
	setlocale(LC_ALL, "rus");

	size_t size = 0;
	std::cout << "Инициализация.\nВведите  число элементов в массиве указателей на базовый класс:\n";
	std::cin >> size;
	mystring* ptr = new mystring [size];
	identification* iden = new identification[size];
	complex* comp = new complex[size];

	char choose = 0;
	char choose1 = 0;
	char choose2 = 0;
	char choose3 = 0;

	//---------------------------------------------------------
	char* assin_mystr = new char[0];
	char* compare_mystr = new char[0];
	char* mystr = new char[0];
	//-------------------------------------------------------

	//-----------------------------------
	char* assin_myiden = new char[0];
	char* myiden = new char[0];
	//-------------------------------------

	//---------------------------------------------
	char* assin_real = new char[0];
	char* div_real = new char[0];
	char* real = new char[0];
	//-----------------------------------------------

	std::cout << "Choose object type:\n\t1 - mystring\n\t2 - identification\n\t3 - complex\n\t9 - exit->";
	std::cin >> choose;
	while (choose != '9') {
		switch (choose)
		{
		case '1':

			std::cout << "Введите строку\n";
			std::cin >> mystr;
			ptr = new mystring(mystr);

			std::cout << "Choose method:\n\t1 - Получение длины строки\n\t2 - Переопределение операции присваивания\n\t3 - перевод всех символов строки (кроме цифр) в верхний регистр\n\t4 - Переопределение операции сравнения\n\t5 - вывод строки на экран>";
			std::cin >> choose1;
			switch (choose1)
			{
			case '1':
				ptr->get_length();
				break;
			case '2':
				std::cout << "Введите строку\n";
				std::cin >> assin_mystr;
				ptr->operator=(mystring(assin_mystr));
				break;
			case '3':
				ptr->to_upper_case();
				break;
			case '4':
				std::cout << "Введите строку\n";
				std::cin >> compare_mystr;
				ptr->operator< (mystring(compare_mystr));
				break;
			case '5':
				ptr->show();
				break;
			};
			break;
		case '2':

			std::cout << "Введите строку\n";
			std::cin >> myiden;
			iden = new identification(myiden);

			std::cout << "Choose method:\n\t1 - Получение длины строки\n\t2 - Переопределение операции присваивания\n\t3 - вывод строки на экран>";
			std::cin >> choose2;
			switch (choose2)
			{
			case '1':
				iden->get_length();
				break;
			case '2':
				std::cout << "Введите строку\n";
				std::cin >> assin_myiden;
				iden->operator=(identification(assin_myiden));
				break;
			case '3':
				iden->show();
				break;
			};
			break;
		case '3':
			std::cout << "Введите complex\n";
			std::cin >> real;
			comp = new complex(real);
			std::cout << "Choose method:\n\t1 - Получение длины строки\n\t2 - Переопределение операции присваивания\n\t3 - Переопределение операции деления \n\t4 -Переопределение операции отрицания \n\t5 - вывод строки на экран>";
			std::cin >> choose3;
			switch (choose3)
			{
			case '1':
				comp->get_length();
				break;
			case '2':
				std::cout << "Введите complex\n";
				std::cin >> assin_real;
				comp->operator=(complex(assin_real));
				break;
			case '3':
				std::cout << "Введите complex\n";
				std::cin >> div_real;
				comp->operator/(complex(div_real));
				break;
			case '4':
				comp->operator!();
				break;
			case '5':
				comp->show();
				break;
			};
			break;
		case '9':
			return 0;
		};
	}
}

