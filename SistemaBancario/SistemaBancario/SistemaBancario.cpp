/**
 * @file SistemaBancario.cpp
 * @brief Sistema de gestion de turnos para una sucursal bancaria.
 * @author Angel Teran
 * @version 0.5
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>

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
    vector<Cliente> historialAtendidos;

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
        {
            if (clientesEspera.empty())
            {
                cout << "No hay clientes en espera." << endl;
            }
            else
            {
                Cliente siguienteCliente = clientesEspera.front();

                cout << "====================================" << endl;
                cout << "          SIGUIENTE CLIENTE          " << endl;
                cout << "====================================" << endl;

                cout << "Turno: " << siguienteCliente.turno << endl;
                cout << "Nombre: " << siguienteCliente.nombre << endl;
                cout << "Tramite: " << siguienteCliente.tramite << endl;
            }

            break;
        }

        case 3:
        {
            if (clientesEspera.empty())
            {
                cout << "No hay clientes en espera para atender." << endl;
            }
            else
            {
                Cliente clienteAtendido = clientesEspera.front();

                clientesEspera.pop();

                historialAtendidos.push_back(clienteAtendido);

                cout << "====================================" << endl;
                cout << "          CLIENTE ATENDIDO           " << endl;
                cout << "====================================" << endl;

                cout << "Turno: " << clienteAtendido.turno << endl;
                cout << "Nombre: " << clienteAtendido.nombre << endl;
                cout << "Tramite: " << clienteAtendido.tramite << endl;

                cout << endl;
                cout << "Cliente atendido correctamente." << endl;
            }

            break;
        }

        case 4:
        {
            if (clientesEspera.empty())
            {
                cout << "No hay clientes en espera." << endl;
            }
            else
            {
                queue<Cliente> colaTemporal = clientesEspera;

                cout << "====================================" << endl;
                cout << "        CLIENTES EN ESPERA           " << endl;
                cout << "====================================" << endl;

                while (!colaTemporal.empty())
                {
                    Cliente cliente = colaTemporal.front();

                    cout << "Turno: " << cliente.turno << endl;
                    cout << "Nombre: " << cliente.nombre << endl;
                    cout << "Tramite: " << cliente.tramite << endl;
                    cout << "------------------------------------" << endl;

                    colaTemporal.pop();
                }
            }

            break;
        }

        case 5:
        {
            if (historialAtendidos.empty())
            {
                cout << "No hay clientes atendidos." << endl;
            }
            else
            {
                cout << "====================================" << endl;
                cout << "       HISTORIAL DE ATENDIDOS        " << endl;
                cout << "====================================" << endl;

                for (const Cliente& cliente : historialAtendidos)
                {
                    cout << "Turno: " << cliente.turno << endl;
                    cout << "Nombre: " << cliente.nombre << endl;
                    cout << "Tramite: " << cliente.tramite << endl;
                    cout << "------------------------------------" << endl;
                }
            }

            break;
        }

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