// test1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>



template <class Tdata, class Tnumber>

void trans_pos(Tdata mas[], Tnumber n) {
	Tnumber i, p;
	for (p = 0; p <= n; p++) {
		for (i = n-2; i >= 0; i--) {
			if (mas[i] % 2 == 0) {
				Tdata temp = mas[i];
				mas[i] = mas[i+1];
				mas[i+1] = temp;
			}
		}
	}
}


int main()
{
	setlocale(LC_ALL, "rus");

	int mas[] = { 1,2,3,4,5,6,7};
	
	std::cout << "\nИсходный массив int\n";
	for (int i = 0; i < 7; i++) {
		std::cout << mas[i];
		std::cout << ", ";
	}
	trans_pos(mas, 7);
	std::cout << "\nмассив int с переставленными элементами\n";
	for (char i = 0; i < 7; i++) {
		std::cout << mas[i];
		std::cout << ", ";
	}

	char mas1[] = "asdfghj";
	std::cout << "\nИсходный массив char\n";
	for (int i = 0; i < 7; i++) {
		std::cout << mas1[i];
		std::cout << ", ";
	}
	trans_pos(mas1, 7);
	std::cout << "\nмассив char с переставленными элементами\n";
	for (int i = 0; i < 7; i++) {
		std::cout << mas1[i];
		std::cout << ", ";
	}
}

