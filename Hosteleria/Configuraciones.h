#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED

///COPIAS///
void copiaCategoria();
void copiaDetallesPago();
void copiaEmpleado();
void copiaHuesped();
void copiaPago();
void copiaRegimenComida();
void copiaTipoEmpleado();
void copiaTurnoEmpleado();
void copiaHabitacion();

void copiaTodos();

void copiaTodos()
{
    copiaCategoria();
    copiaDetallesPago();
    copiaEmpleado();
    copiaHuesped();
    copiaPago();
    copiaRegimenComida();
    copiaTipoEmpleado();
    copiaTurnoEmpleado();
    copiaHabitacion();
}

void copiaCategoria()
{
    ArchivoCategoria arcCat, bkpCat("categoria.bkp");
    bkpCat.limpiarArchivo();
    int contarReg = arcCat.contarRegistros();
    Categoria obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcCat.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpCat.grabarRegistro(obj);
        }
    }
}

void copiaDetallesPago()
{
    ArchivoDetalles arcDet, bkpDet("detallePago.bkp");
    bkpDet.limpiarArchivo();
    int contarReg = arcDet.contarRegistros();
    DetallesPago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcDet.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpDet.grabarRegistro(obj);
        }
    }
}

void copiaEmpleado()
{
    ArchivoEmpleado arcEmp, bkpEmp("empleado.bkp");
    bkpEmp.limpiarArchivo();
    int contarReg = arcEmp.contarRegistros();
    Empleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcEmp.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpEmp.grabarRegistro(obj);
        }
    }
}

void copiaHuesped()
{
    ArchivoHuesped arcHues, bkpHues("huesped.bkp");
    bkpHues.limpiarArchivo();
    int contarReg = arcHues.contarRegistros();
    Huesped obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcHues.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpHues.grabarRegistro(obj);
        }
    }
}

void copiaPago()
{
    ArchivoPago arcPag, bkpPag("pago.bkp");
    bkpPag.limpiarArchivo();
    int contarReg = arcPag.contarRegistros();
    Pago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcPag.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpPag.grabarRegistro(obj);
        }
    }
}

void copiaRegimenComida()
{
    ArchivoRegimenComida arcReg, bkpReg("regimenComida.bkp");
    bkpReg.limpiarArchivo();
    int contarReg = arcReg.contarRegistros();
    RegimenComida obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcReg.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpReg.grabarRegistro(obj);
        }
    }
}

void copiaTipoEmpleado()
{
    ArchivoTipoEmpleado arcTipo, bkpTipo("tipoempleado.bkp");
    bkpTipo.limpiarArchivo();
    int contarReg = arcTipo.contarRegistros();
    TipoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcTipo.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpTipo.grabarRegistro(obj);
        }
    }
}

void copiaTurnoEmpleado()
{
    ArchivoTurnoEmpleado arcTurno, bkpTurno("turnoempleado.bkp");
    bkpTurno.limpiarArchivo();
    int contarReg = arcTurno.contarRegistros();
    TurnoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcTurno.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpTurno.grabarRegistro(obj);
        }
    }
}

void copiaHabitacion()
{
    ArchivoHabitacion arcHabit, bkpHabit("habitacion.bkp");
    bkpHabit.limpiarArchivo();
    int contarReg = arcHabit.contarRegistros();
    Habitacion obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcHabit.leerRegistro(i);
        if (obj.getEstado())
        {
            bkpHabit.grabarRegistro(obj);
        }
    }
}
///COPIAS///

///RESTABLECER///
void restablecerCategoria();
void restablecerDetallesPago();
void restablecerEmpleado();
void restablecerHuesped();
void restablecerPago();
void restablecerRegimenComida();
void restablecerTipoEmpleado();
void restablecerTurnoEmpleado();
void restablecerHabitacion();

void restablecerTodos();

void restablecerTodos()
{
    restablecerCategoria();
    restablecerDetallesPago();
    restablecerEmpleado();
    restablecerHuesped();
    restablecerPago();
    restablecerRegimenComida();
    restablecerTipoEmpleado();
    restablecerTurnoEmpleado();
    restablecerHabitacion();
}

void restablecerCategoria()
{
    ArchivoCategoria arcCat, bkpCat("categoria.bkp");
    arcCat.limpiarArchivo();
    int contarReg = bkpCat.contarRegistros();
    Categoria obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpCat.leerRegistro(i);
        if (obj.getEstado())
        {
            arcCat.grabarRegistro(obj);
        }
    }
}

void restablecerDetallesPago()
{
    ArchivoDetalles arcDet, bkpDet("detallesPago.bkp");
    arcDet.limpiarArchivo();
    int contarReg = bkpDet.contarRegistros();
    DetallesPago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpDet.leerRegistro(i);
        if (obj.getEstado())
        {
            arcDet.grabarRegistro(obj);
        }
    }
}

void restablecerEmpleado()
{
    ArchivoEmpleado arcEmp, bkpEmp("empleado.bkp");
    arcEmp.limpiarArchivo();
    int contarReg = bkpEmp.contarRegistros();
    Empleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpEmp.leerRegistro(i);
        if (obj.getEstado())
        {
            arcEmp.grabarRegistro(obj);
        }
    }
}

void restablecerHuesped()
{
    ArchivoHuesped arcHues, bkpHues("huesped.bkp");
    arcHues.limpiarArchivo();
    int contarReg = bkpHues.contarRegistros();
    Huesped obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpHues.leerRegistro(i);
        if (obj.getEstado())
        {
            arcHues.grabarRegistro(obj);
        }
    }
}

void restablecerPago()
{
    ArchivoPago arcPag, bkpPag("pago.bkp");
    arcPag.limpiarArchivo();
    int contarReg = bkpPag.contarRegistros();
    Pago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpPag.leerRegistro(i);
        if (obj.getEstado())
        {
            arcPag.grabarRegistro(obj);
        }
    }
}

void restablecerRegimenComida()
{
    ArchivoRegimenComida arcReg, bkpReg("regimenComida.bkp");
    arcReg.limpiarArchivo();
    int contarReg = bkpReg.contarRegistros();
    RegimenComida obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpReg.leerRegistro(i);
        if (obj.getEstado())
        {
            arcReg.grabarRegistro(obj);
        }
    }
}

void restablecerTipoEmpleado()
{
    ArchivoTipoEmpleado arcTipo, bkpTipo("tipoempleado.bkp");
    arcTipo.limpiarArchivo();
    int contarReg = bkpTipo.contarRegistros();
    TipoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpTipo.leerRegistro(i);
        if (obj.getEstado())
        {
            arcTipo.grabarRegistro(obj);
        }
    }
}

void restablecerTurnoEmpleado()
{
    ArchivoTurnoEmpleado arcTurno, bkpTurno("turnoempleado.bkp");
    arcTurno.limpiarArchivo();
    int contarReg = bkpTurno.contarRegistros();
    TurnoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpTurno.leerRegistro(i);
        if (obj.getEstado())
        {
            arcTurno.grabarRegistro(obj);
        }
    }
}

void restablecerHabitacion()
{
    ArchivoHabitacion arcHabit, bkpHabit("habitacion.bkp");
    arcHabit.limpiarArchivo();
    int contarReg = bkpHabit.contarRegistros();
    Habitacion obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = bkpHabit.leerRegistro(i);
        if (obj.getEstado())
        {
            arcHabit.grabarRegistro(obj);
        }
    }
}
///RESTABLECER///

///ESTABLECER DATOS INI///
void establecerDatosIniCategoria();
void establecerDatosIniDetallesPago();
void establecerDatosIniEmpleado();
void establecerDatosIniHuesped();
void establecerDatosIniPago();
void establecerDatosIniRegimenComida();
void establecerDatosIniTipoEmpleado();
void establecerDatosIniTurnoEmpleado();
void establecerDatosIniHabitacion();

void establecerDatosIniHabitacion();

void establecerDatosIniTodos()
{
    establecerDatosIniCategoria();
    establecerDatosIniDetallesPago();
    establecerDatosIniEmpleado();
    establecerDatosIniHuesped();
    establecerDatosIniPago();
    establecerDatosIniRegimenComida();
    establecerDatosIniTipoEmpleado();
    establecerDatosIniTurnoEmpleado();
    establecerDatosIniHabitacion();
}

void establecerDatosIniCategoria()
{
    ArchivoCategoria arcCat, arcCatIni("categoria.ini");
    arcCatIni.limpiarArchivo();
    int contarReg = arcCat.contarRegistros();
    Categoria obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcCat.leerRegistro(i);
        if (obj.getEstado())
        {
            arcCatIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniDetallesPago()
{
    ArchivoDetalles arcDet, arcDetIni("detallesPago.ini");
    arcDetIni.limpiarArchivo();
    int contarReg = arcDet.contarRegistros();
    DetallesPago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcDet.leerRegistro(i);
        if (obj.getEstado())
        {
            arcDetIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniEmpleado()
{
    ArchivoEmpleado arcEmp, arcEmpIni("empleado.ini");
    arcEmpIni.limpiarArchivo();
    int contarReg = arcEmp.contarRegistros();
    Empleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcEmp.leerRegistro(i);
        if (obj.getEstado())
        {
            arcEmpIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniHuesped()
{
    ArchivoHuesped arcHues, arcHuesIni("huesped.ini");
    arcHuesIni.limpiarArchivo();
    int contarReg = arcHues.contarRegistros();
    Huesped obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcHues.leerRegistro(i);
        if (obj.getEstado())
        {
            arcHuesIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniPago()
{
    ArchivoPago arcPag, arcPagIni("pago.ini");
    arcPagIni.limpiarArchivo();
    int contarReg = arcPag.contarRegistros();
    Pago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcPag.leerRegistro(i);
        if (obj.getEstado())
        {
            arcPagIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniRegimenComida()
{
    ArchivoRegimenComida arcReg, arcRegIni("regimenComida.ini");
    arcRegIni.limpiarArchivo();
    int contarReg = arcReg.contarRegistros();
    RegimenComida obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcReg.leerRegistro(i);
        if (obj.getEstado())
        {
            arcRegIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniTipoEmpleado()
{
    ArchivoTipoEmpleado arcTipo, arcTipoIni("tipoempleado.ini");
    arcTipoIni.limpiarArchivo();
    int contarReg = arcTipo.contarRegistros();
    TipoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcTipo.leerRegistro(i);
        if (obj.getEstado())
        {
            arcTipoIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniTurnoEmpleado()
{
    ArchivoTurnoEmpleado arcTurno, arcTurnoIni("turnoempleado.ini");
    arcTurnoIni.limpiarArchivo();
    int contarReg = arcTurno.contarRegistros();
    TurnoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcTurno.leerRegistro(i);
        if (obj.getEstado())
        {
            arcTurnoIni.grabarRegistro(obj);
        }
    }
}

void establecerDatosIniHabitacion()
{
    ArchivoHabitacion arcHabit, arcHabitIni("habitacion.ini");
    arcHabitIni.limpiarArchivo();
    int contarReg = arcHabit.contarRegistros();
    Habitacion obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcHabit.leerRegistro(i);
        if (obj.getEstado())
        {
            arcHabitIni.grabarRegistro(obj);
        }
    }
}
///ESTABLECER DATOS INI///

///RESTABLECER DATOS INI///
void restablecerDatosIniCategoria();
void restablecerDatosIniDetallesPago();
void restablecerDatosIniEmpleado();
void restablecerDatosIniHuesped();
void restablecerDatosIniPago();
void restablecerDatosIniRegimenComida();
void restablecerDatosIniTipoEmpleado();
void restablecerDatosIniTurnoEmpleado();
void restablecerDatosIniHabitacion();

void restablecerDatosIniTodos();

void restablecerDatosIniTodos()
{
    restablecerDatosIniCategoria();
    restablecerDatosIniDetallesPago();
    restablecerDatosIniEmpleado();
    restablecerDatosIniHuesped();
    restablecerDatosIniPago();
    restablecerDatosIniRegimenComida();
    restablecerDatosIniTipoEmpleado();
    restablecerDatosIniTurnoEmpleado();
    restablecerDatosIniHabitacion();

}

void restablecerDatosIniCategoria()
{
    ArchivoCategoria arcCat, arcCatIni("categoria.ini");
    arcCat.limpiarArchivo();
    int contarReg = arcCatIni.contarRegistros();
    Categoria obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcCatIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcCat.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniDetallesPago()
{
    ArchivoDetalles arcDet, arcDetIni("detallesPago.ini");
    arcDet.limpiarArchivo();
    int contarReg = arcDetIni.contarRegistros();
    DetallesPago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcDetIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcDet.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniEmpleado()
{
    ArchivoEmpleado arcEmp, arcEmpIni("empleado.ini");
    arcEmp.limpiarArchivo();
    int contarReg = arcEmpIni.contarRegistros();
    Empleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcEmpIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcEmp.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniHuesped()
{
    ArchivoHuesped arcHues, arcHuesIni("huesped.ini");
    arcHues.limpiarArchivo();
    int contarReg = arcHuesIni.contarRegistros();
    Huesped obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcHuesIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcHues.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniPago()
{
    ArchivoPago arcPag, arcPagIni("pago.ini");
    arcPag.limpiarArchivo();
    int contarReg = arcPagIni.contarRegistros();
    Pago obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcPagIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcPag.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniRegimenComida()
{
    ArchivoRegimenComida arcReg, arcRegIni("regimenComida.ini");
    arcReg.limpiarArchivo();
    int contarReg = arcRegIni.contarRegistros();
    RegimenComida obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcRegIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcReg.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniTipoEmpleado()
{
    ArchivoTipoEmpleado arcTipo, arcTipoIni("tipoempleado.ini");
    arcTipo.limpiarArchivo();
    int contarReg = arcTipoIni.contarRegistros();
    TipoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcTipoIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcTipo.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniTurnoEmpleado()
{
    ArchivoTurnoEmpleado arcTurno, arcTurnoIni("turnoempleado.ini");
    arcTurno.limpiarArchivo();
    int contarReg = arcTurnoIni.contarRegistros();
    TurnoEmpleado obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcTurnoIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcTurno.grabarRegistro(obj);
        }
    }
}

void restablecerDatosIniHabitacion()
{
    ArchivoHabitacion arcHabit, arcHabitIni("habitacion.ini");
    arcHabit.limpiarArchivo();
    int contarReg = arcHabitIni.contarRegistros();
    Habitacion obj;
    for (int i = 0; i < contarReg; i++)
    {
        obj = arcHabitIni.leerRegistro(i);
        if (obj.getEstado())
        {
            arcHabit.grabarRegistro(obj);
        }
    }
}
///RESTABLECER DATOS INI///

#endif // CONFIGURACIONES_H_INCLUDED
