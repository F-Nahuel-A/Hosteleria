#ifndef CLSDETALLESPAGOS_H_INCLUDED
#define CLSDETALLESPAGOS_H_INCLUDED

class DetallesPago
{
private:
    int _IDdetalle;
    int _DNI;
    int _NumHabitacion;
    float _total;
    bool _estado;
public:
    DetallesPago(int detalle=0,int numHab=0, float total=0,int dni=0){
    _IDdetalle=detalle;
    _DNI=dni;
    _NumHabitacion=numHab;
    _total=total;
    }

    int getID(){return _IDdetalle;}
    int getNumdehabitacion(){return _NumHabitacion;}
    float getTotalabonado(){return _total;}
    int getDNI(){return _DNI;}
    bool getEstado(){return _estado;}

    void setDNI(int dni);
    void setIDdetalle (int detalle){if(detalle>0){_IDdetalle=detalle;}}
    void setNumHabitacion(int numHab);
    void setTotal(float total);

    DetallesPago reserva(int id,int dni,int num,float total);

    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        float auxF;
         ///ASIGNACIÓN AUTOMATICA DEL ID DETALLE
        FILE *p=fopen("detallePago.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (DetallesPago);
        fclose(p);
        _IDdetalle=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL ID DETALLE
        cout<<"INGRESE EL DNI : ";
        cin>>aux;
        setDNI(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL NUMERO DE HABITACION : ";
        cin>>aux;
        setNumHabitacion(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL TOTAL : ";
        cin>>auxF;
        setTotal(auxF);
        if(_estado==false){return;}
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID DETALLE : "<<_IDdetalle<<endl;
        cout<<"NUMERO DE DNI :"<<_DNI<<endl;
        cout<<"NUMERO DE HABITACION : "<<_NumHabitacion<<endl;
        cout<<"TOTAL RESTANTE : "<<_total<<endl;
        }
    }

};

void DetallesPago::setTotal(float total)
    {
        char aux;
        if(total>0)
        {
            _total=total;
            return;
        }
        else
        {
            while(total<0)
                {

            cout<<"MONTO NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL MONTO : ";
                cin>>total;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _total=total;
        }
    }

void DetallesPago::setDNI(int dni)
       {
        char aux;
        ArchivoHuesped arcH;
        Huesped objH;
        int pos=-1;
        while(pos==-1)
        {
            pos=arcH.buscarRegistro(dni);
            if(pos!=-1)
            {
                cout<<"ESTE ES EL CLIENTE CORRECTO ?"<<endl<<endl;
                objH=arcH.leerRegistro(pos);
                objH.Mostrar();
                cout<<endl<<"S/N : ";
                cin>>aux;

                if(aux=='s'||'S')
                {
                    _DNI=dni;
                    return;
                }
                else
                {
                    system("cls");
                    cout<<"QUIERE VOLVER A INTENTARLO ?"<<endl;
                    cout<<"S/N : ";
                    cin>>aux;
                    if(aux=='s'||'S')
                    {
                       pos=-1;
                    system("cls");
                    }
                    else
                    {
                    _estado=false;
                    return;
                    }
                }
            }
        }

    }

void DetallesPago::setNumHabitacion(int numHab)
    {
        ArchivoHabitacion arc;
        Habitacion obj;
        char aux;
        int pos;
        while(_estado){
        pos=arc.buscarRegistro(numHab);
        if(pos==-1)
        {
            cout<<"NUMERO DE HABITACION NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;
            cout<<endl;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL NUMERO DE HABITACION : ";
                cin>>numHab;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }
        }
        if(pos!=-1)
        {
            obj=arc.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL NUMERO DE HABITACION : "<<obj.getNumero()<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _NumHabitacion=numHab;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRO NUMERO DE HABITACION ? "<<endl<<"S/N : ";
                cin>>aux;
                cout<<endl;
                if(aux=='S' || aux=='s')
                {
                    cout<<"INGRESE EL NUMERO DE HABITACION : ";
                    cin>>numHab;
                }
            else
                {
                _estado=false;
                return;
                }
            }
        }
        }
    }


DetallesPago DetallesPago::reserva(int id,int dni,int num,float total)
{
    _IDdetalle=id;
    _DNI=dni;
    _NumHabitacion=num;
    _total=total;
}
#endif // CLSDETALLESPAGOS_H_INCLUDED
