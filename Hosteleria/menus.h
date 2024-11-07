#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void mostrarMenu();
///MEN�S PRINCIPALES
void menuPersonal();
void menuServicios();
void menuPagosPrincipal();
///MEN�S PRINCIPALES
void menuEmpleado();
void menuCategoria();
void menuHuesped();
void menuHabitacion();
void menuPagos();
void menuDetalles();
void menuRegimen();
void menuTipoEmpleado();
void menuTurnoEmpleado();
///
void menuCategoriaConfig();
void menuDetallesPagoConfig();
void menuEmpleadoConfig();
void menuHuespedConfig();
void menuPagoConfig();
void menuRegimenComidaConfig();
void menuTipoEmpleadoConfig();
void menuTurnoEmpleadoConfig();
void menuHabitacionConfig();

void menuConfiguraciones();
void menuListados();
void menuReserva();

void copiarTodo();
void restablecerTodo();
void establecerIni();
void restablecerIni();

void mostrarMenu()
{
    int y=1,op=1;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(1,29);
    cout<<"https://github.com/F-Nahuel-A/Hosteleria"<<endl;
    rlutil::locate(41,10);
    cout<<"HOSTELERIA-GRUPO 25"<<endl;
    showItem("RESERVA",45,12,y==1);
    showItem("HUESPED",45,13,y==2);
    showItem("PERSONAL",45,14,y==3);
    showItem("SERVICIOS",44,15,y==4);
    showItem("PAGOS",46,16,y==5);
    showItem("INFORMES",45,17,y==6);
    showItem("LISTADOS",45,18,y==7);
    showItem("CONFIGURACIONES",45,19,y==8);
    showItem("SALIR",46,20,y==9);

        switch (rlutil::getkey())
        {
            case 14:  ///Flecha arriba
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posici�n actual
                ///Cicla a la �ltima opci�n si sube desde la primera
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:  ///Flecha abajo
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posici�n actual
                ///Cicla a la primera opci�n si baja desde la �ltima
                y++;
                if(y>9)
                {
                    y=9;
                }
                break;

            case 1:  ///Enter para elegir
                switch (y)
                {
            case 1:
                system("cls");
                menuReserva();
                system("cls");
                break;

            case 2:
                system("cls");
                menuHuesped();
                system("cls");
                break;

            case 3:
                system("cls");
                menuPersonal();
                system("cls");
                break;

            case 4:
                system("cls");
                menuServicios();
                system("cls");
                break;

            case 5:
                system("cls");
                menuPagosPrincipal();
                system("cls");
                break;

            case 6:
                system("cls");
                menuInforme();
                system("cls");
                break;

            case 7:
                system("cls");
                menuListados();
                system("cls");
                break;

            case 8:
                system("cls");
                menuConfiguraciones();
                system("cls");
                break;

            case 9:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}
/// /// ///

void menuPersonal()
{
    int y=1,op=1;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE PERSONAL"<<endl;
    showItem("EMPLEADOS",45,12,y==1);
    showItem("TURNOS",47,13,y==2);
    showItem("SECTORES",46,14,y==3);
    showItem("SALIR",47,15,y==4);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>4)
                {
                    y=4;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                menuEmpleado();
                system("cls");
                break;

            case 2:
                system("cls");
                menuTurnoEmpleado();
                system("cls");
                break;

            case 3:
                system("cls");
                menuTipoEmpleado();
                system("cls");
                break;

            case 4:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuServicios()
{
    int y=1,op=1;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE SERVICIOS"<<endl;
    showItem("HABITACIONES",44,12,y==1);
    showItem("CATEGORIA",45,13,y==2);
    showItem("REGIMEN DE COMIDAS",41,14,y==3);
    showItem("SALIR",47,15,y==4);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>4)
                {
                    y=4;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                menuHabitacion();
                system("cls");
                break;

            case 2:
                system("cls");
                menuCategoria();
                system("cls");
                break;

            case 3:
                system("cls");
                menuRegimen();
                system("cls");
                break;

            case 4:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuPagosPrincipal()
{
    int y=1,op=1;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(43,10);
    cout<<"MENU DE PAGOS"<<endl;
    showItem("PAGOS",45,12,y==1);
    showItem("DETALLE DE PAGOS",40,13,y==2);
    showItem("SALIR",45,14,y==3);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>3)
                {
                    y=3;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                menuPagos();
                system("cls");
                break;

            case 2:
                system("cls");
                menuDetalles();
                system("cls");
                break;

            case 3:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuEmpleado()
{
    int y=1,op=1;
    ArchivoEmpleado arc;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(45,10);
    cout<<"MENU EMPLEADO"<<endl;
    showItem("CARGAR EMPLEADO",42,12,y==1);
    showItem("ELIMINAR EMPLEADO",41,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR EMPLEADOS",42,15,y==4);
    showItem("LISPAR POR ID",43,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesEmpleado();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorID();
                system("cls");
                break;

            case 6:
                system("cls");
                menuEmpleadoConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuHuesped()
{
    int y=1,op=1;
    ArchivoHuesped arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(46,10);
    cout<<"MENU HUESPED"<<endl;
    showItem("CCARGAR HUESPED",42,12,y==1);
    showItem("ELIMINAR HUESPED",42,13,y==2);
    showItem("MODIFICAR ARCHIVO",42,14,y==3);
    showItem("LISTAR HUESPED",43,15,y==4);
    showItem("LISPAR POR DNI",43,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesHuesped();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorDNI();
                system("cls");
                break;

            case 6:
                system("cls");
                menuHuespedConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}


/// /// ///

void menuHabitacion()
{
    int y=1,op=1;
    ArchivoHabitacion arc;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(40,10);
    cout<<"MENU DE HABITACIONES"<<endl;
    showItem("CARGAR HABITACION",41,12,y==1);
    showItem("ELIMINAR HABITACION",40,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR HABITACIONES",40,15,y==4);
    showItem("LISTAR POR NUMERO",41,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:  ///Flecha arriba
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesHabitacion();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorNumero();
                system("cls");
                break;

            case 6:
                system("cls");
                menuHabitacionConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuPagos()
{
    int y=1,op=1;
    ArchivoPago arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(45,10);
    cout<<"MENU DE PAGOS"<<endl;
    showItem("CARGAR PAGO",44,12,y==1);
    showItem("ELIMINAR PAGO",43,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR PAGOS",44,15,y==4);
    showItem("LISTAR POR ID",43,16,y==5);
    showItem("LISTAR POR DNI",43,17,y==6);
    showItem("CONFIGURACIONES",42,18,y==7);
    showItem("SALIR",47,19,y==8);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>8)
                {
                    y=8;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesPago();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorID();
                system("cls");
                break;

            case 6:
                system("cls");
                arc.listarPorDNI();
                system("cls");
                break;
            case 7:
                system("cls");
                menuPagoConfig();
                system("cls");
                break;

            case 8:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuRegimen()
{
    int y=1,op=1;
    ArchivoRegimenComida arc;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE REGIMEN"<<endl;
    showItem("CARGAR REGIMEN",42,12,y==1);
    showItem("ELIMINAR REGIMEN",42,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR REGIMEN",43,15,y==4);
    showItem("LISTAR POR ID",43,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesRegimen();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorID();
                system("cls");
                break;
            case 6:
                system("cls");
                menuRegimenComidaConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuTipoEmpleado()
{
    int y=1,op=1;
    ArchivoTipoEmpleado arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(41,10);
    cout<<"MENU DE SECTOR LABORAL"<<endl;
    showItem("CARGAR SECTOR LABORAL",39,12,y==1);
    showItem("ELIMINAR SECTOR",42,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR SECTORES",42,15,y==4);
    showItem("LISTAR POR ID",43,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesTipoEmpleado();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorID();
                system("cls");
                break;

            case 6:
                system("cls");
                menuTipoEmpleadoConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}


/// /// ///

void menuTurnoEmpleado()
{
    int y=1,op=1;
    ArchivoTurnoEmpleado arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(45,10);
    cout<<"MENU DE TURNOS"<<endl;
    showItem("CARGAR TURNOS",43,12,y==1);
    showItem("ELIMINAR TURNO",43,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR TURNOS",43,15,y==4);
    showItem("LISTAR POR ID",43,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesTurnoEmpleado();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorID();
                system("cls");
                break;

            case 6:
                system("cls");
                menuTurnoEmpleadoConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuCategoria()
{
    int y=1,op=1;
    ArchivoCategoria arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(43,10);
    cout<<"MENU DE CATEGORIA"<<endl;
    showItem("CARGAR CATEGORIA",42,12,y==1);
    showItem("ELIMINAR CATEGORIA",41,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR CATEGORIAS",42,15,y==4);
    showItem("LISTAR POR ID",43,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesCategoria();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorID();
                system("cls");
                break;

            case 6:
                system("cls");
                menuCategoriaConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

/// /// ///

void menuDetalles()
{
    int y=1,op=1;
    ArchivoDetalles arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(42,10);
    cout<<"MENU DETALLES DE PAGO"<<endl;
    showItem("CARGAR DETALLE",43,12,y==1);
    showItem("ELIMINAR DETALLE",42,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("LISTAR DETALLES",42,15,y==4);
    showItem("LISTAR POR ID",43,16,y==5);
    showItem("CONFIGURACIONES",42,17,y==6);
    showItem("SALIR",47,18,y==7);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>7)
                {
                    y=7;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.altaRegistro();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.bajaRegistro();
                system("cls");
                break;

            case 3:
                system("cls");
                modificacionesDetallesdePago();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.listarArchivo();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorID();
                system("cls");
                break;

            case 6:
                system("cls");
                menuDetallesPagoConfig();
                system("cls");
                break;

            case 7:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

void menuReserva()
{
    int y=1,op=1;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE RESERVA"<<endl;
    showItem("AGREGAR RESERVA",44,12,y==1);
    showItem("DISPONIBILIDAD POR CATEGORIA",45,13,y==2);
    showItem("HABITACIONES LIBRES",41,14,y==3);
    showItem("SALIR",47,15,y==4);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>4)
                {
                    y=4;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                menuHabitacion();
                system("cls");
                break;

            case 2:
                system("cls");
                menuCategoria();
                system("cls");
                break;

            case 3:
                system("cls");
                menuRegimen();
                system("cls");
                break;

            case 4:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}
void menuConfiguraciones()
{
    int y=1,op=1;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE CONFIGURACIONES"<<endl;
    showItem("COPIA",44,12,y==1);
    showItem("RESTABLECER COPIA",45,13,y==2);
    showItem("ESTABLECER DATOS DE INICIO",41,14,y==3);
    showItem("RESTABLECER DATOS DE INICIO",41,15,y==4);
    showItem("SALIR",47,16,y==5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>5)
                {
                    y=5;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiarTodo();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerTodo();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerIni();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerIni();
                system("cls");
                break;

            case 5:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}
void menuListados()
{
    int y=1,op=1;

    ArchivoHuesped arcH;
    ArchivoHabitacion arcHab;
    ArchivoCategoria arcCat;
    ArchivoRegimenComida arcReg;
    ArchivoEmpleado arcEmp;
    ArchivoTurnoEmpleado arcTur;
    ArchivoTipoEmpleado arcTip;
    ArchivoDetalles arcDet;
    ArchivoPago arcPag;
    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE LISTADOS"<<endl;
    showItem("HUESPED",44,12,y==1);
    showItem("HABITACION",45,13,y==2);
    showItem("CATEGORIA",41,14,y==3);
    showItem("REGIMEN",41,15,y==4);
    showItem("EMPLEADO",41,16,y==5);
    showItem("HORARIOS LABORALES",41,17,y==6);
    showItem("SECTORES LABORALES",41,18,y==7);
    showItem("DETALLES DE COMPRA",41,19,y==8);
    showItem("PAGOS",41,20,y==9);
    showItem("SALIR",47,21,y==10);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>10)
                {
                    y=10;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arcH.listarArchivo();
                system("cls");
                break;

            case 2:
                system("cls");
                arcHab.listarArchivo();
                system("cls");
                break;

            case 3:
                system("cls");
                arcCat.listarArchivo();
                system("cls");
                break;

            case 4:
                system("cls");
                arcReg.listarArchivo();
                system("cls");

            case 5:
                system("cls");
                arcEmp.listarArchivo();
                system("cls");

            case 6:
                system("cls");
                arcTur.listarArchivo();
                system("cls");

            case 7:
                system("cls");
                arcTip.listarArchivo();
                system("cls");

            case 8:
                system("cls");
                arcDet.listarArchivo();
                system("cls");

            case 9:
                system("cls");
                arcPag.listarArchivo();
                system("cls");

            case 10:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}
#endif // MENUS_H_INCLUDED
