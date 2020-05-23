#include <iostream>
#include <iomanip>
#include<cstdio>
//#include "Estudiante.cpp"
//#include "calificacion.cpp"
//#include "participacion.cpp"
//#include "tareas.cpp"
#include "nodo.h"
#include "participacion.cpp"
#include "Lista.h"

using namespace std;

class Materia{

    private:

    ///Datos
    List <Calificacion> calificaciones;
    List <string> SE;//ST=String Estudiante
    List <int> ST;//ST=String Tarea
    List <string>SC;//SC=String Calificaciones
    string nombre;
    string NRC;
    string clave;
    string modulo;
    string ciclo;
    string aula;
    string dias;
    string seccion;
    fecha fecha_inicio;
    fecha fecha_fin;
    fecha horario;
    string re;
    int rr;
    int porcentajeTareas;
    int porcentajeParticipacion;
    public:

    ///Setters

    void setPorcentajeTareas(int p){
        porcentajeTareas = p;
    }

    void setPorcentajeParticipacion(int p){
        porcentajeParticipacion = p;
    }

    int getPorcentajeTareas(){
        return porcentajeTareas;
    }

    int getPorcentajeParticipacion(){
        return porcentajeParticipacion;
    }

    void set_nombre(const string& name){
        nombre=name;
    }
    void set_NRC(const string& nrc){
        NRC=nrc;
    }
    string getNRC(){
    return NRC;
    }
    void set_clave(const string& clav){
        clave=clav;
    }
    void set_modulo(const string& mod){
        modulo=mod;
    }
    void set_ciclo(const string& clo){
        ciclo=clo;
    }
    void set_Aula(const string& aul){
        aula=aul;
    }
    void set_Fecha_inicio(const fecha& fi){
        fecha_inicio=fi;
    }
    void set_Fecha_fin(const fecha& ff){
        fecha_fin=ff;
    }
    void set_Dias(const string& dia){
        dias=dia;
    }
    void set_Seccion(const string& secc){
        seccion=secc;
    }
    void set_Horario(const fecha& hor){
        horario=hor;
    }

    ///Getters

    string get_nombre()const{
        return nombre;
    }
    string get_NRC()const{
        return NRC;
    }
    string get_clave()const{
        return clave;
    }
    string get_modulo()const{
        return modulo;
    }
    string get_ciclo()const{
        return ciclo;
    }
    string get_Aula()const{
        return aula;
    }
    fecha get_Fecha_inicio()const{
        return fecha_inicio;
    }
    fecha get_Fecha_fin()const{
        return fecha_fin;
    }
    string get_Dias()const{
        return dias;
    }
    string get_seccion()const{
        return seccion;
    }
    fecha get_Horario()const{
        return horario;
    }
    ///Operators

    bool operator == (const Materia&)const;
    bool operator != (const Materia&)const;
    bool operator <  (const Materia&)const;
    bool operator <= (const Materia&)const;
    bool operator >= (const Materia&)const;

    friend std::ostream& operator << (std::ostream&, Materia&);
    friend std::istream& operator >> (std::istream&, Materia&);

	void insertCodigoE(string& d)
	{
	    SE.insertInList(d);
	}

	void insertCodigoT(int& d)
	{
       cout <<"Adding Codigo de Tarea: "<<d<<" En materia: "<<getNRC()<<endl;;
	   ST.insertInList(d);
	}

	void insertCodigoC(string& d)
	{
        SC.insertInList(d);
	}

	void deleteE(int& pos)
	{
        SE.deleteInList(pos);
	}

	void deleteT(int& pos)
	{
        ST.deleteInList(pos);
	}

	void deleteC(int& pos)
	{
        SC.deleteInList(pos);
	}

	string retrieveE(int& pos)
	{
        re=SE.retrieve(pos);
        return re;
	}
	int retrieveT(int& pos)
	{
        rr=ST.retrieve(pos);
        return rr;
	}
	string retrieveC(int& pos)
	{
        re=SC.retrieve(pos);
        return re;
	}



	std::string toString(){
 //   cout<< nombre << " || "<< NRC<< " || "<<" || "<<clave<<" || "<<modulo<<" || "<<ciclo<<" || "<<aula<<" || "<<fecha_inicio<<" || "<<fecha_fin<<" || "<< dias<<" || "
 //	 <<seccion<<" || "<<horario;

	 cout<< nombre << " || "<< NRC<<" || "<<clave<<" || "<<modulo<<" || "<<ciclo<<" || "<<aula<<" || "<< dias<<" || "
	 <<seccion<<" || " <<fecha_inicio.getHora()<<":" << fecha_inicio.getMinuto()<<":"
	 <<fecha_fin.getHora()<<":"<<fecha_fin.getMinuto()
	 <<" || Criterios de evaluacion: \n"
	 <<"  porcentaje participacion: "<<porcentajeParticipacion
	 <<"  porcentaje tareas: "<<porcentajeTareas ;
	 cout<<endl;
	 cout<<"Estudiantes: ";//SE.print_list();
	 printSE();
	 cout<<"Tareas: ";
	 printST();
	 return "";
	}

    void printSE(){
         for(int x=1;x<=SE.contador;x++){
           cout<< SE.retrieve(x)<<" ";
         }
         cout<<endl;
	 }

     void printST(){
         for(int x=1;x<=ST.contador;x++){
           cout<< ST.retrieve(x)<<" ";
         }
         cout<<endl;
	 }

    void addCalificacion( float puntaje, std::string cAlumno, std::string cMateria ){
        Calificacion cNueva;

        cNueva.setPuntaje( puntaje );
        cNueva.setCodigoAlumno(cAlumno);
        cNueva.setCodigoMateria(cMateria);

        calificaciones.insertInList(cNueva);
    }

    std::string calificacionesToString(){
        return calificaciones.toString();
    }

    /*
        utilizando sus propios criterios de evaluacion buscamos al
            estudiante y sus entregas
    */
    float calificar(std::string NRCmateria, std::string codigoAlumno, List<Participacion> par, List<Entrega> entes ){
        bool alumnoEncontrado;
        /*
            Buscaremos el codigo de alumno, si esta entonces podemos seguir
        */
        for( int i = 0; i < SE.getSize(); i++  ){
            if( codigoAlumno == SE.retrieve( i ) ){
                alumnoEncontrado = true;
                break;
            }
        }
        if( alumnoEncontrado){
                ///puntajes para el alumno
            float puntajeTotal(0), puntajeTareas, puntajeParticipaciones;
            int totalmisParticipaciones(0);
            float promedioTareas, promedioParticipaciones;
        //Busqueda de tareas
            for( int i = 0; i <ST.getSize(); i++){
                    for( int j = 0; j <entes.getSize(); j++){
                            /*
                                Si el codigo de tarea existe en esta materia y tiene
                                    el codigo del estudiante ingresado se agrega a la
                                    calificacion
                            */
                        if( entes.retrieve(j).getIdTarea() ==  ST.retrieve(i) &&
                                    entes.retrieve(j).getCodigoAlumno() == codigoAlumno  ){
                            promedioTareas += entes.retrieve(j).getPuntaje();
                        }
                    }
            }///fin busqueda calificaciones

            for( int i = 0; i <par.getSize(); i++){

                            /*
                                Si el codigo de participacion tiene el de la clase y el alumno
                                    lo tomamos
                            */
                        if( par.retrieve(i).get_CodigoDeCurso() ==  NRCmateria &&
                                    par.retrieve(i).get_CodigoDeEstudiante() == codigoAlumno  ){
                            promedioParticipaciones += entes.retrieve(i).getPuntaje();
                            totalmisParticipaciones++;
                        }
            }///fin agregado de participaciones

            puntajeTareas = ( promedioTareas/100 ) * porcentajeTareas;
            puntajeParticipaciones= ( promedioParticipaciones/100 ) * porcentajeParticipacion;
            puntajeTotal = puntajeTareas+puntajeParticipaciones;
            addCalificacion( puntajeTotal, codigoAlumno, NRCmateria);
            return puntajeTotal;
        }
        //En caso de no encontrar el alumno
        return -1.0;
    }

};






