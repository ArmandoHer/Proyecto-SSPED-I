#include <iostream>

using namespace std;

class estudiante{

    private:
        ///Datos primordiales
        string codigo;
        string nombre;
        string apellido;
        string carrera;
        string correo;
    public:
        ///Setters
        void set_Codigo(const string& c) {
            codigo = c;
        }
        void set_Nombre(const string& n) {
            nombre = n;
        }
        void set_Apellido(const string& a) {
            apellido = a;
        }
        void set_Carrera(const string& c) {
            carrera = c;
        }
        void set_Correo(const string& c) {
            correo = c;
        }
        ///Getters
        string get_Codigo() const {
            return codigo;
        }
        string get_Nombre() const {
            return nombre;
        }
        string get_Apellido() const {
            return apellido;
        }
        string get_Carrera() const {
            return carrera;
        }
        string get_Correo() const {
            return correo;
        }
        ///Operadores
        bool operator==(const estudiante& s) const {
            return codigo == s.codigo;
        }
        bool operator!=(const estudiante& s) const {
            return codigo != s.codigo;
        }
        bool operator<(const estudiante& s) const {
            return codigo < s.codigo;
        }
        bool operator<=(const estudiante& s) const {
            return codigo <= s.codigo;
        }
        bool operator>(const estudiante& s) const {
            return codigo > s.codigo;
        }
        bool operator>=(const estudiante& s) const {
            return codigo >= s.codigo;
        }
        ///Clases amigas
        friend ostream& operator << (ostream&, estudiante&);
        friend istream& operator >> (istream&, estudiante&);

        string toString(){
            string str("");
            str+="Datos del  estudiantes:\ncodigo:";
            str+=codigo;
            str+=" || nombre: ";
            str+=nombre;
            str+=" || apellido: ";
            str+=apellido;
            str+=" || carrera: ";
            str+= carrera;
            str+=" || correo: ";
            str+= correo;
        }
};
