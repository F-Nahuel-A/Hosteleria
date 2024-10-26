#ifndef ARCCATEGORIA_H_INCLUDED
#define ARCCATEGORIA_H_INCLUDED

class ArchivoCategoria {
private:
    char _nombre[30];
    
public:
    ArchivoCategoria(const char *n="categoria.dat") { strcpy(_nombre,n); }

    Categoria leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Categoria obj);
    int buscarRegistro();
    void modificarRegistro(Categoria obj,int pos);
    void listarArchivo();
    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
};

Categoria ArchivoCategoria::leerRegistro(int pos) {
    Categoria obj;
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

int ArchivoCategoria::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
            return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Categoria);
    fclose(p);
    return cantRegistros;
}

bool ArchivoCategoria::grabarRegistro(Categoria obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoCategoria::buscarRegistro(){
    int l;
    cout<<"INGRESE EL ID CATEGORIA: ";
    cin>>l;
    int cant = contarRegistros();
    Categoria obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getId() == l && obj.getId()){
            return i;
        }
    }
    cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    return -1;
}

void ArchivoCategoria::modificarRegistro(Categoria obj, int pos){
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

void ArchivoCategoria::listarArchivo(){
    Categoria obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ArchivoCategoria::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fclose(p);
}

void ArchivoCategoria::altaRegistro()
{
    Categoria obj;
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


void ArchivoCategoria::bajaRegistro()
{
    Categoria obj;
    ArchivoCategoria arc;
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


#endif // ARCCATEGORIA_H_INCLUDED
