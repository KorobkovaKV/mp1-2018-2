#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h> 
void Name(int l)
{
	if (l == 0)
		printf_s("������\n");
	if (l == 1)
		printf_s("������\n");
	if (l == 2)
		printf_s("�������\n");
	if (l == 3)
		printf_s("���� NESTLE\n");
	if (l == 4)
		printf_s("��������\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int N; //����� ���������
	int sh[5] = { 5831, 5832, 5833, 5834, 5835 }; // ������ ����������
	int k[5] = { 0 }; // ���������� ��������� �������, ������� ����� � ����
	int d[5] = { 70, 60, 180, 100, 200 }; // ���� �� �������(��������)
	int s[5] = { 0 }; // ��� ����� �������� ����������� ���� �� �������, �������� ����������
	int i;
	int r; // radar
	int sale; // ������
	int I; // �����
	int D; // ����������� ���� ��� ������, �������� ����������
	int S; // ������

	printf_s("������� ����� ��������� �� ������������:\n 5831\n 5832\n 5833\n 5834\n 5835\n ������� 0, ����� ������������ ���.\n");
	scanf_s("%d", &N);

	while (N >= 5831 && N <= 5835)
	{
		r = 1; // ��� ������

		if (N == 5831)
		{
			printf_s("������ - 1� - 70�\n");
			printf_s("������� ����������\n");
			scanf_s("%d", &k[0]);
			sale = 1 + rand() % 50;
			printf_s("������ %d\n", sale);
			s[0] = 70 * k[0] - (70 * sale *k[0] / 100);
			printf_s("%d\n", s[0]);

		}

		else if (N == 5832)
		{
			printf_s("������ ������� - 1�� - 60�\n");
			printf_s("������� ����������\n");
			scanf_s("%d", &k[1]);
			sale = 1 + rand() % 50;
			printf_s("������ %d\n", sale);
			s[1] = 60 * k[1] - (60 * sale *k[1] / 100);
			printf_s("%d\n", s[1]);
		}

		else if (N == 5833)
		{
			printf_s("������� - 1��������(1��) - 180�\n");
			printf_s("������� ����������\n");
			scanf_s("%d", &k[2]);
			sale = 1 + rand() % 50;
			printf_s("������ %d\n", sale);
			s[2] = 180 * k[2] - (180 * sale *k[2] / 100);
			printf_s("%d\n", s[2]);
		}

		else if (N == 5834)
		{
			printf_s("���� NESTLE - 1�������� - 100�\n");
			printf_s("������� ����������\n");
			scanf_s("%d", &k[3]);
			sale = 1 + rand() % 50;
			printf_s("������ %d\n", sale);
			s[3] = 100 * k[3] - (100 * sale *k[3] / 100);
			printf_s("%d\n", s[3]);
		}

		else if (N == 5835)
		{
			printf_s("�������� - 4��(��������) - 200�\n");
			printf_s("������� ����������\n");
			scanf_s("%d", &k[4]);
			sale = 1 + rand() % 50;
			printf_s("������ %d\n", sale);
			s[4] = 200 * k[4] - (200 * sale *k[4] / 100);
			printf_s("%d\n", s[4]);
		}
		printf_s("������� ����� ���������\n");
		scanf_s("%d", &N);

		if (N == 0)
			break;
	}

	D = 70 * k[0] + 60 * k[1] + 180 * k[2] + 100 * k[3] + 200 * k[4];
	I = s[0] + s[1] + s[2] + s[3] + s[4]; // �����
	S = D - I;

	// ���
	printf_s("\n\n\n");
	printf_s("��� ���\n");

	for (i = 0; i < 5; i++)
	{
		if (k[i] != 0)
		{
			Name(i);
			printf_s("���� �� ������� %d, �� %d, ���� � ������ ���-�� � ������ %d\n", d[i], k[i], s[i]);
		}
	}
	printf_s("���� ������ � ��� %d\n", S);
	printf_s("����� � ���: %d\n", I);
	printf_s("������� �� �������!\n");
	scanf_s("%d", &N);
}