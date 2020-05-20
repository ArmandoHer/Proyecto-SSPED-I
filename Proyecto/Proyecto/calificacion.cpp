#include <iostream>
//#include "Estudiante.cpp"

using namespace std;

class Calificacion{
    private:
        ///Atributos
        float calif_tarea;
        float calif_alumno;
        float calif_grupo;
        int cant_tareas;
        int cant_alumnos;

    public:
        ///Metodos
        void setCalifTarea(const float& t){
            calif_tarea=t;
        }

        void setCalifAlumno(const float& a){
            calif_alumno=a;
        }

        void setCalifGrupo(const float& g){
            calif_grupo=g;
        }

        void setCantTareas(const int& ct){
            cant_tareas=ct;
        }

        void setCantAlumnos(const int& ca){
            cant_alumnos=ca;
        }

        float getCalifTarea() const{
            return calif_tarea;
        }

        float getCalifAlumno() const{
            return calif_alumno;
        }

        float getCalifGrupo() const{
            return calif_grupo;
        }

        int getCantTareas() const{
            return cant_tareas;
        }

        int getCantAlumnos() const{
            return cant_alumnos;
        }
};
