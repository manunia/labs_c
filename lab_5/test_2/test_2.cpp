// test_2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream> 
#include <cstdlib> 

using namespace std; 

typedef int DataType; 

class Element  // класс, описывающий элемент 
{ 
	public: 
		DataType value; 
		Element *Next; 

		Element() //конструктор элемента 
		{ 
			Next = NULL; 
		} 
}; 

class Stack    // класс, описывающий стек 
{
	Element* Head, * Next;
public:
	Stack() {
		Head = Next = NULL;
	}
	~Stack() {
		Element* Rex; 
		while(Head) { 
			Rex = Head; 
			Head = Head->Next; 
			delete Rex;
		}
	}

	void push(void) {
		Element* Rex = new Element; 
		cout << endl << "\tADD:" << endl; 
		cout << "\t\tEnter value = "; 
		cin >> Rex->value; 
		cout << "\tPress any key..." << endl << endl; 
		if (Head == NULL)
			Head = Rex;
		else
			Rex->Next = Head; 			
		Head = Rex;
		
	}
	void print(void) {
		Element* Rex; 
		cout << endl << "\tSHOW:" << endl; 
		if (!Head) { 
			cout << "\t\tStack is empty!" << endl; 
			cout << "\tPress any key..." << endl << endl; 
			return; 
		} 
		cout << "\t\tvalue" << endl; 
		Rex = Head; 
		while (Rex) 
		{ 
			cout << "\t\t\t" << Rex->value << endl; 
			Rex = Rex->Next; 
		} 
		cout << "\tPress any key..." << endl << endl;
	}
};

int main() {

	Stack st; 
	int k = 0; 
	do { 
		cout << "MENU:" << endl << endl; 
		cout << "\t1 - ADD" << endl << "\t2 - SHOW" << endl; 
		cout << "\t3 - Exit" << endl << endl; 
		cout << "Press any key..." << endl; 
		k = getchar(); 
		switch(k) { 
			case 49: 
				st.push(); 
				break; 
			case 50: 
				st.print(); 
				break; 
		}
	} while (k != 51); 

	return 0;

}


