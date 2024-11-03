#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

void mostrarMenu();
///MENúS PRINCIPALES
void menuPersonal();
void menuServicios();
void menuPagosPrincipal();
///MENúS PRINCIPALES
void menuEmpleado();
void menuHuesped();
void menuHabitacion();
void menuPagos();
void menuRegimen();
void menuTipoEmpleado();
void menuTurnoEmpleado();

void cargarCadena(char *palabra, int tamano){

    int i=0;

    fflush(stdin);

    for (i=0; i<tamano; i++){

        palabra[i]=cin.get();

        if (palabra[i]=='\n'){

            break;

        }

    }

    palabra[i]='\0';

    fflush(stdin);

}

    void showItem(const char* text, int posx, int posy,bool selected) {
    if (selected)
    {
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
        rlutil::locate(posx,posy);
        cout<<"  "<<text<<"  "<<endl;
    }
    else {
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(posx,posy);
        cout<<"  "<<text<<"  "<<endl;

    }
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
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
    rlutil::locate(42,10);
    cout<<"HOSTELERIA-GRUPO 25"<<endl;
    showItem("HUESPED",45,12,y==1);
    showItem("PERSONAL",45,13,y==2);
    showItem("SERVICIOS",45,14,y==3);
    showItem("PAGOS",46,15,y==4);
    showItem("SALIR",46,16,y==5);

        switch (rlutil::getkey())
        {
            case 14:  ///Flecha arriba
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posición actual
                ///Cicla a la última opción si sube desde la primera
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:  ///Flecha abajo
                rlutil::locate(48, 12 + y);
                cout << " ";  ///Borra el cursor en la posición actual
                ///Cicla a la primera opción si baja desde la última
                y++;
                if(y>5)
                {
                    y=5;
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
#endif // FUNCIONESGLOBALES_H_INCLUDED
