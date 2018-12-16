#include <stdio.h> 
#include <math.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h> 

double myexp(double x, double N, double eps)
{
	//double x; // ���������� 
	//double N; // ����� ��������� 
	int i = 2;
	long double Xn = 1;
	long double result = 1;

	for (i = 2; i <= N; i++)
	{
		Xn = Xn * (x / (i - 1));
		result = result + Xn;
		if (fabs(result - exp(x)) < eps)
			break;
	}
	return result;
}

double mysin(double x, double N, double eps)
{
	//double x; // ���������� 
	//double N; // ����� ��������� 
	int i;
	long double Xn = 1;
	long double result = x;

	for (i = 2; i <= N; i++)
	{
		Xn = Xn * ((x*x*(-1)) / ((2 * i - 1)*(2 * i - 2)));
		result = result + Xn;

		if (fabs(result - sin(x)) < eps)
			break;
	}
	return result;
}

double mycos(double x, double N, double eps)
{
	//double x; // ���������� 
	//double N; // ����� ��������� 
	int i;
	long double Xn = 1;
	long double result = 1;

	for (i = 1; i <= N; i++)
	{
		Xn = Xn * (((x*x)*(-1)) / ((2 * i - 2)*(2 * i - 3)));
		result = result + Xn;

		if (fabs(result - cos(x)) < eps)
			break;
	}
	return result;
}

double mych(double x, double N, double eps)
{
	//double x; // ���������� 
	//double N; // ����� ��������� 
	int i;
	long double Xn = 1;
	long double result = 1;

	for (i = 2; i <= N; i++)
	{
		Xn = Xn * (x / (i - 1));

		if (i % 2 == 1)
		{
			result = result + Xn;
		}

		if (fabs(result - cosh(x)) < eps)
			break;
	}
	return result;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int Re; // Regim 
	int F; // Function 
	long double eps;
	long double x;
	long double N;


	while (1 > 0)
	{
		printf_s("������� �����:\n");
		printf_s("1 ����� - ������������ ������� �� ��������� ����� ���������, �������� ���������� � �������� ��������\n");
		printf_s("2 ����� - �� �������� ���������� ������� �������� ��� ����� ��������� �� 1 �� 25\n");
		printf_s("������� 0, ����� ��������� ������ � ������ ������\n");
		scanf_s("%d", &Re);

		if (Re == 1)
		{
			printf_s("�������� �������\n");
			printf_s("'1' - ����������\n");
			printf_s("'2' - �����\n");
			printf_s("'3' - �������\n");
			printf_s("'4' - ��������������� �������\n");
			printf_s("������� '0', ����� �������� ��������� �������� � ������ ��������\n");
			scanf_s("%d", &F);

			while (2 > 1)
			{
				if (F == 1)
				{
					printf_s("������� ����������\n");
					scanf_s("%lf", &x);
					printf_s("������� ����� ��������� �� 1 �� 1000\n");
					scanf_s("%lf", &N);
					printf_s("������� �������� ���������� >= 0.000001\n");
					scanf_s("%lf", &eps);

					if (eps >= 0.000001 && N >= 1 && N <= 1000)
					{
						myexp(x, N, eps);
						printf_s("��������� �������� ���������� ");
						printf_s("%lf\n", exp(x));
						printf_s("����������� ������ �������� ���������� ");
						printf_s("%lf\n", myexp(x, N, eps));
						printf_s("������� ����� ������� � ��������� ��������� ���������� ");
						printf_s("%lf\n", fabs(myexp(x, N, eps) - exp(x)));
						printf_s("���������� ���������, ������� ���� ��������� ");
						printf_s("%lf\n", N);
					}
					else
					{
						printf_s("�� ����� ������������ ��������");
						break;
					}
				}

				if (F == 2)
				{
					printf_s("������� ���������� � \n");
					scanf_s("%lf", &x);
					printf_s("������� ����� ��������� �� 1 �� 1000\n");
					scanf_s("%lf", &N);
					printf_s("������� �������� ���������� >= 0.000001\n");
					scanf_s("%lf", &eps);

					if (eps >= 0.000001 && N >= 1 && N <= 1000)
					{
						mysin(x, N, eps);
						printf_s("��������� �������� ������ ");
						printf_s("%lf\n", sin(x));
						printf_s("����������� ������ �������� ������ ");
						printf_s("%lf\n", mysin(x, N, eps));
						printf_s("������� ����� ������� � ��������� ��������� ");
						printf_s("%lf\n", fabs(mysin(x, N, eps) - sin(x)));
						printf_s("���������� ���������, ������� ���� ��������� ");
						printf_s("%lf\n", N);

					}
					else
					{
						printf_s("�� ����� ������������ ��������");
						break;

					}

				}

				if (F == 3)
				{
					printf_s("������� ���������� � \n");
					scanf_s("%lf", &x);
					printf_s("������� ����� ��������� �� 1 �� 1000\n");
					scanf_s("%lf", &N);
					printf_s("������� �������� ���������� >= 0.000001\n");
					scanf_s("%lf", &eps);

					if (eps >= 0.000001 && N >= 1 && N <= 1000)
					{
						mycos(x, N, eps);
						printf_s("��������� �������� �������� ");
						printf_s("%lf\n", cos(x));
						printf_s("����������� ������ �������� �������� ");
						printf_s("%lf\n", mycos(x, N, eps));
						printf_s("������� ����� ������� � ��������� ��������� �������� ");
						printf_s("%lf\n", fabs(mycos(x, N, eps) - cos(x)));
						printf_s("���������� ���������, ������� ���� ��������� ");
						printf_s("%lf\n", N);
					}
					else
					{
						printf_s("�� ����� ������������ ��������");
						break;
					}
				}

				if (F == 4)
				{
					printf_s("������� ���������� � \n");
					scanf_s("%lf", &x);
					printf_s("������� ����� ��������� �� 1 �� 1000\n");
					scanf_s("%lf", &N);
					printf_s("������� �������� ���������� >= 0.000001\n");
					scanf_s("%lf", &eps);

					if (eps >= 0.000001 && N >= 1 && N <= 1000)
					{
						mych(x, N, eps);
						printf_s("%lf\n", mych(x, N, eps));
						printf_s("��������� �������� ���������������� �������� ");
						printf_s("%lf\n", cosh(x));
						printf_s("����������� ������ �������� ���������������� �������� ");
						printf_s("%lf\n", mych(x, N, eps));
						printf_s("������� ����� ������� � ��������� ��������� ���������������� �������� ");
						printf_s("%lf\n", fabs(mych(x, N, eps) - cosh(x)));
						printf_s("���������� ���������, ������� ���� ��������� ");
						printf_s("%lf\n", N);
					}
					else
					{
						printf_s("�� ����� ������������ ��������");
						break;
					}


				}

				if (F == 0)
					break;

				else
				{
					printf_s("����� ������� �� ����������!\n\n");
					break;
				}
			}

		}


		if (Re == 2)
		{
			while (3 > 2)
			{
				eps = 0;
				printf_s("�������� �������\n");
				printf_s("'1' - ����������\n");
				printf_s("'2' - �����\n");
				printf_s("'3' - �������\n");
				printf_s("'4' - ��������������� �������\n");
				scanf_s("%d", &F);

				if (F == 1)
				{
					printf_s("������� ����������\n");
					scanf_s("%lf", &x);
					for (N = 1; N <= 25; N++)
					{
						myexp(x, N, eps);
						printf_s("��������� �������� ���������� %lf\n", exp(x));
						printf_s("���������� ��������� %lf\n", N);
						printf_s("����������� �������� %lf\n", myexp(x, N, eps));
						printf_s("������� %lf\n", fabs(myexp(x, N, eps) - exp(x)));
					}
				}
				if (F == 2)
				{
					printf_s("������� ����������\n");
					scanf_s("%lf", &x);
					for (N = 1; N <= 25; N++)
					{
						mysin(x, N, eps);
						printf_s("��������� �������� %lf\n", sin(x));
						printf_s("���������� ��������� %lf\n", N);
						printf_s("����������� �������� %lf\n", mysin(x, N, eps));
						printf_s("������� %lf\n", fabs(mysin(x, N, eps) - sin(x)));
					}
				}
				if (F == 3)
				{
					printf_s("������� ����������\n");
					scanf_s("%lf", &x);
					for (N = 1; N <= 25; N++)
					{
						mycos(x, N, eps);
						printf_s("��������� �������� %lf\n", cos(x));
						printf_s("���������� ��������� %lf\n", N);
						printf_s("����������� �������� %lf\n", mycos(x, N, eps));
						printf_s("������� %lf\n", fabs(mycos(x, N, eps) - cos(x)));
					}

				}
				if (F == 4)
				{
					printf_s("������� ����������\n");
					scanf_s("%lf", &x);
					for (N = 1; N <= 25; N++)
					{
						mych(x, N, eps);
						printf_s("��������� �������� %lf\n", cosh(x));
						printf_s("���������� ��������� %lf\n", N);
						printf_s("����������� �������� %lf\n", mych(x, N, eps));
						printf_s("������� %lf\n", fabs(mych(x, N, eps) - cosh(x)));
					}

				}
				if (F == 0)
					break;
				else
				{
					printf_s("����� ������� �� ����������! \n\n");
					printf_s("�������� �������\n");
					printf_s("'1' - ����������\n");
					printf_s("'2' - �����\n");
					printf_s("'3' - �������\n");
					printf_s("'4' - ��������������� �������\n");
					scanf_s("%d", &F);

					printf_s("������� ����������\n");
					scanf_s("%lf", &x);
				}
			}
		}

		if (Re == 0)
			break;

		else
		{
			printf_s("������� �����:\n");
			printf_s("1 ����� - ������������ ������� �� ��������� ����� ���������, �������� ���������� � �������� ��������\n");
			printf_s("2 ����� - �� �������� ���������� ������� �������� ��� ����� ��������� �� 1 �� 25\n");
			printf_s("������� 0, ����� ��������� ������ � ������ ������\n");
			scanf_s("%d", &Re);
		}
		
	}
	scanf_s("%lf", &eps);
}