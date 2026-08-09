/**
 * @file SistemaBancario.cpp
 * @brief Sistema de gestion de turnos para una sucursal bancaria.
 * @author Angel Teran
 * @version 1.0
 */

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <limits>

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
 * @brief Registra un nuevo cliente y lo agrega a la cola de espera.
 * @param clientesEspera Cola de clientes en espera.
 * @param siguienteTurno Numero de turno que sera asignado.
 */
void registrarCliente(queue<Cliente>& clientesEspera, int& siguienteTurno)
{
    Cliente nuevoCliente;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    do
    {
        cout << "Nombre del cliente: ";
        getline(cin, nuevoCliente.nombre);

        if (nuevoCliente.nombre.empty())
        {
            cout << "El nombre no puede estar vacio." << endl;
        }

    } while (nuevoCliente.nombre.empty());

    do
    {
        cout << "Tipo de tramite: ";
        getline(cin, nuevoCliente.tramite);

        if (nuevoCliente.tramite.empty())
        {
            cout << "El tramite no puede estar vacio." << endl;
        }

    } while (nuevoCliente.tramite.empty());

    nuevoCliente.turno = siguienteTurno;
    siguienteTurno++;

    clientesEspera.push(nuevoCliente);

    cout << endl;
    cout << "Cliente registrado correctamente." << endl;
    cout << "Turno asignado: " << nuevoCliente.turno << endl;
}

/**
 * @brief Muestra al primer cliente de la cola sin eliminarlo.
 * @param clientesEspera Cola de clientes en espera.
 */
void verSiguienteCliente(const queue<Cliente>& clientesEspera)
{
    if (clientesEspera.empty())
    {
        cout << "No hay clientes en espera." << endl;
        return;
    }

    Cliente siguienteCliente = clientesEspera.front();

    cout << "====================================" << endl;
    cout << "          SIGUIENTE CLIENTE          " << endl;
    cout << "====================================" << endl;

    cout << "Turno: " << siguienteCliente.turno << endl;
    cout << "Nombre: " << siguienteCliente.nombre << endl;
    cout << "Tramite: " << siguienteCliente.tramite << endl;
}

/**
 * @brief Atiende al primer cliente de la cola y lo guarda en el historial.
 * @param clientesEspera Cola de clientes en espera.
 * @param historialAtendidos Vector con los clientes ya atendidos.
 */
void atenderCliente(
    queue<Cliente>& clientesEspera,
    vector<Cliente>& historialAtendidos)
{
    if (clientesEspera.empty())
    {
        cout << "No hay clientes en espera para atender." << endl;
        return;
    }

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

/**
 * @brief Muestra todos los clientes que permanecen en espera.
 * @param clientesEspera Cola de clientes en espera.
 */
void mostrarClientesEspera(const queue<Cliente>& clientesEspera)
{
    if (clientesEspera.empty())
    {
        cout << "No hay clientes en espera." << endl;
        return;
    }

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

/**
 * @brief Muestra el historial de clientes atendidos.
 * @param historialAtendidos Vector que almacena los clientes atendidos.
 */
void mostrarHistorial(const vector<Cliente>& historialAtendidos)
{
    if (historialAtendidos.empty())
    {
        cout << "No hay clientes atendidos." << endl;
        return;
    }

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

/**
 * @brief Funcion principal del programa.
 *
 * Controla el menu principal y permite seleccionar
 * las distintas operaciones del sistema.
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

        while (!(cin >> opcion))
        {
            cout << "Que crees que haces chico?, ingresa un dato valido, 1 al 6: ";

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        cout << endl;

        switch (opcion)
        {
        case 1:
            registrarCliente(clientesEspera, siguienteTurno);
            break;

        case 2:
            verSiguienteCliente(clientesEspera);
            break;

        case 3:
            atenderCliente(clientesEspera, historialAtendidos);
            break;

        case 4:
            mostrarClientesEspera(clientesEspera);
            break;

        case 5:
            mostrarHistorial(historialAtendidos);
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