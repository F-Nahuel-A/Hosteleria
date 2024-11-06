#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
void tipoDpago();
void recaudacionHabitacion();
void gananciaAnual();

void menuInforme()
{
    int y=1,op=1;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE INFORMES"<<endl;
    showItem("TIPO DE PAGO",44,12,y==1);
    showItem("HABITACIONES CON MAS RECAUDACION",35,13,y==2);
    showItem("GANANCIA ANUAL",43,14,y==3);
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
                tipoDpago();
                system("cls");
                break;

            case 2:
                system("cls");
                recaudacionHabitacion();
                system("cls");
                break;

            case 3:
                system("cls");
                gananciaAnual();
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

void tipoDpago()
{
    ArchivoPago arc;
    Pago obj;
    int tipoPago[2]={},contReg=arc.contarRegistros();
    for (int i=0;i<contReg;i++)
        {
            obj=arc.leerRegistro(i);
            if(obj.getEstado())
            {
                tipoPago[obj.getFormadepago()-1]++;
            }
        }
    float porcentaje1 = (float(tipoPago[0]) / float(contReg)) * 100;
    float porcentaje2 = (float(tipoPago[1]) / float(contReg)) * 100;

        cout<<"EL METODO CON MAS USOS FUE EL ";
    if(porcentaje1>porcentaje2)
    {
        cout<<"TIPO DE PAGO 1"<<endl<<"CON UN PORCENTAJE DE : "<<porcentaje1<<"%"<<endl;
    }
    else{cout<<"TIPO DE PAGO 2"<<endl<<"CON UN PORCENTAJE DE : "<<porcentaje2<<"%"<<endl;}
    system("pause");
}

void recaudacionHabitacion()
{
    ArchivoDetalles arcD;
    DetallesPago objD;
    float habitaciones[6]={};
    int contReg=arcD.contarRegistros();

    for (int i=0;i<contReg;i++)
    {
        objD=arcD.leerRegistro(i);
        if(objD.getEstado())
        {
            habitaciones[objD.getNumdehabitacion()-1]+=objD.getTotalabonado();
        }
    }
cout<<"RECAUDACION DE HABITACIONES"<<endl<<endl;

    for (int i=0;i<6;i++) {
        float maxRecaudado=0;
        int pos=0;

        for (int j=0;j<6;j++) {
            if(habitaciones[j] > maxRecaudado)
            {
                maxRecaudado = habitaciones[j];
                pos=j;
            }
        }

        cout<<"HABITACION : "<<pos<<endl;
        cout<<"RECAUDACION : "<<maxRecaudado<<endl<<endl;
        habitaciones[pos]=0;

    }
    system("pause");
}

void gananciaAnual() {

    ArchivoDetalles archivoDetalles;
    int cantDetalles = archivoDetalles.contarRegistros();
    float recaudadoAnual=0;

    if (cantDetalles <= 0)
    {
        cout << "NO HAY DATOS SUFICIENTES PARA CALCULAR LA MAXIMA GANANCIA." << endl;
        return;
    }

    for (int i = 0; i < cantDetalles; i++) {
        DetallesPago detalle = archivoDetalles.leerRegistro(i);

        if (detalle.getEstado()) {
            recaudadoAnual+=detalle.getTotalabonado();
        }
    }
    cout<<"LA RECAUDACION DEL 2024 ES DE : "<<recaudadoAnual<<"$"<<endl;
    system("pause");
}

#endif // INFORME_H_INCLUDED
