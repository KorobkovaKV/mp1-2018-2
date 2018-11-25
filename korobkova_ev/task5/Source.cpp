#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h> 
#include <io.h> 
#include <string.h> 

void bubbleSort(unsigned a[], char nf[10000][32], long n) 
{
	long i, j;
	int x;
	char F[260];

	for (i = 0; i < n; i++) 
	{
		for (j = n - 1; j > i; j--) 
		{
			if (a[j - 1] > a[j]) 
			{
				x = a[j - 1]; a[j - 1] = a[j]; a[j] = x;
				strncpy(F, nf[j], 32);
				strncpy(nf[j], nf[j - 1], 32);
				strncpy(nf[j - 1], F, 32);
			}
		}
	}
}

void selectSort(unsigned a[], char nf[10000][32], long n) {
	long i, j, k; // k - индекс наим элемента 
	int x;
	char F[260];

	for (i = 0; i < n; i++) 
	{
		k = i; x = a[i];

		for (j = i + 1; j < n; j++)
			if (a[j] < x) 
			{
				k = j; x = a[j];
			}

		a[k] = a[i]; a[i] = x;
		strncpy(F, nf[k], 32);
		strncpy(nf[k], nf[i], 32);
		strncpy(nf[i], F, 32);
	}
}
void insertSort(unsigned a[], char nf[10000][32], long n) {
	long i, j;
	int x;
	char F[260];

	for (i = 0; i < n; i++) 
	{ 
		x = a[i];

		for (j = i - 1; j >= 0 && a[j] > x; j--)
			a[j + 1] = a[j];

		a[j + 1] = x;
		strncpy(F, nf[j + 1], 32);
		strncpy(nf[j + 1], nf[j], 32);
		strncpy(nf[j], F, 32);
	}
}


int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int p, d;
	int i;
	int N_SORT; // номер сортировки 
	struct _finddata_t c_file;
	intptr_t hFile;
	char path[260]; // путь по директории 
	int count = 0; // число файлов в директории 
	char file_name[10000][32];
	unsigned file_size[10000];

	clock_t t1, t2;

	while(1>0)
	{
		printf_s("¬ведите путь к репозиторию\n");
		printf_s("ѕуть: \n");
		gets_s(path, 260);
		strcat(path, "*");

		if ((hFile = _findfirst(path, &c_file)) == -1L)
			printf("No *.c files in current directory!\n");
		else 
		{
			printf_s("Listing of .c files\n\n");
			printf_s("FILE SIZE\n", ' ');
			printf_s("--Ч Ч--\n", ' ');
			do {
				strncpy(file_name[count], c_file.name, 32);
				file_size[count] = c_file.size;
				printf("%-12.12s %10u\n", file_name[count], file_size[count]);
				count++;
			} while (_findnext(hFile, &c_file) == 0);
			_findclose(hFile);
			printf("\ncount of files: %d\n", count);

			printf_s("¬ведите номер сортировки\n\n");
			printf_s("¬иды сортировок:\n");
			printf_s("1. пузырьком\n");
			printf_s("2. выбором\n");
			printf_s("3. вставками\n");
			printf_s("¬ведите 0, чтобы закончить работу с этим репозиторием\n\n");
			do
			{
				scanf_s("%d", &N_SORT);
				if (N_SORT > 3 || N_SORT < 0)
					printf("Ќеправильно введен номер\n");
			} while (N_SORT > 3 || N_SORT < 0);
			while(N_SORT <= 3 && N_SORT >= 0)
			{
				if (N_SORT == 1)
				{
					t1 = clock();
					bubbleSort(file_size, file_name, count);
					t2 = clock();
					printf_s("ќтсортированный список\n");
					for (p = 0; p < count; p++)
						//for (d = 0; d < count; d++) 
						//printf_s("%d %d\n", file_size[p], file_name[p][d]); 
						printf("%-12.12s %10u\n", file_name[p], file_size[p]);

					double tt = double(t2 - t1) / CLOCKS_PER_SEC;
					printf_s("¬рем€ сортировки в сек:  %f\n\n", tt);
					printf_s("¬ведите номер сортировки\n\n");
					scanf_s("%d", &N_SORT);
				}

				else if (N_SORT == 2)
				{
					t1 = clock();
					selectSort(file_size, file_name, count);
					t2 = clock();
					printf_s("ќтсортированный список\n");
					for (p = 0; p < count; p++)
						//for (d = 0; d < count; d++) 
						//printf_s("%d %d\n", file_size[p], file_name[p][d]); 
						printf("%-12.12s %10u\n", file_name[p], file_size[p]);
					double tt = double(t2 - t1) / CLOCKS_PER_SEC;
					printf_s("¬рем€ сортировки в сек:  %f\n\n", tt);
					printf_s("¬ведите номер сортировки\n\n");
					scanf_s("%d", &N_SORT);
				}

				else if (N_SORT == 3)
				{
					t1 = clock();
					insertSort(file_size, file_name, count);
					t2 = clock();
					printf_s("ќтсортированный список\n");
					for (p = 0; p < count; p++)
						//for (d = 0; d < count; d++) 
						//printf_s("%d %d\n", file_size[p], file_name[p][d]); 
						printf("%-12.12s %10u\n", file_name[p], file_size[p]);
					double tt = double(t2 - t1) / CLOCKS_PER_SEC;
					printf_s("¬рем€ сортировки в сек:  %f\n\n", tt);
					printf_s("¬ведите номер сортировки\n\n");
					scanf_s("%d", &N_SORT);
				}
				else if (N_SORT == 0)
					break;
			}
			
			gets_s(path, 260);
			strcat(path, "*");
			count = 0;
		}
		
	}
	
}