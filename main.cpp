#include <iostream>

using namespace std;
#include "Problemas.h"
int main()
{
    int problema = 0;

    while (true) {  // bucle infinito
        cout << "Ingrese el numero del problema a ejecutar (0 para salir): ";
        cin >> problema;

        if (problema == 0) break; // salir del programa

        switch(problema){

        case 2: Problema2(); break;

        case 4: Problema4(); break;

        case 6: Problema6(); break;

        case 8: Problema8(); break;

        case 10: Problema10(); break;

        default: cout << "Opcion no valida" << endl;
        }
    }

    return 0;
}
