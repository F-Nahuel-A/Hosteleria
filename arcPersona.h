#ifndef ARCPERSONA_H_INCLUDED
#define ARCPERSONA_H_INCLUDED
class ArchivoPersona
{
private:
    char _nombre[30];
public:
    ArchivoPersona(const char *n="persona.dat")
    {
        strcpy(_nombre,n);
    }

    Persona leerRegistro(int pos);
    int contarRegistros();
    bool grabarRegistro(Persona obj);
    int buscarRegistro(int dni);
    void modificarRegistro(Persona obj, int pos);
    void listarArchivo();
    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro();
};

// Métodos:

Persona ArchivoPersona::leerRegistro(int pos)
{
    Persona obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cerr << "Error al abrir el archivo para lectura." << endl;
        return obj;
    }
    fseek(p, pos * sizeof obj, SEEK_SET);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoPersona::contarRegistros()
{
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL)
    {
        cerr << "Error al abrir el archivo para contar registros." << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof(Persona);
    fclose(p);
    return cantRegistros;
}

bool ArchivoPersona::grabarRegistro(Persona obj)
{
    FILE *p = fopen(_nombre, "ab");
    if (p == NULL)
    {
        cerr << "Error al abrir el archivo para grabar un registro." << endl;
        return false;
    }
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

int ArchivoPersona::buscarRegistro(int dni)
{
    int cant = contarRegistros();
    Persona obj;
    for (int i = 0; i < cant; i++)
    {
        obj = leerRegistro(i);
        if (obj.getDni() == dni && obj.getEstado())
        {
            return i;
        }
    }
    return -1;
}

void ArchivoPersona::modificarRegistro(Persona obj, int pos)
{
    FILE *p = fopen(_nombre, "rb+");
    if (p == NULL)
    {
        cerr << "Error al abrir el archivo para modificar un registro." << endl;
        return;
    }
    fseek(p, pos * sizeof obj, SEEK_SET);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoPersona::listarArchivo()
{
    Persona obj;
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

void ArchivoPersona::limpiarArchivo()
{
    FILE *p = fopen(_nombre, "wb");
    if (p == NULL)
    {
        cerr << "Error al limpiar el archivo." << endl;
        return;
    }
    fclose(p);
}

void ArchivoPersona::altaRegistro()
{
    Persona obj;
    obj.Cargar();
    if (obj.getEstado())
    {
        if (grabarRegistro(obj))
        {
            cout << "Registro guardado correctamente." << endl;
        }
        else
        {
            cerr << "No se pudo guardar el registro." << endl;
        }
    }
    else
    {
        cerr << "Registro inválido, no se guardó." << endl;
    }
}

void ArchivoPersona::bajaRegistro()
{
    int dni;
    cout << "Ingrese el DNI de la persona a eliminar: ";
    cin >> dni;
    int pos = buscarRegistro(dni);
    if (pos == -1)
    {
        cerr << "Registro no encontrado o ya está inactivo." << endl;
        return;
    }
    Persona obj = leerRegistro(pos);
    obj.setEstado(false);  // Borrado lógico
    modificarRegistro(obj, pos);
    cout << "Registro eliminado correctamente." << endl;
}

#endif // ARCPERSONA_H_INCLUDED
