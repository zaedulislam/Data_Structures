// Stack (Using Static Array).cpp

#include<iostream>
using namespace std;

const int MAXSIZE = 10;
int stack[MAXSIZE], top = -1;




bool IsEmpty()
{
	if (top == -1)
		return true;

	return false;
}



void Push(int n)
{
	if (top == MAXSIZE)
	{
		cout << "Stack Overflow\n";
		return;
	}
		
	stack[++top] = n;
}



void Pop()
{
	if (IsEmpty())
	{
		cout << "Stack is Empty\n";
		return;
	}

	top--;
}



void Print()
{
	if (IsEmpty())
	{
		cout << "Stack is Empty\n";
		return;
	}

	for (int I = top; I >= 0; I--)
		cout << stack[I] << ' ';
	cout << '\n';
}



int main()
{
	int n, q, type;

	cin >> q;
	for (int I = 0; I < q; I++)
	{
		cin >> type;

		if (type == 1)
		{
			cin >> n;
			Push(n);
		}
		else if (type == 2)
			Pop();
		else if (type == 3)
			Print();
	}

	return 0;
}
