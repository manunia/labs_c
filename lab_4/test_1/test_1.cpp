// test_1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib> 
using namespace std; 

//typedef int DataType;
typedef std::string mark;
typedef std::string country;
typedef int year;
typedef int volume;
typedef int gas;
typedef float price;
typedef int num;


class Element  // класс, описывающий элемент односвязного списка 
{
public: mark mark; 
		country country;
		year year;
		volume volume;
		gas gas;
		price price;
		num count;

		Element* Next; 
		Element() //конструктор элемента 
		{ 
			Next = NULL; 
		}
};
class List    // класс, описывающий односвязный список 
{
	Element* Begin, * End;
	public: 
		List() //конструктор списка 
		{ 
			Begin = End = NULL; 
		} 
		~List() //деструктор списка 
		{ 
			Element *Rex; 
			while (Begin) 
			{ 
				Rex = Begin; 
				Begin = Begin->Next; 
				delete Rex; 
			} 
		} 
		void Add(char* file) //метод добавления элемента в конец списка 
		{ 
			FILE* f;
			system("CLS");
			if ((f = fopen(file, "ab")) == NULL) /* открываем для дозаписи */
			{
				perror("Error open file");
				system("pause");
				return;
			}

			Element *Rex = new Element; 

			cout << endl << "\tADD:" <<endl; 
			cout << "\t\tEnter mark = "; 
			cin >> Rex->mark;
			cout << "\t\tEnter country = ";
			cin >> Rex->country;
			cout << "\t\tEnter year = ";
			cin >> Rex->year;
			cout << "\t\tEnter volume = ";
			cin >> Rex->volume;
			cout << "\t\tEnter gas = ";
			cin >> Rex->gas;
			cout << "\t\tEnter price = ";
			cin >> Rex->price;
			cout << "\t\tEnter count = ";
			cin >> Rex->count;
			cout << "\tPress any key..." << endl << endl; 
			if (Begin == NULL) {
				Begin = Rex;
			}
			else {
				End->Next = Rex;
			}			 
			End = Rex; 

			fwrite(&Rex, sizeof(Rex), 1, f);
			fclose(f);
		} 
		void Show (char* file) //печать списка 
		{ 
			FILE* f;
			Element *Rex; 
			int k = 0;
			system("CLS");
			if ((f = fopen(file, "rb")) == NULL) /* открываем файл  для чтения */
			{
				perror("Error open file");
				system("pause");
				return;
			}

			cout << endl << "\tSHOW:" <<endl; 

			if(!Begin) { 
				cout << "\t\tList is empty!" << endl; 
				cout << "\tPress any key..." << endl << endl; 
				system("pause");
				return; 
			} 
			cout << "\t\tMark" << "\t\tCountry" << "\t\tYear" << "\t\tVolume" << "\t\tGas" << "\t\tPrice" << "\t\tCount" << endl;
			Rex = Begin; 

			while (fread(&Rex, sizeof(Rex), 1, f) == 1) {
				//while (Rex) {
					cout << "\t\t" << Rex->mark << "\t\t" << Rex->country << "\t\t" << Rex->year << "\t\t" << Rex->volume << "\t\t" << Rex->gas << "\t\t" << Rex->price << "\t\t" << Rex->count << endl;
					Rex = Rex->Next;
				//}
			}
			cout << "\tPress any key..." << endl << endl;
			fclose(f); 
			system("pause");
		} 
		
		void print_one(Element* Rex) {
			cout << "\t\t" << Rex->mark << "\t\t" << Rex->country << "\t\t" << Rex->year << "\t\t" << Rex->volume << "\t\t" << Rex->gas << "\t\t" << Rex->price << "\t\t" << Rex->count << endl;
		}

		void Edit(char* file) {
			FILE* f;
			Element* Rex;
			float price, prise2; char yes;
			system("CLS");
			if ((f = fopen(file, "rb+")) == NULL) // открываем файл для чтения и редактирования 
			{
				perror("Error open file");
				system("pause");
				return;
			}
			Rex = Begin;
			printf("Price: ");
			fflush(stdin);
			scanf("%f", &price);
			while (fread(&Rex, sizeof(Rex), 1, f)) {
				if (Rex->price == price) // если совпадает 
				{
					print_one(Rex);
					puts("\nRedact? (y/n)");
					do {
						yes = getchar();
					} while (yes != 'y' && yes != 'Y' && yes != 'n' && yes != 'N');
					if (yes == 'y' || yes == 'Y')
					{ // редактирование 
						cout << "\t\tEnter new price = ";
						cin >> Rex->price;
						fseek(f, sizeof(Rex), SEEK_CUR);
						fwrite(&Rex, sizeof(Rex), 1, f);
						fseek(f, 0, SEEK_CUR);
						Rex = Rex->Next;
					}
				}
			}
			system("pause");
			fclose(f);
		}

		void Search (char* file) {
			FILE* f;
			Element* Rex;
			int volume;
			system("CLS");
			if ((f = fopen(file, "rb")) == NULL) // открываем файл для чтения  
			{
				perror("Error open file");
				system("pause");
				return;
			}
			Rex = Begin;
			printf("Volume: ");
			fflush(stdin);
			scanf("%d", &volume);
			while (fread(&Rex, sizeof(Rex), 1, f)) {
				if (Rex->volume == volume) // если совпадает 
				{
					print_one(Rex);
					Rex = Rex->Next;
				}
			}
			system("pause");
			fclose(f);
		}

		void Min_gas(char* file) {
			FILE* f;
			Element* Rex;
			int min_gas = 0;
			system("CLS");
			if ((f = fopen(file, "rb")) == NULL) // открываем файл для чтения  
			{
				perror("Error open file");
				system("pause");
				return;
			}
			Rex = Begin;
			min_gas = Rex->gas;
			while (fread(&Rex, sizeof(Rex), 1, f)) {
				if (Rex->gas < min_gas)  
				{
					min_gas = Rex->gas;
				}
			}
			cout << "\tMark with min gas: " << Rex->mark << endl;
			cout << "\tPress any key..." << endl << endl;
			system("pause");
			fclose(f);
		}
	
};

int main()
{
	List L;  
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
		puts("5. Search mark with min gas");
		puts("6. Exit");
		menu = getchar();
		switch (menu) {
			case '1': 
				L.Add(file); 
				break;
			case '2': 
				L.Edit(file); 
				break;
			case '3': 
				L.Show(file); 
				break;
			case '4': 
				L.Search(file);
				break;
			case '5':
				L.Min_gas(file);
		}
	} while (menu != '6');
	
	return 0;
}

