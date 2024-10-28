#ifndef CLSCATEGORIA_H_INCLUDED
#define CLSCATEGORIA_H_INCLUDED

class Categoria {
private:
    int _id;
    char _descripcion[100];
    float _precio;
    bool _estado;

public:
    Categoria()
    {
      _id = 0;
      _precio = 0.0f;
      _estado = false;
      _descripcion[0] = '\0';
    }

    Categoria(int id, char* desc, float precio)
    {
      _id = id;
      _precio = precio;
      _estado = false;
      setDescripcion (desc);
    }

    int getId() { return _id; }
    char* getDescripcion() { return _descripcion; }
    float getPrecio() { return _precio; }
    bool getEstado() { return _estado; }

    void setId(int id) 
    { _id = id; }
    void setDescripcion(char* descripcion) 
    {
        int i;
        for (i = 0; i < 99 && descripcion[i] != '\0'; i++) 
        {
            _descripcion[i] = descripcion[i];
        }
        _descripcion[i] = '\0';
    }
    void setPrecio(float precio) { _precio = precio; }
    void setEstado(bool e) { _estado=e; }
    
    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL ID: ";
        cin>>aux;
        setId(aux);
        
        cin.ignore();
        char auxD[100];
        cout << "INGRESE UNA DESCRIPCION: ";
        cin.getline(auxD, 100);
        setDescripcion(auxD);
        
        float auxF;
        cout<<"INGRESE PRECIO: ";
        cin>>auxF;
        setPrecio(auxF);
    }
    
    void Mostrar()
    {
        if(_estado){
        cout<<"ID: "<<getId()<<"\n";
        cout<<"DESCRIPCION: "<<getDescripcion()<<"\n";
        cout<<"PRECIO: "<<getPrecio()<<"\n";
        }
    }
};

#endif // CLSCATEGORIA_H_INCLUDED
