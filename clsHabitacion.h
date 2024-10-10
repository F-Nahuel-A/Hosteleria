#ifndef CLSHABITACION_H_INCLUDED
#define CLSHABITACION_H_INCLUDED
class Habitacion
{
private:
    int _codigoHabitacion;
    char _tipoHabitacion[30];
    char _estado[20]; ///(Libre, Ocupada, Reservada, Fuera de servicio)
    int _capacidad;

public:
    Habitacion(int codigo, const char* tipo, const char* estado, int capacidad)
    {
        _codigoHabitacion = codigo;
        strcpy(_tipoHabitacion, tipo);
        strcpy(_estado, estado);
        _capacidad = capacidad;
    }
    Habitacion()
    {
        _codigoHabitacion = 0;
        strcpy(_tipoHabitacion, "Sin definir");
        strcpy(_estado, "Libre");
        _capacidad = 0;
    }

    void setCodigoHabitacion(int codigo)
    {
        _codigoHabitacion = codigo;
    }
    void setTipoHabitacion(const char* tipo)
    {
        strcpy(_tipoHabitacion, tipo);
    }
    void setEstado(const char* estado)
    {
        strcpy(_estado, estado);
    }
    void setCapacidad(int capacidad)
    {
        _capacidad = capacidad;
    }

    int getCodigoHabitacion() 
    {
        return _codigoHabitacion;
    }
    const char* getTipoHabitacion() 
    {
        return _tipoHabitacion;
    }
    const char* getEstado() 
    {
        return _estado;
    }
    int getCapacidad() 
    {
        return _capacidad;
    }

    void Cargar()
    {
        cout << "Ingrese el código de la habitación: ";
        cin >> _codigoHabitacion;
        cout << "Ingrese el tipo de habitación: ";
        cin.ignore();
        cargarCadena(_tipoHabitacion, 29);
        cout << "Ingrese el estado de la habitación: "; ///(Libre, Ocupada, Reservada, Fuera de servicio)
        cargarCadena(_estado, 19);
        cout << "Ingrese la capacidad de la habitación: ";
        cin >> _capacidad;
    }

    void Mostrar()
    {
        cout << "Código de habitación: " << _codigoHabitacion << endl;
        cout << "Tipo de habitación: " << _tipoHabitacion << endl;
        cout << "Estado: " << _estado << endl;
        cout << "Capacidad: " << _capacidad << endl;
    }
};

#endif // CLSHABITACION_H_INCLUDED
