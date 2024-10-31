#ifndef ARCHABITACION_H_INCLUDED
#define ARCHABITACION_H_INCLUDED

class ArchivoHabitacion {
private:
    char _nombre[30];

public:
    ArchivoHabitacion(const char *n = "habitacion.dat") { strcpy(_nombre, n); }

    Habitacion leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Habitacion obj);
    int buscarRegistro(int id);
    void modificarRegistro(Habitacion obj, int pos);
    void listarArchivo();
    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
};

Habitacion ArchivoHabitacion::leerRegistro(int pos) {
    Habitacion obj;
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

int ArchivoHabitacion::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
            return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Habitacion);
    fclose(p);
    return cantRegistros;
}

bool ArchivoHabitacion::grabarRegistro(Habitacion obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoHabitacion::buscarRegistro(int id){
    int cant = contarRegistros();
    Habitacion obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumero() == id && obj.getNumero()){
            return i;
        }
    }
    cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    return -1;
}

void ArchivoHabitacion::modificarRegistro(Habitacion obj, int pos){
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

void ArchivoHabitacion::listarArchivo(){
    Habitacion obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ArchivoHabitacion::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fclose(p);
}

void ArchivoHabitacion::altaRegistro()
{
    Habitacion obj;
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

void ArchivoHabitacion::bajaRegistro()
{
    Habitacion obj;
    ArchivoHabitacion arc;
    int aux;
    cout<<"INGRESE EL ID DE LA HABITACION QUE DESEE BORRAR";
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

#endif // ARCHABITACION_H_INCLUDED
