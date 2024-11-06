#ifndef CLSDETALLESPAGOS_H_INCLUDED
#define CLSDETALLESPAGOS_H_INCLUDED

class DetallesPago
{
private:
    int _IDdetalle;
    int _NumRecibo;
    int _NumHabitacion;
    float _totalabonado;
    bool _estado;
public:
    DetallesPago(int detalle=0,int numrecibo=0,int numHab=0, float tabonado=0){
    _IDdetalle=detalle;
    _NumRecibo=numrecibo;
    _NumHabitacion=numHab;
    _totalabonado=tabonado;
    }

    int getID(){return _IDdetalle;}
    int getNumeroderecibo(){return _NumRecibo;}
    int getNumdehabitacion(){return _NumHabitacion;}
    float getTotalabonado(){return _totalabonado;}
    bool getEstado(){return _estado;}


    void setNumrecibo(int recibo);
    void setIDdetalle (int detalle){if(detalle>0){_IDdetalle=detalle;}}
    void setNumHabitacion(int numHab);
    void setTotalabonado(float tabonado);

    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        float auxF;
         ///ASIGNACIÓN AUTOMATICA DEL ID DETALLE
        FILE *p=fopen("detallepago.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (DetallesPago);
        fclose(p);
        _IDdetalle=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL ID DETALLE
        cout<<"INGRESE EL NUMERO DE RECIBO : ";
        cin>>aux;
        setNumrecibo(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL NUMERO DE HABITACION : ";
        cin>>aux;
        setNumHabitacion(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL TOTAL : ";
        cin>>auxF;
        setTotalabonado(auxF);
        if(_estado==false){return;}
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID DETALLE : "<<_IDdetalle<<endl;
        cout<<"NUMERO DE RECIBO :"<<_NumRecibo<<endl;
        cout<<"NUMERO DE HABITACION : "<<_NumHabitacion<<endl;
        cout<<"TOTAL ABONADO: "<<_totalabonado<<endl;
        }
    }

};

void DetallesPago::setTotalabonado(float tabonado)
    {
        char aux;
        if(tabonado>0)
        {
            _totalabonado=tabonado;
            return;
        }
        else
        {
            while(tabonado<0)
                {

            cout<<"MONTO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL MONTO : ";
                cin>>tabonado;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _totalabonado=tabonado;
        }
    }

void DetallesPago::setNumrecibo(int recibo)
       {
        char aux;
        if(recibo>0)
        {
            _NumRecibo=recibo;
            return;
        }
        else
        {
            while(recibo<0)
                {

            cout<<"NUMERO DE RECIBO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL NUMERO DE RECIBO : ";
                cin>>recibo;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _NumRecibo=recibo;
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
            else{return;}
            }
        }
        }
    }
#endif // CLSDETALLESPAGOS_H_INCLUDED
