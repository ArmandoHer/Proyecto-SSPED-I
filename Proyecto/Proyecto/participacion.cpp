#include <iostream>
//#include "tareas.cpp"

using namespace std;

class Participacion{

private:

    string codigo_estudiante;
    fecha fecha_de_participacion;
    string Codigo_de_curso;

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

};
