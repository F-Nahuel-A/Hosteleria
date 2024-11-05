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
    system("cls");
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
                system("pause");
                break;

            case 2:
                system("cls");
                recaudacionHabitacion();
                system("pause");
                break;

            case 3:
                system("cls");
//                gananciaAnual();
                system("pause");
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

        cout<<"EL METODO CON MAS USOS FUE EL : ";
    if(porcentaje1>porcentaje2)
    {
        cout<<"TIPO DE PAGO 1"<<"CON UN PORCENTAJE DE : "<<porcentaje1<<"%"<<endl;
    }
    else{cout<<"TIPO DE PAGO 2"<<"CON UN PORCENTAJE DE : "<<porcentaje2<<"%"<<endl;}
}

void recaudacionHabitacion()
{
    ArchivoHabitacion archivoHabitacion;
    ArchivoCategoria archivoCategoria;

    int contarHabitaciones = archivoHabitacion.contarRegistros();
    int contarCategorias = archivoCategoria.contarRegistros();
    if (contarHabitaciones < 0 || contarCategorias < 0) 
    {
        cout << "ERROR AL ABRIR EL ARCHIVO\n";
        return;
    }

    Habitacion* habitaciones = new Habitacion[contarHabitaciones];
    
    for (int i = 0; i < contarHabitaciones; i++) 
    {
        habitaciones[i] = archivoHabitacion.leerRegistro(i);
    }

    cout << "-------RECAUDACION POR HABITACION-------\n";
    cout << "| NUM HABITACION | RECAUDACION         |\n";
    cout << "----------------------------------------\n";

    for (int i = 0; i < contarHabitaciones; i++) 
    {
        Habitacion habitacion = habitaciones[i];
        if (habitacion.getEstado()) 
        {
            int idCategoria = habitacion.getIdCategoria();
            int capacidad = habitacion.getCapacidad();
            float precioPorPersona = 0.0f;

            int posCategoria = archivoCategoria.buscarRegistro(idCategoria);
            if (posCategoria != -1) 
            {
                Categoria categoria = archivoCategoria.leerRegistro(posCategoria);
                precioPorPersona = categoria.getPrecioXpersona();
            }

            if (habitacion.getDisponibilidad() == 1) 
            {
                float recaudacion = capacidad * precioPorPersona;
                rlutil::locate(1, 4+i*2);
                cout << "| " << habitacion.getNumero();
                rlutil::locate(18, 4+i*2);
                cout << "| $" << recaudacion << "\n";
                rlutil::locate(40, 4+i*2);
                cout << "|\n";
                cout << "-----------------+----------------------\n";
                cout << "|                |                     |\n";
            } 
            else 
            {
                cout << "| " << habitacion.getNumero() << "| NO TIENE RECAUDACION " << "\n";
                cout << "-----------------+----------------------\n";
                cout << "|                |                     |\n";
            }
        }
    }
    cout << "----------------------------------------\n";

    delete[] habitaciones;
}

#endif // INFORME_H_INCLUDED
