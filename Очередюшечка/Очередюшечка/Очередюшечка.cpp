#include "stdafx.h"
#include <iostream> 
using namespace std;

class Ochered {
	static const int SIZE = 100;
	int *queue;
	int head, tail;
public:
	Ochered();
	void push(int num);
	friend void out(Ochered q);
	int size();
	void pop();
	int front();
	int back();
};     
Ochered::Ochered()
{
	queue = new int[SIZE];
	head = tail = 0;
}
void out(Ochered q) {
	for (int i = q.head + 1; i<q.tail + 1; i++)
	{
		cout << " " << q.queue[i];
	}
}
void Ochered::push(int num)
{
	if (tail + 1 == head || (tail + 1 == SIZE && !head)) {
		cout << "очередь полна\n";
		return;
	}
	tail++;
	if (tail == SIZE) tail = 0;
	queue[tail] = num;
}
void Ochered::pop()
{
	if (head == tail) {
		cout << "очередь пуста\n";
		return;
	}
	head++;
	if (head == SIZE) head = 0;

}
int Ochered::size()
{
	int s = 0;
	for (int i = head; i<tail; i++)
	{
		s++;
	}
	return s;
}
int Ochered::back()
{
	return queue[tail];
}
int Ochered::front()
{
	return queue[head + 1];
}
int main()
{
	setlocale(LC_ALL, "russian");
	Ochered queue1, queue2;
	int i;
	for (i = 1; i <= 5; i++) {
		queue1.push(i);
	}
	cout << "Изначальная очередь ";
	out(queue1);
	cout << "\nвведите еще элемент: ";
	int n;
	cin >> n;
	queue1.push(n);
	cout << "теперь очередь имеет следующий вид" << endl;
	out(queue1);
	cout << "\nРазмер очереди:" << endl;
	cout << queue1.size();
	cout << "\nдальний элемент:" << endl;
	cout << queue1.back();
	cout << "\nближний элемент" << endl;
	cout << queue1.front();
	cout << "\nудаление элемента";
	queue1.pop();
	cout << "\nтекущие данные";
	out(queue1);
	cout << "\nеще одно добавление элемента";
	queue1.push(n);
	out(queue1);
	cout << endl;
	system("pause");
	return 0;
}
