#include <iostream>
using namespace std;

struct Nodo {
    string calle;
    int numeroCalle;
    int id;
    Nodo* next;
};

struct LinkedList {
    int size;
    Nodo* firstItem;
    Nodo* lastItem;
};

Nodo* getNode() {
    string nombre;
    int numero, id;
    Nodo* nuevoNodo = new Nodo();

    cout << "Ingrese id_cliente: ";
    cin >> id;
    nuevoNodo->id = id;

    cout << "Ingrese nombre de la calle: ";
    cin.ignore();
    getline(cin, nombre);

    cout << "Ingrese numero de Calle: ";
    cin >> numero;

    nuevoNodo->calle = nombre;
    nuevoNodo->numeroCalle = numero;
    nuevoNodo->next = NULL;
    return nuevoNodo;
}

LinkedList* getNewLinkedList() {
    LinkedList* ll = new LinkedList();
    ll->size = 0;
    ll->firstItem = NULL;
    ll->lastItem = NULL;
    return ll;
}

void add(LinkedList* ll, Nodo* node) {
    if (ll->firstItem == NULL) {
        ll->firstItem = node;
    } else {
        ll->lastItem->next = node;
    }
    ll->lastItem = node;
    ll->size++;
}

Nodo* buscar(LinkedList* ll, int id_cliente, int& index) {
    index = 0; // Inicializar el índice en 0

    if (ll->size == 0) {
        cout << "Lista Vacía" << endl;
        return nullptr;
    }

    Nodo* nodoBuscar = ll->firstItem;
    while (nodoBuscar != nullptr) {
        if (nodoBuscar->id == id_cliente) {
            return nodoBuscar; // Se encontró el nodo, retornamos
        }
        nodoBuscar = nodoBuscar->next;
        index++; // Aumentar el índice
    }

    index = -1; // Si no se encontró, devolvemos -1
    return nullptr;
}

void remove(LinkedList* ll, int index) {
    if (ll->size == 0 || index < 0 || index >= ll->size) {
        cout << "Índice fuera de rango o lista vacía." << endl;
        return;
    }

    Nodo* aux;
    if (index == 0) { // Si eliminamos el primer nodo
        aux = ll->firstItem;
        ll->firstItem = ll->firstItem->next;
        if (ll->firstItem == NULL) {
            ll->lastItem = NULL; // Lista vacía después de eliminar
        }
    } else {
        Nodo* listExplorer = ll->firstItem;
        for (int i = 0; i < index - 1; i++) {
            listExplorer = listExplorer->next;
        }
        aux = listExplorer->next;
        listExplorer->next = aux->next;
        if (aux == ll->lastItem) {
            ll->lastItem = listExplorer; // Si eliminamos el último nodo
        }
    }

    delete aux;
    ll->size--;
}

void imprimirLista(LinkedList* lista) {
    if (lista->size == 0) {
        cout << "Lista vacía." << endl;
        return;
    }

    Nodo* temp = lista->firstItem;
    cout << "Elementos de la lista:" << endl;
    while (temp != nullptr) {
        cout << "ID: " << temp->id
             << ", Calle: " << temp->calle
             << ", Número: " << temp->numeroCalle << endl;
        temp = temp->next;
    }
}

void freeLinkedList(LinkedList* ll) {
    Nodo* current = ll->firstItem;
    while (current != NULL) {
        Nodo* next = current->next;
        delete current;
        current = next;
    }
    delete ll;
}

int main() {
    int opcion;
    int index;
    LinkedList* LIST = getNewLinkedList();

    cout << "*************MENU*************\n";
    cout << "1. Agregar Cliente\n";
    cout << "2. Buscar Cliente\n";
    cout << "3. Eliminar Cliente\n";
    cout << "4. Mostrar Lista Cliente\n";
    cout << "5. Salir\n";

    cout << "Que operacion desea realizar: seleccionar 1-5" << endl;
    cin >> opcion;

    while (opcion != 5) {
        switch (opcion) {
            case 1: {
                Nodo* nuevoNodo = getNode();
                add(LIST, nuevoNodo);
                break;
            }
            case 2: {
                int id;
                cout << "Ingrese el id a buscar: ";
                cin >> id;
                Nodo* resultado = buscar(LIST, id, index);
                if (resultado != nullptr) {
                    cout << "Valor encontrado: ID = " << resultado->id
                         << ", Calle = " << resultado->calle
                         << ", Número = " << resultado->numeroCalle
                         << ", Índice = " << index << endl;
                } else {
                    cout << "El elemento no se encontró." << endl;
                }
                break;
            }
            case 3: {
                int id;
                cout << "Que id quiere eliminar: ";
                cin >> id;
                Nodo* resultado = buscar(LIST, id, index);
                if (resultado != nullptr) {
                    remove(LIST, index);
                    cout << "Nodo eliminado con éxito." << endl;
                } else {
                    cout << "No se encontró el nodo para eliminar." << endl;
                }
                break;
            }
            case 4: {
                imprimirLista(LIST);
                break;
            }
            default:
                cout << "Opción no válida, intente nuevamente." << endl;
                break;
        }

        cout << "Que operacion desea realizar: seleccionar 1-5" << endl;
        cin >> opcion;
    }

    cout << "Adios" << endl;
    freeLinkedList(LIST);
    return 0;
}
