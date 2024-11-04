#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED
///COPIAS///
void copiaCategoria();
void copiaDetallesdPago();
void copiaEmpleado();
void copiaHuesped();
void copiaPago();
void copiaRegimenComida();
void copiaTipoEmpleado();
void copiaTurnoEmpleado();
void copiaHabitacion();

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
    cout << "ARCHIVO CATEGORIA COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO DETALLES DE PAGO COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO EMPLEADO COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO HUESPED COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO PAGO COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO REGIMEN DE COMIDA COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO TIPO DE EMPLEADO COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO TURNO DE EMPLEADO COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO HABITACION COPIADO" << endl;
    system("pause");
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
    cout << "ARCHIVO CATEGORIA RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO DETALLES DE PAGO RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO EMPLEADO RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO HUESPED RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO PAGO RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO REGIMEN DE COMIDA RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO TIPO DE EMPLEADO RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO TURNO DE EMPLEADO RESTABLECIDO" << endl;
    system("pause");
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
    cout << "ARCHIVO HABITACION RESTABLECIDO" << endl;
    system("pause");
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
    cout << "DATOS INI CATEGORIA ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI DETALLES DE PAGO ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI EMPLEADO ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI HUESPED ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI PAGO ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI REGIMEN DE COMIDA ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI TIPO DE EMPLEADO ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI TURNO DE EMPLEADO ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI HABITACION ESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI CATEGORIA RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI DETALLES DE PAGO RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI EMPLEADO RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI HUESPED RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI PAGO RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI REGIMEN DE COMIDA RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI TIPO DE EMPLEADO RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI TURNO DE EMPLEADO RESTABLECIDOS" << endl;
    system("pause");
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
    cout << "DATOS INI HABITACION RESTABLECIDOS" << endl;
    system("pause");
}

///RESTABLECER DATOS INI///

#endif // CONFIGURACIONES_H_INCLUDED
