#ifndef ARCDETALLESPAGO_H_INCLUDED
#define ARCDETALLESPAGO_H_INCLUDED

class ArchivoDetalles
{
private:
    char _nombre[30];

public:
    ArchivoDetalles(const char *n="detallePago.dat")
    {
        strcpy(_nombre,n);
    }

   DetallesPago leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(DetallesPago obj);
    int buscarRegistro(int id);
    void modificarRegistro(DetallesPago obj, int pos);
    void listarArchivo();

    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();

    void cambiarNumRecibo();
    void cambiarNumHabitacion();
    void cambiarTotalAbonado();
};

 DetallesPago ArchivoDetalles::leerRegistro(int pos)
    {
        DetallesPago obj;
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

    int ArchivoDetalles::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
            return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (DetallesPago);
    fclose(p);
    return cantRegistros;
}

bool ArchivoDetalles::grabarRegistro(DetallesPago obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoDetalles::buscarRegistro(int id){
    int cant = contarRegistros();
    DetallesPago obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getID() == id && obj.getEstado()){
            return i;
        }
    }
    cout<<"NO SE ENCONTRO EL REGISTRO"<<endl;
    return -1;
}

void ArchivoDetalles::modificarRegistro(DetallesPago obj, int pos){
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

void ArchivoDetalles::listarArchivo(){
    DetallesPago obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

void ArchivoDetalles::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){
        cout<<"ERROR EN LA APERTURA"<<endl;
        system("pause");
        return;}
    fclose(p);
}

void ArchivoDetalles::altaRegistro()
{
    DetallesPago obj;
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

    void ArchivoDetalles::bajaRegistro()
{
    DetallesPago obj;
    ArchivoDetalles arc;
    int aux;
    cout<<"INGRESE EL NUMERO DEL REGISTRO QUE DESEE ELIMINAR :";
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

void ArchivoDetalles::cambiarNumRecibo()
{
    int pos,recibo;
    char aux;
    DetallesPago obj;
    while(true){
    cout<<"INGRESE EL ID DEL DETALLE QUE DESEE CAMBIAR :"<<endl;
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
           cout<<"INGRESE EL NUEVO NUMERO DE RECIBO : ";
           cin>>recibo;
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NUMERO DE RECIBO : "<<recibo<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setIDrecibo(recibo);
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

void ArchivoDetalles::cambiarNumHabitacion()
{
    int pos,posHab,num;
    char aux;
    DetallesPago obj;
    Habitacion objHab;
    ArchivoHabitacion arcHab;
    while(true){
    cout<<"INGRESE EL ID DE DETALLE QUE DESEE CAMBIAR :"<<endl;
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
           cin>>num;
           posHab=arcHab.buscarRegistro(num);
           if(posHab!=-1)
                {
           objHab=arcHab.leerRegistro(posHab);
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NUMERO DE HABITACION : "<<objHab.getNumero()<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setNumHabitacion(num);
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
void ArchivoDetalles::cambiarTotalAbonado()
{
    int pos;
    float total;
    char aux;
    DetallesPago obj;
    while(true){
    cout<<"INGRESE EL ID DE DETALLE QUE DESEE CAMBIAR :"<<endl;
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
           cout<<"INGRESE EL NUEVO TOTAL ABONADO : ";
           cin>>total;
           cout<<"ESTAS SEGURO QUE QUERES ASIGNAR EL TOTAL DE : "<<"$"<<total<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setTotalabonado(total);
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

#endif // ARCDETALLESPAGO_H_INCLUDED
