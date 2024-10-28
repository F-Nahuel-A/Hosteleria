#ifndef CLSHABITACION_H_INCLUDED
#define CLSHABITACION_H_INCLUDED

class Habitacion {
private:
    int _numero;
    int _idCategoria;
    int _idRegimen;
    int _disponibilidad; /// 0: disponible, 1: ocupado, 2: reservada, 3: en reparaciones
    int _capacidad;
    bool _estado;

public:
    Habitacion()
    { 
      _numero = 0;
      _idCategoria = 0;
      _idRegimen = 0;
      _disponibilidad = 0;
      _capacidad = 0;
      _estado = false;
    }
    Habitacion(int numero, int categoria, int regimen, int disponibilidad, int cap) 
    { 
      _numero = numero;
      _idCategoria = categoria;
      _idRegimen = regimen;
      _disponibilidad = disponibilidad;
      _capacidad = cap;
      _estado = false;
    }

    int getNumero() { return _numero; }
    int getIdCategoria() { return _idCategoria; }
    int getIdRegimen() { return _idRegimen; }
    int getDisponibilidad() { return _disponibilidad; }
    int getCapacidad() { return _capacidad; }
    bool getEstado(){return _estado;}

    void setNumero(int numero) { _numero = numero; }
    void setIdCategoria(int categoria) { _idCategoria = categoria; }
    void setIdRegimen(int regimen) { _idRegimen = regimen; }
    void setDisponibilidad(int estado) { _disponibilidad = estado; }
    void setCapacidad(int cap) { _capacidad = cap; }
    void setEstado(bool e){_estado=e;}
    
    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL NUMERO H: ";
        cin>>aux;
        setNumero(aux);
        cout<<"INGRESE DISPONIBILIDAD: ";
        cin>>aux;
        setDisponibilidad(aux);
        cout<<"INGRESE CAPACIDAD MAX: ";
        cin>>aux;
        setCapacidad(aux);
    }
    
    void Mostrar()
    {
        if(_estado){
        cout<<"NUMERO H: "<<getNumero()<<"\n";
        cout<<"DISPONIBILIDAD: "<<getDisponibilidad()<<"\n";
        cout<<"CAPACIDAD MAX: "<<getCapacidad()<<"\n";
        }
    }
};

#endif // CLSHABITACION_H_INCLUDED
