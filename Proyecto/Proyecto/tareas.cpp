#include <iostream>
#include <stdio.h>
using namespace std;

class fecha{
private:
     int dia, mes, anio, hora, minuto;
public:
     int getDia(){
    return dia;
    }
     int getMes(){
    return mes;
    }
    int getAnio(){
    return anio;
    }
     int getHora(){
    return hora;
    }
     int getMinuto(){
    return minuto;
    }

    void setDia(int d){
    dia = d;
    }
    void setMes(int m){
    mes = m;
    }
    void setAnio(int a){
    anio = a;
    }
    void setHora(int h){
    hora = h;
    }
    void setMinuto(int m){
    minuto = m;
    }
    string toString(){
        char adia[3], ames[3], aanio[4];
        sprintf(adia, "%i", dia );
        sprintf(ames, "%i", mes);
        sprintf(aanio, "%i", anio);
        std::string str;
        str = "Fecha ";
        str += adia;
        str +=":";
        str += ames;
        str += ":";
        str += aanio;
        return str;
    }

};

class Entrega{
private:
    /*
        - EL id de tarea nos indicara a que tarea pertenece esta Entrega
        - El codigo de alumno muestra la pertenencia de el trabajo entregado
    */
    int idTarea;
    std::string codigoAlumno;
    std::string Archivo;
public:

    int getIdTarea(){
    return idTarea;
    }
    std::string getCodigoAlumno(){
    return codigoAlumno;
    }
    std::string getArchivo(){
    return Archivo;
    }

    void setIdTarea(int t){
    idTarea = t;
    }
    void setCodigoAlumno(std::string c){
    codigoAlumno = c;
    }
    void setArchivo(std::string a){
    Archivo = a;
    }

};

class Tarea{
    private:
        std::string Nombre, descripcion;
        //Trabajaremos los archivos como si fueran un documento de texto
        std::string archivoAsignacion;
        std::string idCurso;
        fecha fechaEntrega;
        int calificacion;
        /*
            -Id funciona como propio identificador de tarea, asi cada entrega tendra un objetivo
                al que apuntar y saber donde tiene sentido verlo
            -Id curso es para saber en donde aplica la tarea
        */
        int id;
    public:
        explicit Tarea(): calificacion(0)
        {        }

        std::string getNombre(){
        return Nombre;
        }
        std::string getDesc(){
        return descripcion;
        }
        std::string getArchivoAsignacion(){
        return archivoAsignacion;
        }
        std::string getidCurso(){
        return idCurso;
        }
        fecha getFechaEntrega(){
        return fechaEntrega;
        }
        int getCalificacion(){
        return calificacion;
        }
        int getId(){
        return id;
        }
        void setNombre(std::string n){
        Nombre = n;
        }
        void setDesc(std::string d){
        descripcion = d;
        }
        void setArchivoAsignacion(std::string a){
        archivoAsignacion = a;
        }
        void setFechaEntrega(fecha f){
        fechaEntrega.setDia(f.getDia());
        fechaEntrega.setMes(f.getMes());
        fechaEntrega.setAnio(f.getAnio());
        fechaEntrega.setHora(f.getHora());
        fechaEntrega.setMinuto(f.getMinuto());
        }
        void setCalificacion(int c){
        calificacion = c;
        }
        void setId(int i){
        id = i;
        }
        void seIdCurso(int i){
        idCurso = i;
        }

        string toString(){
            string str;
            char aId[10], aCalif[2];
            sprintf( aId, "%i", id );
            sprintf( aCalif, "%i", calificacion );
            str = "Nombre de la tarea: ";
            str += Nombre ;
            str += "\ndesc: ";
            str += descripcion;
            str += "\nid: ";
            str += aId ;
            str += " || archivo: ";
            str += archivoAsignacion;
            str += " || idCurso ";
            str += aId;
            str += "\nfecha de entrega: ";
            str += fechaEntrega.toString();
            str += " || calificacion: ";
            str +=aCalif;
            return str;
        }
};
