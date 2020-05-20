#include <iostream>
#include "tareas.cpp"
#include "Estudiante.cpp"
#include "calificacion.cpp"
#include "materia.cpp"
#include "participacion.cpp"
#include "Lista.h"

using namespace std;
///Funciones que registran todo
void ReEs(estudiante&, List<estudiante>&);
void ReMa(Materia&, List<Materia>&, fecha& f);
void ReTa( List<Tarea>&);
void modTa( List<Tarea>&, int idTarea);
void delTa( List <Tarea>&Tas, int idTarea);

bool validateNRC(List<Materia> LL,string nrc){
bool result=true;

      for(int x=1;x<=LL.contador;x++){
           Materia m= LL.retrieve(x);

           if(m.get_NRC()==nrc){
             result=false;
           }
        }

return result;
}

int main()
{
    List<Materia> LM;
    List<estudiante> LE;
    List<Tarea> LT;
    List<Calificacion> LC;
    Materia a;
    estudiante b;
    Tarea c;
    Calificacion d;
    fecha f;
    int x,y,w;
    string Str,Str2;
do{
    cout<<"Con que deseas trabajar?"<<endl;
    cout<<"1.Materias"<<endl;
    cout<<"2.Estudiantes"<<endl;
    cout<<"3.Tareas"<<endl;
    cout<<"4.Salir"<<endl;
    cin>>x;
    cout<<endl;

    switch(x){

        case 1:
        do{
            cout<<"Que desea realizar?"<<endl<<endl;
            cout<<"1. Crear nueva materia"<<endl;
            cout<<"2. Ver las materias actuales"<<endl;
            cout<<"3. Ingresar un nuevo alumno en una materia"<<endl;
            cout<<"4. Ver los estudiantes de una materia"<<endl;
            cout<<"5. Ingresar una nueva tarea en una materia"<<endl;
            cout<<"6. Ver las tareas de una materia"<<endl;
            cout<<"7. Salir"<<endl;
            cin>>w;
            cout<<endl;

                switch(w){
                    case 1://-- Registra materia
                        ReMa(a, LM, f);
                        break;
                    case 2://-- Muestra la lista de materias
                        LM.print_list();
                        break;
                    case 3://-- Agrega  un estudiante a una materia

                        cout<<"Escriba el NRC de la materia"<<endl;
                        cin>>Str;
                        cout<<"Escriba el codigo del estudiante que desea agregar a la materia"<<endl;
                        cin>>Str2;

                        for(int x=1;x<=LM.contador;x++){
                           Materia* m= LM.retrieve2(x);
                           if(m->get_NRC()==Str){
                            m->insertCodigoE(Str2);
                           }
                        }
                        cout<<endl;
                        break;

                    case 4:
                       cout<<"Escriba el NRC de la materia"<<endl;
                       cin>>Str;
                      cout<<"Los estudiantes de la materia son: ";
                      for(int x=1;x<=LM.contador;x++){
                           Materia m= LM.retrieve(x);

                           if(m.get_NRC()==Str){
                            m.printSE();
                           }

                        }
                        system("pause");
                        cout<<endl;
                        break;

                    case 5:
                        cout<<"Escriba el NRC de la materia"<<endl;
                        cin>>Str;
                        cout<<"Escriba el id de la tarea que desea agregar a la materia"<<endl;
                        cin>>y;

                        for(int x=1;x<=LM.contador;x++){
                           Materia* m= LM.retrieve2(x);
                           if(m->get_NRC()==Str){
                            m->insertCodigoT(y);
                           }
                        }
                        cout<<endl;
                        break;
                    case 6:
                        cout<<"Escriba el NRC de la materia"<<endl;
                        cin>>Str;
                        cout<<"Las tareas de la materia son: ";

                      for(int x=1;x<=LM.contador;x++){
                           Materia m= LM.retrieve(x);

                           if(m.get_NRC()==Str){
                            m.printST();
                           }

                        }
                        system("pause");
                        cout<<endl;
                        break;
                }
            }while(w!=7);
            break;

        case 2:
            do{
                cout<<"Que desea realizar?"<<endl<<endl;
                cout<<"1.Registrar nuevo alumno"<<endl;
                cout<<"2.Ver todos los alumnos registrados"<<endl;
                cout<<"3.Salir"<<endl;
                cin>>w;
                    switch(w)
                    {
                        case 1:
                            ReEs(b, LE);
                            break;
                        case 2:
                            LE.print_list();
                            break;
                    }
            }while(w!=3);
            break;

        case 3:
            do{
                cout<<"Que desea realizar?"<<endl<<endl;
                cout<<"1.Registrar nueva tarea"<<endl;
                cout<<"2.Modificar tareas"<<endl;
                cout<<"3.Ver todas las tareas registradas"<<endl;
                cout<<"3.Salir"<<endl;
                cin>>w;
                    switch(w)
                    {
                        case 1:{
                            ReTa(  LT );
                            break;
                        }case 2:{
                            int id;
                            cout<<"Escriba el id de la tarea a modificar"<<endl;
                            cin>>id;
                            modTa(LT, id);
                            break;
                        }
                        case 3:{
                            LT.print_list();
                            break;
                        }case 4:{
                            int id;
                            cout<<"Escriba el id de la tarea a modificar"<<endl;
                            cin>>id;
                            delTa(LT, id);
                            break;
                        }
                    }
            }while(w!=5);
            break;
    }
}while(x!=4);

    return 0;
}

void ReEs(estudiante& e, List<estudiante>& l){
    string Str;
    cin.ignore();
    cout<<"Cual es el nombre del estudiante?"<<endl;
    getline(cin, Str);
    e.set_Nombre(Str);
    cout<<"Cual es el apellido del estudiante?"<<endl;
    getline(cin, Str);
    e.set_Apellido(Str);
    cout<<"Cual es el codigo del estudiante?"<<endl;
    getline(cin, Str);
    e.set_Codigo(Str);
    cout<<"Cual es la carrera del estudiante?"<<endl;
    getline(cin, Str);
    e.set_Carrera(Str);
    cout<<"Cual es la correo del estudiante?"<<endl;
    getline(cin, Str);
    e.set_Correo(Str);
    l.insertInList(e);
}

void ReMa(Materia& m, List<Materia>& l, fecha& f){
    bool res;
    string Str, Str2;
    size_t pos;
    res = false;
    while(res == false){
        cout<<"Cual es el NRC de la materia?"<<endl;
        cin>>Str;
        res = validateNRC(l,Str);
    }
    fflush(stdin);
    m.set_NRC(Str);
    cout<<"Cual es el nombre de la materia?"<<endl;
    getline(cin,Str);
    m.set_nombre(Str);
    cout<<"Cual es la clave de la materia?"<<endl;
    cin>>Str;
    m.set_clave(Str);
    cout<<"Cual es el modulo de la materia?"<<endl;
    cin>>Str;
    m.set_modulo(Str);
    cout<<"Cual es el ciclo de la materia?"<<endl;
    cin>>Str;
    m.set_ciclo(Str);
    cout<<"Cual es el aula de la materia?"<<endl;
    cin>>Str;
    m.set_Aula(Str);
    cout<<"Cual es el horario de la materia?(HH:MM, 24HRS)"<<endl;
    cout<<"Horario de Inicio:";
    cin>>Str;
    pos = Str.rfind(":");
    Str2 = Str.substr(0, pos);
    f.setHora(stoi(Str2));
    Str2 = Str.substr(pos+1,Str.size() );
    f.setMinuto(stoi(Str2));
    m.set_Fecha_inicio(f);

    cout<<"Hora en que termina:";
    cin>>Str;
    pos = Str.rfind(":");
    Str2 = Str.substr(0, pos);
    f.setHora(stoi(Str2));
    Str2 = Str.substr(pos+1,Str.size() );
    f.setMinuto(stoi(Str2));
    /*
    cout<<"Escriba los minutos a los que inicia la materia"<<endl;
    cin>>y;
    f.setMinuto(y);
    cout<<"Escriba la hora a la que inicia la materia"<<endl;
    cin>>y;

    f.setHora(y);
    a.set_Fecha_inicio(f);

    cout<<"Escriba los minutos a los que termina la materia"<<endl;
    cin>>y;
    f.setMinuto(y);
    cout<<"Escriba la hora a la que termina la materia"<<endl;
    cin>>y;
    f.setHora(y);
    */
    m.set_Fecha_fin(f);
    fflush(stdin);
    cout<<"Cuales dias se va a impartir la materia?"<<endl;
    getline(cin,Str);
    m.set_Dias(Str);
    cout<<"Cual es la seccion de la materia?"<<endl;
    cin>>Str;
    m.set_Seccion(Str);
    l.insertInList(m);
    cout<<endl;
}

void ReTa( List <Tarea>& Tas){
            Tarea nueva;
            fecha f;
            int datofecha;
            string Str;
            int y;
            //--Registro de la tarea
            fflush(stdin);
            cout<<"Cual es el nombre de la tarea?"<<endl;
            getline(cin,Str);
            nueva.setNombre(Str);
            cout<<"Cual es la descripcion de la tarea?"<<endl;
            getline(cin,Str);
            nueva.setDesc(Str);
            cout<<"Cual es el archivo asignacion de la tarea?"<<endl;
            getline(cin,Str);
            nueva.setArchivoAsignacion(Str);
            cin.ignore();
            cout<<"Cual es el id de la tarea?"<<endl;
            cin>>y;
            nueva.setId(y);
            cout<<"Cual es la fecha de entrega de la tarea?"<<endl<<endl;
            cout<<"Escriba el dia"<<endl;
            cin>>datofecha;
            f.setDia(datofecha);
            cout<<"Escriba el mes"<<endl;
            cin>>datofecha;
            f.setMes(datofecha);
            cout<<"Escriba el anio"<<endl;
            cin>>datofecha;
            f.setAnio(datofecha);
            cout<<"Escriba la hora"<<endl;
            cin>>datofecha;
            f.setHora(datofecha);
            cout<<"Escriba los minutos"<<endl;
            cin>>datofecha;
            f.setMinuto(datofecha);
            nueva.setFechaEntrega(f);
            cout<<endl;
            Tas.insertInList(nueva);
            cout<<"Tarea registrada"<<endl;
}


void modTa( List <Tarea>&Tas, int idTarea){
    int datofecha;
    int indice(-1);
    string Str;
    int y;
    //obtengo indice por el codigo
    for( int i = 0; i < Tas.getSize(); i++){
            if( idTarea == Tas.retrieve( i ).getId() ){
                    indice = i;
                    break;
            }
    }
    if( indice > -1){
            Tarea *editada =Tas.retrieve2(indice);
            fecha f;
            //Si no lo tengo no edito
            fflush(stdin);
            cout<<"Cual es el nombre de la tarea?"<<endl;
            getline(cin,Str);
            editada->setNombre(Str);
            cout<<"Cual es la descripcion de la tarea?"<<endl;
            getline(cin,Str);
            editada->setDesc(Str);
            cout<<"Cual es el archivo asignacion de la tarea?"<<endl;
            getline(cin,Str);
            editada->setArchivoAsignacion(Str);
            cout<<"Cual es el id de la tarea?"<<endl;
            cin>>y;
            editada->setId(y);
            cout<<"Cual es la fecha de entrega de la tarea?"<<endl<<endl;
            cout<<"Escriba el dia"<<endl;
            cin>>datofecha;
            f.setDia(datofecha);
            cout<<"Escriba el mes"<<endl;
            cin>>datofecha;
            f.setMes(datofecha);
            cout<<"Escriba el anio"<<endl;
            cin>>datofecha;
            f.setAnio(datofecha);
            cout<<"Escriba la hora"<<endl;
            cin>>datofecha;
            f.setHora(datofecha);
            cout<<"Escriba los minutos"<<endl;
            cin>>datofecha;
            f.setMinuto(datofecha);
            editada->setFechaEntrega(f);
            cout<<endl;
            cout<<"Cacion editada"<<endl;
            cout<<Tas.retrieve2(indice)->toString()<<endl;
    } else {
        cout<<"No hay una tarea registrada con ese id"<<endl;
    }
}

void delTa( List <Tarea>&Tas, int idTarea){
    int datofecha;
    int indice(-1);
    string Str;
    int y;
    //obtengo indice por el codigo
    for( int i = 0; i < Tas.getSize(); i++){
            if( idTarea == Tas.retrieve( i ).getId() ){
                    indice = i;
                    break;
            }
    }
    if( indice > -1){
            Tas.deleteInList( indice);
    } else {
        cout<<"No hay una tarea registrada con ese id"<<endl;
    }
}

