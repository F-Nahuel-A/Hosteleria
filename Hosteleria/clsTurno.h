#ifndef CLSTURNO_H_INCLUDED
#define CLSTURNO_H_INCLUDED

class TurnoEmpleado
{
private:
    int _ID;
    char _horario[6];
    bool _estado;
public:
    TurnoEmpleado(int i=0,const char *h="00")
    {
        _ID=i;
        strcpy(_horario,h);
    }

    int getID(){return _ID;}
    const char *getHorario(){return _horario;}
    bool getEstado(){return _estado;}

    void setID(int i){_ID=i;}
    void setHorario(const char *h){strcpy(_horario,h);}
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        FILE *p=fopen("turnoempleado.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (TurnoEmpleado);
        fclose(p);
        _ID=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        cout<<"INGRESE EL HORARIO DEL TURNO : ";
        cargarCadena(_horario,5);
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID DEL TURNO : "<<_ID<<endl;
        cout<<"HORARIO DEL TURNO : "<<_horario<<endl;
        }
}

};


#endif // CLSTURNO_H_INCLUDED
