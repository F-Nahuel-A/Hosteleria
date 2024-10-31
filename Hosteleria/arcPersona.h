#ifndef ARCPERSONA_H_INCLUDED
#define ARCPERSONA_H_INCLUDED

class ArchivoPersona
{
private:
    char _nombre[30];
public:
    ArchivoPersona(const char *n="persona.dat"){strcpy(_nombre,n);}

    Persona leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Persona obj);
    int buscarRegistro(int dni);
    void modificarRegistro(Persona obj,int pos);
    void listarArchivo();


    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();

};

Persona ArchivoPersona::leerRegistro(int pos)
{
    Persona obj;
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoPersona::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
            return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Persona);
    fclose(p);
    return cantRegistros;
}

bool ArchivoPersona::grabarRegistro(Persona obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoPersona::buscarRegistro(int dni){
    int cant = contarRegistros();
    Persona obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getDni() == dni && obj.getEstado()){
            return i;
        }
    }
    cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    return -1;
}

void ArchivoPersona::modificarRegistro(Persona obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    cout<<"MODIFICACION HECHA"<<endl;
    system("pause");
}

void ArchivoPersona::listarArchivo(){
    Persona obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ArchivoPersona::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fclose(p);
}

void ArchivoPersona::altaRegistro()
{
    Persona obj;
    obj.Cargar();
    if(obj.getEstado())
    {
     if(grabarRegistro(obj))
        {
        cout<<"REGISTRO GUARDADO CORRECTAMENTE"<<endl;

        } else{cout<<"NO SE PUDO GUARDAR EL ARCHIVO"<<endl;}

    } else{cout<<"NO SE PUDO CARGAR CORRECTAMENTE EL ARCHIVO"<<endl;}

    system("pause");
}


void ArchivoPersona::bajaRegistro()
{
    Persona obj;
    ArchivoPersona arc;
    int aux;
    cout<<"INGRESE EL DNI DEL REGISTRO QUE DESEE ELIMINAR";
    cin>>aux;
    aux=arc.buscarRegistro(aux);
    if(aux==-1)
    {
        cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
        system("pause");
        return;
    }
    obj=arc.leerRegistro(aux);
    if(obj.getEstado()==false)
    {
        cout<<"EL REGISTRO YA HABIA SIDO BORRADO."<<endl;
        system("pause");
        return;
    }
    obj.setEstado(false);
    arc.modificarRegistro(obj,aux);
    cout<<"EL REGISTRO SE BORRO CORRECTAMENTE."<<endl;
    system("pause");
}

#endif // ARCPERSONA_H_INCLUDED
