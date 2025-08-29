#include <iostream>
#include "Tienda.h"
#include <string>
#include <iomanip>

using std::cout;
using std::cin;
using std::fixed;
using std::setprecision;

void mostrarMenuPrincipal()
{
    cout << "Tienda de video Juegos\n";
    cout << "1.Catalogo de video juegos\n";
    cout << "2.Ver subtotal del pedido\n";
    cout << "3.Finalizar y pagar\n";
    cout << "4.Limpiar carrito\n";
    cout << "5.Salir\n";
    cout << "Seleccione una opcion: ";
}

int leerOpcionMenu()
{
    int opcion;
    cin >> opcion;
    while (opcion < 1 || opcion > 6)
    {
        cout << "Opcion invalida. Intentalo de nuevo (1-5): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> opcion;
    }
    return opcion;
}

int main()
{
    int codigos[MAX_ITEMS] = {0};
    int cantidades[MAX_ITEMS] = {0};
    int cantidadItemsRegistrados = 0;

    int opcion = 0;
    do
    {
        mostrarMenuPrincipal();
        opcion = leerOpcionMenu();

        switch (opcion)
        {
        case 1:
            registrarProducto(codigos, cantidades, cantidadItemsRegistrados);
            break;
        case 2:
        {
            double subtotal = calcularSubtotalPedido(codigos, cantidades, cantidadItemsRegistrados);
            cout << fixed << setprecision(2);
            cout << "\nSubtotal actual: $" << subtotal << "\n\n";
            break;
        }
        case 3:
        {
            if (cantidadItemsRegistrados == 0)
            {
                cout << "\nNo hay productos en el pedido.\n\n";
                break;
            }
            double subtotal = calcularSubtotalPedido(codigos, cantidades, cantidadItemsRegistrados);
            int tipoCliente = leerTipoUsuario();
            double porcentajeDescuento = obtenerPorcentajeDescuento(tipoCliente);
            mostrarResumenPedido(codigos, cantidades, cantidadItemsRegistrados, porcentajeDescuento);
            double total = calcularTotal(subtotal, porcentajeDescuento);
            cout << fixed << setprecision(2);
            cout << "Total a pagar: $" << total << "\n\n";
            break;
        }
        case 4:
            for (int i = 0; i < MAX_ITEMS; i++) {
                codigos[i] = 0;
                cantidades[i] = 0;
            }
            cantidadItemsRegistrados = 0;
            cout << "\nCarrito limpiado.\n\n";
            break;
        case 5:
            cout << "\nSaliendo. ¡Hasta pronto!\n";
            break;
        }
    } while (opcion != 5);

    return 0;
}
