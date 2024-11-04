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


    void setIDrecibo(int recibo){if(recibo>0){_NumRecibo=recibo;}}
    void setIDdetalle (int detalle){if(detalle>0){_IDdetalle=detalle;}}
    void setNumHabitacion(int numHab){if(numHab>0){_NumHabitacion=numHab;} }
    void setTotalabonado(float tabonado);

    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
         ///ASIGNACI�N AUTOMATICA DEL ID DETALLE
        FILE *p=fopen("detallepago.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Pago);
        fclose(p);
        _IDdetalle=cantRegistros+1;
        ///ASIGNACI�N AUTOMATICA DEL ID DETALLE
        cout<<"INGRESE EL TOTAL ABONADO";
        cin>>aux;
        setTotalabonado(aux);
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
    if (tabonado > 0)
    {
        _totalabonado = tabonado;
        return;
    }
    else
    {
        while (tabonado <= 0)
        {
            cout << "MONTO NO VALIDO, �QUIERE VOLVER A INTENTAR? S/N" << endl;
            cin >> aux;

            if (aux == 'S' || aux == 's')
            {
                system("cls");
                cout << "INGRESE EL TOTAL ABONADO: ";
                cin >> tabonado;
            }
            else if (aux == 'N' || aux == 'n')
            {
                system("cls");
                _estado = false;
                return;
            }
            else
            {
                cout << "OPCI�N NO V�LIDA. INTENTE DE NUEVO." << endl;
            }
        }

        _totalabonado = tabonado;
    }
}


#endif // CLSDETALLESPAGOS_H_INCLUDED
