#ifndef FUNCIONESGLOBALES_H_INCLUDED
#define FUNCIONESGLOBALES_H_INCLUDED

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


#endif // FUNCIONESGLOBALES_H_INCLUDED
