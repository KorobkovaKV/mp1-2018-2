#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));
	int N; // N - �����
	int k; // k - ����� �������
	int a = 1, b = 1000;
	int number;
	int c;
	char z[2];

	printf("������� ����� \n");
	scanf_s("%d", &N);

	if (N == 1)
	{
		c = a + rand() % (b - a + 1);
		printf("������� ����� \n");
		scanf_s("%d", &number);
			k = 1;
		while (number != c)
		{
			if (number > c)
				printf("������ \n");
			if (number < c)
				printf("������ \n");
			printf("������� ����� \n");
			scanf_s("%d", &number);
			k++;
		}
		printf("���! \n");
		printf("%d", k);
	}

	if (N == 2)
	{
		printf("������� �����, ������� �� ������ �������� \n");
		scanf_s("%d", &number);
		k = 1;
		c = a + rand() % (b - a + 1);
		printf("%d", c);
		printf("������? \n");
		gets_s(z);
		while (1 > 0)
		{
			gets_s(z);

			if (z[0] == '<')
				b = c - 1;
			if (z[0] == '>')
				a = c + 1;
			if (z[0] == '=')
				break;
			c = a + rand() % (b - a + 1);
			printf("%d", c);
			k++;
		}
		printf("������! \n");
		printf("%d", k);
	}

	printf("���� ��������\n");
	scanf_s("%d", &k);
}