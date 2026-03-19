#include <iostream>
#include <random>
#include "Problemas.h"

using namespace std;


/*Problema 2. Elabore un programa que genere un arreglo de 200 letras mayúsculas aleatorias, imprima este arreglo
y luego imprima cuantas veces se repite cada letra en el arreglo.
Ejemplo: supóngase que se genera el arreglo de 10 elementos: ABARSECAAB. El programa debe imprimir: ABARSECAAB
A: 4
B: 2
C: 1
Y así sucesivamente.*/
void Problema2() {
    const int TAM = 200;

    char* arreglo = new char[TAM];

    // Generar numero aleatorio
    random_device rd;              // semilla
    mt19937 gen(rd());             // generador
    uniform_int_distribution<> dist(0, 25); // rango 0-25

    // Generar letras aleatorias (A-Z)
    for (int i = 0; i < TAM; i++) {
        *(arreglo + i) = 'A' + dist(gen);
    }

    cout << "Arreglo generado:\n";
    for (int i = 0; i < TAM; i++) {
        cout << *(arreglo + i);
    }
    cout << endl << endl;

    // Contar repeticiones
    int* contador = new int[26];

    // Inicializar en 0
    for (int i = 0; i < 26; i++) {
        *(contador + i) = 0;
    }

    // Contar letras
    for (int i = 0; i < TAM; i++) {
        int indice = *(arreglo + i) - 'A';
        (*(contador + indice))++;
    }

    // Mostrar resultados
    cout << "Frecuencia de letras:\n";
    for (int i = 0; i < 26; i++) {
        cout << char('A' + i) << ": " << *(contador + i) << endl;
    }

    // Liberar memoria
    delete[] arreglo;
    delete[] contador;
}




/*Problema 4. Haga una función que reciba una cadena de caracteres numéricos, la convierta a un número entero
y retorne dicho número. Escriba un programa de prueba.
Ejemplo: si recibe la cadena “123”, debe retornar un int con valor 123*/

// Función que convierte la cadena a entero
int convertirCadenaEntero(const char* cadena) {
    int resultado = 0;

    // Recorremos la cadena hasta el '\0'-> nulo
    while (*cadena != '\0') {
        resultado = resultado * 10 + (*cadena - '0');
        cadena++; // avanzar el puntero
    }

    return resultado;
}

// Función del problema
void Problema4() {
    char cadena[100];

    cout << "Ingrese una cadena numerica: ";
    cin >> cadena;

    int numero = convertirCadenaEntero(cadena);

    cout << "Numero convertido: " << numero << endl;

}
/*Problema 6. Escriba un programa que reciba una cadena de caracteres y cambie las letras minúsculas por mayúsculas, los demás caracteres no deben ser alterados.
    Ejemplo: se recibe Man-zana debe mostrar MAN-ZANA.
    Nota: la salida del programa debe ser: Original: Man-zana. En mayuscula: MAN-ZANA.*/

    /*Problema 6...*/

// Función que convierte minúsculas a mayúsculas usando punteros
void convertirMayusculas(char* cadena) {
    while (*cadena != '\0') {
        if (*cadena >= 'a' && *cadena <= 'z') {
            *cadena = *cadena - ('a' - 'A');
        }
        cadena++;
    }
}

//Funcion del problema

void Problema6() {
    char* entrada = new char[100];
    char* salida = new char[100];

    cout << "Ingrese una cadena de caracteres: ";
    cin.ignore(1000, '\n');
    cin.getline(entrada, 100);

    char* pEntrada = entrada;
    char* pSalida = salida;

    while (*pEntrada != '\0') {

        if (*pEntrada >= 'a' && *pEntrada <= 'z') {
            *pSalida = *pEntrada - ('a' - 'A');
        } else {
            *pSalida = *pEntrada;
        }

        pEntrada++;
        pSalida++;
    }

    *pSalida = '\0';

    cout << "Original: " << entrada
         << ". En mayuscula: " << salida << "." << endl;

    delete[] entrada;
    delete[] salida;
}


/*Problema 8. Escriba un programa que reciba una cadena de caracteres y separe los números del resto de caracteres,
generando una cadena que no tiene números y otra con los números que había en la cadena original.
4
Ejemplo: Si se recibe abc54rst el programa debe imprimir las cadenas: abcrst y 54.
Nota: la salida del programa debe ser:
Original: abc54rst.
Texto: abcrst. Numero: 54.*/

void Problema8() {
    char* entrada = new char[100];
    char* texto = new char[100];
    char* numeros = new char[100];

    cout << "Ingrese una cadena: ";
    cin.ignore(1000, '\n');
    cin.getline(entrada, 100);

    char* pEntrada = entrada;
    char* pTexto = texto;
    char* pNumeros = numeros;

    while (*pEntrada != '\0') {

        // Si es número
        if (*pEntrada >= '0' && *pEntrada <= '9') {
            *pNumeros = *pEntrada;
            pNumeros++;
        }
        // Si no es número
        else {
            *pTexto = *pEntrada;
            pTexto++;
        }

        pEntrada++;
    }

    // Cerrar ambas cadenas
    *pTexto = '\0';
    *pNumeros = '\0';

    cout << "Original: " << entrada << "." << endl;
    cout << "Texto: " << texto << ". Numero: " << numeros << "." << endl;

    // Liberar memoria
    delete[] entrada;
    delete[] texto;
    delete[] numeros;
}


/*Problema 10. Escribir un programa que permita convertir un número en el sistema romano al sistema arábigo
usado actualmente. A continuación se encuentran los caracteres usados en el sistema romano y su equivalente arábigo:
M: 1000
D: 500
C: 100
L: 50
X: 10
V: 5
I: 1
Los números romanos se forman usando estos caracteres en base a dos reglas:
Si un carácter esta seguido por uno de igual o menor valor, su valor se suma al total.
Si un carácter esta seguido por uno de mayor valor, su valor se resta del total.
Ejemplo: CC=200, CD=400, DC=600, DCLXVI=666, CLXXIV=174.
Nota: la salida del programa debe ser:
El número ingresado fue: DCLXVI
Que corresponde a: 666.
Realice una versión en Arduino de este programa (en un Arduino físico o Tinkercad). Los datos deben ser ingresados
con la ayuda del serial. Use el monitor serial de Arduino o Tinkercad para ingresar los valores necesarios e imprimir.*/


// Conviertir un carácter romano a su valor
int valorRomano(char c) {
if (c >= 'a' && c <= 'z') {
        c = c - ('a' - 'A');
}
    switch(c) {
        case 'M': return 1000;
        case 'D': return 500;
        case 'C': return 100;
        case 'L': return 50;
        case 'X': return 10;
        case 'V': return 5;
        case 'I': return 1;
        default: return 0;
    }
}


int romanoAEntero(const char* romano) {
    int resultado = 0;

    while (*romano != '\0') {

        int actual = valorRomano(*romano);
        int siguiente = valorRomano(*(romano + 1));

        if (actual < siguiente) {
            resultado -= actual;
        } else {
            resultado += actual;
        }

        romano++;
    }

    return resultado;
}

//Funcion problema

void Problema10() {
    char romano[100];

    cout << "Ingrese numero romano: ";
    cin.ignore(1000, '\n');
    cin.getline(romano, 100);

    int numero = romanoAEntero(romano);

    cout << "El numero ingresado fue: " << romano << endl;
    cout << "Que corresponde a: " << numero << "." << endl;
}
