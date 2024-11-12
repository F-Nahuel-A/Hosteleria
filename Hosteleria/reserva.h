#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED
int verificarCapacidad(int cap);
int verificarCategoria(int cat);
int verificarHabitacion(int num);
int verificarRegimen(int reg);
int habitacionesLibres(int cap,int cat);
float confirmacion(int cat,int cap,int num,int reg,float total);
void habitacionesDisponiblesHasta();

void agregarReserva()
{
    int categoria,capacidad,numHab,regimen;
    char aux;

    ArchivoHabitacion arcHab;
    Habitacion objHab;

    categoria=verificarCategoria(categoria);
    if(categoria==-1){return;}

    capacidad=verificarCapacidad(capacidad);
    if(capacidad==-1){return;}

    cout<<endl<<"HABITACIONES DISPONIBLES : "<<endl;
    int libres=habitacionesLibres(capacidad,categoria);
    if(libres==0)
    {
        cout<<"NO HAY HABITACIONES DISPONIBLES."<<endl;
        system("pause");
        return;
    }

    cout<<endl<<"DESEA CONTINUAR ?"<<endl<<"S/N : ";
    cin>>aux;
    if(aux=='n' || aux=='N'){return;}

    system("cls");
    numHab=verificarHabitacion(numHab);
    if(numHab==-1){return;}
    cout<<endl<<"DESEA UN REGIMEN DE COMIDA ?"<<endl<<"S/N : ";
    cin>>aux;
    cout<<endl;
    if(aux=='s' || aux=='S')
        {
            regimen=verificarRegimen(regimen);
        }
        else{regimen=0;}

    system("cls");
    float totalApagar;
    totalApagar=confirmacion(categoria,capacidad,numHab,regimen,totalApagar);
    system("cls");

    Fecha ingreso,salida,pago;
    int disponibilidad;
    int pos;

    if(totalApagar!=-1)
    {
        pos=arcHab.buscarRegistro(numHab);
        objHab=arcHab.leerRegistro(pos);
        cout<<"PARA RESERVAR O OCUPAR HOY : ";
        cin>>disponibilidad;
        system("cls");

        switch (disponibilidad)
        {
        case 1:
            cout<<"INGRESE LA FECHA DE SALIDA"<<endl;
            salida.Cargar();
            break;

        case 2:
            cout<<"INGRESE LA FECHA DE INGRESO"<<endl;
            ingreso.Cargar();
            cout<<endl<<"INGRESE LA FECHA DE SALIDA"<<endl;
            salida.Cargar();
            break;

        default:
            cout<<"OPCION INVALIDA"<<endl;
            system("pause");
            return;
        }

        system("cls");
    }

    ArchivoHuesped arcH;
    Huesped objH;
    objH.Cargar();
    arcH.grabarRegistro(objH);
    system("cls");

    ArchivoPago arcP;
    Pago objP;
    float adelantado;
    int forma;
    objP=arcP.leerRegistro();
    int numRecibo;
    numRecibo=objP.getNumeroderecibo()+1;

    cout<<"INGRESE UN PAGO ADELANTADO : ";
    cin>>adelantado;
    objP.setTotalAbonado(adelantado);
    cout<<"FORMA DE PAGO : ";
    cin>>forma;
    objP.setPago(forma);
    cout<<"FECHA DE PAGO"<<endl;
    pago.Cargar();

        if(disponibilidad==1)
        {
            ingreso=pago;///Esto lo hago para no pedir la fecha varias veces. En caso de que reserve para HOY
        }
        objHab.asignar(regimen,disponibilidad,ingreso,salida);
        arcHab.modificarRegistro(objHab,pos);

    ArchivoDetalles arcD;
    DetallesPago objD;
    int idDetalle;
    objD=arcD.leerRegistro();
    idDetalle=objD.getID()+1;



    totalApagar-=adelantado;
    objD.reserva(idDetalle,objH.getDni(),numHab,totalApagar);
    arcD.grabarRegistro(objD);

    objP.reserva(numRecibo,objH.getDni(),idDetalle,pago);
    arcP.grabarRegistro(objP);

    system("cls");


}


int habitacionesLibres(int cap, int cat)
{
    ArchivoHabitacion arcHab;
    Habitacion objHab;
    int contReg=arcHab.contarRegistros();
    int contHab=0;

    for (int i=0;i<contReg;i++)
        {
            objHab=arcHab.leerRegistro(i);
        if(objHab.getEstado() && objHab.getDisponibilidad()==0)
        {
            if(objHab.getIdCategoria()==cat && objHab.getCapacidad()==cap)
            {
                objHab.Mostrar();
                cout<<endl;
                contHab++;
            }
        }

        }
    return contHab;
}

int verificarCapacidad(int cap)
{   char aux;
    while(true)
    {
        cout<<"INGRESE LA CANTIDAD DE PERSONAS QUE SE HOSPEDAN : ";
        cin>>cap;
       cout<<endl<<"ES CORRECTO LA CAPACIDAD DE : "<<cap<<" ? "<<endl;
        cout<<"S/N : ";
        cin>>aux;
        cout<<endl;
        if(aux=='n' || aux=='N')
        {
            system("cls");
            cout<<"DESEA VOLVER A INTENTARLO ?"<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='n' || aux=='N'){return -1;}else{system("cls");}

            }else{return cap;}
}
}

int verificarCategoria(int cat)
{
        cout<<"INGRESE UNA CATEGORIA : ";
        cin>>cat;
        ArchivoCategoria arc;
        Categoria obj;
        char aux;
        int pos;
        while(true){
        pos=arc.buscarRegistro(cat);
        if(pos==-1)
        {
            cout<<"ID DE CATEGORIA NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DE LA CATEGORIA : ";
                cin>>cat;
            }

            else
            {
                system("cls");
                return -1;
            }
        }
        if(pos!=-1)
        {
            obj=arc.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR LA CATEGORIA : "<<obj.getDescripcion()<<endl<<"S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                return cat;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRA CATEGORIA? "<<endl<<"S/N"<<endl;
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    cout<<"INGRESE EL ID DE LA CATEGORIA : ";
                    cin>>cat;
                }
            else
                {
                return -1;
                }
            }
        }
        }
    }

int verificarHabitacion(int num)
{
        int pos;
        char aux;
        ArchivoHabitacion arcHab;
        cout<<"INGRESE EL NUMERO DE HABITACION : ";
        cin>>num;
        pos=arcHab.buscarRegistro(num);
         while(pos==-1)
        {   system("cls");
            cout<<"SE TIPEO MAL LA HABITACION,DESEA VOLVER A INTENTARLO ? "<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='s' || aux=='S')
            {
                system("cls");
                cout<<"INGRESE EL NUMERO DE HABITACION : ";
                cin>>num;
                pos=arcHab.buscarRegistro(num);

            }
            else{return -1;}
        }
        return num;
}

int verificarRegimen(int reg)
{
    ArchivoRegimenComida arcReg;
    RegimenComida objReg;
    char aux;
    int pos=-1;
    while(pos==-1)
    {
        cout<<"INGRESE EL CODIGO DE REGIMEN : ";
        cin>>reg;
        pos=arcReg.buscarRegistro(reg);
        if(pos==-1)
        {
            system("cls");
            cout<<"EL REGIMEN NO EXISTE, DESEA VOLVER A INTENTARLO ? "<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='n' || aux=='N'){return -1;}
        }
        else
        {
            objReg=arcReg.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE QUIERE EL REGIMEN : "<<objReg.getDesc()<<" ? "<<endl;
            cout<<"S/N : ";
            cin>>aux;
            if(aux=='n'||aux=='N')
                {
                    system("cls");
                    cout<<"QUIERE VOLVER A INTENTAR ? "<<endl<<"S/N : ";
                    cin>>aux;
                    if(aux=='n'||aux=='N')
                    {return -1;}
                    else{pos=-1;system("cls");}

                }
        }
    }
    return reg;

}

float confirmacion(int cat,int cap,int num,int reg,float total)
{
    ArchivoCategoria arcC;
    Categoria objCat;
    int pos=arcC.buscarRegistro(cat);
    objCat=arcC.leerRegistro(pos);

    ArchivoRegimenComida arcReg;
    RegimenComida objReg;
    pos=arcReg.buscarRegistro(reg);
    objReg=arcReg.leerRegistro(pos);

    total=objCat.getPrecioXpersona()*cap;

    char aux;

    cout<<"RESUMEN DE SU RESERVA"<<endl;
    cout<<endl<<"HABITACION : "<<num<<endl;
    cout<<"CATEGORIA : "<<objCat.getDescripcion()<<endl;
    if(reg!=0)
    {
        cout<<"REGIMEN : "<<objReg.getDesc()<<endl;
        total+=objReg.getPrecio();
    }
    cout<<"CAPACIDAD : "<<cap<<endl;
    cout<<"TOTAL A PAGAR : "<<total<<"$"<<endl<<endl;

    cout<<"DESEA CONFIRMAR SU ESTADIA ? "<<endl<<"S/N : ";
    cin>>aux;
    if(aux=='S'||'s'){return total;}
    else{return -1;}
}

void habitacionesDisponiblesHasta() {
    Fecha fechaLimite;
    ArchivoHabitacion arcHab;
    Habitacion objHab;

    fechaLimite.Cargar();
    int totalHabitaciones = arcHab.contarRegistros();
    if (totalHabitaciones == -1) {
        cout << "Error al abrir el archivo\n";
        return;
    }

    bool hayDisponibles = false;

    cout << "Habitaciones disponibles hasta ";
    fechaLimite.Mostrar();
    cout << ":\n";

    for (int i = 0; i < totalHabitaciones; ++i) {
        objHab = arcHab.leerRegistro(i);

        /// VERIFICAR DISPONIBILIDAD O SI SE PUEDE USAR ANTES DE LA RESERVA
        if (objHab.getDisponibilidad() == 0 || 
           (objHab.getDisponibilidad() == 2 && objHab.getIngreso().getAnio() > fechaLimite.getAnio()) ||
           (objHab.getDisponibilidad() == 2 && objHab.getIngreso().getAnio() == fechaLimite.getAnio() && objHab.getIngreso().getMes() > fechaLimite.getMes()) ||
           (objHab.getDisponibilidad() == 2 && objHab.getIngreso().getAnio() == fechaLimite.getAnio() && objHab.getIngreso().getMes() == fechaLimite.getMes() && objHab.getIngreso().getDia() > fechaLimite.getDia())) 
        {
            objHab.Mostrar();
            hayDisponibles = true;
        }
    }

    if (!hayDisponibles) {
        cout << "No hay habitaciones disponibles hasta la fecha especificada...\n";
    }
}

#endif // RESERVA_H_INCLUDED
