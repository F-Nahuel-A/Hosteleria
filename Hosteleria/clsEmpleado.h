#ifndef CLSEMPLEADO_H_INCLUDED
#define CLSEMPLEADO_H_INCLUDED
class Empleado
{
private:
    int _legajo;
    int _IDturno;
    int _IDtipo;
    Fecha _ingreso;
    bool _estado;
public:
    Empleado(int l=0, int t=0, int tipo=0)
    {
        _legajo=l;
        _IDturno=t;
        _IDtipo=tipo;
    }

    int getLegajo(){return _legajo;}
    int getIDturno(){return _IDturno;}
    int getIDtipo(){return _IDtipo;}
    Fecha getFecha(){return _ingreso;}
    bool getEstado(){return _estado;}

    void setLegajo(int l)
    {
        char aux;
        if(l>0)
        {
            _legajo=l;
            return;
        }
        else
        {
            while(l<0)
                {

            cout<<"LEGAJO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N";
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                cin>>l;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _legajo=l;
        }
    }
    ///MOMENTANEO,DESPUES SE HACE UNA FUNCION QUE ABRA EL ARCHIVO "TURNOS" PARA VERIFICAR
//    void setIDturno(int t)
//    {
//        char aux;
//        if(t == 1 || t == 2 || t == 3)
//        {
//            _IDturno=t;
//        }
//          else
//        {
//            while(t != 1 || t != 2 || t != 3)
//                {
//
//            cout<<"ID DE TURNO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N";
//            cin>>aux;
//
//            if(aux=='S' || aux=='s')
//            {
//                cin>>t;
//            }
//
//            if(aux=='N' || aux=='n')
//            {
//                system("cls");
//                _estado=false;
//                return;
//            }
//
//            system("cls");
//
//                }
//
//            _IDturno=t;
//        }
//    }
    ///MOMENTANEO,DESPUES SE HACE UNA FUNCION QUE ABRA EL ARCHIVO "TURNO" PARA VERIFICAR

    void setIDturno(int t)
    {
        ArchivoTurnoEmpleado arc;
        TurnoEmpleado obj;
        int contReg=arc.contarRegistros();
        char aux;

        while(_estado){
        for (int i=0;i<contReg;i++)
            {
                obj=arc.leerRegistro(i);
                if(t==obj.getID())
                {
                    _IDturno=t;
                    return;
                }
            }
            cout<<"ID DE TURNO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                cin>>t;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }
        }

    }

      void setIDtipo(int t)
    {
        ArchivoTipoEmpleado arc;
        TipoEmpleado obj;
        int contReg=arc.contarRegistros();
        char aux;

        while(_estado){
        for (int i=0;i<contReg;i++)
            {
                obj=arc.leerRegistro(i);
                if(t==obj.getID())
                {
                    _IDtipo=t;
                    return;
                }
            }
            cout<<"ID DE SECTOR NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N";
            cin>>aux;
            if(aux=='S' || aux=='s')
            {
                cin>>t;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }
        }

    }

    ///MOMENTANEO,DESPUES SE HACE UNA FUNCION QUE ABRA EL ARCHIVO "TIPO" PARA VERIFICAR
//    void setIDtipo(int t)
//    {
//        char aux;
//        if(t == 1 || t == 2 || t == 3)
//        {
//            _IDtipo=t;
//        }
//          else
//        {
//            while(t != 1 || t != 2 || t != 3)
//                {
//
//            cout<<"ID DE SECTOR NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N";
//            cin>>aux;
//
//            if(aux=='S' || aux=='s')
//            {
//                cin>>t;
//            }
//
//            if(aux=='N' || aux=='n')
//            {
//                system("cls");
//                _estado=false;
//                return;
//            }
//
//            system("cls");
//
//                }
//
//            _IDtipo=t;
//        }
//    }
    ///MOMENTANEO,DESPUES SE HACE UNA FUNCION QUE ABRA EL ARCHIVO "TIPO" PARA VERIFICAR
    void setFecha(Fecha f){_ingreso=f;}
    void setEstado(bool e){_estado=e;}

    void Cargar()
    {
        _estado=true;
        int aux;
        cout<<"INGRESE EL LEGAJO";
        cin>>aux;
        setLegajo(aux);
        cout<<"INGRESE EL TURNO";
        cin>>aux;
        setIDturno(aux);
        cout<<"INGRESE EL ID DEL SECTOR DE TRABAJO";
        cin>>aux;
        setIDtipo(aux);
        _ingreso.Cargar();
    }
    void Mostrar()
    {
        if(_estado){
        cout<<"LEGAJO : "<<_legajo<<endl;
        cout<<"TURNO : "<<_IDturno<<endl;
        cout<<"TIPO : "<<_IDtipo<<endl;
        cout<<"FECHA DE INGRESO"<<endl;
        _ingreso.Mostrar();
        }
    }
};



#endif // CLSEMPLEADO_H_INCLUDED
