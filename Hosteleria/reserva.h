#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED
int verificarCapacidad(int cap);
int verificarCategoria(int cat);
int verificarHabitacion(int num);
int verificarRegimen(int reg);
void habitacionesLibres(int cap,int cat);
float confirmacion(int cat,int cap,int num,int reg,float total);

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
    system("cls");
    habitacionesLibres(capacidad,categoria);

    cout<<endl<<"DESEA CONTINUAR ?"<<endl<<"S/N : ";
    cin>>aux;
    if(aux=='n' || aux=='N'){return;}

    system("cls");
    numHab=verificarHabitacion(numHab);
    if(numHab==-1){return;}
    cout<<"DESEA UN REGIMEN DE COMIDA ?"<<endl<<"S/N : ";
    cin>>aux;
    if(aux=='s' || aux=='S')
        {
            regimen=verificarRegimen(regimen);
        }
        else{regimen=0;}

    system("cls");
    float totalApagar;
    totalApagar=confirmacion(categoria,capacidad,numHab,regimen,totalApagar);
    if(totalApagar!=-1)
    {
        int pos=arcHab.buscarRegistro(numHab);
        objHab.setDisponibilidad(0);
        if(regimen!=0)
        {
            objHab.setIdRegimen(regimen);
        }
        arcHab.modificarRegistro(objHab,pos);
    }

    ArchivoHuesped arcH;
    Huesped objH;
    objH.Cargar();
    arcH.grabarRegistro(objH);
    system("cls");

    ArchivoPago arcP;
    Pago objP;
    objP.Cargar();
    arcP.grabarRegistro(objP);
    system("cls");

    ArchivoDetalles arcD;
    DetallesPago objD;
    objD=arcD.leerRegistro();
    int idDetalle;
    idDetalle=objD.getID()+1;

    objD.setIDdetalle(idDetalle);
    objD.setEstado(true);
    objD.setNumHabitacion(numHab);
    objD.setNumrecibo(objP.getNumeroderecibo());
    objD.setTotalabonado(totalApagar-objP.getTotal()); ///TOTAL QUE DEBE PAGAR, NO ABONADO
    arcD.grabarRegistro(objD);
}

void habitacionesLibres(int cap, int cat)
{
    ArchivoHabitacion arcHab;
    Habitacion objHab;
    int contReg=arcHab.contarRegistros();

    for (int i=0;i<contReg;i++)
        {
            objHab=arcHab.leerRegistro(i);
        if(objHab.getEstado() && objHab.getDisponibilidad()==0)
        {
            if(objHab.getIdCategoria()==cat && objHab.getCapacidad()==cap)
            {
                objHab.Mostrar();
            }
        }

        }
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
            cout<<endl<<"DESEA VOLVER A INTENTARLO ?"<<endl<<"S/N : ";
            cin>>aux;
            cout<<endl;
            if(aux=='n' || aux=='N'){return -1;}
            }else{return cap;}
            system("cls");
}
}

int verificarCategoria(int cat)
{
    char aux;
    int pos;
    ArchivoCategoria arcCat;
    cout<<"INGRESE LA CATEGORIA QUE QUIERA : ";
    cin>>cat;
    pos=arcCat.buscarRegistro(cat);
    while(pos==-1)
    {
        system("cls");
        cout<<endl<<"SE TIPEO MAL LA CATEGORIA, QUIERE VOLVER A INTENTAR ? "<<endl<<"S/N : ";
        cin>>aux;
        if(aux=='s' || aux=='S')
            {
                system("cls");
                cout<<"INGRESE LA CATEGORIA : ";
                cin>>cat;
                pos=arcCat.buscarRegistro(cat);

            }
            else{return -1;}
    }
    return cat;
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
        {
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
                    cout<<"QUIERE VOLVER A INTENTAR ? "<<endl<<"S/N : ";
                    cin>>aux;
                    if(aux=='n'||aux=='N')
                    {return -1;}
                    else{pos=-1;}

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
#endif // RESERVA_H_INCLUDED
