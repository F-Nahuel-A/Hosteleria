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
    Fecha _ingreso;
    Fecha _salida;

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
    Fecha getIngreso(){return _ingreso;}
    Fecha getSalida(){return _salida;}

    void setNumero(int numero){_numHabitacion=numero;}
    void setIdCategoria(int categoria);
    void setIdRegimen(int regimen);
    void setDisponibilidad(int estado);
    void setCapacidad(int cap);
    void setIngreso(Fecha in){_ingreso=in;}
    void setSalida(Fecha salida){_salida=salida;}

    Habitacion asignar(int idRegimen,int disponibilidad,Fecha ingreso, Fecha salida)
    {
        _IDRegimen=idRegimen;
        _disponibilidad=disponibilidad;
        _ingreso=ingreso;
        _salida=salida;
    }

    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        ///ASIGNACIÓN AUTOMATICA DE LA HABITACION
        FILE *p=fopen("habitacion.dat","rb");
        if(p == NULL){cout<<"ERROR EN LA APERTURA";return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Habitacion);
        fclose(p);
        _numHabitacion=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DE LA HABITACION
        cout<<"INGRESE LA CATEGORIA: ";
        cin>>aux;
        setIdCategoria(aux);
        if(_estado==false){return;}
        cout<<"INGRESE CAPACIDAD MAX: ";
        cin>>aux;
        setCapacidad(aux);
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"NUMERO HABITACION: "<<_numHabitacion<<endl;
        cout<<"CATEGORIA: "<<_IDCategoria<<endl;
        if(_IDRegimen!=0)
        {cout<<"REGIMEN: "<<_IDRegimen<<endl;}
        switch (_disponibilidad)
        {
        case 0:
            cout<<"DISPONIBLE";
            break;

        case 1:
            cout<<"OCUPADA"<<endl;
            cout<<"FECHA DE INGRESO : ";
            _ingreso.Mostrar();
            cout<<"FECHA DE SALIDA : ";
            _salida.Mostrar();
            break;

        case 2:
            cout<<"RESERVADA"<<endl;
            cout<<"FECHA DE LLEADA : ";
            _ingreso.Mostrar();
            cout<<"FECHA DE SALIDA : ";
            _salida.Mostrar();
            break;

        case 3:
            cout<<"EN REPARACIONES";
            break;
        }
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
            cout<<"ID DE CATEGORIA NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DE LA CATEGORIA : ";
                cin>>categoria;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }
        }
        if(pos!=-1)
        {
            obj=arc.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR LA CATEGORIA : "<<obj.getDescripcion()<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDCategoria=categoria;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRA CATEGORIA? "<<endl<<"S/N : ";
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    system("cls");
                    cout<<"INGRESE EL ID DE LA CATEGORIA : ";
                    cin>>categoria;
                }
            else
                {
                _estado=false;
                return;
                }
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
            cout<<"ID DE REGIMEN NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO : ";
                cin>>regimen;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }
        }
        if(pos!=-1)
        {
            obj=arc.leerRegistro(pos);
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL REGIMEN : "<<obj.getDesc()<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDRegimen=regimen;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRO REGIMEN? "<<endl<<"S/N : ";
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    system("cls");
                    cout<<"INGRESE EL ID DEL REGIMEN : ";
                    cin>>regimen;
                }
            else
                {
                _estado=false;
                return;
                }
            }
        }
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

            cout<<"LA DISPONIBILIDAD DE LA HABITACION NO ES VALIDA,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE LA DISPONIBILIDAD DE LA HABITACION : ";
                cin>>estado;
            }

            else
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

            cout<<"LA CAPACIDAD DE LA HABITACION NO ES VALIDA,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE LA CAPACIDAD DE LA HABITACION : ";
                cin>>cap;
            }

            else
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
