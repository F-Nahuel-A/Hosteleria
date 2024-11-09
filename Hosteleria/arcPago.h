#ifndef ARCPAGO_H_INCLUDED
#define ARCPAGO_H_INCLUDED

class ArchivoPago
{
private:
    char _nombre[30];
public:
    ArchivoPago(const char *n="Pago.dat")
    {
        strcpy(_nombre,n);
    }

    Pago leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Pago obj);
    int buscarRegistro(int id);
    bool modificarRegistro(Pago obj, int pos); ///Doble mensaje
    void listarArchivo();
    void listarPorID(); ///Doble mensaje
    void listarPorDNI(); ///Doble mensaje

    bool limpiarArchivo();
    void altaRegistro();
    void bajaRegistro(); ///Doble mensaje

    void cambiarIDdetalle();
    void cambiarDNI();
    void cambiarFecha();
    void cambiarFormadPago();
    void cambiarTotalAbonado();
};


    Pago ArchivoPago::leerRegistro(int pos=-1)
    {
        Pago obj;
        FILE *p=fopen(_nombre, "rb");
        if(p == NULL){return obj;}
    if(pos==-1)
    {
        fseek(p,0,2);
        int cantBytes;
        cantBytes = ftell(p);
        int cantRegistros = cantBytes / sizeof (Pago);
        obj.setNumeroderecibo(cantRegistros);
    }
    else
    {
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
    }
    }


    ///METODO, LEER REGISTRO SIN PARAMETROS

    int ArchivoPago::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Pago);
    fclose(p);
    return cantRegistros;
}

bool ArchivoPago::grabarRegistro(Pago obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){return false;}
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoPago::buscarRegistro(int recibo){
    int cant = contarRegistros();
    Pago obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getNumeroderecibo() == recibo && obj.getEstado()){
            return i;
        }
    }
    return -1;
}

bool ArchivoPago::modificarRegistro(Pago obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p == NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}


void ArchivoPago::listarArchivo(){
    Pago obj;
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

bool ArchivoPago::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){return false;}
    fclose(p);
    return true;
}

void ArchivoPago::altaRegistro()
{
    Pago obj;
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

    void ArchivoPago::bajaRegistro()
{
    Pago obj;
    ArchivoPago arc;
    int aux;
    cout<<"INGRESE EL NUMERO DEL REGISTRO QUE DESEE ELIMINAR : ";
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

void ArchivoPago::cambiarDNI()
    {
    int pos,dni;
    char aux;
    Pago obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE RECIBO QUE DESEE CAMBIAR : ";
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
           cout<<"INGRESE EL NUEVO DNI : ";
           cin>>dni;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL DNI : "<<dni<<endl<<"S/N : ";
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
           cout<<"DESEA BUSCAR OTRO PAGO ?"<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }
void ArchivoPago::cambiarFecha()
{
    char aux;
    Fecha f;
    Pago obj;
    int pos;
    while(true){
    cout<<"INGRESE EL NUMERO DE RECIBO QUE DESEE MODIFICAR : ";
    cin>>pos;
    cout<<endl;
    pos=buscarRegistro(pos);
     if(pos!=-1)
        {
        obj=leerRegistro(pos);
        if(obj.getEstado())
            {
        cout<<"EL ARCHIVO QUE DESEA MODIFICAR ES EL SIGUIENTE ? "<<endl<<endl;
        obj.Mostrar();
        cout<<endl<<"S/N : ";
        cin>>aux;
        cout<<endl;
        if(aux=='s' || aux=='S')
        {
           cout<<"INGRESE LA NUEVA FECHA DE PAGO"<<endl;
           f.Cargar();
           cout<<endl<<"ESTAS SEGURO QUE DESEA INGRESAR LA FECHA : ";
           f.Mostrar();
           cout<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
           {
               obj.setFecha(f);
               modificarRegistro(obj,pos);
               return;
           }

        }

            }

        }
            cout<<"DESEA BUSCAR OTRO PAGO ? "<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
            cin>>aux;
               if(aux=='n' || aux=='N')
               {
                   return;
               }
            system("cls");
    }

}
void ArchivoPago::cambiarFormadPago()
{
    int pos,forma;
    char aux;
    Pago obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE RECIBO QUE DESEE MODIFICAR : ";
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
           cout<<"INGRESE LA NUEVA FORMA DE PAGO : ";
           cin>>forma;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR LA FORMA : "<<forma<<endl<<"S/N : ";
           cin>>aux;
           cout<<endl;
           if(aux=='s' || aux=='S')
                    {
           obj.setPago(forma);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO PAGO ?"<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }
void ArchivoPago::cambiarTotalAbonado()
{
    int pos;
    float total;
    char aux;
    Pago obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE RECIBO QUE DESEE CAMBIAR : ";
    cin>>pos;
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
           cout<<"INGRESE EL NUEVO TOTAL ABONADO : ";
           cin>>total;
           cout<<endl<<"ESTAS SEGURO QUE QUERES ASIGNAR EL TOTAL DE : "<<"$"<<total<<endl<<"S/N : ";
           cin>>aux;
           if(aux=='s' || aux=='S')
                    {
           obj.setTotalAbonado(total);
           modificarRegistro(obj,pos);
           return;
                    }
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO PAGO ?"<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }

void ArchivoPago::listarPorID()
{
    int id,pos;
    Pago obj;
    cout<<"INGRESE EL ID : ";
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

void ArchivoPago::listarPorDNI()
{
    int dni,pos;
    Pago obj;
    cout<<"INGRESE EL DNI : ";
    cin>>dni;
    pos=buscarRegistro(dni);
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

void ArchivoPago::cambiarIDdetalle()
{
    int pos,id;
    char aux;
    Pago obj;
    while(true){
    cout<<"INGRESE EL NUMERO DE RECIBO QUE DESEE CAMBIAR : ";
    cin>>pos;
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
           cout<<"INGRESE EL NUEVO ID DE DETALLE : ";
           cin>>id;
           obj.setIDdetalle(id);
                }
            }
                }else{cout<<"REGISTRO NO VALIDO"<<endl;} ///ESTE MENSAJE APARECE SI EL OBJETO TIENE EL ESTADO EN FALSO
           cout<<"DESEA BUSCAR OTRO NUMERO DE RECIBO ?"<<endl<<"S/N : "; ///ESTE MENSAJE APARECE SI EL USUARIO NO QUIERE CARGAR ESE REGISTRO
           cin>>aux;
           if(aux=='n' || aux=='N')
           {
               return;
           }
	system("cls");
        }

    }

#endif // ARCPAGO_H_INCLUDED
