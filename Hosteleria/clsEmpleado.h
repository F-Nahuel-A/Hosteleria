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

    void setDNIEmp(int dni);
    void setLegajo(int l){_legajo=l;}
    void setIDturno(int t);
    void setIDtipo(int t);
    void setFecha(Fecha f){_ingreso=f;}
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        Persona::Cargar();
        setDNIEmp(Persona::getDni());
        if(_estado==false){return;}
        cout<<"DATOS PERSONALES CARGADOS"<<endl;
        system("pause");
        system("cls");
        cout<<"DATOS LABORALES"<<endl;
        int aux;
        ///
        FILE *p=fopen("Pago.dat","rb");
        if(p == NULL){cout<<"ERROR EN LA APERTURA"<<endl;return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Empleado);
        fclose(p);
        _legajo=cantRegistros+1;
        ///
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
        cout<<"FECHA DE INGRESO : ";
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
            cout<<"ID DE SECTOR NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO : ";
                cin>>t;
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
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL CARGO : "<<obj.getOcupacion()<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                _IDtipo=t;
                return;
            }
            else
            {
                cout<<"QUIERE INGRESAR OTRO ? "<<endl<<"S/N : ";
                cin>>aux;
                if(aux=='S' || aux=='s')
                {
                    system("cls");
                    cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO : ";
                    cin>>t;
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
            cout<<"ID DE TURNO NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ID DEL TURNO DE TRABAJO : ";
                cin>>t;
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
            cout<<"ESTA SEGURO QUE DESEA ASIGNAR EL TURNO : "<<obj.getHorario()<<endl<<"S/N : ";
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
                    system("cls");
                    cout<<"INGRESE EL ID DEL TURNO : ";
                    cin>>t;
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

void Empleado::setDNIEmp(int dni)
{
        char aux;
        Empleado obj;
        FILE *p=fopen("empleado.dat", "rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Empleado);
        bool existe=false;

        for (int i=0;i<cantRegistros;i++)
        {
            fseek(p, i * sizeof obj, 0);
            fread(&obj, sizeof obj, 1, p);
            if(obj.getDni()==dni)
            {
                existe=true;
            }
        }
            if(existe)
            {
                cout<<"EL DNI YA EXISTE,VUELVA A INGRESAR LOS DATOS."<<endl;
                _estado=false;
            };
       fclose(p); }
#endif // CLSEMPLEADO_H_INCLUDED
