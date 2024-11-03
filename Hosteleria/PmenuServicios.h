#ifndef PMENUSERVICIOS_H_INCLUDED
#define PMENUSERVICIOS_H_INCLUDED

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


#endif // PMENUSERVICIOS_H_INCLUDED
