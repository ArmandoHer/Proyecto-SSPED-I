#include <iostream>
#include <iomanip>
#include<cstdio>
//#include "Estudiante.cpp"
//#include "calificacion.cpp"
//#include "participacion.cpp"
//#include "tareas.cpp"
#include "nodo.h"
#include "Lista.h"

using namespace std;

class Materia{

    private:

    ///Datos
    List <string> SE;//ST=String Estudiante
    List <int> ST;//ST=String Tarea
    List <string>SC;//SC=String Calificaciones
    string nombre;
    string NRC;
    string clave;
    string modulo;
    string ciclo;
    string aula;
    fecha fecha_inicio;
    fecha fecha_fin;
    string dias;
    string seccion;
    fecha horario;
    string re;
    int rr;

    public:

    ///Setters

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

	string toString(){
 //   cout<< nombre << " || "<< NRC<< " || "<<" || "<<clave<<" || "<<modulo<<" || "<<ciclo<<" || "<<aula<<" || "<<fecha_inicio<<" || "<<fecha_fin<<" || "<< dias<<" || "
 //	 <<seccion<<" || "<<horario;

	 cout<< nombre << " || "<< NRC<<" || "<<clave<<" || "<<modulo<<" || "<<ciclo<<" || "<<aula<<" || "<< dias<<" || "
	 <<seccion<<" || " <<fecha_inicio.getHora()<<":" << fecha_inicio.getMinuto()<<":"
	 <<fecha_fin.getHora()<<":"<<fecha_fin.getMinuto();
	 cout<<endl;
	 cout<<"Estudiantes: ";//SE.print_list();
	 printSE();
	 cout<<"Tareas: ";
	 printST();
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

};
