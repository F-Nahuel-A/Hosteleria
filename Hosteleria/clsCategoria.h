#ifndef CLSCATEGORIA_H_INCLUDED
#define CLSCATEGORIA_H_INCLUDED

class Categoria {
private:
    int _id;
    char _descripcion[100];
    float _precio;
    bool _estado;

public:
    Categoria(int id=0,const char *desc="000", float precio=0)
    {
      _id=id;
      _precio=precio;
      strcpy(_descripcion,desc);
    }

    int getId(){return _id;}
    const char *getDescripcion(){return _descripcion;}
    float getPrecio() {return _precio;}
    bool getEstado() {return _estado;}

    void setId(int id) {_id = id;}
    void setDescripcion(const char *descripcion){strcpy(_descripcion,descripcion);}

    void setPrecio(float precio)
    {
        char aux;
        if(precio>0)
        {
            _precio=precio;
            return;
        }
        else
        {
            while(precio<0)
                {

            cout<<"PRECIO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL PRECIO : ";
                cin>>precio;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _precio=precio;
        }
    }
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        FILE *p=fopen("pago.dat","rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Categoria);
        fclose(p);
        _id=cantRegistros+1;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        cout << "INGRESE UNA DESCRIPCION: ";
        cargarCadena(_descripcion,99);
        float auxF;
        cout<<"INGRESE PRECIO: ";
        cin>>auxF;
        setPrecio(auxF);
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID: "<<_id<<endl;
        cout<<"DESCRIPCION: "<<_descripcion<<endl;
        cout<<"PRECIO: "<<_precio<<endl;
        }
    }
};

#endif // CLSCATEGORIA_H_INCLUDED
