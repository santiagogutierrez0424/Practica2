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
            *pSalida = *pEntrada - (32);
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


/*Problema 12. Un cuadrado mágico es una matriz de números enteros sin repetir, en la que la suma de los números
en cada columna, cada fila y cada diagonal principal tienen como resultado la misma constante. Escriba un programa
que permita al usuario ingresar una matriz cuadrada, imprima la matriz y verifique si la matriz es un cuadrado
mágico*/


void Problema12() {
    int n;
    cout << "Ingrese el tamano de la matriz cuadrada: ";
    cin >> n;

    int** matriz = new int*[n];
    for (int i = 0; i < n; i++) {
        matriz[i] = new int[n];
    }

    cout << "Ingrese los elementos de la matriz:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> matriz[i][j];
        }
    }

    cout << "\nMatriz ingresada:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    bool repetidos = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                for (int l = 0; l < n; l++) {
                    if ((i != k || j != l) && matriz[i][j] == matriz[k][l]) {
                        repetidos = true;
                    }
                }
            }
        }
    }

    int sumaMagica = 0;
    for (int j = 0; j < n; j++) {
        sumaMagica += matriz[0][j];
    }

    bool esMagico = true;

    for (int i = 0; i < n; i++) {
        int sumaFila = 0;
        for (int j = 0; j < n; j++) {
            sumaFila += matriz[i][j];
        }
        if (sumaFila != sumaMagica) {
            esMagico = false;
        }
    }

    for (int j = 0; j < n; j++) {
        int sumaColumna = 0;
        for (int i = 0; i < n; i++) {
            sumaColumna += matriz[i][j];
        }
        if (sumaColumna != sumaMagica) {
            esMagico = false;
        }
    }

    int sumaDiagonalPrincipal = 0;
    for (int i = 0; i < n; i++) {
        sumaDiagonalPrincipal += matriz[i][i];
    }
    if (sumaDiagonalPrincipal != sumaMagica) {
        esMagico = false;
    }

    int sumaDiagonalSecundaria = 0;
    for (int i = 0; i < n; i++) {
        sumaDiagonalSecundaria += matriz[i][n - 1 - i];
    }
    if (sumaDiagonalSecundaria != sumaMagica) {
        esMagico = false;
    }

    if (repetidos) {
        esMagico = false;
    }

    if (esMagico) {
        cout << "\nLa matriz SI es un cuadrado magico." << endl;
    } else {
        cout << "\nLa matriz NO es un cuadrado magico." << endl;
    }

    for (int i = 0; i < n; i++) {
        delete[] matriz[i];
    }
    delete[] matriz;
}

/*Problema 14. Elabore un programa que llene una matriz 5x5 con los números del 1 al 25 y la imprima, luego
imprima la matriz rotada 90, 180 y 270 grados.*/

void Problema14() {
    const int N = 5;
    int matriz[N][N];
    int numero = 1;

    // Llenar la matriz con los numeros del 1 al 25
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            matriz[i][j] = numero;
            numero++;
        }
    }

    // Imprimir matriz original
    cout << "Matriz Original:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Imprimir matriz rotada 90 grados
    cout << "\nMatriz Rotada 90 grados:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[N - 1 - j][i] << "\t";
        }
        cout << endl;
    }

    // Imprimir matriz rotada 180 grados
    cout << "\nMatriz Rotada 180 grados:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[N - 1 - i][N - 1 - j] << "\t";
        }
        cout << endl;
    }

    // Imprimir matriz rotada 270 grados
    cout << "\nMatriz Rotada 270 grados:" << endl;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << matriz[j][N - 1 - i] << "\t";
        }
        cout << endl;
    }
}


/*Problema 16. En una malla de 2x2, realizando únicamente movimientos hacia la derecha y hacia abajo hay 6
posibles caminos para llegar de la esquina superior izquierda a la inferior derecha como se observa en la Figura 7.*/

void Problema16() {
    int n;
    cout << "Ingrese el tamano de la malla: ";
    cin >> n;

    unsigned long long** caminos = new unsigned long long*[n + 1];
    for (int i = 0; i <= n; i++) {
        caminos[i] = new unsigned long long[n + 1];
    }

    for (int i = 0; i <= n; i++) {
        caminos[i][0] = 1;
    }

    for (int j = 0; j <= n; j++) {
        caminos[0][j] = 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            caminos[i][j] = caminos[i - 1][j] + caminos[i][j - 1];
        }
    }

    cout << "En una malla de " << n << "x" << n
         << " hay " << caminos[n][n] << " caminos posibles." << endl;

    for (int i = 0; i <= n; i++) {
        delete[] caminos[i];
    }
    delete[] caminos;
}


/*Problema 18. Las permutaciones lexicográficas son permutaciones ordenadas numérica o alfabéticamente, por
ejemplo las permutaciones lexicográficas de 0,1 y 2 son: 012, 021, 102, 120, 201, 210. Escribir un programa que
reciba un número n y halle la enésima permutación lexicográfica de los números entre 0 y 9.
Ejemplo: para n= 1000000, la permutación lexicográfica es 2783915460.
Nota: la salida del programa debe ser:
La permutacion numero 1000000 es: 2783915460  */

unsigned long long factorial(int n) {
    unsigned long long fact = 1;
    for (int i = 2; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

void Problema18() {
    const int N = 10;
    unsigned long long n, original;

    cout << "Ingrese n: ";
    cin >> n;
    original = n;

    unsigned long long total = factorial(N);

    if (n < 1 || n > total) {
        cout << "n debe estar entre 1 y " << total << "." << endl;
        return;
    }

    int disponibles[N] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int cantidadDisponibles = N;
    int resultado[N];

    n = n - 1;

    for (int pos = 0; pos < N; pos++) {
        unsigned long long bloque = factorial(cantidadDisponibles - 1);
        int indice = n / bloque;

        resultado[pos] = disponibles[indice];

        for (int i = indice; i < cantidadDisponibles - 1; i++) {
            disponibles[i] = disponibles[i + 1];
        }

        cantidadDisponibles--;
        n = n % bloque;
    }

    cout << "La permutacion numero " << original << " es: ";
    for (int i = 0; i < N; i++) {
        cout << resultado[i];
    }
    cout << endl;
}
