#ifndef MENUCONFIGURACIONES_H_INCLUDED
#define MENUCONFIGURACIONES_H_INCLUDED

void menuCategoriaConfig();
void menuDetallesPagoConfig();
void menuEmpleadoConfig();
void menuHuespedConfig();
void menuPagoConfig();
void menuRegimenComidaConfig();
void menuTipoEmpleadoConfig();
void menuTurnoEmpleadoConfig();
void menuHabitacionConfig();

void menuCategoriaConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(35, 10);
        cout << "MENU DE CATEGORIA CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
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
                restablecerCategoria();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniCategoria();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniCategoria();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuDetallesPagoConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(33, 10);
        cout << "MENU DE DETALLES DE PAGO CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaDetallesPago();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerDetallesPago();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniDetallesPago();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniDetallesPago();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuEmpleadoConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(35, 10);
        cout << "MENU DE EMPLEADO CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaEmpleado();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerEmpleado();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniEmpleado();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniEmpleado();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuHuespedConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(36, 10);
        cout << "MENU DE HUESPED CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaHuesped();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerHuesped();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniHuesped();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniHuesped();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuPagoConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(37, 10);
        cout << "MENU DE PAGO CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaPago();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerPago();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniPago();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniPago();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuRegimenComidaConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(31, 10);
        cout << "MENU DE REGIMEN DE COMIDA CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaRegimenComida();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerRegimenComida();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniRegimenComida();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniRegimenComida();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuTipoEmpleadoConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(32, 10);
        cout << "MENU DE TIPO DE EMPLEADO CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaTipoEmpleado();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerTipoEmpleado();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniTipoEmpleado();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniTipoEmpleado();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuTurnoEmpleadoConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(32, 10);
        cout << "MENU DE TURNO DE EMPLEADO CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaTurnoEmpleado();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerTurnoEmpleado();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniTurnoEmpleado();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniTurnoEmpleado();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}

void menuHabitacionConfig()
{
    int y = 1, op = 1;

    do
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::hidecursor();
        rlutil::locate(34, 10);
        cout << "MENU DE HABITACION CONFIGURACIONES" << endl;
        showItem("COPIAR", 46, 12, y == 1);
        showItem("RESTABLECER", 44, 13, y == 2);
        showItem("ESTABLECER DATOS .INI", 38, 14, y == 3);
        showItem("RESTABLECER DATOS .INI", 38, 15, y == 4);
        showItem("SALIR", 47, 16, y == 5);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if (y < 1) y = 1;
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if (y > 5) y = 5;
                break;
             case 1:
                switch (y)
                {
            case 1:
                system("cls");
                copiaHabitacion();
                system("cls");
                break;

            case 2:
                system("cls");
                restablecerHabitacion();
                system("cls");
                break;

            case 3:
                system("cls");
                establecerDatosIniHabitacion();
                system("cls");
                break;

            case 4:
                system("cls");
                restablecerDatosIniHabitacion();
                system("cls");
                break;

            case 5:
                op = 0;
                break;
                }
            default:
                break;
        }
    } while (op != 0);
}


#endif // MENUCONFIGURACIONES_H_INCLUDED
