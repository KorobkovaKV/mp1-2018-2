#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <locale.h>
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int n; //n - ���������� ���� � �����
	int r = 1; //���������� ��� �������� ������ �� �����
	int K[5] = { 0 }; // ������ ��� �������� ����������� �����
	int B[5] = { 0 }; // ������ ��� �������� ����� �����
	int cow = 0; //"������"
	int bull = 0; //"����"
	int i;
	int m;
	int p = 1; //p - �������� �� �������� ����� ��������� �����
	int z; // z - ���� ������� ������� ���������� �����

	printf_s("������� ����: �� ��������� ������� �����, ���������� �����������, �ow - ������� ���� ������� ��� ���������� � �� ��������� � ���������� �����, � bull - ������� ���� ������� ������ �� ������� � ���������� �����\n");

	do
	{
		printf_s("������� ���������� ���� � �����\n");
		scanf_s("%d", &n);
	} 
	while (n < 2 || n > 5);

		while (r > 0)
		{
		r = 0; // r=0 - ����� ��� ��������
			for (i = 0; i < n; i++)
			{
				if (i == (n - 1))
					K[i] = 1 + rand() % 9; // ��� ������ ����� ����� 9 ��������� ����� �� 1 �� 9
				else
					K[i] = rand() % 10; // ��� ��������� ���� ����� 10 ��������� ���� �� 0 �� 9
			}
			for (i = 0; i < n; i++)
				for (m = i + 1; m < n; m++)
				{
					if (K[i] == K[m])
				{
					r = 1; // ������ ���� �������
					break;
				}
			}
		}

			for (i = 0; i < n; i++)
				p = p * 10;

	printf_s("������ ����!\n");

	while (bull != n)
	{
		do
		{
			r = 1; //��� ��������
			printf_s("������� ����� � ���������������� �������\n");
			scanf_s("%d", &z);
				if (z > p - 1)
				{
					printf_s("���� ����� ������, ��� �����\n");
					r = 0; 
				}	
					else if (z < p / 10)
					{
						printf_s("���� ����� ������, ��� �����\n");
						r = 0;
					}
						else
						{ 
							for (i = 0; i < n; i++)
							{
								B[i] = z % 10;
								z = z / 10;
							}
							for (i = 0; i < n; i++)
								for (m = i + 1; m < n; m++)
									if (B[i] == B[m])
									{
										r = 0; // ���� �������, ���� �����������
										break;
									}
						}
		} 
		while (r != 1);
			
			bull = 0;
			cow = 0;
			for (i = 0; i < n; i++)
			{
				for (m = 0; m < n; m++)
				{
					if (B[i] == K[m] && i == m)
						bull++;
						if (B[i] == K[m] && i != m)
							cow++;
				}
			}
				printf_s("cow-%d, bull-%d\n", cow, bull);
	}
	printf_s("������!:)");
	scanf_s("%d", &cow);
}