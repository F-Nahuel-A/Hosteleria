#ifndef PMENUPAGOS_H_INCLUDED
#define PMENUPAGOS_H_INCLUDED

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


#endif // PMENUPAGOS_H_INCLUDED
