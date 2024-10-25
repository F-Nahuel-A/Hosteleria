#ifndef CLSTIPO_H_INCLUDED
#define CLSTIPO_H_INCLUDED

class TipoEmpleado
{
private:
    int _ID;
    char _ocupacion[30];
    float _sueldo;
    bool _estado;
public:
    Tipo(int id=0,const char *o="000", float s=0)
    {
        _ID=id;
        strcpy(_ocupacion,o);
        _sueldo=s;
    }

    int getID(){return _ID;}
    float getSueldo(){return _sueldo;}
    const char *getOcupacion(){return _ocupacion;}
    bool getEstado(){return _estado;}

    void setOcupacion(const char *o)
    {
        strcpy(_ocupacion,o);
    }
    void setEstado(bool e){_estado=e;}
    void setSueldo(float s){_sueldo=s;}
    void setID(int id){if(id>0)_ID=id;}
    void Cargar()
    {
        _estado=true;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        FILE *p=fopen("tipoempleado.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (TipoEmpleado);
        fclose(p);
        _ID=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        cout<<"INGRESE EL NOMBRE DE LA OCUPACION"<<endl;
        cargarCadena(_ocupacion,29);
        cout<<"INGRESE EL SUELDO DEL SECTOR"<<endl;
        cin>>_sueldo;
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID : "<<_ID<<endl;
        cout<<"OCUPACION : "<<_ocupacion<<endl;
        cout<<"SUELDO : "<<_sueldo<<endl;
        }
    }
};


#endif // CLSTIPO_H_INCLUDED
