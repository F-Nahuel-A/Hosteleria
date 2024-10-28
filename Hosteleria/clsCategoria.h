#ifndef CLSCATEGORIA_H_INCLUDED
#define CLSCATEGORIA_H_INCLUDED

class Categoria {
private:
    int _id;
    char _descripcion[100];
    float _precio;
    bool _estado;

public:
    Categoria(int id=0,const char *desc="000", float precio=0)
    {
      _id=id;
      _precio=precio;
      strcpy(_descripcion,desc);
    }

    int getId(){return _id;}
    const char *getDescripcion(){return _descripcion;}
    float getPrecio() {return _precio;}
    bool getEstado() {return _estado;}

    void setId(int id) {_id = id;}
    void setDescripcion(const char *descripcion){strcpy(_descripcion,descripcion);}
    void setPrecio(float precio){_precio=precio;}
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL ID: ";
        cin>>aux;
        setId(aux);
        cout << "INGRESE UNA DESCRIPCION: ";
        cargarCadena(_descripcion,99);
        float auxF;
        cout<<"INGRESE PRECIO: ";
        cin>>auxF;
        setPrecio(auxF);
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID: "<<_id<<endl;
        cout<<"DESCRIPCION: "<<_descripcion<<endl;
        cout<<"PRECIO: "<<_precio<<endl;
        }
    }
};

#endif // CLSCATEGORIA_H_INCLUDED
