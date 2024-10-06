#ifndef CLSPERSONA_H_INCLUDED
#define CLSPERSONA_H_INCLUDED
class Persona
{
private:
     int _dni;
    char _nombre[30];
    char _apellido[30];
    char _telefono[10];
    Fecha _nacimiento;
    bool _estado;
public:
    Persona(int dni,const char *n, const char *a, const char *t,Fecha f)
    {
        _dni=dni;
        strcpy(_nombre,n);
        strcpy(_apellido,a);
        strcpy(_telefono,t);
        _nacimiento=f;

    }
    Persona()
    {
        _dni=0;
        strcpy(_nombre,"0");
        strcpy(_apellido,"0");
        strcpy(_telefono,"0");
    }

    void setEstado(bool est){_estado=est;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setApellido(const char *a){strcpy(_apellido,a);}
    void setTelefono(const char *t){strcpy(_telefono,t);}
    void setNacimiento(Fecha f){_nacimiento=f;}
    void setDNI(int dni)
    {
        char aux;
        if(dni>0)
        {
            _dni=dni;
            return;
        }
        else
        {
            while(dni<0)
                {

            cout<<"DNI NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                cin>>dni;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _dni=dni;
        }
    }

    bool getEstado(){return _estado;}
    const char *getNombre(){return _nombre;}
    const char *getApellido(){return _apellido;}
    const char *getTelefono(){return _telefono;}
    Fecha getNacimiento(){return _nacimiento;}
    int getDni(){return _dni;}


    void Cargar()
    {
        _estado=true;
        int aux;
        Fecha auxF;
        cout<<"INGRESE EL DNI";
        cin>>aux;
        setDNI(aux);
        cout<<"INGRESE EL NOMBRE";
        cargarCadena(_nombre,29);
        cout<<"INGRESE EL APELLIDO";
        cargarCadena(_apellido,29);
        cout<<"INGRESE EL NUMERO DE TELEFONO";
        cargarCadena(_telefono,9);
        cout<<"INGRESE LA FECHA DE NACIMIENTO"<<endl;
        auxF.Cargar();
    }

    void Mostrar()
    {
        if(_estado)
        {
        cout<<"DNI : "<<_dni<<endl;
        cout<<"NOMBRE : "<<_nombre<<endl;
        cout<<"APELLIDO : "<<_apellido<<endl;
        cout<<"NUMERO DE TELEFONO : "<<_telefono<<endl;
        _nacimiento.Mostrar();
        }
    }
};



#endif // CLSPERSONA_H_INCLUDED
