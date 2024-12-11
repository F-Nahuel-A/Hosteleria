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
                tipoPago[obj.getFormadepago()]++;
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

    ArchivoPago arcP;
    Pago objP;

    ArchivoHabitacion arcH;
    Habitacion objH=arcH.leerRegistro(-1);
    int cant=objH.getNumero();
    float *recau;
    recau=new float[cant];
    for (int i=0;i<cant;i++){recau[i]=0;}
    int contReg=arcP.contarRegistros();

    for (int i=0;i<contReg;i++)
        {
            objP=arcP.leerRegistro(i);
            int pos=arcD.buscarRegistro(objP.getIDdetalle());
            objD=arcD.leerRegistro(pos);
            recau[objD.getNumdehabitacion()]+=objP.getTotalAbonado();


        }

    for (int i=0;i<cant;i++)
    {
        cout<<"HABITACION "<<i+1<<" : "<<recau[i]<<"$"<<endl;;
    }

    system("pause");
    delete[] recau;
}

void gananciaAnual() {

    ArchivoPago arcP;
    Pago objP;
    int catReg=arcP.contarRegistros();
    float recauAnual=0;

    if (catReg<=0)
    {
        cout << "NO HAY DATOS SUFICIENTES PARA CALCULAR LA MAXIMA GANANCIA." << endl;
        system("pause");
        return;
    }

    for (int i=0;i<catReg;i++) {
        objP=arcP.leerRegistro(i);

        if (objP.getEstado()) {
            recauAnual+=objP.getTotalAbonado();
        }
    }
    cout<<"LA RECAUDACION DEL 2024 ES DE : "<<recauAnual<<"$"<<endl;
    system("pause");
}

#endif // INFORME_H_INCLUDED
