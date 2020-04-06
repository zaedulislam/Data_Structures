/* Queue using Stacks (Method 2 - By making Dequeue operation costly).cpp
In this method, in en-queue operation, the new element is entered at the top of stack1. In de-queue operation, if stack2
is empty then all the elements are moved to stack2 and finally top of stack2 is returned.
Method 2 is definitely better than method 1.
Method 1 moves all the elements twice in Enqueue operation, while method 2 (in Dequeue operation) moves the elements
once and moves elements only if stack2 empty.
*/

#include <iostream>
#include <stack>
using namespace std;




struct Queue 
{
	stack<int> stack1, stack2;

	// Enqueue an item to the queue 
	// Here time complexity will be O(1)
	void Enqueue(int x)
	{
		// Push item into the first stack 
		stack1.push(x);
	}

	// Dequeue an item from the queue
	// Here time complexity will be O(n)
	int Dequeue()
	{
		// if both stacks are empty 
		if (stack1.empty() && stack2.empty()) {
			cout << "Queue is empty\n";
			exit(0);
		}

		// if stack2 is empty, move elements from stack1 
		if (stack2.empty())
		{
			while (!stack1.empty()) 
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}

		// return the top item from stack2 
		int x = stack2.top();
		stack2.pop();
		return x;

	}
};



int main()
{
	Queue Q;

	Q.Enqueue(1);
	Q.Enqueue(2);
	Q.Enqueue(3);

	cout << Q.Dequeue() << '\n';
	cout << Q.Dequeue() << '\n';
	cout << Q.Dequeue() << '\n';

	return 0;
}
