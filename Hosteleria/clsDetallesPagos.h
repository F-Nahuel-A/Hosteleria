#ifndef CLSDETALLESPAGOS_H_INCLUDED
#define CLSDETALLESPAGOS_H_INCLUDED

class Detalles
{
private:
    int _IDdetalle;
    int _NumRecibo;
    int _NumHabitacion;
    float _totalabonado;
    bool _estado;
public:
    Pago(int detalle=0, float tabonado=0){
    _IDdetalle=detalle;
    _totalabonado=tabonado;
    }

    int getNumeroderecibo(){return _NumRecibo;}
    int getNumdehabitacion(){return _NumHabitacion;}
    float getTotalabonado(){return _totalabonado;}
    bool getEstado(){return _estado;}


    void setID (int detalle){
    if (detalle>0){return _IDdetalle;}
    }

    void setTotalabonado (float tabonado;)

    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
         ///ASIGNACIÓN AUTOMATICA DEL ID DETALLE
        FILE *p=fopen("detallepago.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Pago);
        fclose(p);
        _IDdetalle=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL ID DETALLE
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

void DetallesPagos::setTotalabonado(float tabonado)
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
            cout << "MONTO NO VALIDO, ¿QUIERE VOLVER A INTENTAR? S/N" << endl;
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
                cout << "OPCIÓN NO VÁLIDA. INTENTE DE NUEVO." << endl;
            }
        }

        _totalabonado = tabonado;
    }
}


#endif // CLSDETALLESPAGOS_H_INCLUDED
