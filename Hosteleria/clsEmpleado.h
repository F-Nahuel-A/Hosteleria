#ifndef CLSEMPLEADO_H_INCLUDED
#define CLSEMPLEADO_H_INCLUDED
class Empleado : public Persona
{
private:
    int _legajo;
    int _IDturno;
    int _IDtipo;
    Fecha _ingreso;
    bool _estado;
public:
    Empleado(int l=0, int t=0, int tipo=0)
    {
        _legajo=l;
        _IDturno=t;
        _IDtipo=tipo;
    }

    int getLegajo(){return _legajo;}
    int getIDturno(){return _IDturno;}
    int getIDtipo(){return _IDtipo;}
    Fecha getFecha(){return _ingreso;}
    bool getEstado(){return _estado;}

    void setLegajo(int l);
    void setIDturno(int t);
    void setIDtipo(int t);
    void setFecha(Fecha f){_ingreso=f;}
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        Persona::Cargar();
        cout<<"DATOS PERSONALES CARGADOS"<<endl;
        system("pause");
        system("cls");
        cout<<"DATOS LABORALES"<<endl;
        int aux;
        cout<<"INGRESE EL LEGAJO : ";
        cin>>aux;
        setLegajo(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL TURNO : ";
        cin>>aux;
        setIDturno(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO : ";
        cin>>aux;
        setIDtipo(aux);
        if(_estado==false){return;}
        cout<<"FEHCA DE INGRESO"<<endl;
        _ingreso.Cargar();
    }
    void Mostrar()
    {
        if(_estado){
        Persona::setEstado(true); ///No encontre otra forma de hacer que se vea.
        Persona::Mostrar();
        cout<<"LEGAJO : "<<_legajo<<endl;
        cout<<"TURNO : "<<_IDturno<<endl;
        cout<<"TIPO : "<<_IDtipo<<endl;
        cout<<"FECHA DE INGRESO"<<endl;
        _ingreso.Mostrar();
        }
    }
};

void Empleado::setIDtipo(int t)
    {
        ArchivoTipoEmpleado arc;
        TipoEmpleado obj;
        char aux;
        int pos;
        while(_estado){
        pos=arc.buscarRegistro(t);
        if(pos==-1)
        {
            cout<<"ID DE SECTOR NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO : ";
                cin>>t;
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
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL CARGO : "<<obj.getOcupacion()<<endl<<"S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDtipo=t;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRO ? "<<endl<<"S/N"<<endl;
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO : ";
                    cin>>t;
                }
            else{return;}
            }
        }
        }
    }

void Empleado::setIDturno(int t)
    {
        ArchivoTurnoEmpleado arc;
        TurnoEmpleado obj;
        char aux;
        int pos;
        while(_estado){
        pos=arc.buscarRegistro(t);
        if(pos==-1)
        {
            cout<<"ID DE TURNO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DEL TURNO DE TRABAJO : ";
                cin>>t;
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
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL TURNO : "<<obj.getHorario()<<endl<<"S/N"<<endl;
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDturno=t;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRO ? "<<endl<<"S/N"<<endl;
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    cout<<"INGRESE EL ID DEL TURNO : ";
                    cin>>t;
                }
            else{return;}
            }
        }
        }
    }

void Empleado::setLegajo(int l)
    {
        char aux;
        if(l>0)
        {
            _legajo=l;
            return;
        }
        else
        {
            while(l<0)
                {

            cout<<"LEGAJO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL LEGAJO : ";
                cin>>l;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _legajo=l;
        }
    }
#endif // CLSEMPLEADO_H_INCLUDED
