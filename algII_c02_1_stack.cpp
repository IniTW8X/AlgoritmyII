#include <iostream>
#include <string>
using namespace std;
#define MAX 100

class MyStack{
private:
	int top;
	char poleZnaku[MAX];
public:
	MyStack();
	~MyStack();
	void Push(char znak);
	char Pop();
	int IsEmpty();
};

MyStack::MyStack()
{
	top = 0;
}
MyStack::~MyStack()
{
}
void MyStack::Push(char znak)
{
		if (top == MAX)
			cout << "Stack overflow!" << endl;
		else
			poleZnaku[top++] = znak;
}
char MyStack::Pop()
{
	if (top == 0)
		cout << "Stack underflow!" << endl;
	else
		return poleZnaku[(top--) -1];
}
int MyStack::IsEmpty()
{
	if (top == 0)
		return 1;
	else
		return 0;
}

bool TestParentheses(string Text)
{
	MyStack S;
	for (unsigned int i = 0; i < Text.length(); i++)
	{
		switch (Text[i])
		{
		case '(':
			S.Push(')');
			break;
		case '[':
			S.Push(']');
			break;
		case '{':
			S.Push('}');
			break;
		case ')':
		case ']':
		case '}':
			if (!S.IsEmpty())
			{
				char ch = S.Pop();
				if (ch != Text[i])
					return false;
			}
			else
			{
				return false;
			}
			break;
		}
	}
	return S.IsEmpty();
}

int main()
{
	//ULOHA 2 + 3 
	cout << TestParentheses("()");
	cout << TestParentheses(")(");
	cout << TestParentheses("(()())");
	cout << TestParentheses("[()()]");
	cout << TestParentheses("{()()()[()()]}");
	cout << TestParentheses("[()()");
	cout << TestParentheses("[(]()]");
	cout << TestParentheses("[[()]");
	cout << endl;

	//ULOHA 4
	MyStack *stack = new MyStack();
	string s = "";
	cin >> s;
	cout << s;
	for (int i = 0; i < s.length(); i++){
		stack->Push(s[i]);
	}
	while (stack->IsEmpty() != 1) cout << stack->Pop();


	system("pause");
	return 0;

}