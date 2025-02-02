#include <iostream>
#include <stack>
using namespace std;

int main()
{
    string nombre = "()(){}{}[";
    stack<char> pila;

    for(char caracter: nombre)
    {
        if(caracter == '(' || caracter == '[' || caracter == '{')
        {
            pila.push(caracter);
        }
        else
        {
            if(caracter == ')' || caracter == ']' || caracter == '}')
            {
                if(!pila.empty() && 
                    ((pila.top() == '(' && caracter == ')') ||
                     (pila.top() == '[' && caracter == ']') ||
                     (pila.top() == '{' && caracter == '}')))
                {
                    pila.pop();
                }
                else
                {
                    return 0;
                }
            }
        }
    }

    if(pila.empty()){
        cout << "String valido" << endl;
    } else {
        cout << "No valido" << endl;
    }

    return 0;
}
