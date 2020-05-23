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
///Funciones para tareas
void ReTa( List<Tarea>&);
void modTa( List<Tarea>&, int idTarea);
void delTa( List <Tarea>&Tas, int idTarea);

///Funciones para participaciones
void delPa( List <Participacion>&Tas, int idParticipacion);
void modPa( List < Participacion>&Tas, int  idParticipacion);
void RePa( List < Participacion>& Tas);

void ReEn( List<Entrega>& , List<Tarea> , List<estudiante> );
void ModEn( List<Entrega>& , List<Tarea> , List<estudiante> , int idEntrega);
void DelEn( List<Entrega>& , int  idEntrega);

void calificarMateria( List<Materia>& LM, List<Participacion> par, List<Entrega> ene );

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

/*
No, el avance pasado ya contempla el registro tanto
de tareas como participación, en el 5 toman las calificaciones
y las ponderan con los criterios de evaluación de la materia.

Por ejemplo,
si un alumno esta registrado en una materia, donde habia 10 tareas
y todas las entrego y en todas tiene 100, en el avance 5 se recupera
esa información junto con los criterios de evaluación de la materia y
 si por ejemplo, las tareas valen 20% en la materia, ese alumno sumaria
 20 puntos a su calificación, esto se repite para el resto de criterios de
 evaluación.
*/

int main()
{
    List<Materia> LM;
    List<estudiante> LE;
    List<Tarea> LT;
    List<Calificacion> LC;
    List< Participacion> LP ;
    List<Entrega>LEntre;
    Materia a;
    estudiante b;
    Tarea c;
    //Calificacion d;
    fecha f;
    int x,y,w;
    string Str,Str2;
do{
    cout<<"Con que deseas trabajar?"<<endl;
    cout<<"1- Materias"<<endl;
    cout<<"2- Estudiantes"<<endl;
    cout<<"3- Tareas"<<endl;
    cout<<"4- Participaciones"<<endl;
    cout<<"5- Entregas"<<endl,
    cout<<"6- Calificaciones"<<endl;
    cout<<"7- Salir"<<endl;
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
                cout<<"--------------------------"<<endl;
                cout<<"Modulo de tareas"<<endl;
                cout<<"-----\nQue desea realizar?"<<endl<<endl;
                cout<<"1.Registrar nueva tarea"<<endl;
                cout<<"2.Modificar tareas"<<endl;
                cout<<"3.Eliminar tareas"<<endl;
                cout<<"4.Ver todas las tareas registradas"<<endl;
                cout<<"5.Buscar tareas"<<endl;
                cout<<"6.Salir"<<endl;
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
                            int id;
                            cout<<"Escriba el id de la tarea a eliminar"<<endl;
                            cin>>id;
                            delTa(LT, id);
                            break;
                        } case 4:{
                            int idTarea, indice(-1);
                            cout<<"Escriba el id de la tarea a encontrar"<<endl;
                            cin>>idTarea;
                            for( int i = 0; i < LT.getSize(); i++){
                            if( idTarea == LT.retrieve( i ).getId() ){
                                            indice = i;
                                            break;
                                    }
                            }
                            if( indice > -1){

                                cout<<LT.retrieve(indice).toString()<<endl;

                            } else {
                                cout<<"El id de la tarea no existe"<<endl;
                            }
                            break;
                         }
                        case 5:{
                            LT.print_list();
                            break;
                        }
                    }
            }while(w!=6);
            break;
        //Modulos para tareas
        case 4:{
            do{
                cout<<"--------------------------"<<endl;
                cout<<"Modulo de participaciones"<<endl;
                cout<<"-----\nQue desea realizar?"<<endl<<endl;
                cout<<"1.Registrar nueva participacion"<<endl;
                cout<<"2.Modificar participacion"<<endl;
                cout<<"3.Eliminar participacion"<<endl;
                cout<<"3.Buscar participacion"<<endl;
                cout<<"5.Ver todas las participaciones registradas"<<endl;
                cout<<"6.Salir"<<endl;
                cin>>w;
                    switch(w)
                    {
                        case 1:{
                            RePa(  LP );
                            break;
                        }case 2:{
                            int id;
                            cout<<"Escriba el id de la participacion a modificar"<<endl;
                            cin>>id;
                            modPa(LP, id);
                            break;
                        }
                        case 3:{
                            int id;
                            cout<<"Escriba el id de la participacion a eliminar"<<endl;
                            cin>>id;
                            delPa(LP, id);
                            break;
                        } case 4:{
                            int idParticipacion, indice(-1);
                            cout<<"Escriba el id de la participacion a encontrar"<<endl;
                            cin>>idParticipacion;
                            for( int i = 0; i < LP.getSize(); i++){
                            if( idParticipacion== LP.retrieve( i ).getId() ){
                                            indice = i;
                                            break;
                                    }
                            }
                            if( indice > -1){
                                cout<<LP.retrieve(indice).toString()<<endl;
                            } else {
                                cout<<"El id de la tarea no existe"<<endl;
                            }
                            break;
                         }
                        case 5:{
                            LP.print_list();
                            break;
                        }
                    }
            }while(w!=6);
            break;
        }

        case 5:{
            int opcEntregas =0;
            do
            {
                cout<<"Entregas"<<endl;
                cout<<"1- Registrar entrega"<<endl;
                cout<<"2- Modificar entrega"<<endl;
                cout<<"3- Eliminar entrega"<<endl;
                cout<<"4- Calificar entrega"<<endl;
                cout<<"5- Ver entregas"<<endl;
                cout<<"6- Volver al menu principal"<<endl;
                cout<<"Escriba la accion que desea realizar:"<<endl;
                cin>>opcEntregas;
                switch(opcEntregas){
                    case 1:{
                        ReEn( LEntre, LT, LE );
                        break;
                    }
                    case 2:{
                        int idEntrega;
                        cout<<"-- Modificando entregas"<<endl;
                        cout<<"-- Entregas disponibles"<<endl;
                        cout<<LEntre.toString()<<endl;
                        cout<<"Ingrese el id de la entrega(-1 para salir)"<<endl;
                        cin>>idEntrega;
                        if( idEntrega < -1 && idEntrega < LEntre.getSize() ){
                            ModEn( LEntre, LT, LE, idEntrega );
                        }
                        break;
                    }
                    case 3:{
                        int idEntrega;
                        cout<<"-- Eliminando entregas"<<endl;
                        cout<<"-- Entregas disponibles"<<endl;
                        cout<<LEntre.toString()<<endl;
                        cout<<"Ingrese el id de la entrega(-1 para salir)"<<endl;
                        cin>>idEntrega;
                        if( idEntrega < -1 && idEntrega < LEntre.getSize() ){
                            DelEn( LEntre, idEntrega );
                        }
                        break;
                    }
                    case 4:{
                        int idEntrega;
                        cout<<"-- Calificando entregas"<<endl;
                        cout<<"-- Entregas disponibles"<<endl;
                        cout<<LEntre.toString()<<endl;
                        cout<<"Ingrese el id de la entrega(-1 para salir)"<<endl;
                        cin>>idEntrega;
                        if( idEntrega < -1 && idEntrega < LEntre.getSize() ){
                            Entrega* e = LEntre.retrieve2(idEntrega);
                            int p;
                            cout<<"Escriba el puntaje (calificacion/100)"<<endl;
                            cin>>p;
                            e->setPuntaje(p);
                        }
                        break;
                    }
                    case 5:{
                        cout<<"-- Entregas disponibles"<<endl;
                        cout<<LEntre.toString()<<endl;
                        break;
                    }

                }
            } while( opcEntregas != 6);
        break;
        }

        case 6:{

            break;
        }
    }
}while(x!=6);

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

    int criterio;
    cout<<"Criterios de evaluacion:"<<endl;
    cout<<"Porcentaje valido para tareas: "<<endl;
    cin>>criterio;
    m.setPorcentajeTareas(criterio);
    cout<<"Porcentaje valido para tareas: "<<endl;
    cin>>criterio;
    m.setPorcentajeParticipacion(criterio);

    cout<<"Hora en que termina:";
    cin>>Str;
    pos = Str.rfind(":");
    Str2 = Str.substr(0, pos);
    f.setHora(stoi(Str2));
    Str2 = Str.substr(pos+1,Str.size() );
    f.setMinuto(stoi(Str2));

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

/*=========================================
Funciones para las participaciones
=========================================*/
void RePa( List < Participacion>& Tas){
             Participacion nueva;
            fecha f;
            int datofecha;
            string Str;
            int id;
            //--Registro de la tarea
            fflush(stdin);
            cout<<"Codigo de estudiante:"<<endl;
            getline(cin,Str);
            nueva.set_CodigoDeEstudiante(Str);
            cout<<"NRC de curso:"<<endl;
            getline(cin,Str);
            nueva.set_CodigoDeCurso(Str);
            //-----
            cout<<"Fecha de participacion:"<<endl<<endl;
            cout<<"Escriba el dia:"<<endl;
            cin>>datofecha;
            f.setDia(datofecha);
            cout<<"Escriba el mes:"<<endl;
            cin>>datofecha;
            f.setMes(datofecha);
            cout<<"Escriba el anio:"<<endl;
            cin>>datofecha;
            f.setAnio(datofecha);
            cout<<"Escriba la hora:"<<endl;
            cin>>datofecha;
            f.setHora(datofecha);
            cout<<"Escriba los minutos:"<<endl;
            cin>>datofecha;
            f.setMinuto(datofecha);
            nueva.set_FechaDeParticipacion(f);
            cout<<"Id de participacion:"<<endl;
            cin>>id;
            nueva.setId(id);
            Tas.insertInList(nueva);
            cout<<"Participacion registrada"<<endl;
}

void modPa( List < Participacion>&Tas, int  idParticipacion){
    int datofecha;
    int indice(-1);
    string Str;
    int y;
    //obtengo indice por el codigo
    for( int i = 0; i < Tas.getSize(); i++){
            if( idParticipacion == Tas.retrieve( i ).getId() ){
                    indice = i;
                    break;
            }
    }
    if( indice > -1){
            Participacion *editada =Tas.retrieve2(indice);
            fecha f;
            //Si no lo tengo no edito
           fflush(stdin);
            cout<<"Codigo de estudiante:"<<endl;
            getline(cin,Str);
            editada->set_CodigoDeEstudiante(Str);
            cout<<"Codigo de curso:"<<endl;
            getline(cin,Str);
            editada->set_CodigoDeCurso(Str);
            //-----
            cout<<"Fecha de participacion:"<<endl<<endl;
            cout<<"Escriba el dia:"<<endl;
            cin>>datofecha;
            f.setDia(datofecha);
            cout<<"Escriba el mes:"<<endl;
            cin>>datofecha;
            f.setMes(datofecha);
            cout<<"Escriba el anio:"<<endl;
            cin>>datofecha;
            f.setAnio(datofecha);
            cout<<"Escriba la hora:"<<endl;
            cin>>datofecha;
            f.setHora(datofecha);
            cout<<"Escriba los minutos:"<<endl;
            cin>>datofecha;
            f.setMinuto(datofecha);
            editada->set_FechaDeParticipacion(f);
            cout<<endl;
            cout<<"Cacion editada"<<endl;
            cout<<Tas.retrieve2(indice)->toString()<<endl;
    } else {
        cout<<"No hay una tarea registrada con ese id"<<endl;
    }
}

void delPa( List <Participacion>&Tas, int idParticipacion){
    int indice(-1);
    string Str;
    //obtengo indice por el codigo
    for( int i = 0; i < Tas.getSize(); i++){
            if( idParticipacion == Tas.retrieve( i ).getId() ){
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
/*=========================================================
        Funciones para registrar entregas de tareas
=========================================================*/
void ReEn( List<Entrega>& ents, List<Tarea> tas, List<estudiante> estus){
    //Datos para el registro
    string strs;
    int c;
    Entrega e;
    cout<<"--Registrando entrega"<<endl;
    cout<<"Id de entrega:"<<endl;
    cin>>c;
    e.setId(c);
    cout<<"-Lista de tareas registradas:"<<endl;
    cout<<tas.toString()<<endl;
    cout<<"Escriba el id de la tarea a la que pertenence:"<<endl;
    cin>>c;
    e.setIdTarea( c );
    cout<<"-Lista de estudiantes"<<endl;
    cout<<estus.toString()<<endl;
    cout<<"Codigo alumno:"<<endl;
    cin>>strs;
    e.setCodigoAlumno(strs);
    cout<<"Agregue un adjunto a la entrega:"<<endl;
    cin>>strs;
    e.setArchivo(strs);
    ents.insertInList(e);
        //Trabajaremos los archivos como si fueran un documento de texto

}

void ModEn( List<Entrega>& ents, List<Tarea> tas , List<estudiante> estus, int idEntrega){
    //Datos para el registro
    string strs;
    int c;
    int indice(-1);
    for( int i = 0; i < ents.getSize(); i++){
            if( idEntrega == ents.retrieve( i ).getId() ){
                    indice = i;
                    break;
            }
    }
    if( indice > -1){
    Entrega *e = ents.retrieve2(indice);
    cout<<"--Registrando entrega"<<endl;
    cout<<"Id de tarea:"<<endl;
    cin>>c;
    e->setId(c);
    cout<<"-Lista de tareas registradas:"<<endl;
    cout<<tas.toString()<<endl;
    cout<<"Escriba el id de la tarea a la que pertenence:"<<endl;
    cin>>c;
    e->setIdTarea( c );
    cout<<"-Lista de estudiantes"<<endl;
    cout<<estus.toString()<<endl;
    cout<<"Codigo alumno:"<<endl;
    cin>>strs;
    e->setCodigoAlumno(strs);
    cout<<"Agregue un adjunto a la entrega:"<<endl;
    cin>>strs;
    e->setArchivo(strs);
    }
}

void DelEn( List<Entrega>& ents, int  idEntrega){
    int indice(-1);
    for( int i = 0; i < ents.getSize(); i++){
            if( idEntrega == ents.retrieve( i ).getId() ){
                    indice = i;
                    break;
            }
    }
    if(indice >-1){
        ents.deleteInList(indice);
    }
}

void calificarMateria( List<Materia>& LM, List<Participacion> par, List<Entrega> ene ){
        std::string NRCmateria, codAlumno;
        Materia* m;
        cout<<"Escriba el NRC de la materia"<<endl;
        cin>>NRCmateria;
        cout<<"Escriba el codigo del estudiante a calificar"<<endl;
        cin>>codAlumno;
        //Vamos a buscar la materia para calificar al estudiante
        for(int x=1;x<=LM.contador;x++){
           m= LM.retrieve2(x);
           if(m->get_NRC()==NRCmateria){
                m->calificar(NRCmateria, codAlumno, par, ene);
                cout<<"Calificacion agregada"<<endl;
                break;
           }
        }
        //Obtenemos los datos de la materia

}






