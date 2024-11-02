#ifndef ARCHUESPED_H_INCLUDED
#define ARCHUESPED_H_INCLUDED

class ArchivoHuesped
{
private:
    char _nombre[30];

public:
    ArchivoHuesped(const char *n = "huesped") { strcpy(_nombre, n); }

    Huesped leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Huesped obj);
    int buscarRegistro(int dni);
    void modificarRegistro(Huesped obj, int pos);
    void listarArchivo();
    
    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
};

Huesped ArchivoHuesped::leerRegistro(int pos)
{
    Huesped obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoHuesped::contarRegistros()
{
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int cantBytes = ftell(p);
    fclose(p);
    return cantBytes / sizeof(Huesped);
}

bool ArchivoHuesped::grabarRegistro(Huesped obj)
{
    FILE *p = fopen(_nombre, "ab");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

int ArchivoHuesped::buscarRegistro(int dni)
{
    int cant = contarRegistros();
    Huesped obj;
    for (int i = 0; i < cant; i++)
    {
        obj = leerRegistro(i);
        if (obj.getDni() == dni && obj.getEstado())
        {
            return i;
        }
    }
    cout << "NO SE ENCONTRO EL REGISTRO" << endl;
    return -1;
}

void ArchivoHuesped::modificarRegistro(Huesped obj, int pos)
{
    FILE *p = fopen(_nombre, "rb+");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return;
    }
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    cout << "MODIFICACION HECHA" << endl;
}

void ArchivoHuesped::listarArchivo()
{
    Huesped obj;
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++)
    {
        obj = leerRegistro(i);
        if (obj.getEstado())
        {
            obj.Mostrar();
            cout << endl;
        }
    }
}

void ArchivoHuesped::limpiarArchivo()
{
    FILE *p = fopen(_nombre, "wb");
    if (p == NULL)
    {
        cout << "ERROR EN LA APERTURA" << endl;
        return;
    }
    fclose(p);
}

void ArchivoHuesped::altaRegistro()
{
    Huesped obj;
    obj.Cargar();
    if (obj.getEstado())
    {
        if (grabarRegistro(obj))
        {
            cout << "REGISTRO GUARDADO CORRECTAMENTE" << endl;
        }
        else
        {
            cout << "NO SE PUDO GUARDAR EL ARCHIVO" << endl;
        }
    }
    else
    {
        cout << "NO SE PUDO CARGAR CORRECTAMENTE EL ARCHIVO" << endl;
    }
}

void ArchivoHuesped::bajaRegistro()
{
    Huesped obj;
    int dni;
    cout << "INGRESE EL DNI DEL HUESPED QUE DESEA BORRAR: ";
    cin >> dni;
    int pos = buscarRegistro(dni);
    if (pos == -1)
    {
        cout << "NO SE ENCONTRO EL REGISTRO" << endl;
        return;
    }
    obj = leerRegistro(pos);
    if (!obj.getEstado())
    {
        cout << "EL REGISTRO YA HABIA SIDO BORRADO." << endl;
        return;
    }
    obj.setEstado(false);
    modificarRegistro(obj, pos);
    cout << "EL REGISTRO SE BORRO CORRECTAMENTE." << endl;
}

#endif // ARCHUESPED_H_INCLUDED
