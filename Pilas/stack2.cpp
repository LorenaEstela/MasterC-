#include <iostream>

struct Nodo
{
    char valor;
    Nodo * next;
};

struct Pila
{
    int size;
    Nodo *tope;
};
bool isEmpty(Pila *s);
Pila * getNewStack()
{
    Pila *nuevaElemento = new Pila();
    nuevaElemento->size = 0;
    nuevaElemento->tope = nullptr;
    return nuevaElemento;
}

void push(Pila *s, char valor)
{
    if(s)
    {
        Nodo *nuevoNodo = new Nodo();
        nuevoNodo->valor = valor;
        nuevoNodo->next = s->tope;
        s->tope = nuevoNodo;
        s->size++;
        std::cout<<"Nodo agregado con exito a la pila"<<std::endl;
        
    }
}
void mostrarElementosPila(Pila *s)
{   
    if(isEmpty(s))
    {
        std::cout<<"No hay elemetnos. La pila esta vacía";
        return;
    }
    Nodo *actual = s->tope;
    while (actual != nullptr)
    {
        std::cout<<actual->valor<<std::endl;
        actual = actual->next;

    }
    
}
void eliminarTope(Pila *s)
{
    if(isEmpty(s)){
        std::cout<<"Lo siento no se pudo eliminar, la pila esta vacía"<<std::endl;
    }else{
        Nodo * nodo_aux = s->tope;
        s->tope= nodo_aux->next;
        s->size--;
        delete nodo_aux;
        std::cout<<"El tope se eliminó con exito"<<std::endl;
    }
}
bool isEmpty(Pila *s)
{
    if(s->tope == nullptr){
        return true;
    }
    return false;
}
int main()
{
    Pila *nuevaPila = getNewStack();
    push(nuevaPila, 'h');
    push(nuevaPila, 'o');
    push(nuevaPila, 'l');
    push(nuevaPila, 'a');
    mostrarElementosPila(nuevaPila);
    std::cout<<std::endl;
    mostrarElementosPila(nuevaPila);
    return 0;
}