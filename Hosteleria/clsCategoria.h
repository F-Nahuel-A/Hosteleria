#ifndef CLSCATEGORIA_H_INCLUDED
#define CLSCATEGORIA_H_INCLUDED

class Categoria {
private:
    int _id;
    string _descripcion;
    float _precio;
    bool _estado;

public:
    Categoria() : _id(0), _descripcion(""), _precio(0.0f) {}

    Categoria(int id, string& desc, float precio) 
        : _id(id), _descripcion(desc), _precio(precio) {}

    int getId() { return _id; }
    string getDescripcion() { return _descripcion; }
    float getPrecio() { return _precio; }
    bool getEstado(){return _estado;}

    void setId(int id) { _id = id; }
    void setDescripcion(string& descripcion) { _descripcion = descripcion; }
    void setPrecio(float precio) { _precio = precio; }
    void setEstado(bool e){_estado=e;}
};

#endif // CLSCATEGORIA_H_INCLUDED
