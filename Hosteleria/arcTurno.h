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
    int buscarRegistro(int id);
    bool modificarRegistro(TurnoEmpleado obj,int pos);
    void listarArchivo();
    void listarPorID();

    bool limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
    bool bajaFisica(int pos);

    void cambiarHorario();
};

TurnoEmpleado ArchivoTurnoEmpleado::leerRegistro(int pos)
{
    TurnoEmpleado obj;
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return obj;}
    if(pos==-1)
    {
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (TurnoEmpleado);
        obj.setID(cantRegistros);
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoTurnoEmpleado::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (TurnoEmpleado);
    fclose(p);
    return cantRegistros;
}

bool ArchivoTurnoEmpleado::grabarRegistro(TurnoEmpleado obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){return false;}
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoTurnoEmpleado::buscarRegistro(int id){
    int cant = contarRegistros();
    TurnoEmpleado obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getID() == id && obj.getEstado()){
            return i;
        }
    }
    return -1;
}

bool ArchivoTurnoEmpleado::modificarRegistro(TurnoEmpleado obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p == NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
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
    system("pause");

}

bool ArchivoTurnoEmpleado::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){return false;}
    fclose(p);
    return true;
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

void ArchivoTurnoEmpleado::cambiarHorario()
{
    int pos;
    char aux,horario[6];
    TurnoEmpleado obj;
    while(true){
    cout<<"INGRESE EL ID DEL TURNO QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE EL NUEVO HORARIO : ";
           cargarCadena(horario,14);
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL HORARIO : "<<horario<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setHorario(horario);
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

void ArchivoTurnoEmpleado::listarPorID()
{
    int id,pos;
    TurnoEmpleado obj;
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

bool ArchivoTurnoEmpleado::bajaFisica(int pos)
{
    TurnoEmpleado *objTE;
    objTE=new TurnoEmpleado[contarRegistros()-1];
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
#endif // ARCTURNO_H_INCLUDED
