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

    void cambiarNumHabitacion();
    void cambiarIDcategoria();
    void cambiarIDregimen();
    void cambiarDisponibilidad();
    void cambiarCapacidad();
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
        if(obj.getNumero() == id && obj.getEstado()){
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
    cout<<"INGRESE EL ID DE LA HABITACION QUE DESEE BORRAR : ";
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


void ArchivoHabitacion::cambiarNumHabitacion()
{
    int pos,numHab;
    char aux;
    Habitacion obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : "<<endl;
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
           cout<<"INGRESE EL NUEVO NUMERO DE HABITACION : ";
           cin>>numHab;
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NUMERO DE HABITACION : "<<numHab<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setNumero(numHab);
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
void ArchivoHabitacion::cambiarIDcategoria()
{
    int pos,posCat,id;
    char aux;
    Habitacion obj;
    Categoria objCat;
    ArchivoCategoria arcCat;
    while(true){
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : "<<endl;
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
           cout<<"INGRESE LA NUEVA ID DE CATEGORIA : ";
           cin>>id;
           posCat=arcCat.buscarRegistro(id);
           if(posCat!=-1)
                {
           objCat=arcCat.leerRegistro(posCat);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR LA CATEGORIA : "<<objCat.getDescripcion()<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setIdCategoria(id);
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
void ArchivoHabitacion::cambiarIDregimen()
{
    int pos,posRegimen,id;
    char aux;
    Habitacion obj;
    RegimenComida objRegimen;
    ArchivoRegimenComida arcRegimen;
    while(true){
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : "<<endl;
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
           cout<<"INGRESE LA NUEVA ID DE REGIMEN : ";
           cin>>id;
           posRegimen=arcRegimen.buscarRegistro(id);
           if(posRegimen!=-1)
                {
           objRegimen=arcRegimen.leerRegistro(posRegimen);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL REGIMEN : "<<objRegimen.getDesc()<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setIdRegimen(id);
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
void ArchivoHabitacion::cambiarDisponibilidad()
{
    int pos,disp;
    char aux;
    Habitacion obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : "<<endl;
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
           cout<<"INGRESE LA NUEVA DISPONIBILIDAD : ";
           cin>>disp;
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR LA DISPONIBILIDAD : "<<disp<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setDisponibilidad(disp);
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

void ArchivoHabitacion::cambiarCapacidad()
{
    int pos,cap;
    char aux;
    Habitacion obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : "<<endl;
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
           cout<<"INGRESE LA NUEVA CAPACIDAD : ";
           cin>>cap;
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR LA CAPACIDAD : "<<cap<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setCapacidad(cap);
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

#endif // ARCHABITACION_H_INCLUDED
