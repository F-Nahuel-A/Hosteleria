#ifndef MODIFICACIONES_H_INCLUDED
#define MODIFICACIONES_H_INCLUDED

void modificacionesEmpleado();
void modificacionesHuesped();
void modificacionesTipoEmpleado();
void modificacionesTurnoEmpleado();
void modificacionesCategoria();
void modificacionesHabitacion();
void modificacionesRegimen();
void modificacionesPago();
void modificacionesDetallesdePago();

void modificacionesEmpleado()
{
    int y=1,op=1;
    ArchivoEmpleado arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(36,10);
    cout<<"MENU DE MODIFICACIONES EMPLEADO"<<endl;
    showItem("DNI",48,12,y==1);
    showItem("NOMBRE",47,13,y==2);
    showItem("APELLIDO",46,14,y==3);
    showItem("FECHA DE NACIMIENTO",40,15,y==4);
    showItem("TELEFONO",46,16,y==5);
    showItem("ID SECTOR LABORAL",41,17,y==6);
    showItem("ID HORARIO LABORAL",41,18,y==7);
    showItem("FECHA DE INGRESO",42,19,y==8);
    showItem("SALIR",47,20,y==9);

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
                if(y>9)
                {
                    y=9;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.cambiarDNI();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarNombre();
                system("cls");
                break;

            case 3:
                system("cls");
                arc.cambiarApellido();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.cambiarFechaIngreso();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.cambiarTelefono();
                system("cls");
                break;

            case 6:
                system("cls");
                arc.cambiarTipoEmpleado();
                system("cls");
                break;

            case 7:
                system("cls");
                arc.cambiarTurnoEmpleado();
                system("cls");
                break;

            case 8:
                system("cls");
                arc.cambiarFechaIngreso();
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

void modificacionesHuesped()
{
    int y=1,op=1;
    ArchivoHuesped arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(37,10);
    cout<<"MENU DE MODIFICACIONES HUESPED"<<endl;
    showItem("DNI",48,12,y==1);
    showItem("NOMBRE",47,13,y==2);
    showItem("APELLIDO",46,14,y==3);
    showItem("FECHA DE NACIMIENTO",40,15,y==4);
    showItem("TELEFONO",46,16,y==5);
    showItem("EMAIL",47,17,y==6);
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
                arc.cambiarDNI();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarNombre();
                system("cls");
                break;

            case 3:
                system("cls");
                arc.cambiarApellido();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.cambiarFechaNacimiento();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.cambiarTelefono();
                system("cls");
                break;

            case 6:
                system("cls");
                arc.cambiarEmail();
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

void modificacionesTipoEmpleado()
{
    int y=1,op=1;
    ArchivoTipoEmpleado arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(38,10);
    cout<<"MENU DE MODIFICACIONES SECTOR"<<endl;
    showItem("OCUPACION",46,12,y==1);
    showItem("SUELDO",47,13,y==2);
    showItem("SALIR",47,14,y==3);

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
                arc.cambiarOcupacion();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarSueldo();
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

void modificacionesTurnoEmpleado()
{
    int y=1,op=1;
    ArchivoTurnoEmpleado arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(38,10);
    cout<<"MENU DE MODIFICACIONES TURNOS"<<endl;
    showItem("HORARIO",46,12,y==1);
    showItem("SALIR",47,13,y==2);

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
                if(y>2)
                {
                    y=2;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                arc.cambiarHorario();
                system("cls");
                break;

            case 2:
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

void modificacionesCategoria()
{
    int y=1,op=1;
    ArchivoCategoria arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(35,10);
    cout<<"MENU DE MODIFICACIONES CATEGORIA"<<endl;
    showItem("DESCRIPCION",44,12,y==1);
    showItem("PRECIO POR PERSONA",41,13,y==2);
    showItem("SALIR",47,14,y==3);

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
                arc.cambiarDescripcion();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarPrecioXpersona();
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

void modificacionesHabitacion()
{
    int y=1,op=1;
    ArchivoHabitacion arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(36,10);
    cout<<"MENU DE MODIFICACIONES CATEGORIA"<<endl;
    showItem("ID REGIMEN",44,12,y==1);
    showItem("ID CATEGORIA",43,13,y==2);
    showItem("DISPONIBILIDAD",43,14,y==3);
    showItem("CAPACIDAD",45,15,y==4);
    showItem("INGRESO",46,16,y==5);
    showItem("SALIDA",46,17,y==6);
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
                arc.cambiarIDregimen();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarIDcategoria();
                system("cls");
                break;

            case 3:
                system("cls");
                arc.cambiarDisponibilidad();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.cambiarCapacidad();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.cambiarFechaLlegada();
                system("cls");
                break;

            case 6:
                system("cls");
                arc.cambiarFechaSalida();
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

void modificacionesRegimen()
{
    int y=1,op=1;
    ArchivoRegimenComida arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(36,10);
    cout<<"MENU DE MODIFICACIONES REGIMEN"<<endl;
    showItem("DESCRIPCION",44,12,y==1);
    showItem("PRECIO",46,13,y==2);
    showItem("SALIR",47,14,y==3);

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
                arc.cambiarDescripcion();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarPrecio();
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

void modificacionesPago()
{
    int y=1,op=1;
    ArchivoPago arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(37,10);
    cout<<"MENU DE MODIFICACIONES REGIMEN"<<endl;
    showItem("ID DE DETALLE",43,12,y==1);
    showItem("DNI",48,13,y==2);
    showItem("FECHA DE PAGO",43,14,y==3);
    showItem("FORMA DE PAGO",43,15,y==4);
    showItem("TOTAL",47,16,y==5);
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
                arc.cambiarIDdetalle();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarDNI();
                system("cls");
                break;

            case 3:
                system("cls");
                arc.cambiarFecha();
                system("cls");
                break;

            case 4:
                system("cls");
                arc.cambiarFormadPago();
                system("cls");
                break;

            case 5:
                system("cls");
                arc.cambiarTotalAbonado();
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

void modificacionesDetallesdePago()
{
    int y=1,op=1;
    ArchivoDetalles arc;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(37,10);
    cout<<"MENU DE MODIFICACIONES REGIMEN"<<endl;
    showItem("NUMERO DE DOCUMENTO",42,12,y==1);
    showItem("NUMERO DE HABITACION",40,13,y==2);
    showItem("TOTAL A PAGAR",43,14,y==3);
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
                arc.cambiarDNI();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarNumHabitacion();
                system("cls");
                break;

            case 3:
                system("cls");
                arc.cambiarTotalApagar();
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
#endif // MODIFICACIONES_H_INCLUDED
