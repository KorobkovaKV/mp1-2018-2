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
	int i;
	int r; // radar
	int sale; // скидка
	int I; // итого
	int D; // посчитанные цены без скидок, учитывая количество
	int S; // скидка

	printf_s("Введите номер штрихкода из существующих:\n 5831\n 5832\n 5833\n 5834\n 5835\n Введите 0, чтобы сформировать чек.\n");
	scanf_s("%d", &N);

	while (N >= 5831 && N <= 5835)
	{
		r = 1; // все хорошо

		if (N == 5831)
		{
			printf_s("Молоко - 1л - 70р\n");
			printf_s("Введите количество\n");
			scanf_s("%d", &k[0]);
			sale = 1 + rand() % 50;
			printf_s("Скидка %d\n", sale);
			s[0] = 70 * k[0] - (70 * sale *k[0] / 100);
			printf_s("%d\n", s[0]);

		}

		else if (N == 5832)
		{
			printf_s("Киндер сюрприз - 1шт - 60р\n");
			printf_s("Введите количество\n");
			scanf_s("%d", &k[1]);
			sale = 1 + rand() % 50;
			printf_s("Скидка %d\n", sale);
			s[1] = 60 * k[1] - (60 * sale *k[1] / 100);
			printf_s("%d\n", s[1]);
		}

		else if (N == 5833)
		{
			printf_s("Персики - 1упаковка(1кг) - 180р\n");
			printf_s("Введите количество\n");
			scanf_s("%d", &k[2]);
			sale = 1 + rand() % 50;
			printf_s("Скидка %d\n", sale);
			s[2] = 180 * k[2] - (180 * sale *k[2] / 100);
			printf_s("%d\n", s[2]);
		}

		else if (N == 5834)
		{
			printf_s("Каша NESTLE - 1упаковка - 100р\n");
			printf_s("Введите количество\n");
			scanf_s("%d", &k[3]);
			sale = 1 + rand() % 50;
			printf_s("Скидка %d\n", sale);
			s[3] = 100 * k[3] - (100 * sale *k[3] / 100);
			printf_s("%d\n", s[3]);
		}

		else if (N == 5835)
		{
			printf_s("Капкейки - 4шт(упаковка) - 200р\n");
			printf_s("Введите количество\n");
			scanf_s("%d", &k[4]);
			sale = 1 + rand() % 50;
			printf_s("Скидка %d\n", sale);
			s[4] = 200 * k[4] - (200 * sale *k[4] / 100);
			printf_s("%d\n", s[4]);
		}
		printf_s("Введите номер штрихкода\n");
		scanf_s("%d", &N);

		if (N == 0)
			break;
	}

	D = 70 * k[0] + 60 * k[1] + 180 * k[2] + 100 * k[3] + 200 * k[4];
	I = s[0] + s[1] + s[2] + s[3] + s[4]; // Итого
	S = D - I;

	// чек
	printf_s("\n\n\n");
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