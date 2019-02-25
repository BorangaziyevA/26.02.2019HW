#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<locale.h>

using namespace std;

void FillArray(int *p, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		*(p + i) = 0 + rand() % 100;
	}

}

void PrintArray(int *p, int n)
{
	for (size_t i = 0; i < n; i++)
	{
		cout << *(p + i) << " ";
	}

}

void Sort(int *p, int n)
{
	for (size_t i = 1; i < n; i++)
	{
		for (size_t j = 1; j < n; j++)
		{
			if (p[j] < p[j-1])
			{
				swap(p[j], p[j - 1]);
			}

		}

	}

}

void Pbol(int *p, int n,int P)
{
	int O = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (P < *(p+i))
		{
			O--;
		}
		else if (P > *(p + i))
		{
			O++;
		}
		else;
	}

	if (O > 0)
	{
		cout << " P > больше чем < P " << endl;
	}
	else if (O < 0)
	{
		cout << " P > меньше чем < P " << endl;
	}
	else cout << " Они равны" << endl;
}

int PandK(int *p, int n, int P,int K)
{
	int sum = 0;

	for (size_t i = 0; i < n; i++)
	{
		if (P < *(p + i) && K >= *(p+i))
		{
			sum = sum + *(p+i);
		}
		
	}
	return sum;
}

int main()

{

	setlocale(LC_ALL, "");
	srand(time(NULL));

	const int n = 10, m = 5;

	int a[n];

	int *p = a;

	int x, y;

	int flag, task;


	do

	{

		cout << "Task Number";

		cin >> task;



		switch (task)

		{

		case 1:
			int P;
			cin >> P;

			FillArray(p, n);
			Sort(p, n);
			PrintArray(p, n);
			Pbol(p, n, P);
		
			break;

		case 2:
			cin >> P;

			int K;
			cin >> K;

			FillArray(p, n);
			Sort(p, n);
			PrintArray(p, n);

			cout << endl << PandK(p, n, P, K) << endl;

			break;

		}



		cout << "Continue?1/0";

		cin >> flag;



	} while (flag == 1);



}