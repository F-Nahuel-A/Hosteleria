#ifndef RESERVA_H_INCLUDED
#define RESERVA_H_INCLUDED
int verificarCapacidad(int cap);
int verificarCategoria(int cat);
int verificarHabitacion(int num);
int verificarRegimen(int reg);
void verificarPago(int deuda,int abonado);
int habitacionesLibres(int cap,int cat,Fecha ing,Fecha sal);
float confirmacion(int cat,int cap,int num,int reg,float total);
void habitacionesDisponiblesHasta();
void pagosHechos();
void pagoFinal();
void actualizarFacturasAnt(int fac,int cantReg);
int asignarDisponibilidad(Fecha ingreso);
bool verificarOcupada(Habitacion obj,Fecha ing);
bool verificarReservada(Habitacion obj,Fecha sal);

void agregarReserva()
{
    int categoria,capacidad,numHab,regimen;
    char aux;

    ArchivoHabitacion arcHab;
    Habitacion objHab;

    Fecha ingreso,salida,pago;

    cout<<"INGRESE EL INGRESO DEL HUESPED"<<endl;
    ingreso.Cargar();
    cout<<"INGRESE LA SALIDA DEL HUESPED"<<endl;
    salida.Cargar();
    cout<<endl;

    categoria=verificarCategoria(categoria);
    if(categoria==-1){return;}

    capacidad=verificarCapacidad(capacidad);
    if(capacidad==-1){return;}
    system("cls");

    cout<<"HABITACIONES DISPONIBLES : "<<endl;
    int libres=habitacionesLibres(capacidad,categoria,ingreso,salida);
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

    if(totalApagar==-1)
    {
        return;
    }

    int disponibilidad=asignarDisponibilidad(ingreso);
    int pos;

    pos=arcHab.buscarRegistro(numHab);
    objHab=arcHab.leerRegistro(pos);

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

        if(objHab.getDisponibilidad()!=0)
        {
        objHab.asignar(regimen,disponibilidad,ingreso,salida);
        arcHab.grabarRegistro(objHab);
        }
        else
        {
        objHab.asignar(regimen,disponibilidad,ingreso,salida);
        arcHab.modificarRegistro(objHab,pos);
        }
        ///Lo que hago acá es subir otro registro si el anterior ya se encuentra ocupado, una vez se libere esa hbitación, se va a borrar del sistema para no tener duplicados.

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

int habitacionesLibres(int cap, int cat,Fecha ing,Fecha sal)
{
    ArchivoHabitacion arcHab;
    Habitacion objHab;
    int contReg=arcHab.contarRegistros();
    int contHab=0;

    for (int i=0;i<contReg;i++)
        {
            objHab=arcHab.leerRegistro(i);

        switch (objHab.getDisponibilidad())
        {
        case 0:
            if(objHab.getIdCategoria()==cat && objHab.getCapacidad()==cap)
            {
                objHab.Mostrar();
                cout<<endl;
                contHab++;
            }
            break;

        case 1:
            if(verificarOcupada(objHab,ing))
            {
                objHab.Mostrar();
                cout<<endl;
                contHab++;
            }
            break;

        case 2:
           if(verificarReservada(objHab,sal))
            {
                objHab.Mostrar();
                cout<<endl;
                contHab++;
            }
            break;

        default:
            break;
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

void pagoFinal()
{
    ArchivoPago arcP;
    Pago objP;
    int contReg=arcP.contarRegistros();
    int dni,abonado;
    bool pago=false;

    cout<<"INGRESE EL DNI DEL HUESPED : ";
    cin>>dni;

    for (int i=0;i<contReg;i++)
    {
        objP=arcP.leerRegistro(i);
        if(objP.getEstado() && objP.getDNI()==dni)
        {
            if(objP.getTotalAbonado()!=0)
            {
            cout<<"EL TOTAL A PAGAR ES DE : "<<objP.getTotalAbonado()<<"$"<<endl<<endl;
            cout<<"INGRESE EL MONTO ABONADO : ";
            cin>>abonado;
            verificarPago(objP.getTotalAbonado(),abonado);
            system("pause");
            pago=true;
            break;
            }
        }
    }
    if(pago)
    {

    ArchivoDetalles arcD;
    DetallesPago objD;
    int numH=objD.getNumdehabitacion();

    ///Creación del nuevo detalle anteriormente abonado.
    objD=arcD.leerRegistro();
    objD.setIDdetalle(objD.getID()+1);
    objD.setDNI(dni);
    objD.setNumHabitacion(numH);
    objD.setTotal(abonado);
    ///Leer registros sin parametros te retorna un nuevo número de ID

    objP.setTotalAbonado(0);
    objP.setIDdetalle(objD.getID());
    arcP.grabarRegistro(objP);

    actualizarFacturasAnt(objP.getNumeroderecibo(),contReg);
    ///Pone a todas las facturas anteriores con el mismo número en 0


    }
    else
    {
        cout<<"EL CLIENTE NO DEBE PAGAR";
    }
}

void pagosHechos()
{
    Pago objP;
    ArchivoPago arcP;
    objP=arcP.leerRegistro();
    int cantRecibos=objP.getNumeroderecibo()+1;

    DetallesPago objD;
    ArchivoDetalles arcD;

    int contReg=arcP.contarRegistros();

    for(int i=0;i<cantRecibos;i++)
    {

        for (int j=0;j<contReg;j++)
        {
            objP=arcP.leerRegistro(j);
            if(i==objP.getNumeroderecibo() && objP.getTotalAbonado()==0)
            {
                int pos=arcD.buscarRegistro(objP.getIDdetalle());
                objD=arcD.leerRegistro(pos);
                objP.Mostrar();
                cout<<"PAGADO : "<<objD.getTotalabonado()<<"$"<<endl;
            }
        }

    }
}

void verificarPago(int deuda,int abonado)
{
    while(abonado<deuda)
    {
        cout<<"LO ABONADO NO ES SUFICIENTE, VUELVA A ABONAR"<<endl;
        cout<<"INGRESE EL MONTO : ";
        cin>>abonado;
        system("cls");
    }
    cout<<"PAGO REALIZADO"<<endl;
}


void actualizarFacturasAnt(int fac,int cantReg)
{
    Pago obj;
    ArchivoPago arc;

    for (int i=0;i<cantReg;i++)
    {
        if(fac==obj.getNumeroderecibo())
        {
            obj=arc.leerRegistro(i);
            obj.setTotalAbonado(0);
            arc.modificarRegistro(obj,i);
        }
    }

}

int asignarDisponibilidad(Fecha ingreso)
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int dia=now->tm_mday;
    int mes=now->tm_mon;
    int anio=now->tm_year;

    if(ingreso.getAnio()==anio && ingreso.getMes()==mes&& ingreso.getDia()==dia)
    {
        return 1;
    }
    else {return 2;}
}


bool verificarOcupada(Habitacion obj,Fecha ing)
{
    if(ing==obj.getSalida())
    {
        return true;
    }
    if(ing.getAnio()>obj.getSalida().getAnio())
    {
        return true;
    }
    if(ing.getAnio()==obj.getSalida().getAnio() && ing.getMes()>obj.getSalida().getMes())
    {
        return true;
    }
    if(ing.getAnio()==obj.getSalida().getAnio() && ing.getMes()==obj.getSalida().getMes()&& ing.getDia()>obj.getSalida().getDia())
    {
        return true;
    }
    return false;
}

bool verificarReservada(Habitacion obj,Fecha sal)
{
    if(sal==obj.getIngreso())
    {
        return true;
    }
    if(sal.getAnio()<obj.getIngreso().getAnio())
    {
        return true;
    }
    if(sal.getAnio()==obj.getIngreso().getAnio() && sal.getMes()<obj.getIngreso().getMes())
    {
        return true;
    }
    if(sal.getAnio()==obj.getIngreso().getAnio() && sal.getMes()==obj.getIngreso().getMes()&& sal.getDia()<obj.getIngreso().getDia())
    {
        return true;
    }
    return false;
}

#endif // RESERVA_H_INCLUDED
