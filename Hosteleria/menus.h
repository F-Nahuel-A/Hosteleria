#ifndef MENUS_H_INCLUDED
#define MENUS_H_INCLUDED

void mostrarMenu();
///MENUS PRINCIPALES
void menuPersonal();
void menuServicios();
void menuPagosPrincipal();
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
void menuListados();
void menuReserva();

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
    showItem("CONFIGURACION",42,19,y==8);
    showItem("SALIR",46,20,y==9);

        switch (rlutil::getkey())
        {
            case 14:  ///Flecha arriba
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posición actual
                ///Cicla a la última opción si sube desde la primera
                y--;
                if(y<1)
                {
                    y=9;
                }
                break;

            case 15:  ///Flecha abajo
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posición actual
                ///Cicla a la primera opción si baja desde la última
                y++;
                if(y>9)
                {
                    y=1;
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
                agregarReserva();
                system("cls");
                break;

            case 2:
                system("cls");
//                menuCategoria();
                system("cls");
                break;

            case 3:
                system("cls");
//                menuRegimen();
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
    showItem("LISTAR POR ID",43,15,y==4);
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
                arc.listarPorID();
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
    showItem("LISPAR POR DNI",43,15,y==4);
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
                arc.listarPorDNI();
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
    showItem("LISTAR POR NUMERO",41,15,y==4);
    showItem("SALIR",47,16,y==5);

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
                arc.listarPorNumero();
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
    showItem("LISTAR POR ID",43,15,y==4);
    showItem("LISTAR POR DNI",43,16,y==5);
    showItem("SALIR",47,17,y==6);

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
                if(y>6)
                {
                    y=6;
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
                arc.listarPorID();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.listarPorDNI();
                system("cls");
                break;


            case 6:
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
    showItem("LISTAR POR ID",43,15,y==4);
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
                arc.listarPorID();
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
    showItem("LISTAR POR ID",43,15,y==4);
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
                arc.listarPorID();
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
    showItem("LISTAR POR ID",43,15,y==4);
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
                arc.listarPorID();
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

/// /// ///

void menuListados()
{
  int y=1,op=1;
    ArchivoCategoria archivoCategoria;
    ArchivoDetalles archivoDetalles;
    ArchivoEmpleado archivoEmpleado;
    ArchivoHabitacion archivoHabitacion;
    ArchivoHuesped archivoHuesped;
    ArchivoPago archivoPago;
    ArchivoPersona archivoPersona;
    ArchivoRegimenComida archivoRegimenComida;
    ArchivoTipoEmpleado archivoTipoEmpleado;
    ArchivoTurnoEmpleado archivoTurnoEmpleado;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(43,10);
    cout<<"-----LISTADOS-----"<<endl;
    showItem("LISTAR CATEGORIAS",40,12,y==1);
    showItem("LISTAR DETALLES",40,13,y==2);
    showItem("LISTAR EMPLEADOS",40,14,y==3);
    showItem("LISTAR HABITACIONES",40,15,y==4);
    showItem("LISTAR HUESPEDES",40,16,y==5);
    showItem("LISTAR PAGOS",40,17,y==6);
    showItem("LISTAR REGIMENES",40,18,y==7);
    showItem("LISTAR TIPOS DE EMPLEADOS",40,19,y==8);
    showItem("LISTAR TURNOS DE EMPLEADOS",40,20,y==9);
    showItem("<- ATRAS",44,22,y==10);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=10;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>10)
                {
                    y=1;
                }
                break;

            case 1:
                switch (y)
                {
                  case 1:
                      system("cls");
                      archivoCategoria.listarArchivo();
                      system("cls");
                      break;

                  case 2:
                      system("cls");
                      archivoDetalles.listarArchivo();
                      system("cls");
                      break;

                  case 3:
                      system("cls");
                      archivoEmpleado.listarArchivo();
                      system("cls");
                      break;

                  case 4:
                      system("cls");
                      archivoHabitacion.listarArchivo();
                      system("cls");
                      break;

                  case 5:
                      system("cls");
                      archivoHuesped.listarArchivo();
                      system("cls");
                      break;

                  case 6:
                      system("cls");
                      archivoPago.listarArchivo();
                      system("cls");
                      break;

                  case 7:
                      system("cls");
                      archivoRegimenComida.listarArchivo();
                      system("cls");
                      break;
                  case 8:
                      system("cls");
                      archivoTipoEmpleado.listarArchivo();
                      system("cls");
                      break;
                  case 9:
                      system("cls");
                      archivoTurnoEmpleado.listarArchivo();
                      system("cls");
                      break;
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
    showItem("LISTAR POR ID",43,15,y==4);
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
                arc.listarPorID();
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
    showItem("LISTAR POR ID",43,15,y==4);
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
                arc.listarPorID();
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

#endif // MENUS_H_INCLUDED
