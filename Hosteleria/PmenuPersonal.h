#ifndef PMENUPERSONAL_H_INCLUDED
#define PMENUPERSONAL_H_INCLUDED

void menuPersonal()
{
    int y=1,op=1;


    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(43,10);
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


#endif // PMENUPERSONAL_H_INCLUDED
