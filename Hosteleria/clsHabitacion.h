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

    void setNumero(int numero);
    void setIdCategoria(int categoria);
    void setIdRegimen(int regimen);
    void setDisponibilidad(int estado);
    void setCapacidad(int cap);

    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL NUMERO HABITACION: ";
        cin>>aux;
        setNumero(aux);
        if(_estado=false){return;}
        cout<<"INGRESE LA CATEGORIA: ";
        cin>>aux;
        setIdCategoria(aux);
        if(_estado=false){return;}
        cout<<"INGRESE EL REGIMEN: ";
        cin>>aux;
        setIdRegimen(aux);
        if(_estado=false){return;}
        cout<<"INGRESE DISPONIBILIDAD: ";
        cin>>aux;
        setDisponibilidad(aux);
        if(_estado=false){return;}
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

void Habitacion::setIdCategoria(int categoria)
    {
        ArchivoCategoria arc;
        Categoria obj;
        char aux;
        int pos;
        while(_estado){
        pos=arc.buscarRegistro(categoria);
        if(pos==-1)
        {
            cout<<"ID DE CATEGORIA NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DE LA CATEGORIA : ";
                cin>>categoria;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }
        }
        if(pos!=-1)
        {
            obj=arc.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR LA CATEGORIA : "<<obj.getDescripcion()<<endl<<"S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDCategoria=categoria;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRA CATEGORIA? "<<endl<<"S/N"<<endl;
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    cout<<"INGRESE EL ID DE LA CATEGORIA : ";
                    cin>>categoria;
                }
            else{return;}
            }
        }
        }
    }

void Habitacion::setIdRegimen(int regimen)
    {
        ArchivoRegimenComida arc;
        RegimenComida obj;
        char aux;
        int pos;
        while(_estado){
        pos=arc.buscarRegistro(regimen);
        if(pos==-1)
        {
            cout<<"ID DE REGIMEN NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO : ";
                cin>>regimen;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }
        }
        if(pos!=-1)
        {
            obj=arc.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL REGIMEN : "<<obj.getDesc()<<endl<<"S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDRegimen=regimen;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRO REGIMEN? "<<endl<<"S/N"<<endl;
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    cout<<"INGRESE EL ID DEL REGIMEN : ";
                    cin>>regimen;
                }
            else{return;}
            }
        }
        }
    }

void Habitacion::setNumero(int numero)
    {
        char aux;
        if(numero>0)
        {
            _numHabitacion=numero;
            return;
        }
        else
        {
            while(numero<0)
                {

            cout<<"NUMERO DE HABITACION NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL NUMERO DE HABITACION : ";
                cin>>numero;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _numHabitacion=numero;
        }
    }

void Habitacion::setDisponibilidad(int estado)
    {
        char aux;
        if(estado>0)
        {
            _disponibilidad=estado;
            return;
        }
        else
        {
            while(estado<0)
                {

            cout<<"LA DISPONIBILIDAD DE LA HABITACION NO ES VALIDA,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE LA DISPONIBILIDAD DE LA HABITACION : ";
                cin>>estado;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _disponibilidad=estado;
        }
    }

void Habitacion::setCapacidad(int cap)
    {
        char aux;
        if(cap>0)
        {
            _capacidad=cap;
            return;
        }
        else
        {
            while(cap<0)
                {

            cout<<"LA CAPACIDAD DE LA HABITACION NO ES VALIDA,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE LA CAPACIDAD DE LA HABITACION : ";
                cin>>cap;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _capacidad=cap;
        }
    }
#endif // CLSHABITACION_H_INCLUDED
