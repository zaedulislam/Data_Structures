#include<iostream>
#include<string>
#include<stack>
using namespace std;

bool balancedparantheses(string exp) //checks if parentheses are
{                                    //balanced or not
	stack<char> S;
	for (int i = 0; i<exp.length(); i++)
	{
		if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
			S.push(exp[i]);
		else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']')
		{
			if (S.top() == '(' && exp[i] == ')')
				S.pop();
			else if (S.top() == '{' && exp[i] == '}')
				S.pop();
			else if (S.top() == '[' && exp[i] == ']')
				S.pop();
		}
	}
	return S.empty() ? true : false;
}

int main()
{
	string expression;

	cout << "Enter an expression to check: ";
	cin >> expression;

	if (balancedparantheses(expression))
		cout << "Balanced expression \n";

	else
		cout << "Expression is not balanced \n";
}
