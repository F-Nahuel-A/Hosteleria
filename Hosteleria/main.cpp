#include <iostream>
#include <cstring>

using namespace std;

#include "rlutil.h"
#include "funcionesGlobales.h"
#include "clsFecha.h"
#include "clsPersona.h"
#include "arcPersona.h"
#include "clsTipo.h"
#include "arcTipo.h"
#include "clsTurno.h"
#include "arcTurno.h"
#include "clsCategoria.h"
#include "arcCategoria.h"
#include "clsEmpleado.h"
#include "arcEmpleado.h"
#include "clsRegimenComida.h"
#include "arcRegimenComida.h"
#include "clsHabitacion.h"
#include "arcHabitacion.h"
#include "clsDetallesPagos.h"
#include "arcDetallesPago.h"
#include "clsPagos.h"
#include "arcPago.h"
#include "clsDetallesPagos.h"
#include "arcDetallesPago.h"
#include "clsHuesped.h"
#include "arcHuesped.h"
#include "modificaciones.h"
#include "informe.h"
#include "Configuraciones.h"
#include "menuConfiguraciones.h"
#include "reserva.h"
#include "menus.h"

void limpiar();

int main()
{
  mostrarMenu();
  return 0;
}

void limpiar()
{
    ArchivoCategoria a;
    ArchivoDetalles b;
    ArchivoEmpleado c;
    ArchivoHabitacion d;
    ArchivoHuesped e;
    ArchivoPago f;
    ArchivoRegimenComida g;
    ArchivoTipoEmpleado h;
    ArchivoTurnoEmpleado i;

    a.limpiarArchivo();
    b.limpiarArchivo();
    c.limpiarArchivo();
    d.limpiarArchivo();
    e.limpiarArchivo();
    f.limpiarArchivo();
    g.limpiarArchivo();
    h.limpiarArchivo();
    i.limpiarArchivo();
}
