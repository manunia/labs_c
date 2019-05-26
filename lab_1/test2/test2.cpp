// test2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* f, *fout;
	const int N = 3; //размер массива
	int x[N][N], k = 0;
	char c;
	
	f = fopen("int.txt", "rt");
	fout = fopen("rez.txt", "wt");
	if (!f) {
		printf("Can not open text file\n"); /* сообщаем об  ошибке */       
		system("pause");       
		return 0; /* прерываем программу */
	}
	if (!fout) /*если не удалось создать новый файл */ 
	{ 
		printf("Can not create text file\n"); /* сообщаем  об ошибке */ 
		system("pause"); 
		return 0; /* прерываем программу */ 
	} 
	printf("\n\n open file: \n");

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			fscanf(f, "%d", &x[i][j]);
		}
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) {
				fprintf(fout, "%d ", x[N - 1][N - 1]);
			}
			else {
				fprintf(fout, "%d ", x[i][j]);
			}
		}
		fprintf(fout, "\n");
	}

	fclose(f);  
	fclose(fout);
	return 0;
}

