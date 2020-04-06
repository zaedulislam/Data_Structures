// Queue (Using Array).cpp

#include <iostream>
using namespace std;
const int SIZE = 100;
int queue[SIZE], front = -1, rear = -1;




void Enqueue(int value)
{
	if (rear == -1)
		front = 0;

	queue[++rear] = value;
}



void Dequeue()
{
	if (front > rear || front == -1)
	{
		cout << "Queue is empty!\n";
		return;
	}

	front++;
}



void Print()
{
	if (front > rear || front == -1)
	{
		cout << "Queue is empty!\n";
		return;
	}

	int I;
	for (I = front; I <= rear; I++)
		cout << queue[I] << ' ';

	cout << endl;
}



int main()
{
	int I, q, n, type, value;
	cin >> q;
	for (I = 0; I < q; I++)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> value;
			Enqueue(value);
		}
		else if (type == 2)
			Dequeue();
		else
			Print();
	}

	return 0;
}