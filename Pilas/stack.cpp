#include <iostream>
#include <vector>

using namespace std;
struct Stack
{
    int numero;
};
bool isEmpty(const vector<Stack>& pila)
{
    return pila.empty();
}
// Agregar un elemento a la pila
void push(vector<Stack>& lista, int elemento){
    Stack nuevo;
    nuevo.numero = elemento;
    lista.push_back(nuevo);
}

// Eliminar el último elemento de la pila
void eliminar(vector<Stack>& lista)
{
    if(!isEmpty(lista)){
        lista.pop_back();
    }else{
        cout << "No se puede eliminar, la lista está vacía" << endl;
    }
}

// Mostrar el último elemento de la pila
void peek(vector<Stack>& lista)
{
    if(!isEmpty(lista)){
        cout << "El último elemento es: " << lista.back().numero << endl;
    } else {
        cout << "La lista está vacía" << endl;
    }
}
int main()
{
    vector<Stack> lista;  // Aquí se debe usar vector<Stack>, no vector<Stack*>
    
    push(lista, 6);
    push(lista, 10);
    peek(lista);  // Mostrará el último elemento

    eliminar(lista);  // Eliminará el último elemento
    peek(lista);  // Mostrará el nuevo último elemento

    return 0;
}
