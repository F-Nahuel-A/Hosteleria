#ifndef INFORME_H_INCLUDED
#define INFORME_H_INCLUDED
void tipoDpago();
void recaudacionHabitacion();
void gananciaAnual();

void menuInforme()
{
    int y=1,op=1;

    do
    {
    rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::hidecursor();
    rlutil::locate(44,10);
    cout<<"MENU DE INFORMES"<<endl;
    showItem("TIPO DE PAGO",44,12,y==1);
    showItem("HABITACIONES CON MAS RECAUDACION",35,13,y==2);
    showItem("GANANCIA ANUAL",43,14,y==3);
    showItem("SALIR",47,15,y==4);

        switch (rlutil::getkey())
        {
            case 14:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y--;
                if(y<1)
                {
                    y=1;
                }
                break;

            case 15:
                rlutil::locate(48, 12 + y);
                cout << " ";
                y++;
                if(y>4)
                {
                    y=4;
                }
                break;

            case 1:
                switch (y)
                {
            case 1:
                system("cls");
                tipoDpago();
                system("pause");
                break;

            case 2:
                system("cls");
                recaudacionHabitacion();
                system("pause");
                break;

            case 3:
                system("cls");
//                gananciaAnual();
                system("pause");
                break;

            case 4:
                op=0;
                break;

                default:
                    break;
                }


            default:
                break;
        }
    }
    while(op!=0);
}

void tipoDpago()
{
    ArchivoPago arc;
    Pago obj;
    int tipoPago[2]={},contReg=arc.contarRegistros();
    for (int i=0;i<contReg;i++)
        {
            obj=arc.leerRegistro(i);
            if(obj.getEstado())
            {
                tipoPago[obj.getFormadepago()-1]++;
            }
        }
    float porcentaje1 = (float(tipoPago[0]) / float(contReg)) * 100;
    float porcentaje2 = (float(tipoPago[1]) / float(contReg)) * 100;

        cout<<"EL METODO CON MAS USOS FUE EL : ";
    if(porcentaje1>porcentaje2)
    {
        cout<<"TIPO DE PAGO 1"<<"CON UN PORCENTAJE DE : "<<porcentaje1<<"%"<<endl;
    }
    else{cout<<"TIPO DE PAGO 2"<<"CON UN PORCENTAJE DE : "<<porcentaje2<<"%"<<endl;}
}

void recaudacionHabitacion()
{
  ArchivoHabitacion archivoHabitacion;
  ArchivoCategoria archivoCategoria;
  ArchivoRegimenComida archivoRegimenComida;
  ArchivoPago archivoPago;
  ArchivoDetalles archivoDetalles;
  
  int contarHabitaciones = archivoHabitacion.contarRegistros();
  int contarCategorias = archivoCategoria.contarRegistros();
  int contarRegimen = archivoRegimenComida.contarRegistros();
  int contarPago = archivoPago.contarRegistros();
  int contarDetalle = archivoDetalles.contarRegistros();

  if (contarHabitaciones < 0 || contarCategorias < 0 || contarRegimen < 0 || contarPago < 0 || contarDetalle < 0)
    {
      cout << "ERROR AL ABRIR EL ARCHIVO\n";
      return;
    }

  cout << "-------RECAUDACION POR HABITACION-------\n";
  cout << "| NUM HABITACION | RECAUDACION         |\n";

  for (int i = 0; i < contarHabitaciones; i++)
    {
      Habitacion habitacion = archivoHabitacion.leerRegistro(i);

      if (habitacion.getEstado()) 
        {
            int idCategoria = habitacion.getIdCategoria();
            int idRegimen = habitacion.getIdRegimen();
            float precioPorPersona = 0.0f;
            float regimenCosto = 0.0f;
            float recaudacionTotal = 0.0f;


          for (int j = 0; j < contarCategorias; j++) 
            {
              Categoria categoria = archivoCategoria.leerRegistro(j);
              if (categoria.getId() == idCategoria && categoria.getEstado()) 
                {
                  precioPorPersona = categoria.getPrecioXpersona();
                  break;
                }
            }
          
          for (int k = 0; k < contarRegimen; k++) {
              RegimenComida regimen = archivoRegimenComida.leerRegistro(k);
              if (regimen.getID() == idRegimen && regimen.getEstado()) 
                {
                  regimenCosto = regimen.getPrecio();
                  break;
                }
          }
          
          for (int l = 0; l < contarPago; l++) 
            {
              Categoria categoria = archivoCategoria.leerRegistro(l);

              /*if ()
                {
                  DetallesPago detalles = archivoDetalles.leerRegistro(pos);

                  Fecha checkIn = ;
                  Fecha checkOut = ;
                  int diasEstadia = ;
                  int numeroHuespedes = ;

                  float recaudacionEstadia = ((precioPorPersona * numeroHuespedes) * diasEstadia) + regimenCosto;
                  recaudacionTotal += recaudacionEstadia;
                  
                }*/
            }
          cout << "| " << habitacion.getNumero() << "| $" << recaudacionTotal << "\n";
          cout << "+------------------+-------------------+\n";
        }
    }
  cout << "----------------------------------------\n";
}

#endif // INFORME_H_INCLUDED
