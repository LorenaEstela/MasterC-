#include <iostream>
#include <memory>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;

// Excepción personalizada para manejar entradas no enteras
class InputError : public std::exception {
public:
    const char* what() const noexcept override {
        return "Error: Se esperaba un número entero.";
    }
};

int FuncionSumar(const std::vector<std::unique_ptr<int>>& vec) {
    int suma = 0;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i]) {
            suma += *vec[i];
        }
    }
    return suma;
}

int main() {
    int n;
    cout << "¿Cuántas calificaciones desea ingresar?: " << endl;
    cin >> n;

    // Creamos un vector de punteros únicos para almacenar las calificaciones
    std::vector<std::unique_ptr<int>> vec(n);

    int numero = 0;
    for (int i = 0; i < n; i++) {
        while (true) {  
            try {
                cout << "Ingresa calificación #" << i + 1 << ": " << endl;
                cin >> numero;

                if (cin.fail()) {
                    throw InputError();  // Si falla la entrada, lanzamos una excepción
                }

                vec[i] = make_unique<int>(numero);
                break;  
            } catch (const InputError& e) {
                // Capturamos la excepción y mostramos el mensaje
                cout << e.what() << endl;
                cin.clear();  // Limpiamos el estado de error
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            }
        }
    }

    // Calculamos la suma y el promedio
    int resultado = FuncionSumar(vec);
    float promedio = static_cast<float>(resultado) / vec.size(); 
    cout << "El promedio es: " << promedio << endl;

    return 0;
}
