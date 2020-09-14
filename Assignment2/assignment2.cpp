#include <iostream>
#include <string>
#include <stack>
using namespace std;

double calculate(char a, double b, double c)
{
    if (a == '+') 
    {
        return b + c;
    }
    else if (a == '-')
    {
        return b - c;
    }
    else if (a == '*')
    {
        return b * c;
    }
    else if (a == '/') 
    {
        return b / c;
    }
}

bool isOperate(char a) 
{
    if (a == '+' | a == '-' | a == '*' | a == '/' | a == '(' | a == ')') 
    {
        return true;
    }
    return false;
}
int priority(char a) 
{
    if (a == '+' | a == '-')
    {
        return 1;
    }
    else if(a == '*' | a == '/')
    {
        return 2;
    }
    return 0;
}

int main()
{
    while (true) 
    {
        string expression;
        getline(cin, expression);
        stack<char> operate;
        stack<double> number;
        string temp = "";
        char a;
        double num;
        double d1 = 0;
        double d2 = 0;
        char b;
        for (int i = 0; i < expression.length(); i++) 
        {
            a = expression[i];
            if (isOperate(a) == false) 
            {
                if (a != ' ')
                {
                    temp = temp.append(1, a);
                }
                if (i == expression.length() - 1) {
                    num = stod(temp);
                    number.push(num);
                    temp = "";
                }
            }
            else 
            {
                if (temp != "")
                {
                    num = stod(temp);
                    number.push(num);
                    temp = "";
                }
                if (operate.empty() | a == '(')
                {
                    operate.push(a);
                }
                else if (a == ')')
                {
                    while (true) {
                        b = operate.top();
                        operate.pop();
                        if (b == '(')
                        {
                            break;
                        }
                        d2 = number.top();
                        number.pop();
                        d1 = number.top();
                        number.pop();
                        number.push(calculate(b, d1, d2));
                    }
                }
                else if(priority(a) <= priority(operate.top()))
                {
                    while (true) 
                    {
                        d2 = number.top();
                        number.pop();
                        d1 = number.top();
                        number.pop();
                        b = operate.top();
                        operate.pop();
                        number.push(calculate(b, d1, d2));
                        if (operate.empty())
                        {
                            operate.push(a);
                            break;
                        }
                        else if (priority(a) > priority(operate.top()))
                        {
                            operate.push(a);
                            break;
                        }
                    }
                    

                }
                else
                {
                    operate.push(a);
                }
            }
        }
        while (true) 
        {
            if (operate.empty() == true)
            {
                break;
            }
            d2 = number.top();
            number.pop();
            d1 = number.top();
            number.pop();
            b = operate.top();
            operate.pop();
            number.push(calculate(b, d1, d2));
        }
        cout << number.top() << endl;
    }
    return 0;
}
