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
    int buscarRegistro(int codigo);
    void modificarRegistro(Habitacion obj, int pos);
    void listarArchivo();
    void limpiarArchivo();
    void altaRegistro();
    void bajaRegistro(int codigo);
};

// Leer un registro específico por posición
Habitacion ArchivoHabitacion::leerRegistro(int pos) {
    Habitacion obj;
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL) {
        cout << "ERROR EN LA APERTURA" << endl;
        system("pause");
        return obj;
    }
    fseek(p, pos * sizeof(Habitacion), 0);
    fread(&obj, sizeof(Habitacion), 1, p);
    fclose(p);
    return obj;
}

// Contar la cantidad de registros en el archivo
int ArchivoHabitacion::contarRegistros() {
    FILE *p = fopen(_nombre, "rb");
    if (p == NULL) {
        cout << "ERROR EN LA APERTURA" << endl;
        return -1;
    }
    fseek(p, 0, SEEK_END);
    int cantBytes = ftell(p);
    int cantRegistros = cantBytes / sizeof(Habitacion);
    fclose(p);
    return cantRegistros;
}

// Grabar un nuevo registro
bool ArchivoHabitacion::grabarRegistro(Habitacion obj) {
    FILE *p = fopen(_nombre, "ab");
    if (p == NULL) {
        cout << "ERROR EN LA APERTURA" << endl;
        return false;
    }
    fwrite(&obj, sizeof(Habitacion), 1, p);
    fclose(p);
    return true;
}

// Buscar un registro por el código de habitación
int ArchivoHabitacion::buscarRegistro(int codigo) {
    int cant = contarRegistros();
    Habitacion obj;
    for (int i = 0; i < cant; i++) {
        obj = leerRegistro(i);
        if (obj.getCodigoHabitacion() == codigo) {
            return i;
        }
    }
    cout << "NO SE ENCONTRO EL REGISTRO" << endl;
    return -1;
}

// Modificar un registro en una posición específica
void ArchivoHabitacion::modificarRegistro(Habitacion obj, int pos) {
    FILE *p = fopen(_nombre, "rb+");
    if (p == NULL) {
        cout << "ERROR EN LA APERTURA" << endl;
        system("pause");
        return;
    }
    fseek(p, pos * sizeof(Habitacion), 0);
    fwrite(&obj, sizeof(Habitacion), 1, p);
    fclose(p);
    cout << "MODIFICACION HECHA" << endl;
    system("pause");
}

// Listar todas las habitaciones en el archivo
void ArchivoHabitacion::listarArchivo() {
    Habitacion obj;
    int cantReg = contarRegistros();
    for (int i = 0; i < cantReg; i++) {
        obj = leerRegistro(i);
        obj.Mostrar();
        cout << endl;
    }
}

// Limpiar todo el archivo (reescribirlo vacío)
void ArchivoHabitacion::limpiarArchivo() {
    FILE *p = fopen(_nombre, "wb");
    if (p == NULL) {
        cout << "ERROR EN LA APERTURA" << endl;
        system("pause");
        return;
    }
    fclose(p);
}

// Dar de alta una nueva habitación (registrar una nueva habitación)
void ArchivoHabitacion::altaRegistro() {
    Habitacion obj;
    obj.Cargar();
    if (grabarRegistro(obj)) {
        cout << "REGISTRO GUARDADO CORRECTAMENTE" << endl;
    } else {
        cout << "NO SE PUDO GUARDAR EL ARCHIVO" << endl;
    }
    system("pause");
}

// Dar de baja una habitación (marcarla como fuera de servicio)
void ArchivoHabitacion::bajaRegistro(int codigo) {
    Habitacion obj;
    int pos = buscarRegistro(codigo);
    if (pos == -1) {
        cout << "NO SE ENCONTRO LA HABITACION" << endl;
        system("pause");
        return;
    }
    obj = leerRegistro(pos);
    obj.setEstado("Fuera de servicio");
    modificarRegistro(obj, pos);
    cout << "LA HABITACION FUE DADA DE BAJA" << endl;
    system("pause");
}

#endif // ARCHABITACION_H_INCLUDED
