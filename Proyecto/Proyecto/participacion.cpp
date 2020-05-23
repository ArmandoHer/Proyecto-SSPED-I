#ifndef PARTICIPACION_CPP_INCLUDE
#define PARTICIPACION_CPP_INCLUDE
#include <iostream>
//#include "tareas.cpp"

using namespace std;

class Participacion{
private:

    static int idAutoIncrement;
    int id;
    string codigo_estudiante;
    fecha fecha_de_participacion;
    string Codigo_de_curso;//Funcionara como NRC de materia

public:

    void set_CodigoDeEstudiante(const string& cod_est){
        codigo_estudiante=cod_est;
    }
    void set_FechaDeParticipacion(const fecha& fdp){
        fecha_de_participacion=fdp;
    }
    void set_CodigoDeCurso(const string& cod_cur){
        Codigo_de_curso=cod_cur;
    }
    string get_CodigoDeEstudiante(){
        return codigo_estudiante;
    }

    fecha get_FechaDeParticipacion(){
        return fecha_de_participacion;
    }

    string get_CodigoDeCurso(){
        return Codigo_de_curso;
    }

    void setId( int i ){
            id = i;
    }

    int getId(){
        return id;
    }

    bool operator == (const Participacion& t)const{
        return id == t.id;
    }
    bool operator != (const  Participacion& t)const{
        return id != t.id;
    }

    bool operator <  (const Participacion& t)const{
        return id < t.id;
    }
    bool operator  > (const  Participacion& t)const{
        return id > t.id;
    }
    bool operator <= (const  Participacion& t)const{
        return id <= t.id;
    }
    bool operator >= (const  Participacion& t)const{
        return id >= t.id;
    }

    string toString(){
        string str("");
        char aId[10];
        sprintf( aId, "%i", id );
        str += "Id: ";
        str += aId;
        str += "|| codigo estudiante: ";
        str += codigo_estudiante;
        str += "||\nFecha de participacion: ";
        str += fecha_de_participacion.toString();
        str += "||codigo de curso:";
        str += Codigo_de_curso;

        return str;

    }

};
#endif // LSITA_H_INCLUDED
