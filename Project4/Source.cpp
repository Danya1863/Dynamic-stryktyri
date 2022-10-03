#include <iostream>
#include <string.h>
#include <windows.h>
using namespace std;

class Queue
{
	char* Wait;
	int MaxQueueLenght;
	int QueueLenght;
public:
	Queue(const char* buf);
	~Queue();
	bool IsEmpty();
	char Extract();
};

Queue::Queue(const char* buf)
{
	MaxQueueLenght = 5;
	Wait = new char[MaxQueueLenght];
	strcpy_s(Wait, 6, buf);
	QueueLenght = 5;
}

bool Queue::IsEmpty()
{
	return QueueLenght == 0;
}

char Queue::Extract()
{
	char temp = Wait[0];
	for (int i = 1; i < QueueLenght; i++)
		Wait[i - 1] = Wait[i];
	Wait[QueueLenght - 1] = temp;
	return temp;
}

Queue::~Queue()
{
	delete[]Wait;
}

int main()
{
	srand(time(0));
	HANDLE h;
	Queue Bar1("DS1l5");
	Queue Bar2("DS1l5");
	Queue Bar3("DS1l5");
	char B1c, B2c, B3c;
	int rand_spin;
	while (true)
	{
		rand_spin = rand() % (10 - 40) + 10;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 0 , 0 };
			c = Bar1.Extract();
			SetConsoleTextAttribute(h, 7);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B1c = c;
			Sleep(100);
		}
		rand_spin = rand() % (10 - 40) + 10;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 5 , 0 };
			c = Bar2.Extract();
			SetConsoleTextAttribute(h, 7);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B2c = c;
			Sleep(100);
		}
		rand_spin = rand() % (10-40) + 10;
		for (int i = 0; i < rand_spin; i++)
		{
			char c;
			h = GetStdHandle(STD_OUTPUT_HANDLE);
			COORD a{ 10 , 0 };
			c = Bar3.Extract();
			SetConsoleTextAttribute(h, 7);
			SetConsoleCursorPosition(h, a);
			cout << c;
			B3c = c;
			Sleep(100);
		}
		cout << endl;
		if (B1c == B2c == B3c)
		{
			if (B1c == 'D')
				cout << "Vi vigrali 50$";
			else if (B1c == 'S')
				cout << "Vi vigrali 100$";
			else if (B1c == '1')
				cout << "Vi vigrali 250$";
			else if (B1c == 'l')
				cout << "Vi vigrali 350$";
			else if (B1c == '5')
				cout << "Vi vigrali 450$";
		}
		else
			cout << "Vi proigrali";
		cout << endl;
		system("pause");
		system("cls");
	}
}