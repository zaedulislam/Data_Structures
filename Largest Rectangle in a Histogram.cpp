/*
Maximum Rectangular Area/Largest Rectangle in a Histogram.cpp

Given an array representing height of bar in bar graph, find max histogram area in the bar graph. Max histogram
will be max rectangular area in the graph.

* Maintain a stack

* If stack is empty or value at index of stack is less than or equal to value at current  index, push this into stack.
* Otherwise keep removing values from stack till value at index at top of stack is less than value at current index.
While removing value from stack calculate area
if stack is empty, it means that till this point value just removed has to be smallest element so area = ar[top] * I
if stack is not empty then this value at index top is less than or equal to everything from stack top + 1 till I. So
area will area = ar[top] * (I - S.top() - 1);

Finally maxArea is area if area is greater than maxArea.

Time complexity is O(n)
Space complexity is O(n)
 */

#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
#define NL '\n'


const int SIZE = 1e5;
int ar[SIZE];
stack<int> S;

int FindMaxRectangle(int n)
{
	int I = 0, area = 0, maxArea = 0, top;
	while (I < n)
	{
		// If this bar is higher than the bar on top stack, push it to stack.
		if (S.empty() || ar[S.top()] <= ar[I])
		{
			S.push(I);
			I++;
		}
		/*
		If this bar is lower than top of stack, then calculate area of rectangle with stack top as the smallest
		(or minimum height) bar. 'I' is 'right index' for the top and element before top in stack is 'left index'
		*/
		else
		{
			// store the top index
			top = S.top();
			S.pop();

			if (S.empty())
				area = ar[top] * I;
			else
				area = ar[top] * (I - S.top() - 1);

			if (area > maxArea)
				maxArea = area;
		}

	}

	// Now pop the remaining bars from stack and calculate area with every popped bar as the smallest bar.
	while (!S.empty())
	{
		// store the top index
		top = S.top();
		S.pop();

		if (S.empty())
			area = ar[top] * I;
		else
			area = ar[top] * (I - S.top() - 1);

		if (area > maxArea)
			maxArea = area;
	}

	return maxArea;
}


int main()
{
	int tcases, I, J, K, N, n, m, cnt = 0, len;
	cin >> n;
	for (I = 0; I < n; I++)
		cin >> ar[I];

	cout << FindMaxRectangle(n) << NL;

	return 0;
}
