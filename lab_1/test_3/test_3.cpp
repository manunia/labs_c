// test_3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void Gen_press(void);
void Pow_file(void);
/* вывод содержимого бинарного файла на экран */ 
void Out_file(void);

const int size = 15;
int arr[size];

int main(void)
{
	int key = 0;  
	srand(time(0)); 
	while (key != 27) {
		system("CLS");   
		printf("Menu:\n\t1 - Create file gen press\n\t2 - Output file\n\t3 - Change file\n\t4 - Exit\n");
		key = getchar();   
		if (key == 49) Gen_press();   
		if (key == 50) Out_file();   
		if (key == 51) Pow_file();
	}
	return 0;
}

void Gen_press(void) {
	/* ввод чисел и их количества с помощью генератора случайных чисел */
	int n = 0, k = size;
	FILE* fin;
	fin = fopen("datfile.dat", "wb");
	if (!fin) {
		printf("Can not create binary file\n");   
		system("pause");   
		exit(0);
	}
	//k = rand() % 100 + 1; 
	while (k) {
		n = rand() % 101 - 50;   
		fwrite(&n, sizeof(n), 1, fin);  
		k--;
	}
	fclose(fin);  
	printf("\n\nFile create\n ");  
	system("pause");
}

void Out_file(void) {
	// вывод содержимого файла на экран  
	int n = 0;  
	FILE *fin;  
	fin = fopen("datfile.dat", "rb"); 
	if (!fin) {
		printf("Can not open binary file\n");   
		system("pause");   
		exit(0);
	}
	printf("\n\nIn file: \n");  
	while (fread(&n, sizeof(n), 1, fin)) { 
		printf("%5d", n); 
	}  
	fclose(fin);  
	system("pause");
}

int Find_min() {
	int n = 0;
	int min = 0;
	FILE* fin;
	fin = fopen("datfile.dat", "r+b");
	if (!fin) {
		printf("Can not open binary file\n");
		system("pause");
		exit(0);
	}
	rewind(fin);
	while (fread(&n, sizeof(n), 1, fin)) {
		if (n <= min) {
			min = n;
		}
	}
	printf("\n\n min = %d\  ", min);
	return min;
}

int Find_max() {
	int n = 0;
	int max = 0;
	FILE* fin;
	fin = fopen("datfile.dat", "r+b");
	if (!fin) {
		printf("Can not open binary file\n");
		system("pause");
		exit(0);
	}
	rewind(fin);
	while (fread(&n, sizeof(n), 1, fin)) {
		if (n > max) {
			max = n;
		}
	}
	printf("\n\n max = %d\  ", max);
	return max;
}

void Pow_file(void) {  // изменение содержимого файла   
	int n = 0;  	 
	int min = Find_min();
	int max = Find_max();
	FILE* fin;  
	fin = fopen("datfile.dat", "r+b");  
	if (!fin) {
		printf("Can not open binary file\n");   
		system("pause");   
		exit(0);
	}
	rewind(fin);  
	while (fread(&n, sizeof(n), 1, fin)) {
		if (n == min || n == max) { 
			n = NULL;
		}
		fseek(fin, ftell(fin) - sizeof(n), SEEK_SET);    
		fwrite(&n, sizeof(n), 1, fin);    
		fseek(fin, ftell(fin), SEEK_SET);
	}

	fclose(fin);  
	printf("\n\nFile change!\ ");  
	system("pause");
}




