/**
 * @file SistemaBancario.cpp
 * @brief Sistema de gestion de turnos para una sucursal bancaria.
 * @author Angel Teran
 * @version 0.2
 */

#include <iostream>

using namespace std;

/**
 * @brief Funcion principal del programa.
 *
 * Muestra el menu principal del sistema y permite al usuario
 * seleccionar las diferentes opciones disponibles.
 *
 * @return 0 si el programa finaliza correctamente.
 */
int main()
{
    int opcion;

    do
    {
        cout << "====================================" << endl;
        cout << "      SISTEMA DE TURNOS BANCARIOS   " << endl;
        cout << "====================================" << endl;

        cout << "1. Registrar cliente" << endl;
        cout << "2. Ver siguiente cliente" << endl;
        cout << "3. Atender siguiente cliente" << endl;
        cout << "4. Mostrar clientes en espera" << endl;
        cout << "5. Mostrar historial de atendidos" << endl;
        cout << "6. Salir" << endl;

        cout << endl;
        cout << "Selecciona una opcion: ";
        cin >> opcion;

        cout << endl;

        switch (opcion)
        {
        case 1:
            cout << "Opcion seleccionada: Registrar cliente." << endl;
            break;

        case 2:
            cout << "Opcion seleccionada: Ver siguiente cliente." << endl;
            break;

        case 3:
            cout << "Opcion seleccionada: Atender siguiente cliente." << endl;
            break;

        case 4:
            cout << "Opcion seleccionada: Mostrar clientes en espera." << endl;
            break;

        case 5:
            cout << "Opcion seleccionada: Mostrar historial de atendidos." << endl;
            break;

        case 6:
            cout << "Saliendo del sistema..." << endl;
            break;

        default:
            cout << "Opcion no valida. Intenta nuevamente." << endl;
            break;
        }

        cout << endl;

    } while (opcion != 6);

    return 0;
}