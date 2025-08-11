/******************************************************************************
Codigo que genera el RFC de una persona
Autor: Rodolfo Ramos
Fecha: 10/08/2025
*******************************************************************************/
#include <iostream>
#include <vector>
#include <string>
#include <cctype>  //para usar toupper, convierte en mayus cada caracter
#include <algorithm> //para usar algoritmo de transform, convierte en mayus las letras de una cadena

//using namespace std;
//Diccionario de palabras NO permitidas
const std::vector<std::string> palabrasProhibidas = {
    "PENE", "CACA", "PUTO", "MAMO", "CULO", "QULO", "TETA", "PEDO", "JOTO",
    "VERG", "KAKA", "CAGO", "FETO", "PUTA", "RUIN", "COGE", "COJE", "KULO",
    "MION", "PITO", "LOCO", "VAGA", "SENO", "CAGA"
};

// Verificar y modificar palabras prohibdas del Diccionario (segun renapo es la segunda letra, no la ultima como se indico en clase)
std::string corregirRFC(const std::string& rfc) {
    for (const std::string& palabra : palabrasProhibidas) {
        if (rfc == palabra) {
            return rfc.substr(0,1) + "X" + rfc.substr(2,3); // Reemplaza la segunda letra por 'X'
        }
    }
    return rfc;
}

// Funcion para obtener la primera vocal interna de una cadena
char obtenerPrimeraVocalInterna(const std::string& str) {
    for (size_t i =1; i < str.length(); ++i) {
        char c = str[i];
        if ( c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
        return c;
    }
    return 'X'; // Si no encuentra ninguna vocal interna, se usa una X
}

// Funcion principal para calcular rfc
std::string calcularRFC(const std::string& nombre, const std::string& apellidoPaterno, const std::string& apellidoMaterno, const std::string fechaNacimiento) {

    //se declara la variable en donde guardaremos rfc
    std::string rfc;
    
    //se obtiene la letra inicial y la primera vocal interna del apellido apellido Paterno
    char letraInicial = apellidoPaterno[0];
    char PrimeraVocalInterna = obtenerPrimeraVocalInterna(apellidoPaterno);
    
    //Se obtiene la inicial del apellido materno o se usa una 'X' si no existe
    char inicialApellidoMaterno = (!apellidoMaterno.empty()) ? apellidoMaterno[0] : 'X';
    
    //Se obtiene la inicial del primer nombre
    char inicialNombre = nombre[0];
    
    //Se obtiene los dos ultimos digitos del año de fechaNacimiento
    std::string anio = fechaNacimiento.substr(2,2);
    
    //Se obtiene el mes y el dia de fechaNacimiento
    std::string mes = fechaNacimiento.substr(5,2);
    std::string dia = fechaNacimiento.substr(8,2);
    
    //Se construye el RFC sumando el texto de la informacion que se proporciona
    rfc = letraInicial;
    rfc += PrimeraVocalInterna;
    rfc += inicialApellidoMaterno;
    rfc += inicialNombre;
    
    //Aqui se compara con la BD de palabras mal formadas y se sustituye con la letra 'X'
    rfc = corregirRFC(rfc);
    
    //Si hay correccion se continua generando el rfc
    rfc += anio;
    rfc += mes;
    rfc += dia;
    
    return rfc;
}

int main(){
    //Enviar a consola los datos que requiere para solicitar nombre, apellidos, fecha de nacimiento
    std::string nombre, apellidoPaterno, apellidoMaterno, fechaAnio, fechaDia, fechaMes;
    
    std::cout << "Introduce tu nombre: ";
    std::getline(std::cin ,nombre);
    std::transform(nombre.begin(), nombre.end(), nombre.begin(), ::toupper); //convierte en mayusculas todo el nombre
    
    std::cout << "Introduce tu apellido paterno: ";
    std::getline(std::cin ,apellidoPaterno);
    std::transform(apellidoPaterno.begin(), apellidoPaterno.end(), apellidoPaterno.begin(), ::toupper); //convierte en mayusculas todo el apellido paterno
    
    std::cout << "Introduce tu apellido materno(si no cuenta con apellido materno presiona enter): ";
    std::getline(std::cin ,apellidoMaterno);
    std::transform(apellidoMaterno.begin(), apellidoMaterno.end(), apellidoMaterno.begin(), ::toupper); //convierte en mayusculas todo el apellido materno

    std::cout << "Introduce tu ANIO de nacimiento en el siguiente formato (YYYY): "; // se cambia la manera en la que se solicita la fecha para mejor entendimiento de usuario
    std::getline(std::cin ,fechaAnio);
    std::cout << "Introduce tu MES de nacimiento en el siguiente formato (MM): ";
    std::getline(std::cin ,fechaMes);
    std::cout << "Introduce tu DIA de nacimiento en el siguiente formato (DD): ";
    std::getline(std::cin ,fechaDia);

    std::string separador = " ";
    std::string fechaNacimiento = fechaAnio + separador + fechaMes + separador + fechaDia;  // se junta en una sola cadena la fecha para reutilizar el mismo codigo propuesto

    std::string rfc = calcularRFC(nombre, apellidoPaterno, apellidoMaterno, fechaNacimiento);
    std::cout << "RFC: " << rfc << std::endl;
    
    return 0;
}