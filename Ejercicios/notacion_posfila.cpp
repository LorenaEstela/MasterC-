#include <iostream>
#include <stack>
#include <cctype>           
using namespace std;

int main()
{
    string operacion = "889*+";
    stack<int> operando;

    for(char caracter: operacion)
    {
        
        if(isdigit(caracter)){
            operando.push(caracter -'0');
        }
        else{
            int a = operando.top();
            operando.pop();
            int b= operando.top();
            operando.pop();
            int resultado;
            switch (caracter)
            {
            case '*':
                resultado = a*b;
                break;
            case '+':
                resultado = a+b;
                break;
            case '-':
                resultado = a-b;
                break;
            default:
                break;
            }
            operando.push(resultado);
        }
    }
    cout<<operando.top();
    return 0;
}
