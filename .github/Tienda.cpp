#include "Tienda.h"

void mostrarCartaProductos()
{
    cout << "\nCatalogo de Videojuegos\n";
    cout << "1. PS5 - Accion - Twisted metal 4 ($" << PRECIO_JUEGO_1 << ")\n";
    cout << "2. Xbox - Accion - GTA IV ($" << PRECIO_JUEGO_2 << ")\n";
    cout << "3. Switch - Accion - Super smash bros ($" << PRECIO_JUEGO_3 << ")\n";
    cout << "4. PS5 - Aventura - Astro bot ($" << PRECIO_JUEGO_4 << ")\n";
    cout << "5. Xbox - Aventura - Resident evil 4 ($" << PRECIO_JUEGO_5 << ")\n";
    cout << "6. Switch - Aventura - Zelda ($" << PRECIO_JUEGO_6 << ")\n";
    cout << "7. PS5 - Deportes - FC25 ($" << PRECIO_JUEGO_7 << ")\n";
    cout << "8. Xbox - Deportes - PES 2017 ($" << PRECIO_JUEGO_8 << ")\n";
    cout << "9. Switch - Deportes - NBA 2K18 ($" << PRECIO_JUEGO_9 << ")\n";
    cout << "10. PS5 - Estrategia - Balatro ($" << PRECIO_JUEGO_10 << ")\n";
    cout << "11. Xbox - Estrategia - Gears tactics ($" << PRECIO_JUEGO_11 << ")\n";
    cout << "12. Switch - Estrategia - Triangle strategy ($" << PRECIO_JUEGO_12 << ")\n";
}

int leerCodigoProducto()
{
    int codigo;
    cout << "Ingrese el codigo del videojuego (1-12): ";
    cin >> codigo;
    while (codigo < 1 || codigo > 12)
    {
        cout << "Codigo invalido. Intente de nuevo (1-12): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> codigo;
    }
    return codigo;
}

int leerCantidadProducto()
{
    int cantidad;
    cout << "Ingrese la cantidad: ";
    cin >> cantidad;
    while (cantidad < 1)
    {
        cout << "Cantidad invalida. Intente de nuevo (minimo 1): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> cantidad;
    }
    return cantidad;
}

int obtenerPrecioPorCodigo(int codigoProducto)
{
    switch (codigoProducto)
    {
        case 1: return PRECIO_JUEGO_1;
        case 2: return PRECIO_JUEGO_2;
        case 3: return PRECIO_JUEGO_3;
        case 4: return PRECIO_JUEGO_4;
        case 5: return PRECIO_JUEGO_5;
        case 6: return PRECIO_JUEGO_6;
        case 7: return PRECIO_JUEGO_7;
        case 8: return PRECIO_JUEGO_8;
        case 9: return PRECIO_JUEGO_9;
        case 10: return PRECIO_JUEGO_10;
        case 11: return PRECIO_JUEGO_11;
        case 12: return PRECIO_JUEGO_12;
        default: return 0;
    }
}

string obtenerNombreProducto(int codigoProducto)
{
    switch (codigoProducto)
    {
        case 1: return "PS5 - Accion - Twisted metal 4 ";
        case 2: return "Xbox - Accion - GTA IV";
        case 3: return "Switch - Accion - Super smash bros ";
        case 4: return "PS5 - Aventura - Astro bot ";
        case 5: return "Xbox - Aventura - Resident evil 4 ";
        case 6: return "Switch - Aventura - Zelda ";
        case 7: return "PS5 - Deportes - FC25 ";
        case 8: return "Xbox - Deportes - PES 2017 ";
        case 9: return "Switch - Deportes - NBA 2K18 ";
        case 10: return "PS5 - Estrategia - Balatro ";
        case 11: return "Xbox - Estrategia - Gears tactics";
        case 12: return "Switch - Estrategia - Triangle strategy ";
        default: return "Desconocido";
    }
}

void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados)
{
    if (cantidadItemsRegistrados >= MAX_ITEMS)
    {
        cout << "No se pueden agregar mas productos. Carrito lleno.\n";
        return;
    }

    mostrarCartaProductos();
    int codigo = leerCodigoProducto();
    int cantidad = leerCantidadProducto();

    codigos[cantidadItemsRegistrados] = codigo;
    cantidades[cantidadItemsRegistrados] = cantidad;
    cantidadItemsRegistrados++;

    cout << "Producto agregado: " << obtenerNombreProducto(codigo)
         << " x" << cantidad << "\n\n";
}

double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados)
{
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; ++i)
    {
        subtotal += obtenerPrecioPorCodigo(codigos[i]) * cantidades[i];
    }
    return subtotal;
}

int leerTipoUsuario()
{
    int tipo;
    cout << "Seleccione el tipo de cliente:\n";
    cout << "1. Cliente Oro (15% descuento)\n";
    cout << "2. Cliente Plata (10% descuento)\n";
    cout << "3. Cliente Regular (sin descuento)\n";
    cout << "Opcion: ";
    cin >> tipo;
    while (tipo < 1 || tipo > 3)
    {
        cout << "Opcion invalida. Intente de nuevo (1-3): ";
        cin.clear();
        cin.ignore(10000, '\n');
        cin >> tipo;
    }
    return tipo;
}

double obtenerPorcentajeDescuento(int tipoUsuario)
{
    switch (tipoUsuario)
    {
        case 1: return DESCUENTO_ORO;
        case 2: return DESCUENTO_PLATA;
        case 3: return DESCUENTO_REGULAR;
        default: return 0.0;
    }
}

double calcularTotal(double subtotal, double porcentajeDescuento)
{
    return subtotal * (1 - porcentajeDescuento);
}

void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,
                          double porcentajeDescuento)
{
    cout << "\nResumen del Pedido\n";
    double subtotal = 0.0;
    for (int i = 0; i < cantidadItemsRegistrados; ++i)
    {
        int codigo = codigos[i];
        int cantidad = cantidades[i];
        double precio = obtenerPrecioPorCodigo(codigo);
        double totalItem = precio * cantidad;
        cout << obtenerNombreProducto(codigo) << " x" << cantidad
             << " - $" << totalItem << "\n";
        subtotal += totalItem;
    }
    cout << "Subtotal: $" << subtotal << "\n";
    cout << "Descuento aplicado: " << porcentajeDescuento * 100 << "%\n";
}

