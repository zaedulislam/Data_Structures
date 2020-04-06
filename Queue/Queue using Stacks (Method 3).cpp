/* Queue using Stacks (Method 3 -  using Function Call Stack).cpp
Queue can also be implemented using one user stack and one Function Call Stack. Below is modified
Method 2 where recursion (or Function Call Stack) is used to implement queue using only one user 
defined stack.
*/

#include <iostream>
#include <stack>
using namespace std;




struct Queue 
{
	stack<int> stack1;

	// Enqueue an item to the queue 
	void Enqueue(int x)
	{
		stack1.push(x);
	}

	// Dequeue an item from the queue 
	int Dequeue()
	{
		if (stack1.empty()) 
		{
			cout << "Queue is empty";
			exit(0);
		}

		// pop an item from the stack 
		int x = stack1.top();
		stack1.pop();

		// if stack becomes empty, return the popped item 
		if (stack1.empty())
			return x;

		// recursive call 
		int item = Dequeue();

		// push popped item back to the stack 
		stack1.push(x);

		// return the result of Dequeue() call 
		return item;
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
