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
    bool modificarRegistro(Habitacion obj, int pos);
    void listarArchivo();
    void listarPorNumero();

    bool limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
    bool bajaFisica(int pos);

    void cambiarNumHabitacion();
    void cambiarIDcategoria();
    void cambiarIDregimen();
    void cambiarDisponibilidad();
    void cambiarCapacidad();
    void cambiarFechaLlegada();
    void cambiarFechaSalida();
};

Habitacion ArchivoHabitacion::leerRegistro(int pos) {
    Habitacion obj;
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return obj;}
    if(pos==-1)
    {
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Habitacion);
        obj.setNumero(cantRegistros);
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoHabitacion::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Habitacion);
    fclose(p);
    return cantRegistros;
}

bool ArchivoHabitacion::grabarRegistro(Habitacion obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){return false;}
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
    return -1;
}

bool ArchivoHabitacion::modificarRegistro(Habitacion obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p == NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
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
    system("pause");
}

bool ArchivoHabitacion::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){return false;}
    fclose(p);
    return true;
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
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE EL NUEVO NUMERO DE HABITACION : ";
           cin>>numHab;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NUMERO DE HABITACION : "<<numHab<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setNumero(numHab);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA HABITACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           cout<<endl;
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
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE LA NUEVA ID DE CATEGORIA : ";
           cin>>id;
           posCat=arcCat.buscarRegistro(id);
           if(posCat!=-1)
                {
           objCat=arcCat.leerRegistro(posCat);
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR LA CATEGORIA : "<<objCat.getDescripcion()<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
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
           cout<<"DESEA BUSCAR OTRA HABITACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           cout<<endl;
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
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE LA NUEVA ID DE REGIMEN : ";
           cin>>id;
           posRegimen=arcRegimen.buscarRegistro(id);
           if(posRegimen!=-1)
                {
           objRegimen=arcRegimen.leerRegistro(posRegimen);
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL REGIMEN : "<<objRegimen.getDesc()<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
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
           cout<<"DESEA BUSCAR OTRA HABITACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           cout<<endl;
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
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE LA NUEVA DISPONIBILIDAD : ";
           cin>>disp;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR LA DISPONIBILIDAD : "<<disp<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setDisponibilidad(disp);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA HABITACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           cout<<endl;
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
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE LA NUEVA CAPACIDAD : ";
           cin>>cap;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR LA CAPACIDAD : "<<cap<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setCapacidad(cap);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA HABITACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           cout<<endl;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }

void ArchivoHabitacion::cambiarFechaLlegada(){
    int pos;
    Fecha nueva;
    char aux;
    Habitacion obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE LA NUEVA FECHA"<<endl;
           nueva.Cargar();
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR LA FECHA : ";
           nueva.Mostrar();
           cout<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setIngreso(nueva);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA HABITACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           cout<<endl;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }

void ArchivoHabitacion::cambiarFechaSalida(){
    int pos;
    Fecha nueva;
    char aux;
    Habitacion obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE HABITACION QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE LA NUEVA FECHA"<<endl;
           nueva.Cargar();
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR LA FECHA : ";
           nueva.Mostrar();
           cout<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setSalida(nueva);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRA HABITACION ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           cout<<endl;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }

void ArchivoHabitacion::listarPorNumero()
{
    int num,pos;
    Habitacion obj;
    cout<<"INGRESE EL NUMERO DE LA HABITACION : ";
    cin>>num;
    pos=buscarRegistro(num);
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
        cout<<"NO SE ENCONTRO EL REGISTRO."<<endl;system("pause");
    }
}

void revisionHab()
{
    time_t t = time(nullptr);
    tm* now = localtime(&t);
    int dia=now->tm_mday;
    int mes=now->tm_mon+1;
    int anio=now->tm_year+1900;

    ArchivoHabitacion arcH;
    int cantReg=arcH.contarRegistros();
    Habitacion objH;

    Fecha actual(dia,mes,anio);

    for (int i=0;i<cantReg;i++)
        {
            objH=arcH.leerRegistro(i);
            if(actual>=objH.getSalida())
            {
               objH.setDisponibilidad(0);
               arcH.modificarRegistro(objH,i);
            }
        }

}

bool ArchivoHabitacion::bajaFisica(int pos)
{
    Habitacion *objH;
    objH=new Habitacion[contarRegistros()-1];
    int contReg=0;

    for (int i=0;i<contarRegistros();i++)
        {
            if(pos!=i)
            {
                objH[i]=leerRegistro(i);
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
            fwrite(&objH[i], sizeof(objH[i]), 1, p);
        }
    fclose(p);
    delete []objH;
}
#endif // ARCHABITACION_H_INCLUDED
