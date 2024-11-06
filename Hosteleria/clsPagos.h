#ifndef CLSPAGOS_H_INCLUDED
#define CLSPAGOS_H_INCLUDED

class Pago
{
private:
    int _NumRecibo;
    int _dni;
    Fecha _FechadPago;
    int _FormadPago; /// 0: al contado y 1: transferencia
    float _total;
    bool _estado;
public:
    Pago(int recibo=0, int forma=0, float t=0,int dni=0){
    _NumRecibo=recibo;
    _dni=dni;
    _FormadPago=forma;
    _total=t;
    }

    int getNumeroderecibo(){return _NumRecibo;}
    int getDNI(){return _dni;}
    Fecha getFecha(){return _FechadPago;}
    int getFormadepago(){return _FormadPago;}
    float getTotal(){return _total;}
    bool getEstado(){return _estado;}

    void setNumero (int recibo){

    if (recibo>0){_NumRecibo=recibo;} ///revisar la manera de que se genere automaticamente || LISTO

    }

    void setFecha(Fecha f){_FechadPago=f;}
    void setNumeroderecibo(float n);
    void setPago(int forma);
    void setTotal (float t); ///revisarlo, falta parte del codigo || LISTO
    void setDNI(int dni);

    void setEstado(bool e){_estado=e;}


    void Cargar()
    {
        _estado=true;
        int aux;
        float auxF;
        cout<<"INGRESE EL NUMERO DE RECIBO : ";
        cin>>auxF;
        setNumeroderecibo(auxF);
        cout<<"INGRESE EL DNI : ";
        cin>>aux;
        setDNI(aux);
        cout<<"INGRESE LA FORMA DE PAGO : ";
        cin>>aux;
        setPago(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL TOTAL : ";
        cin>>auxF;
        setTotal(auxF);
        if(_estado==false){return;}
        _FechadPago.Cargar();
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"NUMERO DE RECIBO : "<<_NumRecibo<<endl;
        cout<<"DNI : "<<_dni<<endl;
        cout<<"FORMA DE PAGO(0 AL CONTADO Y 1 TRANSFERENCIA) :"<<_FormadPago<<endl;
        cout<<"TOTAL : "<<_total<<endl;
        _FechadPago.Mostrar();
        }
    }

};

void Pago::setTotal(float t)
    {
        char aux;
        if(t>0)
        {
            _total=t;
            return;
        }
        else
        {
            while(t<0)
                {

            cout<<"MONTO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
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

            _total=t;
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

            cout<<"FORMA DE PAGO NO VALIDA,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
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
        if(dni>0)
        {
            _dni=dni;
            return;
        }
        else
        {
            while(dni<0)
                {

            cout<<"DNI NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL DNI : ";
                cin>>dni;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _dni=dni;
        }
    }

void Pago::setNumeroderecibo(float recibo)
    {
        ArchivoDetalles arc;
        DetallesPago obj;
        char aux;
        int pos;
        while(_estado){
        pos=arc.buscarRegistro(recibo);
        if(pos==-1)
        {
            cout<<"NUMERO DE RECIBO NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;
            cout<<endl;
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
        }
        if(pos!=-1)
        {
            obj=arc.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL NUMERO DE RECIBO : "<<obj.getNumeroderecibo()<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _NumRecibo=recibo;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRO NUMERO DE RECIBO ? "<<endl<<"S/N : ";
                cin>>aux;
                cout<<endl;
                if(aux=='S' || aux=='s')
                {
                    cout<<"INGRESE EL NUMERO DE RECIBO : ";
                    cin>>recibo;
                }
            else{return;}
            }
        }
        }
    }

#endif // CLSPAGOS_H_INCLUDED
