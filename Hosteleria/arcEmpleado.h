#ifndef ARCEMPLEADO_H_INCLUDED
#define ARCEMPLEADO_H_INCLUDED
class ArchivoEmpleado
{
private:
    char _nombre[30];
public:
    ArchivoEmpleado(const char *n="empleado.dat")
    {
        strcpy(_nombre,n);
    }

    Empleado leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Empleado obj);
    int buscarRegistro(int leg);
    void modificarRegistro(Empleado obj,int pos);
    void listarArchivo();


    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();

    void cambiarTipoEmpleado();
    void cambiarTurnoEmpleado();
    void cambiarFechaIngreso();

};

Empleado ArchivoEmpleado::leerRegistro(int pos)
{
    Empleado obj;
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

int ArchivoEmpleado::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
            return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Empleado);
    fclose(p);
    return cantRegistros;
}

bool ArchivoEmpleado::grabarRegistro(Empleado obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoEmpleado::buscarRegistro(int leg){
    int cant = contarRegistros();
    Empleado obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getLegajo() == leg && obj.getLegajo()){
            return i;
        }
    }
    cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    return -1;
}

void ArchivoEmpleado::modificarRegistro(Empleado obj, int pos){
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

void ArchivoEmpleado::listarArchivo(){
    Empleado obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ArchivoEmpleado::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fclose(p);
}

void ArchivoEmpleado::altaRegistro()
{
    Empleado obj;
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


void ArchivoEmpleado::bajaRegistro()
{
    Empleado obj;
    ArchivoEmpleado arc;
    int aux;
    cout<<"INGRESE EL LEGAJO DEL EMPLEADO QUE DESEE BORRAR";
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

void ArchivoEmpleado::cambiarTipoEmpleado()
{
    int pos,posTipo,id;
    char aux;
    Empleado obj;
    TipoEmpleado objTipo;
    ArchivoTipoEmpleado arcTipo;
    while(true){
    cout<<"INGRESE EL ID DEL EMPLEADO"<<endl;
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
           cout<<"INGRESE LA NUEVA ID : ";
           cin>>id;
           posTipo=arcTipo.buscarRegistro(id);
           if(posTipo!=-1)
                {
           objTipo=arcTipo.leerRegistro(posTipo);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL SECTOR : "<<objTipo.getOcupacion()<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setIDtipo(id);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
        }
           cout<<"DESEA BUSCAR OTRO EMPLEADO ? S/N :"; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }

    system("cls");
    }
}

void ArchivoEmpleado::cambiarTurnoEmpleado()
{
    int pos,posTurno,id;
    char aux;
    Empleado obj;
    TurnoEmpleado objTurno;
    ArchivoTurnoEmpleado arcTurno;
    while(true){
    cout<<"INGRESE EL ID DEL EMPLEADO"<<endl;
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
           cout<<"INGRESE LA NUEVA ID : ";
           cin>>id;
           posTurno=arcTurno.buscarRegistro(id);
           if(posTurno!=-1)
                {
           objTurno=arcTurno.leerRegistro(posTurno);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL TURNO : "<<objTurno.getHorario()<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setIDtipo(id);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
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

void ArchivoEmpleado::cambiarFechaIngreso()
{
    char aux;
    Fecha f;
    Empleado obj;
    int pos,id;
    while(true){
    cout<<"INGRESE EL ID DEL EMPLEADO : ";
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
           cout<<"INGRESE LA NUEVA FECHA"<<endl;
           f.Cargar();
           cout<<"ESTAS SEGURO QUE DESEA INGRESAR LA FECHA : ";
           f.Mostrar();
           cout<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
           {
               obj.setFecha(f);
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
#endif // ARCEMPLEADO_H_INCLUDED
