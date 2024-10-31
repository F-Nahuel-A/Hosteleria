#ifndef CLSHABITACION_H_INCLUDED
#define CLSHABITACION_H_INCLUDED

class Habitacion {
private:
    int _numHabitacion;
    int _IDCategoria;
    int _IDRegimen;
    int _disponibilidad; /// 0: disponible, 1: ocupado, 2: reservada, 3: en reparaciones
    int _capacidad;
    bool _estado;

public:
    Habitacion(int numero=0, int categoria=0, int regimen=0, int disponibilidad=0, int cap=0)
    {
      _numHabitacion = numero;
      _IDCategoria = categoria;
      _IDRegimen = regimen;
      _disponibilidad = disponibilidad;
      _capacidad = cap;
    }

    int getNumero() { return _numHabitacion; }
    int getIdCategoria() { return _IDCategoria; }
    int getIdRegimen() { return _IDRegimen; }
    int getDisponibilidad() { return _disponibilidad; }
    int getCapacidad() { return _capacidad; }
    bool getEstado(){return _estado;}

    void setNumero(int numero) { _numHabitacion = numero; }
    void setIdCategoria(int categoria)
    {
        ArchivoCategoria archivoCategoria;
        int pos = archivoCategoria.buscarRegistro(categoria);
        if (pos != -1) {
            _IDCategoria = categoria;
        } else {
            cout << "ERROR: El ID de categoría no existe." << endl;
        }
    }
    void setIdRegimen(int regimen)
    {
        ArchivoRegimenComida archivoRegimen;
        int pos = archivoRegimen.buscarRegistro(regimen);
        if (pos != -1) {
            _IDRegimen = regimen;
        } else {
            cout << "ERROR: El ID de régimen no existe." << endl;
        }
    }
    void setDisponibilidad(int estado) { _disponibilidad = estado; }
    void setCapacidad(int cap) { _capacidad = cap; }
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL NUMERO HABITACION: ";
        cin>>aux;
        setNumero(aux);
        cout<<"INGRESE LA CATEGORIA: ";
        cin>>aux;
        setIdCategoria(aux);
        cout<<"INGRESE EL REGIMEN: ";
        cin>>aux;
        setIdRegimen(aux);
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
        cout<<"NUMERO HABITACION: "<<_numHabitacion<<endl;
        cout<<"CATEGORIA: "<<_IDCategoria<<endl;
        cout<<"REGIMEN: "<<_IDRegimen<<endl;
        cout<<"DISPONIBILIDAD: "<<_disponibilidad<<endl;
        cout<<"CAPACIDAD MAX: "<<_capacidad<<endl;
        }
    }
};

#endif // CLSHABITACION_H_INCLUDED
