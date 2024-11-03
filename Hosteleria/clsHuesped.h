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

    const char *getEmail() const { return _email; }
    bool getEstado(){return _estado;}

    void Cargar()
    {
        _estado=true;
        Persona::Cargar();
        cout<<"INGRESE EL EMAIL : ";
        cin>>_email;
    }

    void Mostrar()
    {
        if(_estado)
        {
        Persona::Mostrar();
        cout<<"EMAIL : "<<_email<<endl;
        }
    }

};

#endif // CLSHUESPED_H_INCLUDED
