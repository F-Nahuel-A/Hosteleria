#ifndef ARCTURNO_H_INCLUDED
#define ARCTURNO_H_INCLUDED

class ArchivoTurnoEmpleado
{
private:
    char _nombre[30];
public:
    ArchivoTurnoEmpleado(const char *n="turnoempleado.dat")
    {
        strcpy(_nombre,n);
    }

    TurnoEmpleado leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(TurnoEmpleado obj);
    int buscarRegistro();
    void modificarRegistro(TurnoEmpleado obj,int pos);
    void listarArchivo();


    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
};

TurnoEmpleado ArchivoTurnoEmpleado::leerRegistro(int pos)
{
    TurnoEmpleado obj;
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

int ArchivoTurnoEmpleado::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
            return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (TurnoEmpleado);
    fclose(p);
    return cantRegistros;
}

bool ArchivoTurnoEmpleado::grabarRegistro(TurnoEmpleado obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoTurnoEmpleado::buscarRegistro(){
    int id;
    cout<<"INGRESE EL ID : ";
    cin>>id;
    int cant = contarRegistros();
    TurnoEmpleado obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getID() == id && obj.getID()){
            return i;
        }
    }
    cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    return -1;
}

void ArchivoTurnoEmpleado::modificarRegistro(TurnoEmpleado obj, int pos){
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

void ArchivoTurnoEmpleado::listarArchivo(){
    TurnoEmpleado obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ArchivoTurnoEmpleado::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fclose(p);
}

void ArchivoTurnoEmpleado::altaRegistro()
{
    TurnoEmpleado obj;
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


void ArchivoTurnoEmpleado::bajaRegistro()
{
    TurnoEmpleado obj;
    ArchivoTurnoEmpleado arc;
    int aux;
    aux=arc.buscarRegistro();
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


#endif // ARCTURNO_H_INCLUDED