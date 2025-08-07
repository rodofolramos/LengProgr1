//Programa para actividad 1 

#include <iostream>

using namespace std;
int main()

{
    int edad;
    cout << "Ingresa tu edad: ";
    cin >> edad;
    
    if(edad>=18){
        cout << "Usted es ya está mayorcito." << endl;
    } else {
        cout << "Usted aun está chamaquito."  << endl;
    }
    return 0;
    
}