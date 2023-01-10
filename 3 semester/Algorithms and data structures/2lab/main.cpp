 #include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std;
bool IsOperator(char s)
{
	string znaki = "+-*/()";

	if (znaki.find(s) != -1)
		return true;
	else
		return false;
}
bool IsNumber(char s)
{
	string number = "1234567890";

	if (number.find(s) != -1)
		return true;
	else
		return false;
}
bool IsDelimeter(char s)
{
	string d1 = " =";

	if (d1.find(s) != -1)
		return true;
	else
		return false;
}
int GetPrioritet(char s)
{
	switch (s)
	{
	case '(': return 0;
	case ')': return 1;
	case '+': return 2;
	case '-': return 3;
	case '*': return 4;
	case '/': return 5;
	default:return 6;
	}
}


string Preobras(string s)
{
	string time_str = "";
	stack<char> *st=new stack<char>;

	for (int i = 0; i < s.size(); i++)
	{
		if (IsDelimeter(s[i]))
			continue;

		if (IsNumber(s[i]))
		{
			while (!IsDelimeter(s[i]) && !IsOperator(s[i]))
			{
				time_str += s[i];
				i++;

				if (i == s.size())
					break;
			}
			time_str += " ";
			i--;
		}
		if (IsOperator(s[i]))
		{
			if (s[i] == '(')
				st->push(s[i]);

			else if (s[i] == ')')
			{
				char c = st->top();
				st->pop();
				while (c != '(')
				{
					time_str += c;
					c = st->top();
					st->pop();
				}
			}

			else
			{
				if (!st->empty() && GetPrioritet(s[i]) <= GetPrioritet(st->top()))
				{
					time_str += st->top();
					st->pop();
				}
				st->push(s[i]);
			}
		}

	}
	while (!st->empty())
	{
		time_str += st->top();
		st->pop();
	}
	return time_str;

}
double Counting(string s)
{
	double result = 0;
	stack<double> *temp=new stack<double>;

	for (int i = 0; i < s.size(); i++)
	{
		if (IsDelimeter(s[i]))
			continue;

		if (IsNumber(s[i]))
		{
			string a = "";
			while (!IsDelimeter(s[i]) && !IsOperator(s[i]))
			{
				a += s[i];
				i++;
				if (i == s.size())
					break;
			}
			temp->push(stod(a));
			i--;
		}
		else if (IsOperator(s[i]))
		{
			double a = temp->top(); temp->pop();
			double b= temp->top(); temp->pop();
			if (s[i] == '/' && a == 0)
			{
				cout << "No del on 0!!" << endl;
				return -1;
			}
			switch (s[i])
			{
				case '+': result = b + a; break;
				case '-': result = b - a; break;
				case '*': result = b * a; break;
				case '/': result = b / a; break;
			}
			temp->push(result);
		}
	}
	
	return temp->top();

}

double Calculator(string s)
{
	string out = Preobras(s);
	double result = Counting(out);
	return result;
}

int main()
{
	setlocale(LC_ALL,"RUS");
	string vhod;
	cout << "Введите выражение: \n";
	getline(cin, vhod);
	cout << Calculator(vhod) << endl;
}