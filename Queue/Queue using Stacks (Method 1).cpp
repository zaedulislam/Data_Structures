/* Queue using Stacks (Method 1 - By making Enqueue operation costly).cpp
This method makes sure that oldest entered element is always at the top of stack 1, so that deQueue operation 
just pops from stack1. To put the element at top of stack1, stack2 is used.
*/

#include <iostream>
#include <stack>
using namespace std;




struct Queue
{
	stack<int> stack1, stack2;

	// Here time complexity will be O(n)
	void Enqueue(int x)
	{
		// Move all elements from stack1 to stack2 
		while (!stack1.empty())
		{
			stack2.push(stack1.top());
			stack1.pop();
		}

		// Push item into stack1
		stack1.push(x);

		// Push everything back to stack1 
		while (!stack2.empty())
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}

	// Here time complexity will be O(1)
	int Dequeue()
	{
		// if first stack is empty 
		if (stack1.empty())
		{
			cout << "Queue is Empty\n";
			exit(0);
		}

		int x = stack1.top();
		stack1.pop();
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