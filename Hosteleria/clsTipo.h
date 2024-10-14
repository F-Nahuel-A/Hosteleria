#ifndef CLSTIPO_H_INCLUDED
#define CLSTIPO_H_INCLUDED

class Tipo
{
private:
    int _ID;
    char _ocupacion[30];
    bool _estado;
public:
    Tipo(int id=0,const char *o="000")
    {
        _ID=id;
        strcpy(_ocupacion,o);
    }

    int getID(){return _ID;}
    const char *getOcupacion(){return _ocupacion;}
    bool getEstado(){return _estado;}

    void setOcupacion(const char *o)
    {
        strcpy(_ocupacion,o);
    }
    void setEstado(bool e){_estado=e;}
    void setID(int id){if(id>0)_ID=id;}
    void Cargar()
    {
        _estado=true;
        cout<<"INGRESE EL NOMBRE DE LA OCUPACION"<<endl;
        cargarCadena(_ocupacion,29);
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID : "<<_ID<<endl;
        cout<<"OCUPACION : "<<_ocupacion<<endl;
        }
    }
};


#endif // CLSTIPO_H_INCLUDED
