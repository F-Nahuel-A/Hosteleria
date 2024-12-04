#ifndef CLSPAGOS_H_INCLUDED
#define CLSPAGOS_H_INCLUDED

class Pago
{
private:
    int _NumRecibo;
    int _IDdetalle;
    int _dni;
    Fecha _FechadPago;
    int _FormadPago; /// 0: al contado y 1: transferencia
    float _totalAbonado;
    bool _estado;
public:
    Pago(int recibo=0, int forma=0, float t=0,int dni=0){
    _NumRecibo=recibo;
    _dni=dni;
    _FormadPago=forma;
    _totalAbonado=t;
    }

    int getNumeroderecibo(){return _NumRecibo;}
    int getDNI(){return _dni;}
    Fecha getFecha(){return _FechadPago;}
    int getFormadepago(){return _FormadPago;}
    float getTotalAbonado(){return _totalAbonado;}
    bool getEstado(){return _estado;}
    int getIDdetalle(){return _IDdetalle;}

    void setFecha(Fecha f){_FechadPago=f;}
    void setIDdetalle(int id);
    void setNumeroderecibo(int  n){_NumRecibo=n;}
    void setPago(int forma);
    void setTotalAbonado(float t);
    void setDNI(int dni);

    Pago reserva(int numRecibo,int dni, int detalle,Fecha f);

    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        float auxF;
        ///
        FILE *p=fopen("Pago.dat","rb");
        if(p == NULL){cout<<"ERROR EN LA APERTURA"<<endl;return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Pago);
        fclose(p);
        _NumRecibo=cantRegistros+1;
        ///
        cout<<"INGRESE EL DNI : ";
        cin>>aux;
        setDNI(aux);
        if(_estado==false){return;}
        cout<<"INGRESE LA FORMA DE PAGO : ";
        cin>>aux;
        setPago(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL TOTAL : ";
        cin>>auxF;
        setTotalAbonado(auxF);
        if(_estado==false){return;}
        _FechadPago.Cargar();
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"NUMERO DE RECIBO : "<<_NumRecibo<<endl;
        cout<<"ID DETALLE : "<<_IDdetalle<<endl;
        cout<<"DNI : "<<_dni<<endl;
        cout<<"FORMA DE PAGO : ";
        switch (_FormadPago)
        {
        case 0:
            cout<<"AL CONTADO";
            break;

        case 1:
            cout<<"TRANSFERENCIA";
            break;
        }
        cout<<endl<<"TOTAL ABONADO : "<<_totalAbonado<<endl;
        cout<<"FECHA DE PAGO : ";
        _FechadPago.Mostrar();
        }
        cout<<endl;
    }

};

void Pago::setTotalAbonado(float t)
    {
        char aux;
        if(t>0)
        {
            _totalAbonado=t;
            return;
        }
        else
        {
            while(t<0)
                {

            cout<<"MONTO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N : ";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL TOTAL : ";
                cin>>t;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _totalAbonado=t;
        }
    }

void Pago::setPago(int forma)
    {
        char aux;
        if(forma>0)
        {
            _FormadPago=forma;
            return;
        }
        else
        {
            while(forma<0)
                {

            cout<<"FORMA DE PAGO NO VALIDA,QUIERE VOLVER A INTENTAR ? S/N : ";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE LA FORMA DE PAGO (0 AL CONTADO Y 1 TRANSFERENCIA) : ";
                cin>>forma;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _FormadPago=forma;
        }
    }

void Pago::setDNI(int dni)
       {
        char aux;
        ArchivoHuesped arcH;
        Huesped objH;
        int pos;
        while(_estado)
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
                    _dni=dni;
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
                        system("cls");
                        cout<<"INGRESE EL DNI : ";
                        cin>>dni;
                    }
                    else
                    {
                    _estado=false;
                    return;
                    }
                }
            }
            else
            {
                cout<<"EL DNI NO EXISTE, DESEA VOLVER A INTENTARLO ?"<<endl<<"S/N : ";
                cin>>aux;
                if(aux=='s'||'S')
                {
                    system("cls");
                    cout<<"INGRESE EL DNI : ";
                    cin>>dni;
                }
                else
                {
                    _estado=false;
                    return;
                }

            }
        system("cls");}

    }

void Pago::setIDdetalle(int id)
{
    ArchivoDetalles arcD;
    DetallesPago objD;
    int pos;
    char aux;
    while(_estado){
        pos=arcD.buscarRegistro(id);
        if(pos==-1)
        {
            cout<<"ID DE DETALLE NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DEL DETALLE : ";
                cin>>id;
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
            objD=arcD.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL SIGUIENTE DETALLE DE PAGO"<<endl<<endl;
            objD.Mostrar();
            cout<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDdetalle=id;
                return;
            }
            else
            {
                system("cls");
                cout<<"QUIERE INGRESAR OTRO ? "<<endl<<"S/N : ";
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    system("cls");
                    cout<<"INGRESE EL ID DEL DETALLE : ";
                    cin>>id;
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


Pago Pago::reserva(int numRecibo,int dni, int detalle,Fecha f)
{
    _NumRecibo=numRecibo;
    _IDdetalle=detalle;
    _dni=dni;
    _FechadPago=f;
}

///Esto se usa para la linea 132 de reserva.h . . .  Basicamente lo que hace es actuar como constructor pero agregandole fecha, se hizo de esta forma para facilitar la asignación.
///Se podría haber hecho con el constructor anteriormente creado y usando un set, pero veo más prolijo usar otro constructor.


#endif // CLSPAGOS_H_INCLUDED
