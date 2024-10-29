#ifndef CLSREGIMENCOMIDA_H_INCLUDED
#define CLSREGIMENCOMIDA_H_INCLUDED
class RegimenComida
{
private:
    int _ID;
    char _descripcion[100];
    float _precio;
    bool _estado;
public:
    RegimenComida(int id=0,const char *d="00",float p=0)
    {
        _ID=id;
        strcpy(_descripcion,d);
        _precio=p;
    }

    void setID(int id){if(id>0){_ID=id;}}

    void setDesc(const char *d){strcpy(_descripcion,d);}

    void setPrecio(float p){if(p>0){_precio=p;}}

    void setEstado(bool e){_estado=e;}

    int getID(){return _ID;}
    const char *getDesc(){return _descripcion;}
    float getPrecio(){return _precio;}
    bool getEstado(){return _estado;}

    void Cargar()
    {
        float aux;
        _estado=true;
         ///ASIGNACIÓN AUTOMATICA DEL ID
        FILE *p=fopen("regimenComida.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (RegimenComida);
        fclose(p);
        _ID=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        cout<<"INGRESE LA DESCRIPCION ";
        cargarCadena(_descripcion,99);
        cout<<"INGRESE EL PRECIO ";
        cin>>aux;
        setPrecio(aux);
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID : "<<_ID<<endl;
        cout<<"DESCRIPCION : "<<_descripcion<<endl;
        cout<<"PRECIO : "<<_precio<<endl;
        }
    }
};



#endif // CLSREGIMENCOMIDA_H_INCLUDED
