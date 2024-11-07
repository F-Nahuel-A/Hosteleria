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

void menuConfiguraciones();

void menuConfiguracionCopias();
void menuConfiguracionRestablecer();
void menuConfiguracionEstablecerIni();
void menuConfiguracionRestablecerIni();

void menuConfiguraciones()
{
  int y=1,op=1;
  
  do
  {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(43,10);

    cout << "-----CONFIGURACIONES-----" << endl;

    showItem("COPIAR", 40, 12, y == 1);
    showItem("RESTABLECER", 40, 13, y == 2);
    showItem("ESTABLECER DATOS .INI", 40, 14, y == 3);
    showItem("RESTABLECER DATOS .INI", 40, 15, y == 4);
    showItem("<- ATRAS",44,17,y==5);

    switch (rlutil::getkey())
    {
      case 14:
          rlutil::locate(48, 12 + y);
          cout << " ";
          y--;
          if(y<1)
          {
              y=5;
          }
          break;

      case 15:
          rlutil::locate(48, 12 + y);
          cout << " ";
          y++;
          if(y>5)
          {
              y=1;
          }
          break;

      case 1:
          switch (y)
          {
            case 1:
                system("cls");
                menuConfiguracionCopias();
                system("cls");
                break;

            case 2:
                system("cls");
                menuConfiguracionRestablecer();
                break;

            case 3:
                system("cls");
                menuConfiguracionEstablecerIni();
                system("cls");
                break;

            case 4:
                system("cls");
                menuConfiguracionRestablecerIni();
                system("cls");
                break;

            case 5:
                op=0;
                break;

            default:
                break;
          }
          break;
          
      default:
          break;
    }
  }
  while(op!=0);
}

void menuConfiguracionCopias()
{
  int y = 1, op = 1;

  do
  {
    rlutil::locate(43,10);
    ///
    cout << "CONFIGURAR COPIAS" << endl;
    ///
    showItem("Categoria", 40, 12, y == 1);
    showItem("DetallesPago", 40, 13, y == 2);
    showItem("Empleado", 40, 14, y == 3);
    showItem("Huesped", 40, 15, y == 4);
    showItem("Pago", 40, 16, y == 5);
    showItem("Regimen", 40, 17, y == 6);
    showItem("Tipo", 40, 18, y == 7);
    showItem("Turno", 40, 19, y == 8);
    showItem("Habitaciones", 40, 20, y == 9);
    showItem("Todos", 40, 21, y == 10);
    ///
    showItem("<- ATRAS",44,23,y==11);
    ///
    switch (rlutil::getkey())
    {
    case 14:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y--;
        if (y < 1)
        {
            y = 11;
        }
        break;

    case 15:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y++;
        if (y > 11)
        {
            y = 1;
        }
        break;

    case 1:
        switch (y)
        {
        case 1:
          system("cls");
          copiaCategoria();
          system("cls");
            break;

        case 2:
          system("cls");
          copiaDetallesPago();
          system("cls");
            break;

        case 3:
          system("cls");
          copiaEmpleado();
          system("cls");
            break;

        case 4:
          system("cls");
          copiaHuesped();
          system("cls");
            break;

        case 5:
          system("cls");
          copiaPago();
          system("cls");
            break;

        case 6:
          system("cls");
          copiaRegimenComida();
          system("cls");
            break;

        case 7:
          system("cls");
          copiaTipoEmpleado();
          system("cls");
            break;

        case 8:
          system("cls");
          copiaTurnoEmpleado();
          system("cls");
            break;

        case 9:
          system("cls");
          copiaHabitacion();
          system("cls");
            break;

        case 10:
          system("cls");
          copiaTodos();
          system("cls");
            break;

        case 11:
          op = 0;
          break;
            
        default:
            break;
        }
    default:
        break;
    }
  }
  while (op != 0);
}

void menuConfiguracionRestablecer()
{
  int y = 1, op = 1;

  do
  {
    rlutil::locate(43,10);
    ///
    cout << "RESTABLECER ARCHIVOS" << endl;
    ///
    showItem("Categoria", 40, 12, y == 1);
    showItem("DetallesPago", 40, 13, y == 2);
    showItem("Empleado", 40, 14, y == 3);
    showItem("Huesped", 40, 15, y == 4);
    showItem("Pago", 40, 16, y == 5);
    showItem("Regimen", 40, 17, y == 6);
    showItem("Tipo", 40, 18, y == 7);
    showItem("Turno", 40, 19, y == 8);
    showItem("Habitaciones", 40, 20, y == 9);
    showItem("Todos", 40, 21, y == 10);
    ///
    showItem("<- ATRAS",44,23,y==11);
    ///
    switch (rlutil::getkey())
    {
    case 14:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y--;
        if (y < 1)
        {
            y = 11;
        }
        break;

    case 15:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y++;
        if (y > 11)
        {
            y = 1;
        }
        break;

    case 1:
        switch (y)
        {
        case 1:
          system("cls");
          restablecerCategoria();
          system("cls");
            break;

        case 2:
          system("cls");
          restablecerDetallesPago();
          system("cls");
            break;

        case 3:
          system("cls");
          restablecerEmpleado();
          system("cls");
            break;

        case 4:
          system("cls");
          restablecerHuesped();
          system("cls");
            break;

        case 5:
          system("cls");
          restablecerPago();
          system("cls");
            break;

        case 6:
          system("cls");
          restablecerRegimenComida();
          system("cls");
            break;

        case 7:
          system("cls");
          restablecerTipoEmpleado();
          system("cls");
            break;

        case 8:
          system("cls");
          restablecerTurnoEmpleado();
          system("cls");
            break;

        case 9:
          system("cls");
          restablecerHabitacion();
          system("cls");
            break;

        case 10:
          system("cls");
          restablecerTodos();
          system("cls");
            break;

        case 11:
          op = 0;
          break;
            
        default:
            break;
        }
    default:
        break;
    }
  }
  while (op != 0);
}

void menuConfiguracionEstablecerIni()
{
  int y = 1, op = 1;

  do
  {
    rlutil::locate(43,10);
    ///
    cout << "ESTABLECER DATOS .INI" << endl;
    ///
    showItem("Categoria", 40, 12, y == 1);
    showItem("DetallesPago", 40, 13, y == 2);
    showItem("Empleado", 40, 14, y == 3);
    showItem("Huesped", 40, 15, y == 4);
    showItem("Pago", 40, 16, y == 5);
    showItem("Regimen", 40, 17, y == 6);
    showItem("Tipo", 40, 18, y == 7);
    showItem("Turno", 40, 19, y == 8);
    showItem("Habitaciones", 40, 20, y == 9);
    showItem("Todos", 40, 21, y == 10);
    ///
    showItem("<- ATRAS",44,23,y==11);
    ///
    switch (rlutil::getkey())
    {
    case 14:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y--;
        if (y < 1)
        {
            y = 11;
        }
        break;

    case 15:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y++;
        if (y > 11)
        {
            y = 1;
        }
        break;

    case 1:
        switch (y)
        {
        case 1:
          system("cls");
          establecerDatosIniCategoria();
          system("cls");
            break;

        case 2:
          system("cls");
          establecerDatosIniDetallesPago();
          system("cls");
            break;

        case 3:
          system("cls");
          establecerDatosIniEmpleado();
          system("cls");
            break;

        case 4:
          system("cls");
          establecerDatosIniHuesped();
          system("cls");
            break;

        case 5:
          system("cls");
          establecerDatosIniPago();
          system("cls");
            break;

        case 6:
          system("cls");
          establecerDatosIniRegimenComida();
          system("cls");
            break;

        case 7:
          system("cls");
          establecerDatosIniTipoEmpleado();
          system("cls");
            break;

        case 8:
          system("cls");
          establecerDatosIniTurnoEmpleado();
          system("cls");
            break;

        case 9:
          system("cls");
          establecerDatosIniHabitacion();
          system("cls");
            break;

        case 10:
          system("cls");
          establecerDatosIniTodos();
          system("cls");
            break;

        case 11:
          op = 0;
          break;
            
        default:
            break;
        }
    default:
        break;
    }
  }
  while (op != 0);
}

void menuConfiguracionRestablecerIni()
{
  int y = 1, op = 1;

  do
  {
    rlutil::locate(43,10);
    ///
    cout << "RESTABLECER DATOS .INI" << endl;
    ///
    showItem("Categoria", 40, 12, y == 1);
    showItem("DetallesPago", 40, 13, y == 2);
    showItem("Empleado", 40, 14, y == 3);
    showItem("Huesped", 40, 15, y == 4);
    showItem("Pago", 40, 16, y == 5);
    showItem("Regimen", 40, 17, y == 6);
    showItem("Tipo", 40, 18, y == 7);
    showItem("Turno", 40, 19, y == 8);
    showItem("Habitaciones", 40, 20, y == 9);
    showItem("Todos", 40, 21, y == 10);
    ///
    showItem("<- ATRAS",44,23,y==11);
    ///
    switch (rlutil::getkey())
    {
    case 14:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y--;
        if (y < 1)
        {
            y = 11;
        }
        break;

    case 15:
        rlutil::locate(48, 12 + y);
        cout << " ";
        y++;
        if (y > 11)
        {
            y = 1;
        }
        break;

    case 1:
        switch (y)
        {
        case 1:
          system("cls");
          restablecerDatosIniCategoria();
          system("cls");
            break;

        case 2:
          system("cls");
          restablecerDatosIniDetallesPago();
          system("cls");
            break;

        case 3:
          system("cls");
          restablecerDatosIniEmpleado();
          system("cls");
            break;

        case 4:
          system("cls");
          restablecerDatosIniHuesped();
          system("cls");
            break;

        case 5:
          system("cls");
          restablecerDatosIniPago();
          system("cls");
            break;

        case 6:
          system("cls");
          restablecerDatosIniRegimenComida();
          system("cls");
            break;

        case 7:
          system("cls");
          restablecerDatosIniTipoEmpleado();
          system("cls");
            break;

        case 8:
          system("cls");
          restablecerDatosIniTurnoEmpleado();
          system("cls");
            break;

        case 9:
          system("cls");
          restablecerDatosIniHabitacion();
          system("cls");
            break;

        case 10:
          system("cls");
          restablecerDatosIniTodos();
          system("cls");
            break;

        case 11:
          op = 0;
          break;
            
        default:
            break;
        }
    default:
        break;
    }
  }
  while (op != 0);
}

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
    showItem("HUESPED",45,12,y==1);
    showItem("PERSONAL",45,13,y==2);
    showItem("SERVICIOS",44,14,y==3);
    showItem("PAGOS",46,15,y==4);
    showItem("INFORMES",45,16,y==5);
    showItem("LISTADOS",46,17,y==6);
    showItem("CONFIGURACION",46,18,y==7);
    showItem("SALIR",46,19,y==8);

        switch (rlutil::getkey())
        {
            case 14:  ///Flecha arriba
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posición actual
                ///Cicla a la última opción si sube desde la primera
                y--;
                if(y<1)
                {
                    y=8;
                }
                break;

            case 15:  ///Flecha abajo
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posición actual
                ///Cicla a la primera opción si baja desde la última
                y++;
                if(y>8)
                {
                    y=1;
                }
                break;

            case 1:  ///Enter para elegir
                switch (y)
                {
            case 1:
                system("cls");
                menuHuesped();
                system("cls");
                break;

            case 2:
                system("cls");
                menuPersonal();
                system("cls");
                break;

            case 3:
                system("cls");
                menuServicios();
                system("cls");
                break;

            case 4:
                system("cls");
                menuPagosPrincipal();
                system("cls");
                break;

            case 5:
                system("cls");
                menuInforme();
                system("cls");
                break;

            case 6:
              system("cls");
              menuListados();
              system("cls");
              break;
            case 7:
              system("cls");
              menuConfiguraciones();
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
                //menuEmpleadoConfig();
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
                //menuHuespedConfig();
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
                //menuHabitacionConfig();
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
                //menuPagoConfig();
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
                //menuRegimenComidaConfig();
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
                //menuTipoEmpleadoConfig();
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
                //menuTurnoEmpleadoConfig();
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
                      archivoHabitacion.listarArchivo();
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
                //menuCategoriaConfig();
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
                //menuDetallesPagoConfig();
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

#endif // MENUS_H_INCLUDED
