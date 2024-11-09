#ifndef CLSHUESPED_H_INCLUDED
#define CLSHUESPED_H_INCLUDED

class Huesped : public Persona
{
private:
    char _email[50];
    bool _estado;

public:
    Huesped(const char *email = "sinemail")
    {
        strcpy(_email, email);
    }

    void setEmail(const char *email) { strcpy(_email, email); }
    void setEstado(bool e){_estado=e;}
    void setDNIhuesped(int dni);

    const char *getEmail() const { return _email; }
    bool getEstado(){return _estado;}

    void Cargar()
    {
        _estado=true;
        Persona::Cargar();
        setDNIhuesped(Persona::getDni());
        if(_estado==false){return;}
        cout<<"INGRESE EL EMAIL : ";
        cargarCadena(_email,49);
    }

    void Mostrar()
    {
        if(_estado)
        {
        Persona::setEstado(true); ///No encontre otra forma de hacer que se vea.
        Persona::Mostrar();
        cout<<"EMAIL : "<<_email<<endl;
        }
    }

};

void Huesped::setDNIhuesped(int dni)
{
        char aux;
        Huesped obj;
        FILE *p=fopen("huesped.dat", "rb");
        if(p == NULL){return;}
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Huesped);
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

#endif // CLSHUESPED_H_INCLUDED
