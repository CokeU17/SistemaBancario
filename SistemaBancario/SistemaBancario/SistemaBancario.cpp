/**
 * @file SistemaBancario.cpp
 * @brief Sistema de gestion de turnos para una sucursal bancaria.
 * @author Angel Teran
 * @version 0.3
 */

#include <iostream>
#include <string>
#include <queue>

using namespace std;

/**
 * @brief Clase que representa a un cliente del banco.
 */
class Cliente
{
public:
    string nombre;
    string tramite;
    int turno;
};

/**
 * @brief Funcion principal del programa.
 *
 * Permite registrar clientes y administrar el menu principal
 * del sistema bancario.
 *
 * @return 0 si el programa finaliza correctamente.
 */
int main()
{
    int opcion;
    int siguienteTurno = 1;

    queue<Cliente> clientesEspera;

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
        {
            Cliente nuevoCliente;

            cin.ignore();

            cout << "Nombre del cliente: ";
            getline(cin, nuevoCliente.nombre);

            cout << "Tipo de tramite: ";
            getline(cin, nuevoCliente.tramite);

            nuevoCliente.turno = siguienteTurno;

            siguienteTurno++;

            clientesEspera.push(nuevoCliente);

            cout << endl;
            cout << "Cliente registrado correctamente." << endl;
            cout << "Turno asignado: "
                << nuevoCliente.turno << endl;

            break;
        }

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