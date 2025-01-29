#include <iostream>
#include <memory>
#include <vector> 
using namespace std;

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
    cout << "Cuantas calificaciones desea ingresar: " << endl;
    cin >> n;

    std::vector<std::unique_ptr<int>> vec(n);

    int numero = 0;
    for (int i = 0; i < n; i++) {
        cout << "Ingresa calificación: " << endl;
        cin >> numero;
        vec[i] = make_unique<int>(numero); 
    }
    int resultado = FuncionSumar(vec);
    float promedio = resultado/vec.size();
    cout << "Promedio es: " << promedio << endl;
    

    return 0;
}
