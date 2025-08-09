//Programa para actividad 1 

#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

int main() {
    string input;
    int max_digits = 2; // Define la cantidad máxima de dígitos

    cout << "Ingrese un número (máximo " << max_digits << " dígitos): ";
    cin >> input;

    // Validar la longitud de la cadena
    if (input.length() > max_digits) {
        cout << "Error: Demasiados dígitos." << endl;
        return 1; // Opcional: salir del programa si la entrada es inválida
    }

    // Validar que todos los caracteres sean dígitos (opcional, pero recomendado)
    for (char c : input) {
        if (!isdigit(c)) {
            cout << "Error: La entrada debe ser un número." << endl;
            return 1;
        }
    }
    
    // Convertir la cadena a entero (si es necesario y la validación fue exitosa)
    int numero = stoi(input);

    cout << "Número ingresado: " << numero << endl;
    

    if(numero>=18){
        cout << "Usted es ya está mayorcito." << endl;
    } else {
        cout << "Usted aun está chamaquito."  << endl;
    }

    return 0;
}
