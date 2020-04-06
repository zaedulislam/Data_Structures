// Dynamic Stack

class Stack
{
public:
	Stack();
	void initializeStack();  //Initializes the stack to an empty state.
	bool isEmptyStack() const ;  //Determines whether the stack is empty.
	bool isFullStack() const ;      //Determines whether the stack is full.
	void push();
	//int top();
	void pop();
	void printStack();

private:
	int *arr;
	int top;
	int Size;
	void resizeStack()   // Resize the Stack
	{
		this->Size = this->Size * 2;
		int *newarr = new int[Size];
		cout << "Resizing the Stack to " << Size << "Size." << endl;
		for (int i = 0; i <= this->top; i++)
		{
			newarr[i] = this->arr[i];
		}
		this->arr = newarr;
	}
};

Stack::Stack()
{
	this->top = -1;
	initializeStack();
}

void Stack::initializeStack()
{
	cout << "Give the Input of size of the Array: ";
	cin >> this->Size;
	arr = new int[this->Size];
	cout << "Stack Created. . . " << endl;
}
bool Stack::isFullStack() const
{
	return (this->top == this->Size);
}

bool Stack::isEmptyStack() const
{
	return(this->top == -1);
}

void Stack::push()
{
	int value;
	cout << "Enter value: " << endl;
	for (int i = 0; i < this->Size; i++)
	{
		cin >> value;
		if (!isFullStack())
		{
			this->top++;
			this->arr[top] = value;
			cout << value << " pushed." << endl;
		}
		else
		{
			cout << "Stack Full!!!" << endl;
			resizeStack();
			this->top++;
			this->arr[this->top] = value;
			cout << value << " pushed." << endl;
		}
	}
	
}

void Stack::printStack()
{
	cout << "Current Elements of the Stack: ";
	for (int i = 0; i < top; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
	Stack stck;
	stck.push();
	stck.printStack();

	return 0;
}

>> My Dyanmic Stack [1/02/2015] 
>> Increase the length of the Array

class Stack
{
public:
	Stack();
	void initializeStack();
	bool isFullStack();
	bool isEmptyStack();
	void push(int value);
	void pop();
	void print();
private:
	int *arr;
	int Size;
	int top;
	void ResizeStack()
	{
		cout << "Current Size of the Stack: " << this->Size << endl;
		this->Size = this->Size * 4;
		cout << "Resizing the Stack to Size: " << this->Size << endl;
		int *newarr = new int[this->Size];
		{
			for (int i = 0; i <= top; i++)
			{
				newarr[i] = this->arr[i];
			}
		}
		this->arr = newarr;
	}
};

Stack::Stack()
{
	initializeStack();
	cout << "Initial Size of the Stack: " << this->Size << endl;
	this->top = -1;
}

void Stack::initializeStack()
{
	cout << "Size of the Stack: ";
	cin >> this->Size;
	arr = new int[this->Size];
	cout << "Stack created,initialized." << endl;
}

bool Stack::isFullStack()
{
	return (this->top < this->Size - 1);
}

void Stack::push(int value)
{
	if (isFullStack())
	{
		this->top++;
		arr[this->top] = value;
		cout << value << " Pushed." << endl;
	}
	else
	{
		cout << "Stack Full!!!" << endl;
		ResizeStack();
		arr[this->top] = value;
		cout << value << " Pushed." << endl;
	}
	
}
bool Stack::isEmptyStack()
{
	return(this->top > 0);
}

void Stack::pop()
{
	if (isEmptyStack())
	{
		cout << this->arr[this->top] << " Popped" << endl;
		this->top--;
	}
	else
	{
		cout << "Stack Empty!!!" << endl;
	}
}

void Stack::print()
{
	cout << endl <<"Stack: ";
	for (int i = 0; i <= this->top; i++)
	{
		cout << this->arr[i] << "  ";
	}
	cout << endl << endl;
}

int main()
{
	Stack stck;
	stck.push(89);
	stck.push(15);
	stck.push(76);
	stck.push(123);
	stck.print();
	stck.pop();
	stck.print();
	return 0;
}

// Dynamic Circular Queue

#include<iostream>
using namespace std;


class CQueue
{
public:
	CQueue();
	void initializeQueue();
	bool isEmptyQueue();
	bool isFullQueue();
	void Enqueue(int value);
	void Dequeue();
	void print();
private:
	int *Array;
	int Size;
	int front, rear;
	int next_rear;
	void Resize()
	{
		cout << "Current Size of the Queue: " << this->Size << endl;
		this->Size = this->Size * 2;
		cout << "Resizing the Circular Queue to Size: " << this->Size << endl;
		int *newArray = new int[this->Size];
		int k = 0;
		for (int i = this->front; i != this->rear; i = (i + 1) % Size)
		{
			newArray[k] = Array[i];
			k++;
		}
		this->Array = newArray;
	}
};

CQueue::CQueue()
{
	initializeQueue();
	this->front = 0;
	this->rear = 0;
}

void CQueue::initializeQueue()
{
	cout << "Size of the Queue:";
	cin >> this->Size;
	this->Array = new int[this->Size];
	cout << "Queue Created & Initialized." << endl;
	cout << "Initial Size of the Queue: " << this->Size << endl;
}

//bool CQueue::isFullQueue()
//{
//	return (this->next_rear == this->front);
//}

void CQueue::Enqueue(int value)
{
	next_rear = (this->rear + 1) % this->Size;
	if (this->next_rear == this->front)
	{
		cout << "Queue Full!!!" << endl;
		Resize();
		Array[this->rear] = value;
		cout << value << " Added." << endl;
		this->next_rear = (this->rear + 1) % this->Size;
		this->rear = this->next_rear;

	}
	else
	{
		Array[this->rear] = value;
		this->rear = this->next_rear;
		cout << value << " Added." << endl;
	}
}

void CQueue :: Dequeue()
{
	if (isEmptyQueue())
		{
			cout << "Queue Empty" << endl;
		}
		else
		{
			cout << Array[front] << " dequeued" << endl;
			front = (front + 1) % Size;
		}
	}

bool CQueue::isEmptyQueue()
{
	return (this->front == this->rear);
}

void CQueue::print()
{
	cout << "Circular Queue: ";
	for (int i = this->front; i != this->rear; i = (i + 1) % this->Size)
		cout << Array[i] << " ";
	cout << endl;
}

int main()
{
	CQueue q;
	q.Enqueue(49);
	q.Enqueue(5);
	q.Enqueue(13);
	q.Enqueue(63);
	q.print();
	q.Dequeue();
	q.print();
	return 0;
}

