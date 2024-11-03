#ifndef MENUHABITACION_H_INCLUDED
#define MENUHABITACION_H_INCLUDED

void menuHabitacion()
{
    int y=1,op=1;


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
    showItem("SALIR",47,17,y==6);

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
                cout<<"ola"<<endl;
                system("cls");
                break;

            case 2:
                system("cls");
                cout<<"ola"<<endl;
                system("cls");
                break;

            case 3:
                system("cls");
                cout<<"ola"<<endl;
                system("cls");
                break;

            case 4:
                system("cls");
                cout<<"ola"<<endl;
                system("cls");
                break;

            case 5:
                system("cls");
                cout<<"ola"<<endl;
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


#endif // MENUHABITACION_H_INCLUDED
