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
    rlutil::locate(46, 11);
    cout << "-----GRUPO 25-----\n";
    rlutil::locate(50, 12);
    cout << " SUBMENU 1 \n";
    rlutil::locate(50, 13);
    cout << " SUBMENU 2 \n";
    rlutil::locate(50, 14);
    cout << " SUBMENU 3 \n";
    rlutil::locate(50, 15);
    cout << " SUBMENU 4 \n";
    rlutil::locate(50, 16);
    cout << " SALIR \n";
  }
}

void mostrarCursor(int&opcion)
{
    int key=0, y=0;

    rlutil::hidecursor();

    do
    {
        rlutil::locate(48, 12+y);
        cout << char(175) << "\n";

        key=rlutil::getkey();

        switch (key)
        {
            case 14:  ///Flecha arriba
                rlutil::locate(48, 12 + y);
                cout << " \n";  ///Borra el cursor en la posición actual
                ///Cicla a la última opción si sube desde la primera
                if(y - 1 < 0) {y = 4;} else {y = y - 1;}
                break;

            case 15:  ///Flecha abajo
                rlutil::locate(48, 12 + y);
                cout << " \n";  ///Borra el cursor en la posición actual
                ///Cicla a la primera opción si baja desde la última
                if(y + 1 > 4) {y = 0;} else {y = y + 1;}
                break;

            case 1:  ///Enter para elegir
                ///Asigna 0 si selecciona "SALIR", o la opción correspondiente
                if(y == 4) {opcion = 0;} else {opcion = y + 1;}
                break;

            default:
                break;
        }
    }
    while(key!=1);
}
#endif // FUNCIONESGLOBALES_H_INCLUDED
