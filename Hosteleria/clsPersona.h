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
    Persona(int dni=0,const char *n="0000", const char *a="0000", const char *t="0000")
    {
        _dni=dni;
        strcpy(_nombre,n);
        strcpy(_apellido,a);
        strcpy(_telefono,t);
    }

    void setEstado(bool est){_estado=est;}
    void setNombre(const char *n){strcpy(_nombre,n);}
    void setApellido(const char *a){strcpy(_apellido,a);}
    void setTelefono(const char *t){strcpy(_telefono,t);}
    void setNacimiento(Fecha f){_nacimiento=f;}

    void setDNI(int dni);

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
        cout<<"INGRESE EL DNI : ";
        cin>>aux;
        setDNI(aux);
        if(_estado==false){return;}
        cout<<"INGRESE EL NOMBRE : ";
        cargarCadena(_nombre,29);
        cout<<"INGRESE EL APELLIDO : ";
        cargarCadena(_apellido,29);
        cout<<"INGRESE EL NUMERO DE TELEFONO : ";
        cargarCadena(_telefono,9);
        cout<<"INGRESE LA FECHA DE NACIMIENTO "<<endl;
        _nacimiento.Cargar();
    }


    void Mostrar()
    {
        if(_estado)
        {
        cout<<"DNI : "<<_dni<<endl;
        cout<<"NOMBRE : "<<_nombre<<endl;
        cout<<"APELLIDO : "<<_apellido<<endl;
        cout<<"NUMERO DE TELEFONO : "<<_telefono<<endl;
        cout<<"FECHA DE NACIMIENTO : ";
        _nacimiento.Mostrar();
        }
    }
};

void Persona::setDNI(int dni)
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

            cout<<"DNI NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL DNI : ";
                cin>>dni;
            }

            else
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


#endif // CLSPERSONA_H_INCLUDED
