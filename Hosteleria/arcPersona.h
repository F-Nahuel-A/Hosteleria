#ifndef ARCPERSONA_H_INCLUDED
#define ARCPERSONA_H_INCLUDED

class ArchivoPersona
{
private:
    char _nombre[30];
public:
    ArchivoPersona(const char *n="persona.dat"){strcpy(_nombre,n);}

    Persona leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Persona obj);
    int buscarRegistro(int dni);
    bool modificarRegistro(Persona obj,int pos);
    void listarArchivo();


    bool limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
    bool bajaFisica(int pos);

};

Persona ArchivoPersona::leerRegistro(int pos)
{
    Persona obj;
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

int ArchivoPersona::contarRegistros(){
    FILE *p=fopen(_nombre, "rb");
    if(p == NULL){return -1;}
    fseek(p,0,2);
    int cantBytes;
    cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof (Persona);
    fclose(p);
    return cantRegistros;
}

bool ArchivoPersona::grabarRegistro(Persona obj){
    FILE *p = fopen(_nombre,"ab");
    if(p == NULL){return false;}
    fwrite(&obj, sizeof obj, 1,p);
    fclose(p);
    return true;
}

int ArchivoPersona::buscarRegistro(int dni){
    int cant = contarRegistros();
    Persona obj;
    for(int  i=0; i < cant; i++){
        obj = leerRegistro(i);
        if(obj.getDni() == dni && obj.getEstado()){
            return i;
        }
    }
    return -1;
}

bool ArchivoPersona::modificarRegistro(Persona obj, int pos){
    FILE *p=fopen(_nombre, "rb+");
    if(p == NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

void ArchivoPersona::listarArchivo(){
    Persona obj;
    int cantReg = contarRegistros();
    for(int i = 0; i < cantReg; i++){
        obj = leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }

}

bool ArchivoPersona::limpiarArchivo(){
    FILE *p=fopen(_nombre, "wb");
    if(p == NULL){return false;}
    fclose(p);
    return true;
}

void ArchivoPersona::altaRegistro()
{
    Persona obj;
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


void ArchivoPersona::bajaRegistro()
{
    Persona obj;
    ArchivoPersona arc;
    int aux;
    cout<<"INGRESE EL DNI DEL REGISTRO QUE DESEE ELIMINAR : ";
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

bool ArchivoPersona::bajaFisica(int pos)
{
    Persona *objP;
    objP=new Persona[contarRegistros()-1];
    int contReg=0;

    for (int i=0;i<contarRegistros();i++)
        {
            if(pos!=i)
            {
                objP[i]=leerRegistro(i);
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
            fwrite(&objP[i], sizeof(objP[i]), 1, p);
        }
    fclose(p);
    delete []objP;
}


#endif // ARCPERSONA_H_INCLUDED
