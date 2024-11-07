#ifndef MENUCONFIGURACIONES_H_INCLUDED
#define MENUCONFIGURACIONES_H_INCLUDED
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
                system("cls");
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
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 2:
          system("cls");
          copiaDetallesPago();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 3:
          system("cls");
          copiaEmpleado();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 4:
          system("cls");
          copiaHuesped();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 5:
          system("cls");
          copiaPago();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 6:
          system("cls");
          copiaRegimenComida();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 7:
          system("cls");
          copiaTipoEmpleado();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 8:
          system("cls");
          copiaTurnoEmpleado();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 9:
          system("cls");
          copiaHabitacion();
          cout << "ARCHIVO COPIADO" << endl;
          system("pause");
          system("cls");
            break;

        case 10:
          system("cls");
          copiaTodos();
          cout << "TODOS LOS ARCHIVOS HAN SIDO COPIADOS" << endl;
          system("pause");
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
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 2:
          system("cls");
          restablecerDetallesPago();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 3:
          system("cls");
          restablecerEmpleado();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 4:
          system("cls");
          restablecerHuesped();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 5:
          system("cls");
          restablecerPago();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 6:
          system("cls");
          restablecerRegimenComida();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 7:
          system("cls");
          restablecerTipoEmpleado();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 8:
          system("cls");
          restablecerTurnoEmpleado();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 9:
          system("cls");
          restablecerHabitacion();
          cout << "ARCHIVO RESTABLECIDO" << endl;
          system("pause");
          system("cls");
            break;

        case 10:
          system("cls");
          restablecerTodos();
          cout << "TODOS LOS ARCHIVOS HAN SIDO RESTABLECIDOS" << endl;
          system("pause");
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
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 2:
          system("cls");
          establecerDatosIniDetallesPago();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 3:
          system("cls");
          establecerDatosIniEmpleado();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 4:
          system("cls");
          establecerDatosIniHuesped();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 5:
          system("cls");
          establecerDatosIniPago();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 6:
          system("cls");
          establecerDatosIniRegimenComida();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 7:
          system("cls");
          establecerDatosIniTipoEmpleado();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 8:
          system("cls");
          establecerDatosIniTurnoEmpleado();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 9:
          system("cls");
          establecerDatosIniHabitacion();
          cout << "DATOS .INI ESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 10:
          system("cls");
          establecerDatosIniTodos();
          cout << "TODOS LOS DATOS .INI HAN SIDO ESTABLECIDOS" << endl;
          system("pause");
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
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 2:
          system("cls");
          restablecerDatosIniDetallesPago();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 3:
          system("cls");
          restablecerDatosIniEmpleado();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 4:
          system("cls");
          restablecerDatosIniHuesped();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 5:
          system("cls");
          restablecerDatosIniPago();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 6:
          system("cls");
          restablecerDatosIniRegimenComida();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 7:
          system("cls");
          restablecerDatosIniTipoEmpleado();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 8:
          system("cls");
          restablecerDatosIniTurnoEmpleado();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 9:
          system("cls");
          restablecerDatosIniHabitacion();
          cout << "DATOS .INI RESTABLECIDOS" << endl;
          system("pause");
          system("cls");
            break;

        case 10:
          system("cls");
          restablecerDatosIniTodos();
          cout << "TODOS LOS DATOS .INI HAN SIDO RESTABLECIDOS" << endl;
          system("pause");
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
#endif // MENUCONFIGURACIONES_H_INCLUDED
