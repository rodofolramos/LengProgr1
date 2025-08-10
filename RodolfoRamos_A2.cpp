#include <iostream>
using namespace std;

int main(){
    float num1, num2;

    cout << "Bienvenido, este programa usa dos numeros para realizar" << endl;
    cout << "Suma, resta, multiplicacion y division" << endl;

    cout << "Favor de escribir el primer numero (dividendo): ";
    cin >> num1;

    cout << "Favor de escribir el segundo numero (divisor): ";
    cin >> num2;

    float suma = num1 + num2;
    float resta = num1 - num2;
    float multiplicacion = num1 * num2;
    float division = num1 / num2;

    cout << "La suma es: " << suma << endl;
    cout << "La resta es: " << resta << endl;
    cout << "La multiplicacion es: " << multiplicacion << endl;
    cout << "La division es: " << division << endl;

    cout << "Gracias por usar el programa, bonito dia!" << endl;

    return 0;
}