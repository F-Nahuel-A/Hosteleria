#ifndef ARCPAGO_H_INCLUDED
#define ARCPAGO_H_INCLUDED

class ArchivoPagos
{
private:
    char _nombre[30];
public:
    ArchivoPagos(const char *n="Pagos.dat")
    {
        strcpy(_nombre,n);
    }

    Pagos leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(RegimenComida obj);
    int buscarRegistro(int id);
    void modificarRegistro(Pagos obj, int pos);
    void listarArchivo();

    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();


    Pagos ArchivoPagos::leerRegistro(int pos)
    {
        Pagos obj;
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

    int ArchivoPagos::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
            return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Pagos);
    fclose(p);
    return cantRegistros;
}

bool ArchivoPagos::grabarRegistro(Pagos obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoPagos::buscarRegistro(int recibo){
    int cant = contarRegistros();
    Pagos obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumeroderecibo() == recibo && obj.getNumeroderecibo()){
            return i;
        }
    }
    cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    return -1;
}

void ArchivoPagos::modificarRegistro(Pagos obj, int pos){
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

void ArchivoPagos::listarArchivo(){
    Pagos obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ArchivoPagos::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fclose(p);
}

void ArchivoPagos::altaRegistro()
{
    Pagos obj;
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
    Pagos obj;
    ArchivoPagos arc;
    int aux;
    cout<<"INGRESE EL ID DEL REGISTRO QUE DESEE ELIMINAR";
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


#endif // ARCPAGO_H_INCLUDED
