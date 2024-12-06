#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED
class Fecha
{
private:
    int _d;
    int _m;
    int _a;
    bool _estado;
public:
    Fecha(int dia=0, int mes=0, int anio=0000)
    {
      _d=dia;
      _m=mes;
      _a=anio;
    }

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia(){return _d;}
    int getMes(){return _m;}
    int getAnio(){return _a;}
    bool getEstado(){return _estado;}

    void Cargar();
    void Mostrar();

    bool operator==(Fecha a);
};

void Fecha::setAnio(int anio)
{
        char aux;
        if(anio>1900 && anio<2025)
        {
            _a=anio;
            return;
        }
        else
        {
            while(anio<1900 || anio>2025)
                {

            cout<<"ANIO NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL ANIO : ";
                cin>>anio;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _a=anio;
        }
    }

void Fecha::setMes(int mes)
{   bool validar=false;
    char aux;
    while(validar==false){
    if(mes>0&&mes<13)
    {
       if(mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12)
       {

    if(getDia()>0&&getDia()<32)
    {
        validar=true;
        _m=mes;
    }}
    else if(mes==4 || mes==6 || mes==9 || mes==11)
    {
        if(getDia()>0 && getDia()<31)
        {
            validar=true;
            _m=mes;
        }
    }
    else if(mes==2)
    {
        if(getDia()>0&&getDia()<30)
        {
            validar=true;
            _m=mes;
        }
    }
    }
    if(validar==false)
    {   system("cls");
        cout<<"MES NO VALIDO, QUIERE VOLVER A INTENTAR ? S/N"<<endl;
        cin>>aux;
        if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL MES : ";
                cin>>mes;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }
    }
    }
}

void Fecha::setDia(int dia)
{
        char aux;
        if(dia>0 && dia<31)
        {
            _d=dia;
            return;
        }
        else
        {
            while(dia<0 || dia>32)
                {

            cout<<"DIA NO VALIDO,QUIERE VOLVER A INTENTAR ? S/N"<<endl;
            cin>>aux;

            if(aux=='S' || aux=='s')
            {
                system("cls");
                cout<<"INGRESE EL DIA : ";
                cin>>dia;
            }

            if(aux=='N' || aux=='n')
            {
                system("cls");
                _estado=false;
                return;
            }

            system("cls");

                }

            _d=dia;
        }
    }


void Fecha::Cargar()
{   int aux;
    _estado=true;
    cout<<"DIA : ";
    cin>>aux;
    setDia(aux);
    if(_estado==false){return;}
    cout<<"MES : ";
    cin>>aux;
    setMes(aux);
    if(_estado==false){return;}
    cout<<"ANIO : ";
    cin>>aux;
    setAnio(aux);
    if(_estado==false){return;}
}
void Fecha::Mostrar()
{
    if(_estado)
    cout<<_d<<"/"<<_m<<"/"<<_a<<endl;
}

bool Fecha::operator==(Fecha a)
    {
        if(a.getDia()==_d && a.getMes()==_m && a.getAnio()==_a)
        {
            return true;
        }
        return false;
    }
#endif // CLSFECHA_H_INCLUDED
