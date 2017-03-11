#include "stdafx.h" 
#include <iostream> 
#include <windows.h> 
#include <cmath> 
using namespace std;
class Queue {
	static const int s = 100;
	int *queue;
	int pered, zad;
public:
	Queue();
	void push(int k);
	void ydal();
	friend void out(Queue q);
	int size();
	void pop();
	int front();
	int back();
};

Queue::Queue()
{
	queue = new int[s];
	pered = 0;
	zad = 0;
}

void out(Queue q) {
	for (int i = q.pered + 1; i<q.zad + 1; i++)
	{
		cout << " " << q.queue[i];
	}
}

void Queue::push(int k)
{
	if (zad + 1 == pered || (zad + 1 == s && !pered)) {
		cout << "стек полон\n";
		return;
	}
	zad++;
	if (zad == s) zad = 0;
	queue[zad] = k;
}

void Queue::pop()
{
	if (pered == zad) {
		cout << "стек пуст\n";
		return;
	}
	zad--;
	if (pered == s) pered = 0;

}
void Queue::ydal()
{
	while (pered != zad)
	{
		pered++;
		if (pered == s) pered = 0;
	}

}
int Queue::size()
{
	int s = 0;
	for (int i = pered; i<zad; i++)
	{
		s++;
	}
	return s;
}

int Queue::back()
{
	return queue[zad];
}

int Queue::front()
{
	return queue[pered + 1];
}




int main()
{
	setlocale(LC_ALL, "rus");
	Queue queue1, queue2;
	int i, t = 1;
	for (i = 1; i <= 5; i++) {
		queue1.push(i);
	}
	cout << "Изначальный стек ";
	out(queue1);
	cout << endl;
	while (t != 0)
	{
		cout << "1 - добавить элемент" << endl;
		cout << "2 - удалить элемент" << endl;
		cout << "3 - информация о стеке" << endl;
		cout << "4 - очистка стека" << endl;
		cout << "0 - выход" << endl;
		cout << "выберите нужный вам пункт" << endl;
		cin >> t;
		if (t == 0)
		{
			return 0;
		}
		if (t == 1)
		{
			cout << "введите еще элемент: ";
			int n;
			cin >> n;
			queue1.push(n);
		}
		if (t == 2)
		{
			cout << "удаление элемента";
			queue1.pop();
			cout << endl;
		}
		if (t == 3)
		{
			cout << "стек :" << endl;
			out(queue1);
			cout << endl;
			cout << "Размер стека:" << endl;
			cout << queue1.size();
			cout << endl;
			if (queue1.size() != 0)
			{
				cout << "дальний элемент:" << endl;
				cout << queue1.back();
				cout << endl;
				cout << "ближний элемент" << endl;
				cout << queue1.front();
				cout << endl;
				cout << endl;
			}
			else
			{
				cout << "дальний элемент:" << endl;
				cout << " ";
				cout << endl;
				cout << "ближний элемент" << endl;
				cout << " ";
				cout << endl;
				cout << endl;
			}

		}
		if (t == 4)
		{
			queue1.ydal();
		}
	}
	system("pause");
	return 0;
}