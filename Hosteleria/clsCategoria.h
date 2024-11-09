#ifndef CLSCATEGORIA_H_INCLUDED
#define CLSCATEGORIA_H_INCLUDED

class Categoria {
private:
    int _id;
    char _descripcion[100];
    float _precioXpersona;
    bool _estado;

public:
    Categoria(int id=0,const char *desc="000", float precioXpersona=0)
    {
      _id=id;
      _precioXpersona=precioXpersona;
      strcpy(_descripcion,desc);
    }

    int getId(){return _id;}
    const char *getDescripcion(){return _descripcion;}
    float getPrecioXpersona() {return _precioXpersona;}
    bool getEstado() {return _estado;}

    void setId(int id) {_id = id;}
    void setDescripcion(const char *descripcion){strcpy(_descripcion,descripcion);}

    void setPrecioXpersona(float precioXpersona)
    {
        char aux;
        if(precioXpersona>0)
        {
            _precioXpersona=precioXpersona;
            return;
        }
        else
        {
            while(precioXpersona<0)
                {

            cout<<"PRECIO NO VALIDO,QUIERE VOLVER A INTENTAR ?"<<endl<<"S/N : ";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL PRECIO : ";
                cin>>precioXpersona;
            }

            else
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _precioXpersona=precioXpersona;
        }
    }
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        ///ASIGNACIÓN AUTOMATICA DEL ID
        FILE *p=fopen("categoria.dat","rb");
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
        setPrecioXpersona(auxF);
    }

    void Mostrar()
    {
        if(_estado){
        cout<<"ID: "<<_id<<endl;
        cout<<"DESCRIPCION: "<<_descripcion<<endl;
        cout<<"PRECIO: "<<_precioXpersona<<endl;
        }
    }
};

#endif // CLSCATEGORIA_H_INCLUDED
