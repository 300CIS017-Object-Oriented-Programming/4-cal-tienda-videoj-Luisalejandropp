#ifndef TIENDA_H
#define TIENDA_H

#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

const int PRECIO_JUEGO_1 = 81000;
const int PRECIO_JUEGO_2 = 150000;
const int PRECIO_JUEGO_3 = 100000;

const int PRECIO_JUEGO_4 = 180000;
const int PRECIO_JUEGO_5 = 200000;
const int PRECIO_JUEGO_6 = 160000;

const int PRECIO_JUEGO_7 = 90000;
const int PRECIO_JUEGO_8 = 110000;
const int PRECIO_JUEGO_9 = 95000;

const int PRECIO_JUEGO_10 = 170000;
const int PRECIO_JUEGO_11 = 195000;
const int PRECIO_JUEGO_12 = 130000;


const double DESCUENTO_ORO = 0.15;
const double DESCUENTO_PLATA = 0.10;
const double DESCUENTO_REGULAR = 0.00;


const int MAX_ITEMS = 50;


void mostrarCartaProductos();
int leerCodigoProducto();
int leerCantidadProducto();
int obtenerPrecioPorCodigo(int codigoProducto);
string obtenerNombreProducto(int codigoProducto);
void registrarProducto(int codigos[], int cantidades[], int& cantidadItemsRegistrados);
double calcularSubtotalPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados);
int leerTipoUsuario();
double obtenerPorcentajeDescuento(int tipoUsuario);
double calcularTotal(double subtotal, double porcentajeDescuento);
void mostrarResumenPedido(const int codigos[], const int cantidades[], int cantidadItemsRegistrados,double porcentajeDescuento);

#endif
