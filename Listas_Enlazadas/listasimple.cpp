#include <iostream>
#include <string>
using namespace std;
struct Direccion{
    string calle;
    int numeroCasa;
    int codigoPostal;
    Direccion *ptr_next;
};
void insertarInicio(Direccion *& head, std::string calle, int numcasa, int cp){
    Direccion *NuevoNodo = new Direccion();
    NuevoNodo->calle = calle;
    NuevoNodo->numeroCasa = numcasa;
    NuevoNodo->codigoPostal= cp;
    NuevoNodo->ptr_next = head;
    head = NuevoNodo;
}
void imprimirLista(Direccion *head)
{
    Direccion *temp = head;
    while (temp != nullptr)
    {
        cout<<"********************************************\n\n";
        cout<<"Nombre calle: "<<temp->calle<<endl;
        cout<<"Numero casa: "<<temp->numeroCasa<<endl;
        cout<<"Codigo postal: "<<temp->codigoPostal<<endl;
        temp = temp->ptr_next;
    }
    
}
void liberarMemoria(Direccion *&head) {
    while (head != nullptr) {
        Direccion *temp = head;
        head = head->ptr_next;
        delete temp;
    }
}
int main()
{
    string nombrecalle = "Otranto";
    Direccion *head = nullptr;
    insertarInicio(head, nombrecalle, 278, 9000);
    insertarInicio(head, nombrecalle, 288, 870);
    insertarInicio(head, nombrecalle, 278, 9000);
    insertarInicio(head, nombrecalle, 278, 9000);
    insertarInicio(head, nombrecalle, 278, 9000);
    insertarInicio(head, nombrecalle, 278, 9000);

    imprimirLista(head);
    liberarMemoria(head);
    return 0;
}