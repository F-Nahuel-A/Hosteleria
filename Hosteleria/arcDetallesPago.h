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
    bool modificarRegistro(DetallesPago obj, int pos);
    void listarArchivo();
    void listarPorID();

    bool limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
    bool bajaFisica(int pos);

    void cambiarDNI();
    void cambiarNumHabitacion();
    void cambiarTotalApagar();
};

 DetallesPago ArchivoDetalles::leerRegistro(int pos=-1)
    {
        DetallesPago obj;
        FILE *p=fopen(_nombre, "rb");
        if(p == NULL){
        return obj;
    }
    if(pos==-1)
    {
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (DetallesPago);
        obj.setIDdetalle(cantRegistros);
    }
    else
        {
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
        }
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
    return -1;
}

bool ArchivoDetalles::modificarRegistro(DetallesPago obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p == NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
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
    system("pause");
}

bool ArchivoDetalles::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){return false;}
    fclose(p);
    return true;
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

void ArchivoDetalles::cambiarDNI()
{
    int pos,dni;
    char aux;
    DetallesPago obj;
    while(true){
    cout<<"INGRESE EL ID DEL DETALLE QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE EL NUEVO NUMERO DE DNI : ";
           cin>>dni;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NUMERO DE DNI : "<<dni<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setDNI(dni);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO DETALLE DE PAGO ? "<<endl<<"S/N :"; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
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
    cout<<"INGRESE EL ID DE DETALLE QUE DESEE CAMBIAR : "<<endl;
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
           cin>>num;
           cout<<endl;
           posHab=arcHab.buscarRegistro(num);
           if(posHab!=-1)
                {
           objHab=arcHab.leerRegistro(posHab);
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL NUMERO DE HABITACION : "<<objHab.getNumero()<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
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
           cout<<"DESEA BUSCAR OTRO DETALLE DE PAGO ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }

    system("cls");
    }
}
void ArchivoDetalles::cambiarTotalApagar()
{
    int pos;
    float total;
    char aux;
    DetallesPago obj;
    while(true){
    cout<<"INGRESE EL ID DE DETALLE QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE EL NUEVO TOTAL A PAGAR : ";
           cin>>total;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL TOTAL DE : "<<"$"<<total<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setTotal(total);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO DETALLE DE PAGO ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }

void ArchivoDetalles::listarPorID()
{
    int id,pos;
    DetallesPago obj;
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


bool ArchivoDetalles::bajaFisica(int pos)
{
    DetallesPago *objDP;
    objDP=new DetallesPago[contarRegistros()-1];
    int contReg=0;

    for (int i=0;i<contarRegistros();i++)
        {
            if(pos!=i)
            {
                objDP[i]=leerRegistro(i);
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
            fwrite(&objDP[i], sizeof(objDP[i]), 1, p);
        }
    fclose(p);
    delete []objDP;
}
#endif // ARCDETALLESPAGO_H_INCLUDED
