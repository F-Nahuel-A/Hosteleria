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
    Pago(int recibo=0, int forma=0, float t=0){
    _NumRecibo=recibo;
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

    void setPago(int forma){
    if (forma == 1 || forma == 0)
    {
        _FormadPago = forma;
    }
}
    void setTotal (float t){_total=t;} ///revisarlo, falta parte del codigo
    void setEstado(bool e){_estado=e;}


    void Cargar()
    {
        _estado=true;
        int aux;
         ///ASIGNACIÓN AUTOMATICA DEL NUMRECIBO
        FILE *p=fopen("pago.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Pago);
        fclose(p);
        _NumRecibo=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL NUMRECIBO
        cout<<"INGRESE LA FORMA DE PAGO";
        cin>>aux;
        setPago(aux);
        cout<<"INGRESE EL TOTAL";
        cin>>aux;
        setTotal(aux);
        _FechadPago.Cargar();
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"NUMERO DE RECIBO : "<<_NumRecibo<<endl;
        cout<<"FORMA DE PAGO(0 AL CONTADO Y 1 TRANSFERENCIA) :"<<_FormadPago<<endl;
        cout<<"TOTAL : "<<_total<<endl;
        /// cout<<"SEÑA "<<endl;
        _FechadPago.Mostrar();
        }
    }

};



#endif // CLSPAGOS_H_INCLUDED
