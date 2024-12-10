#ifndef ARCTIPO_H_INCLUDED
#define ARCTIPO_H_INCLUDED
class ArchivoTipoEmpleado
{
private:
    char _nombre[30];
public:
    ArchivoTipoEmpleado(const char *n="tipoempleado.dat"){strcpy(_nombre,n);}

    TipoEmpleado leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(TipoEmpleado obj);
    int buscarRegistro(int id);
    bool modificarRegistro(TipoEmpleado obj,int pos);
    void listarArchivo();
    void listarPorID();

    bool limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
    bool bajaFisica(int pos);

    void cambiarOcupacion();
    void cambiarSueldo();
};

TipoEmpleado ArchivoTipoEmpleado::leerRegistro(int pos)
{
    TipoEmpleado obj;
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return obj;}
    if(pos==-1)
    {
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (TipoEmpleado);
        obj.setID(cantRegistros);
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoTipoEmpleado::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (TipoEmpleado);
    fclose(p);
    return cantRegistros;
}

bool ArchivoTipoEmpleado::grabarRegistro(TipoEmpleado obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){return false;}
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoTipoEmpleado::buscarRegistro(int id){
    int cant = contarRegistros();
    TipoEmpleado obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getID() == id && obj.getEstado()){
            return i;
        }
    }
    return -1;
}

bool ArchivoTipoEmpleado::modificarRegistro(TipoEmpleado obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p == NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

void ArchivoTipoEmpleado::listarArchivo(){
    TipoEmpleado obj;
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

bool ArchivoTipoEmpleado::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){return false;}
    fclose(p);
    return true;
}

void ArchivoTipoEmpleado::altaRegistro()
{
    TipoEmpleado obj;
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


void ArchivoTipoEmpleado::bajaRegistro()
{
    TipoEmpleado obj;
    ArchivoTipoEmpleado arc;
    int aux;
    cout<<"INGRESE EL ID QUE DESEE ELIMINAR : ";
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

void ArchivoTipoEmpleado::cambiarOcupacion()
{
    int pos;
    char aux,ocupacion[30];
    TipoEmpleado obj;
    while(true){
    cout<<"INGRESE EL ID DEL SECTOR QUE DESEE CAMBIAR : ";
    cin>>pos;
    cout<<endl;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl<<endl;
        obj.Mostrar();
        cout<<endl<<"S/N : ";
        cin>>aux;
        cout<<endl;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE LA NUEVA OCUPACION : ";
           cargarCadena(ocupacion,29);
           cout<<endl<<"ESTAS SEGURO QUE QUERES ACTUALIZAR LA OCUPACION A : "<<ocupacion<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setOcupacion(ocupacion);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA OCUPACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }
    }
void ArchivoTipoEmpleado::cambiarSueldo()
{
    int pos;
    float sueldo;
    char aux;
    TipoEmpleado obj;
    while(true){
    cout<<"INGRESE EL ID DEL SECTOR QUE DESEE CAMBIAR : ";
    cin>>pos;
    cout<<endl;
    pos=buscarRegistro(pos);
    if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado()){
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl<<endl;
        obj.Mostrar();
        cout<<endl<<"S/N : ";
        cin>>aux;
        cout<<endl;
        if(aux=='s' || aux=='S')
            {
           cout<<"INGRESE EL NUEVO SUELDO : ";
           cin>>sueldo;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL SUELDO DE : "<<"$"<<sueldo<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setSueldo(sueldo);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA OCUPACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }

void ArchivoTipoEmpleado::listarPorID()
{
    int id,pos;
    TipoEmpleado obj;
    cout<<"INGRESE EL ID ";
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

bool ArchivoTipoEmpleado::bajaFisica(int pos)
{
    TipoEmpleado *objTE;
    objTE=new TipoEmpleado[contarRegistros()-1];
    int contReg=0;

    for (int i=0;i<contarRegistros();i++)
        {
            if(pos!=i)
            {
                objTE[i]=leerRegistro(i);
                contReg++;
            }

        }
    FILE *p=fopen(_nombre,"wb");
    if(p==nullptr)
    {
        return false;
    }
    for (int i=0;i<contReg;i++)
        {
            fwrite(&objTE[i], sizeof(objTE[i]), 1, p);
        }
    fclose(p);
    delete []objTE;
}

#endif // ARCTIPO_H_INCLUDED
