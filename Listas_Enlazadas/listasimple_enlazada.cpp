#include <iostream>
#include <string>
using namespace std;
struct Nodo
{
    int id_cliente;
    string nombreCliente;
    int edad;
    Nodo* ptr_next;
};

void insertarInicio(Nodo *& cabeza, int tam)
{
    string nombre;
    int age;
    int id;
    for(int i =0; i<tam; i++)
    {
        Nodo *NuevoNodo = new Nodo();
        cout<<"IDCLiente: "<<endl;
        cin>>id;
        NuevoNodo->id_cliente = id;
        cout<<"Ingrese su nombre: "<<endl;
        cin.ignore();
        getline(cin, nombre);
        NuevoNodo->nombreCliente = nombre;
        cout<<"Ingrese su edad: "<<endl;
        cin>>age;
        NuevoNodo->edad = age;
        NuevoNodo->ptr_next = cabeza;
        cabeza = NuevoNodo;
        
    }
}

void imprimirLista(Nodo *head)
{
    Nodo * temp = head;

    while (temp != nullptr)
    {
        cout<<"\t*****************************************************\n";
        cout<<"\tNombre del cliente: "<<temp->nombreCliente<<endl;
        cout<<"\tEdad: "<<temp->edad<<endl;
        temp= temp->ptr_next;
    }
    
}
Nodo *BuscarElemento(Nodo *head, int id){
    Nodo *temp= head;
    while (temp != nullptr)
    {
        if(temp->id_cliente == id){
            return temp;
        }
        temp = temp->ptr_next;
    }
    return nullptr;
    
}

void eliminar(Nodo *&cabeza, int id){
    if(cabeza == nullptr)
    {
        return;
    }
    if(cabeza->id_cliente== id){
        Nodo *temp= cabeza;
        cabeza = cabeza->ptr_next;
        delete temp;
    }else{
        Nodo *actual = cabeza;
        Nodo* anterior = nullptr;
        while (actual != nullptr && actual->id_cliente != id)
        {
            anterior = actual;
            actual = actual->ptr_next;
        }
        if(actual != nullptr){
            anterior->ptr_next= actual->ptr_next;
            delete actual;
        }
        
    }
    
}
int main()
{   
    string *nombre;
    int *edad;
    Nodo *head = nullptr;
    int n;
    int id;
    
    cout<<"Ingrese cuantos clientes va a registrar: "<<endl;
    cin>>n;
    insertarInicio(head, n);
    imprimirLista(head);
    cout<<"Ingrese el id para buscar:"<<endl;
    cin>>id;
    Nodo * resultado = BuscarElemento(head, id);
    if(resultado != nullptr){
        cout<<"\nSe encontró el elemento:"<<endl;
        cout<<"Nombre:"<<resultado->nombreCliente<<endl;
        cout<<"Edad:"<<resultado->edad<<endl;
    }else{
        cout<<"No se encontro el cliente";
    }
    cout<<"Ingrese el id a eliminar:";
    cin>>id;
    eliminar(head, id);
    imprimirLista(head);
    Nodo *temp;
    while (head != nullptr) {
    temp = head;
    head = head->ptr_next;
    delete temp;
}
    return 0;
}