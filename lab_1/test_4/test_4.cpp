// test_4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <windows.h>
#include <cstdio>


struct car {
	char mark[30];
	char country[10];
	int year;
	int volume;
	int gas;
	float price;
	int count;
};

void add(char*); /* добавление записи */ 
void edit(char*); /* редактирование записи */ 
void show(char*); /* вывод списка */ 
void search(char*); /* поиск */

int main(void)
{
	system("chcp 65001");
	char file[50];     
	char menu;     
	puts("Name of file:"); 
	gets_s(file);
	     
	do {
		system("CLS");        
		puts("1. Add");        
		puts("2. Edit");        
		puts("3. Show");        
		puts("4. Search");        
		puts("5. Exit");        
		menu = getchar();        
		switch (menu) { 
			case '1': add(file); break;               
			case '2': edit(file); break;               
			case '3': show(file); break;               
			case '4': search(file); 
		}
	}
	while (menu != '5');     
	return 0;
}

struct car input_car(void) {
	struct car car;
	//int temp;
	fflush(stdin);
	puts("Mark");
	scanf("%s", &car.mark);
	puts("Country");
	scanf("%s", &car.country);
	puts("Year");
	scanf("%d", &car.year);
	puts("Volume");
	scanf("%d", &car.volume);
	puts("Gas");
	scanf("%d", &car.gas);
	puts("Price");
	scanf("%f", &car.price);
	puts("Count");
	scanf("%d", &car.count);
	return car;
}

void add(char* file) /* добавление записи в файл */
{
	FILE* f;
	struct car car;
	system("CLS");      
	if ((f = fopen(file, "ab")) == NULL) /* открываем для дозаписи */
	{ 
		perror("Error open file");               
		system("pause");          
		return; 
	}
	car = input_car();
	fwrite(&car, sizeof(car), 1, f);
	fclose(f);
}

void print_one(struct car data) {
	printf("Mark: %s\nCountry: %s\nYear: %d\n Volume: %d\nGas: %d\nPrice: %.2f\nCount: %d", data.mark, data.country, data.year, data.volume, data.gas, data.price, data.count);
}

void edit(char* file) /* редактирование записей */
{
	FILE* f;      
	struct car car;     
	float price, yes;      
	system("CLS");
	if ((f = fopen(file, "rb+")) == NULL) /* открываем файл для чтения и редактирования */ 
	{ 
		perror("Error open file");               
		system("pause");           
		return; 
	}
	printf("Price: ");
	fflush(stdin);      
	scanf("%f", &price);
	while (fread(&car, sizeof(car), 1, f)) {
		if (car.price != price) /* если совпадает */
		{
			print_one(car);
			puts("\nRedact? (y/n)");              
			do                   
				yes = getchar();              
			while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');              
			if (yes == 'y' || yes == 'Y')
			{ /* редактирование */
				car = input_car();
				fseek(f, sizeof(car), SEEK_CUR);                    
				fwrite(&car, sizeof(car), 1, f);                 
				fseek(f, 0, SEEK_CUR);
			}
		}
	}
	system("pause");      
	fclose(f);
}

void show(char* file) /* вывод на экран */
{
	FILE* f;      
	struct car car;      
	int k = 0;      
	system("CLS");      
	if ((f = fopen(file, "rb")) == NULL) /* открываем файл  для чтения */ 
	{ 
		perror("Error open file");            
		system("pause");              
		return; 
	}

	puts("|  N |   Mark    |   Country  |  Year | Volume|  Gas  |    Price   |  Count |"); /* шапка таблицы */      
	puts("------------------------------------------------------------------------------------------------");
	while (fread(&car, sizeof(car), 1, f) == 1)         
		printf("|%3d |%10s |%10s | %4d |%4d | %4d |%10.2f |  %2d  |\n", ++k, car.mark, car.country, car.year, car.volume, car.gas, car.price, car.count);      
	puts("------------------------------------------------------------------------------------------------");      
	fclose(f);           
	system("pause");
}

void search(char* file) /* поиск */
{
	FILE* f;      
	struct car car;      
	int volume;      
	int min_gas = 100, pos;      
	system("CLS");
	if ((f = fopen(file, "rb")) == NULL) /* открываем файл  для чтения */ 
	{ 
		perror("Error open file");            
		system("pause");              
		return; 
	}      
	puts("Volume?");      
	scanf("%d", &volume); 
	while (fread(&car, sizeof(car), 1, f) == 1)
	{
		if (car.volume == volume && car.gas < min_gas) {
			min_gas = car.gas;
			pos = ftell(f); /* запоминаем текущую позицию –   конец записи */
		}
	}
	if (min_gas == 0) puts("No cars");      
	else {
		fseek(f, pos - sizeof(car), SEEK_SET);          
		/* возврат к началу запомненной записи */          
		fread(&car, sizeof(car), 1, f);          
		print_one(car);
	}
	fclose(f);      
	system("pause");
}

