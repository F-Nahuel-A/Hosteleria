#ifndef CLSEMPLEADO_H_INCLUDED
#define CLSEMPLEADO_H_INCLUDED
class Empleado
{
private:
    int _legajo;
    int _dni; ///Quedaria mejor composición o herencia
    int _turno;
    Tipo _tipo;
    Fecha _ingreso;
    bool _estado;
public:
    Empleado(int l=0, int d=0, int t=0, int tipo=0)
    {
        _legajo=l;
        _dni=d;
        _turno=t;
        _tipo=tipo;
    }

    int getLegajo(){return _legajo;}
    int getTurno(){return _turno;}
    Tipo getTipo(){return _tipo;}
    Fecha getFecha(){return _ingreso;}
    bool getEstado(){return _estado;}

    void setLegajo(int l)
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

            cout<<"LEGAJO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
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

    void setTurno(int t)
    {
        if(t == 1 || t == 2 || t == 3)
        {
            _turno=t;
        }
    }

    void setFecha(Fecha f){_ingreso=f;}
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL LEGAJO";
        cin>>aux;
        ///DNI
        cout<<"INGRESE EL TURNO";
        cin>>aux;
        setTurno(aux);
        cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO";
        cin>>aux;
        _tipo.setID(aux);
         ///Acá puede haber una función setID pero de la clase empleado, que vaya a el archivo a corroborar
         ///que el ID exista y se le asigne automaticamente el nombre.
        _ingreso.Cargar();
    }
    void Mostrar()
    {
        cout<<"LEGAJO : "<<_legajo<<endl;
        ///dni
        cout<<"TURNO : "<<_turno<<endl;
        _tipo.Mostrar();
        cout<<"FECHA DE INGRESO"<<endl;
        _ingreso.Mostrar();
    }
};



#endif // CLSEMPLEADO_H_INCLUDED
