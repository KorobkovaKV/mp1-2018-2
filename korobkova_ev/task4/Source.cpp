#include <stdio.h> 
#include <time.h> 
#include <stdlib.h> 
#include <locale.h> 
void Name(int l)
{
	if (l == 0)
		printf_s("Молоко\n");
	if (l == 1)
		printf_s("Киндер\n");
	if (l == 2)
		printf_s("Персики\n");
	if (l == 3)
		printf_s("Каша NESTLE\n");
	if (l == 4)
		printf_s("Капкейки\n");
}
int main()
{
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	int N; //номер штрихкода
	int sh[5] = { 5831, 5832, 5833, 5834, 5835 }; // массив штрихкодов
	int k[5] = { 0 }; // количество выбранных товаров, которое будет в чеке
	int d[5] = { 70, 60, 180, 100, 200 }; // цена за единицу(упаковку)
	int s[5] = { 0 }; // тут будут хранится посчитанные цены со скидкой, учитывая количество
	int sale[5] = { 0 };
	int i;
	int r; // radar
	int I=0; // итого
	int S=0; // скидка

	printf_s("Введите номер штрихкода из существующих:\n 5831\n 5832\n 5833\n 5834\n 5835\n Введите 0, чтобы сформировать чек.\n");
	scanf_s("%d", &N);

	for (i = 0; i < 5; i++)
		sale[i] = 1 + rand() % 50;

	while (N >= 5831 && N <= 5835)
	{
		r = 1; // все хорошо

		if (N == sh[0])
		{
			k[0]++;
			printf_s("Молоко - 1л - 70р\n");
			printf_s("Скидка %d\n", sale[0]);
			s[0] = d[0] * k[0] - ( d[0]* sale[0] *k[0] / 100);
			printf_s("Цена с учетом скидки и кол-ва %d\n", s[0]);

		}

		else if (N == sh[1])
		{
			k[1]++;
			printf_s("Киндер сюрприз - 1шт - 60р\n");
			printf_s("Скидка %d\n", sale[1]);
			s[1] = d[1] * k[1] - (d[1] * sale[1] *k[1] / 100);
			printf_s("%d\n", s[1]);
		}

		else if (N == sh[2])
		{
			k[2]++;
			printf_s("Персики - 1упаковка(1кг) - 180р\n");
			printf_s("Скидка %d\n", sale[2]);
			s[2] = d[2] * k[2] - (d[2] * sale[2] *k[2] / 100);
			printf_s("%d\n", s[2]);
		}

		else if (N == sh[3])
		{
			k[3]++;
			printf_s("Каша NESTLE - 1упаковка - 100р\n");
			printf_s("Скидка %d\n", sale[3]);
			s[3] = d[3] * k[3] - (d[3] * sale[3] *k[3] / 100);
			printf_s("%d\n", s[3]);
		}

		else if (N == sh[4])
		{
			k[4]++;
			printf_s("Капкейки - 4шт(упаковка) - 200р\n");
			printf_s("Скидка %d\n", sale[4]);
			s[4] = d[4] * k[4] - (d[4] * sale[4] *k[4] / 100);
			printf_s("%d\n", s[4]);
		}
		printf_s("\n");
		scanf_s("%d", &N);

		if (N == 0)
			break;
	}

	for (i = 0; i < 5; i++)
	{
		S = S + (d[i] * k[i] - s[i]);
		I = I + s[i];
	}

	// чек
	printf_s("\n\n");
	printf_s("ВАШ ЧЕК\n");

	for (i = 0; i < 5; i++)
	{
		if (k[i] != 0)
		{
			Name(i);
			printf_s("цена за единицу %d, шт %d, цена с учетом кол-ва и скидки %d\n", d[i], k[i], s[i]);
		}
	}
	printf_s("ВАША СКИДКА В РУБ %d\n", S);
	printf_s("ИТОГО В РУБ: %d\n", I);
	printf_s("СПАСИБО ЗА ПОКУПКУ!\n");
	scanf_s("%d", &N);
}