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
    rlutil::locate(37,10);
    cout<<"MENU DE MODIFICACIONES EMPLEADO"<<endl;
    showItem("ID SECTOR LABORAL",41,12,y==1);
    showItem("ID HORARIO LABORAL",41,13,y==2);
    showItem("MODIFICAR ARCHIVO",41,14,y==3);
    showItem("FECHA DE INGRESO",42,15,y==4);
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
                arc.cambiarTipoEmpleado();
                system("cls");
                break;

            case 2:
                system("cls");
                arc.cambiarTurnoEmpleado();
                system("cls");
                break;

            case 3:
                system("cls");
                arc.cambiarFechaIngreso();
                system("cls");
                break;

            case 4:
                system("cls");
                cout<<"prueba"<<endl;
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


#endif // MODIFICACIONES_H_INCLUDED
