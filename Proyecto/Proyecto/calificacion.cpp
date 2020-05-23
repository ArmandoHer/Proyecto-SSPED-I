#include <iostream>
//#include "Estudiante.cpp"

class Calificacion{
    private:
        ///Atributos
        float puntaje;
        std::string codigoAlumno;
        std::string codigoMateria;
    public:
        ///Metodos
        void setPuntaje( float p ){
            puntaje = p;
        }
        void setCodigoAlumno(std::string c){
            codigoAlumno = c;
        }
        void setCodigoMateria(std::string c){
            codigoMateria = c;
        }

        float getPuntaje( ){
            return puntaje;
        }
        std::string getCodigoAlumno(){
            return codigoAlumno;
        }
        std::string getCodigoMateria(){
            return codigoMateria;
        }

        string toString(){
            string str("");

            char aPun[8];

            sprintf( aPun, "%f", puntaje);

            str+= "Puntaje: ";
            str+= aPun;
            str+= "\n codigo alumno: ";
            str+= codigoAlumno;
            str+= " || codigo materia: ";
            str+= codigoMateria;
            str+= "\n";
     }

};
