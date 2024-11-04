#ifndef ARCHUESPED_H_INCLUDED
#define ARCHUESPED_H_INCLUDED

class ArchivoHuesped
{
private:
    char _nombre[30];

public:
    ArchivoHuesped(const char *n = "huesped.dat") { strcpy(_nombre, n); }

    Huesped leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Huesped obj);
    int buscarRegistro(int dni);
    void modificarRegistro(Huesped obj, int pos);
    void listarArchivo();
    void listarPorDNI();

    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();

    void cambiarDNI();
    void cambiarNombre();
    void cambiarApellido();
    void cambiarFechaNacimiento();
    void cambiarTelefono();
    void cambiarEmail();
};

Huesped ArchivoHuesped::leerRegistro(int pos)
{
    Huesped obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoHuesped::contarRegistros()
{
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int cantBytes = ftell(p);
    fclose(p);
    return cantBytes / sizeof(Huesped);
}

bool ArchivoHuesped::grabarRegistro(Huesped obj)
{
    FILE *p = fopen(_nombre, "ab");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

int ArchivoHuesped::buscarRegistro(int dni)
{
    int cant = contarRegistros();
    Huesped obj;
    for (int i = 0; i < cant; i++)
    {
        obj = leerRegistro(i);
        if (obj.getDni() == dni && obj.getEstado())
        {
            return i;
        }
    }
    cout << "NO SE ENCONTRO EL REGISTRO" << endl;
    return -1;
}

void ArchivoHuesped::modificarRegistro(Huesped obj, int pos)
{
    FILE *p = fopen(_nombre, "rb+");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return;
    }
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    cout << "MODIFICACION HECHA" << endl;
    system("pause");
}

void ArchivoHuesped::listarArchivo()
{
    Huesped obj;
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++)
    {
        obj = leerRegistro(i);
        if (obj.getEstado())
        {
            obj.Mostrar();
            cout << endl;
        }
    }
    system("pause");
}

void ArchivoHuesped::limpiarArchivo()
{
    FILE *p = fopen(_nombre, "wb");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return;
    }
    fclose(p);
}

void ArchivoHuesped::altaRegistro()
{
    Huesped obj;
    obj.Cargar();
    if (obj.getEstado())
    {
        if (grabarRegistro(obj))
        {
            cout << "REGISTRO GUARDADO CORRECTAMENTE" << endl;
        }
        else
        {
            cout << "NO SE PUDO GUARDAR EL ARCHIVO" << endl;
        }
    }
    else
    {
        cout << "NO SE PUDO CARGAR CORRECTAMENTE EL ARCHIVO" << endl;
    }
    system("pause");
}

void ArchivoHuesped::bajaRegistro()
{
    Huesped obj;
    int dni;
    cout << "INGRESE EL DNI DEL HUESPED QUE DESEA BORRAR : ";
    cin >> dni;
    int pos = buscarRegistro(dni);
    if (pos == -1)
    {
        cout << "NO SE ENCONTRO EL REGISTRO" << endl;
        return;
        system("pause");
    }
    obj = leerRegistro(pos);
    if (!obj.getEstado())
    {
        cout << "EL REGISTRO YA HABIA SIDO BORRADO." << endl;
        system("pause");
        return;
    }
    obj.setEstado(false);
    modificarRegistro(obj, pos);
    cout << "EL REGISTRO SE BORRO CORRECTAMENTE." << endl;
    system("pause");
}

void ArchivoHuesped::cambiarDNI()
{
    int pos,dni;
    char aux;
    Huesped obj;
    while(true){
    cout<<"INGRESE EL DNI DEL HUESPED QUE DESEE CAMBIAR : "<<endl;
    cin>>pos;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl;
        obj.Mostrar();
        cout<<"S/N : ";
        cin>>aux;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE EL NUEVO DNI : ";
           cin>>dni;
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL DNI : "<<dni<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setDNI(dni);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO EMPLEADO ? S/N "<<endl; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
    system("cls");
        }

    }

void ArchivoHuesped::cambiarNombre()
{
    int pos;
    char aux,nuevoNombre[30];
    Huesped obj;
    while(true){
    cout<<"INGRESE EL DNI DEL HUESPED QUE DESEE CAMBIAR : "<<endl;
    cin>>pos;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl;
        obj.Mostrar();
        cout<<"S/N : ";
        cin>>aux;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE EL NUEVO NOMBRE : ";
           cargarCadena(nuevoNombre,29);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NOMBRE : "<<nuevoNombre<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setNombre(nuevoNombre);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO EMPLEADO ? S/N "<<endl; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
    system("cls");
        }

    }

void ArchivoHuesped::cambiarApellido()
{
    int pos;
    char aux,nuevoApellido[30];
    Huesped obj;
    while(true){
    cout<<"INGRESE EL DNI DEL HUESPED QUE DESEE CAMBIAR : "<<endl;
    cin>>pos;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl;
        obj.Mostrar();
        cout<<"S/N : ";
        cin>>aux;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE EL NUEVO APELLIDO : ";
           cargarCadena(nuevoApellido,29);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL APELLIDO : "<<nuevoApellido<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setApellido(nuevoApellido);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO EMPLEADO ? S/N "<<endl; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
    system("cls");
        }

    }

void ArchivoHuesped::cambiarFechaNacimiento()
{
    char aux;
    Fecha f;
    Huesped obj;
    int pos;
    while(true){
    cout<<"INGRESE EL DNI DEL HUESPED QUE DESEE CAMBIAR : ";
    pos=buscarRegistro(pos);
     if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado())
            {
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl;
        obj.Mostrar();
        cout<<"S/N"<<endl;
        cin>>aux;
        if(aux=='s' || aux=='S')
        {
           cout<<"INGRESE LA NUEVA FECHA DE NACIMIENTO"<<endl;
           f.Cargar();
           cout<<"ESTAS SEGURO QUE DESEA INGRESAR LA FECHA : ";
           f.Mostrar();
           cout<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
           {
               obj.setNacimiento(f);
               modificarRegistro(obj,pos);
               return;
           }

        }

            }

        }
            cout<<"DESEA BUSCAR OTRO EMPLEADO ? S/N "<<endl; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
            cin>>aux;
               if(aux=='n' || aux=='N')
               {
                   return;
               }
            system("cls");
    }

}

void ArchivoHuesped::cambiarTelefono()
{
    int pos;
    char aux,telefono[10];
    Huesped obj;
    while(true){
    cout<<"INGRESE EL DNI DEL HUESPED QUE DESEE CAMBIAR : "<<endl;
    cin>>pos;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl;
        obj.Mostrar();
        cout<<"S/N : ";
        cin>>aux;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE EL NUEVO NUMERO DE TELEFONO : ";
           cargarCadena(telefono,9);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NUMERO DE TELEFONO : "<<telefono<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setTelefono(telefono);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO EMPLEADO ? S/N "<<endl; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
    system("cls");
        }

    }

void ArchivoHuesped::cambiarEmail()
{
    int pos;
    char aux,email[50];
    Huesped obj;
    while(true){
    cout<<"INGRESE EL DNI DEL HUESPED QUE DESEE CAMBIAR : "<<endl;
    cin>>pos;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl;
        obj.Mostrar();
        cout<<"S/N : ";
        cin>>aux;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE EL NUEVO EMAIL : ";
           cargarCadena(email,49);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL EMAIL : "<<email<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setEmail(email);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO EMPLEADO ? S/N "<<endl; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
    system("cls");
        }


    }

void ArchivoHuesped::listarPorDNI()
{
    int dni,pos;
    Huesped obj;
    cout<<"INGRESE EL DNI : ";
    cin>>dni;
    pos=buscarRegistro(dni);
    if(pos!=-1)
    {
        obj=leerRegistro(pos);
        if(obj.getEstado())
        {
            obj.Mostrar();
            system("pause");
        }
    }
    else
    {
        cout<<"NO SE ENCONTRO EL ARCHIVO."<<endl;system("pause");
    }
}
#endif // ARCHUESPED_H_INCLUDED
