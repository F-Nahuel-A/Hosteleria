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
#include "clsCategoria.h"
#include "arcCategoria.h"
#include "clsRegimenComida.h"
#include "arcRegimenComida.h"
#include "clsHabitacion.h"
#include "arcHabitacion.h"
#include "clsPagos.h"
#include "clsHuesped.h"

int main()
{
//  int opcion = 0;
//  mostrarMenu();
//  mostrarCursor(opcion);
//    FILE *p=fopen("habitacion.dat","wb");
//    fclose(p);
    ArchivoHabitacion arc;
    arc.listarArchivo();

  return 0;
}
