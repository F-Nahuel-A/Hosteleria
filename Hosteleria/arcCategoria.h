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
    int buscarRegistro(int id);
    void modificarRegistro(Categoria obj,int pos);
    void listarArchivo();
    void listarPorID();

    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();

    void cambiarDescripcion();
    void cambiarPrecioXpersona();
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

int ArchivoCategoria::buscarRegistro(int id){
    int cant = contarRegistros();
    Categoria obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getId() == id && obj.getEstado()){
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
    system("pause");
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
    cout<<"INGRESE EL ID DEL REGISTRO QUE DESEE ELIMINAR :";
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

void ArchivoCategoria::cambiarDescripcion()
{
    int pos;
    char aux,descripcion[100];
    Categoria obj;
    while(true){
    cout<<"INGRESE EL ID DE LA CATEGORIA QUE DESEE CAMBIAR : ";
    cin>>pos;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<endl<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl<<endl;
        obj.Mostrar();
        cout<<endl<<"S/N : ";
        cin>>aux;
        cout<<endl;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE LA NUEVA DESCRIPCION : ";
           cargarCadena(descripcion,99);
           cout<<endl<<"ESTAS SEGURO QUE QUERES ACTUALIZAR LA DESCRIPCION A : "<<descripcion<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setDescripcion(descripcion);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA CATEGORIA ? "<<endl<<"S/N :"<<endl; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }
    }

void ArchivoCategoria::cambiarPrecioXpersona()
{
    int pos;
    float precioXpersona;
    char aux;
    Categoria obj;
    while(true){
    cout<<"INGRESE EL ID DE LA CATEGORIA QUE DESEE CAMBIAR : ";
    cin>>pos;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<endl<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl<<endl;
        obj.Mostrar();
        cout<<endl<<"S/N : ";
        cin>>aux;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE EL NUEVO PRECIO : ";
           cin>>precioXpersona;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL PRECIO DE : "<<"$"<<precioXpersona<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setPrecioXpersona(precioXpersona);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA CATEGORIA ?"<<endl<<"S/N :"; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }


void ArchivoCategoria::listarPorID()
{
    int id,pos;
    Categoria obj;
    cout<<"INGRESE EL ID :";
    cin>>id;
    pos=buscarRegistro(id);
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

#endif // ARCCATEGORIA_H_INCLUDED
