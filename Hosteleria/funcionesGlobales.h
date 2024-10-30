#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED
void mostrarCursor(int&opcion);

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

void mostrarMenu()
{
  {
    rlutil::cls();
    rlutil::locate(26, 9);
    cout << "-----GRUPO 25-----\n";
    rlutil::locate(30, 11);
    cout << " SUBMENU 1 \n";
    rlutil::locate(30, 12);
    cout << " SUBMENU 2 \n";
    rlutil::locate(30, 13);
    cout << " SUBMENU 3 \n";
    rlutil::locate(30, 14);
    cout << " SUBMENU 4 \n";
    rlutil::locate(30, 15);
    cout << " SALIR \n";
  }
}

void mostrarCursor(int&opcion)
{
    int key=0, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::locate(28, 11+y);
        cout << char(175) << "\n";

        key=rlutil::getkey();

        switch(key)
        {
        case 14:
            rlutil::locate(28, 11+y);
            cout << " \n";
            y--;
            if(y<0)
            {
                y=4;
            }
            break;
        case 15:
            rlutil::locate(28, 11+y);
            cout << " \n";
            y++;
            if(y>4)
            {
                y=0;
            }
            break;
        case 1:
            switch(y)
            {
            case 0:
                opcion=1;
                break;
            case 1:
                opcion=2;
                break;
            case 2:
                opcion=3;
                break;
            case 3:
                opcion=4;
                break;
            case 4:
                opcion=0;
                break;
            }
            break;
        }
    }
    while(key!=1);
}
#endif // FUNCIONESGLOBALES_H_INCLUDED
