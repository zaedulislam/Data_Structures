// Check balanced parentheses using Stack

#include<iostream>
#include<stack>
#include<string>
using namespace std;


// Check if parentheses are balanced or not
bool isBalancedParantheses(string expression)
{
	stack<char> stck;
	int expressionLength = expression.length();

	for (int I = 0; I < expressionLength; I++){
		if (expression[I] == '(' || expression[I] == '{' || expression[I] == '[') {
			stck.push(expression[I]);
		}
		else {
			if (stck.empty()) {
				return false;
			}
			
			if (stck.top() == '(' && expression[I] == ')') {
				stck.pop();
			}
			else if (stck.top() == '{' && expression[I] == '}') {
				stck.pop();
			}
			else if (stck.top() == '[' && expression[I] == ']') {
				stck.pop();
			}
			else {
				return false;
			}	
		}
	}

	return stck.empty() ? true : false;
}



int main()
{
	string expression;

	cout << "Enter an expression to check: ";
	cin >> expression;

	if (isBalancedParantheses(expression))
		cout << "Expression is balanced.\n";
	else
		cout << "Expression is not balanced.\n";


	return 0;
}
