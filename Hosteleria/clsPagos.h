#ifndef CLSPAGOS_H_INCLUDED
#define CLSPAGOS_H_INCLUDED

class Pagos
{
private:
    int _numeroderecibo;
    int _dni;
    Fecha _depago;
    int _formadepago; /// 0: al contado y 1: deja seña y paga el resto en recepción
    float _total;
    bool _estado;
public:
    Pagos(int recibo=0, int forma=0, float t=0){
    _numeroderecibo=recibo;
    _formadepago=forma;
    _total=t;
    }

    int getNumeroderecibo(){return _recibo;}
    int getDNI(){return _dni;}
    Fecha getFecha(){return _depago;}
    int getFormadepago(){return _forma;}
    float getTotal(){return _total;}
    bool getEstado(){return _estado;}

    void setNumero (int recibo){

    if (recibo>0){_numeroderecibo=recibo} ///revisar la manera de que se genere automaticamente

    }

    void setFecha(Fecha f){_depago=f;}

    void setPago(int forma){
    if (forma == 1 || forma == 0) /// sea 1 o 0, lo va a mostrar al final
    {
        _formadepago = forma;
    }
}
    void setTotal (float t){_total=t} ///revisarlo, falta parte del codigo
    void setEstado(bool e){_estado=e;}


    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL NUMERO DE RECIBO";
        cin>>aux;
        setRecibo(aux);
        cout<<"INGRESE LA FORMA DE PAGO";
        cin>>aux;
        setFormadepago(aux);
        cout<<"INGRESE EL TOTAL";
        cin>>aux;
        setTotal(aux);
        _ingreso.Cargar();
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"NUMERO DE RECIBO : "<<_numeroderecibo<<endl;
        cout<<"FORMA DE PAGO(0 AL CONTADO Y 1 DEJO SEÑA) :"<<_formadepago<<endl;
        cout<<"TOTAL : "<<_total<<endl;
        /// cout<<"SEÑA "<<endl;
        _ingreso.Mostrar();
        }
    }

};



#endif // CLSPAGOS_H_INCLUDED
