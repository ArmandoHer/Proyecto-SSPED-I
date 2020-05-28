#include <iostream>

using namespace std;



const char * slimpial="clear"; //linux
const char * slimpiaw="cls"; //windows

void  itoa ( int value, char * str, int base ){
  sprintf( str, "%d",value);
}

template <class T>
class Nodo
	{
	    public:
        Nodo(){
	            next=nullptr;
	        };
	        T data;
	        Nodo *next;

	    protected:
        private:

	};

template <class T>
class List{

private:
    T *data;
    Nodo<T> *head;
    Nodo<T> *tail;
    int size;

public:
    int contador;
    List();
    void createnode(T value);
    bool emptyList();
    void ordena();
    void print_list();
    string toString();

    int getSize();

    void insertInList(T& d);
    void deleteInList(int& p);

    T retrieve(int& p);
    T* retrieve2(int& p);
    void modifyCodigo(string ndata, string codigo);
    void modifyTarea(string ndata, int tarea);;
};

template <class T>
List<T>::List()
{
    head=nullptr;
    tail=nullptr;
    contador=0;
    size=0;
}

template <class T>
void List<T>::ordena()
{
    Nodo<T> *temp1, *temp2;
    T data1,data2,data3;
    temp1=head;

    if(head==nullptr)
        return;
    else {

      for(int x=0;x<contador;x++){
        data1=temp1->data;
        temp2=temp1;
        for(int y=x;y<contador;y++){
            data2=temp2->data;
            if(data1<data2){
                data3=data1;
                data1=data2;
                data2=data3;
            }

            temp2=temp2->next;
        }
        temp1=temp1->next;
      }

    }
}


template <class T>
bool List<T>::emptyList()
{
    if(head==nullptr)
        return true;
    else
        return false;
}

template <class T>
void List<T>::createnode(T value){
	      Nodo<T> *temp=new Nodo<T>();
	      temp->data=value;
	      temp->next=nullptr;
	      if(head==nullptr)
	      {
	        head=temp;
	        tail=temp;
	        temp=NULL;
	      }
	      else
	      {
	        tail->next=temp;
	        tail=temp;
	      }
}

template <class T>
void List<T>::print_list()
{
    Nodo<T> *temp;
    T data;
    temp=head;
	    while(temp!=nullptr)
	    {
          data=temp->data;
	      std::cout<<data.toString();
	      temp=temp->next;
	      std::cout<<std::endl;
	    }
	    std::cout<<std::endl<<"Presione Enter para continuar"<<endl;
	    int c = getchar();
}

template <class T>
string List<T>::toString()
{
    string result="";
    Nodo<T> *temp;
    T data;
    temp=head;
	    while(temp != nullptr)
	    {
          data=temp->data;
	      result+=data.toString();
	      temp=temp->next;
	    }
return result;
}

template <class T>
void List<T>::insertInList(T& d)
{
    createnode(d);
    size++;
    contador++;
}

template <class T>
void List<T>::deleteInList(int& pos)
{
    Nodo<T> *current;
    Nodo<T> *previous=nullptr;
    current=head;
    for(int i=1;i<pos;i++)
    {
        previous=current;
        current=current->next;
    }
    if(previous!=nullptr)
        previous->next=current->next;
    else{
        head=head->next;
    }
        size--;
}

template <class T>
T List<T>::retrieve(int& pos)
{
    Nodo<T>  *current=head;

    for(int i=1;i<pos;i++)
    {
        current=current->next;
    }

    return current->data;
}

//Metodo de busqueda linear que nos recupera el puntero del objeto T
template <class T>
T* List<T>::retrieve2(int& pos)
{
    Nodo<T>  *current=head;

    for(int i=1;i<pos;i++)
    {
        current=current->next;
    }

    return &(current->data);
}

template <class T>
void List<T>::modifyCodigo(string ndata, string codigo){
    Nodo<T> *temp;
    T data;
    temp=head;
	    while(temp!=NULL)
	    {
           if(temp->data.get_NRC()==ndata){
                cout<<"NRC found!!!";
                temp->data.insertCodigoE(codigo);
           };
        temp=temp->next;
	    }
}

template <class T>
int List<T>::getSize(){
        return size;
}

template <class T>
void List<T>::modifyTarea(string ndata, int tarea){
    Nodo<T> *temp;
    T data;
    temp=head;
	    while(temp!=NULL)
	    {
           if(temp->data.get_NRC()==ndata){
                cout<<"Tarea id found!!!";
                temp->data.insertCodigoT(tarea);
           };
        temp=temp->next;
	    }
}



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
    int id;
    int idTarea;
    string NRC;
    int puntaje;
    std::string codigoAlumno;
    std::string Archivo;
public:

    int getId(){
        return id;
    }

    int getPuntaje(){
        return puntaje;
    }
    int getIdTarea(){
        return idTarea;
    }
    std::string getCodigoAlumno(){
        return codigoAlumno;
    }
    std::string getArchivo(){
        return Archivo;
    }
    std::string getNRC(){
        return NRC;
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
    void setNRC(std::string a){
        NRC = a;
    }

    void setPuntaje(int p){
        puntaje = p;
    }
    void setId(int i){
        id = i;
    }

    string toString(){
            string str("");
            char aId[10], aPun[8], aIdT[10];
            sprintf( aId, "%i", id );
            sprintf( aPun, "%i", puntaje);
            sprintf( aIdT, "%i", idTarea );
            str+="-- Id: ";
            str+= aId;
            str+= " || NRC: ";
            str+= NRC;
            str+= " || puntaje: ";
            str+= aPun;
            str+= " ||  idTarea: ";
            str+= aIdT;
            str+= "\n codigo alumno: ";
            str+= codigoAlumno;
            str+= " || Archivo: ";
            str+= Archivo;
            str+= "\n";

            return str;
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

        bool operator == (const Tarea& t)const{
            return id == t.id;
        }
        bool operator != (const Tarea& t)const{
            return id != t.id;
        }

        bool operator <  (const Tarea& t)const{
            return id < t.id;
        }
        bool operator  > (const Tarea& t)const{
            return id > t.id;
        }
        bool operator <= (const Tarea& t)const{
            return id <= t.id;
        }
        bool operator >= (const Tarea& t)const{
            return id >= t.id;
        }
};



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

            return str;
        }
};



class Calificacion{
    private:
        ///Atributos
        float puntaje;
        std::string codigoAlumno;
        std::string codigoMateria;
    public:
        bool operator<(const Calificacion& s) const {
            return puntaje < s.puntaje;
        }
        bool operator>(const Calificacion& s) const {
            return puntaje > s.puntaje;
        }
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

            return str;
     }

};



class Participacion{
private:

    static int idAutoIncrement;
    int id;
    string codigo_estudiante;
    fecha fecha_de_participacion;
    string Codigo_de_curso;//Funcionara como NRC de materia
    int puntaje;

public:
    int getPuntaje(){
        return puntaje;
    }
    void setPuntaje(int p){
        puntaje = p;
    }
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
        str += "||Puntaje:";


        itoa(puntaje,aId,10);
        str += aId;


        return str;

    }

};



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


     List <Calificacion> getCalificaciones(){
        return calificaciones;
     }
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


void GeneraCalificacion(List<Materia> *LM,List<Participacion>&LP, List<Entrega>&LEntre)
{
    string NRC, CE;
    Materia materia;
    Materia * materia2;
    int porcentajeTareas=0;
    int porcentajeParticipacion=0;
    int promedioAlumnoParticipacion=0;
    int promedioAlumnoTareas=0;
    Participacion p;

        cout<<"Cual es el NRC de la materia?"<<endl;
        cin>>NRC;
        cout<<"Codigo de estudiante:"<<endl;
        cin>>CE;

        //obtenemos los porcentajes de la calificacion por tareas y participacion
            for(int c=0;c<LM->getSize();c++){
                materia=LM->retrieve(c);
                if(materia.getNRC()==NRC){
                        porcentajeTareas=materia.getPorcentajeTareas();
                        cout<<"Porcentaje de Tareas:"<<porcentajeTareas;
                        porcentajeParticipacion=materia.getPorcentajeParticipacion();
                        cout<<"Porcentaje de Participacion:"<<porcentajeParticipacion<<endl;
                }
            }


            if(porcentajeTareas>0 || porcentajeParticipacion  >0){
                int counter=0;
                int puntaje=0;
                int newPuntaje=0;


                //Sacamos el puntaje de todas las participaciones del alumno en la materia
                for(int c=0;c<LP.getSize();c++){
                    p=LP.retrieve(c);
                    if(p.get_CodigoDeCurso()==NRC && p.get_CodigoDeEstudiante()==CE){
                        cout<<"entrada found!"<<endl;
                        newPuntaje=p.getPuntaje();
                        puntaje+= newPuntaje;
                        cout<<newPuntaje<<endl;
                        counter++;
                    }
                }
                //si encontramos participaciones, sacamos promedio sino el valor quedara en cero
                if(counter>0){
                    promedioAlumnoParticipacion=puntaje/counter;
                 }

                 cout<<endl<<"Promedio Alumno Participacion: "<<promedioAlumnoParticipacion<<endl;

                //Ahora realizamos un proceso similar, pero ahora para las tareas.
                    counter=0;
                    puntaje=0;
                     int cTareas=LEntre.getSize();
                     for(int c=0;c<cTareas;c++){
                        Entrega p;

                        p=LEntre.retrieve(c);
                        if(p.getNRC()==NRC && p.getCodigoAlumno()==CE){
                           puntaje+= p.getPuntaje();
                           counter++;
                        }
                     }
                    if(counter>0){
                        promedioAlumnoTareas=puntaje/counter;
                    }

                    int promediofinal=promedioAlumnoParticipacion*porcentajeParticipacion/100  +promedioAlumnoTareas*porcentajeTareas/100 ;

                //agregar la calificacion a la lista en materia:  List <Calificacion> calificaciones;

                     for(int c=0;c<LM->getSize();c++){
                        materia2=LM->retrieve2(c);
                        if(materia2->getNRC()==NRC){
                         materia2->addCalificacion(promediofinal,CE,NRC);

                         cout<<endl<<"Calificacion Final Alumno "<<CE<<" en la materia "<<NRC<<" es: "<<promediofinal<<endl;
                                break;
                        }
                    }
            }
            else{
                   cout<<"No se han definido los criterios de evaluacion para tareas y participacion de la materia"<<endl;
            }
}


void  MuestraCalificacion(List<Materia>LM){
 string NRC, CE;
  int v;
   Materia materia;
   List<Calificacion> lCalificacion;

        cout<<"Cual es el NRC de la materia?"<<endl;
        cin>>NRC;
    //    cout<<"Codigo de estudiante:"<<endl;
    //    cin>>CE;


                 v=LM.getSize();
                    for(int c=0;c<v;c++){
                        materia=LM.retrieve(c);
                        if(materia.getNRC()==NRC){
                         cout<<endl<<"Calificaciones "<<endl;
                         lCalificacion=materia.getCalificaciones();
                        cout<< lCalificacion.toString();
                        cout<<endl;
                                break;
                        }
                    }
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
    m.set_NRC(Str);
   cin.ignore();

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

    m.set_Fecha_fin(f);
    fflush(stdin);
     cin.ignore();
    cout<<"Cuales dias se va a impartir la materia?"<<endl;

    getline(cin,Str);
    m.set_Dias(Str);
    cout<<"Cual es la seccion de la materia?"<<endl;
    cin>>Str;
    m.set_Seccion(Str);

    int criterio;
    cout<<"Criterios de evaluacion:"<<endl;
    cout<<"Porcentaje valido para tareas: "<<endl;
    cin>>criterio;
    m.setPorcentajeTareas(criterio);
    cout<<"Porcentaje valido para participacion: "<<endl;
    cin>>criterio;
    m.setPorcentajeParticipacion(criterio);

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

            cout<<"Cual es el id de la tarea?"<<endl;
            cin>>y;
            nueva.setId(y);
    fflush(stdin); cin.ignore();
            cout<<"Cual es el nombre de la tarea?"<<endl;
            getline(cin,Str);
            nueva.setNombre(Str);
            cout<<"Cual es la descripcion de la tarea?"<<endl;
            getline(cin,Str);
            nueva.setDesc(Str);
            cout<<"Cual es el archivo asignacion de la tarea?"<<endl;
            getline(cin,Str);
            nueva.setArchivoAsignacion(Str);
       //     cin.ignore();

            cout<<"Cual es la fecha de entrega de la tarea?"<<endl<<endl;
            cout<<"Escriba el dia (entero)"<<endl;
            cin>>datofecha;
            f.setDia(datofecha);
            cout<<"Escriba el mes(1-12)"<<endl;
            cin>>datofecha;
            f.setMes(datofecha);
            cout<<"Escriba el anio(2020)"<<endl;
            cin>>datofecha;
            f.setAnio(datofecha);
            cout<<"Escriba la hora (sin minutos)"<<endl;
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
    //int y;
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
            cout<<"Registre puntaje:"<<endl;
            cin>>id;
            nueva.setPuntaje(id);
            Tas.insertInList(nueva);
            cout<<"Participacion registrada"<<endl;
}

void modPa( List < Participacion>&Tas, int  idParticipacion){
    int datofecha;
    int indice(-1);
    string Str;
  //  int y;
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
    cout<<"Escriba el NRC de la materia ala que pertenece:"<<endl;
    cin>>strs;
    e.setNRC(strs);
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
    cout<<"Registre Calificacion:"<<endl;
    cin>>c;
    e.setPuntaje(c);
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
    int cx;
do{
    system(slimpial);;
    cout<<"Con que deseas trabajar?"<<endl;
    cout<<"1- Materias"<<endl;
    cout<<"2- Estudiantes"<<endl;
    cout<<"3- Tareas"<<endl;
    cout<<"4- Participaciones"<<endl;
    cout<<"5- Entregas de Tareas"<<endl,
    cout<<"6- Calificaciones"<<endl;
    cout<<"7- Salir"<<endl;
    cin>>x;
    cout<<endl;

    switch(x){
        system(slimpial);;
        case 1:
        do{
            system(slimpial);
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
                    system(slimpial);
                    case 1://-- Registra materia
                        ReMa(a, LM, f);
                        break;
                    case 2://-- Muestra la lista de materias
                        LM.print_list();
                        cin.ignore();

                        cx= getchar();
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
                       cout<<"Datos de la materia: "<<endl;
                        LM.print_list();
                        cin.ignore();

                      cout<<"Los estudiantes de la materia son: "<<LM.contador<<endl;
                      for(int x=1;x<=LM.contador;x++){
                           Materia m= LM.retrieve(x);

                           if(m.get_NRC()==Str){
                            m.printSE();
                           }

                        }
                         std::cout<<std::endl<<"Presione Enter para continuar"<<endl;
                        cx = getchar();

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
                        int c = getchar();
                        cout<<endl;
                        break;
                }
            }while(w!=7);
            break;

        case 2:
            do{
                system(slimpial);
                cout<<"Que desea realizar?"<<endl<<endl;
                cout<<"1.Registrar nuevo alumno"<<endl;
                cout<<"2.Ver todos los alumnos registrados"<<endl;
                cout<<"3.Salir"<<endl;
                cin>>w;
                    switch(w)
                    {
                        system(slimpial);
                        case 1:
                            ReEs(b, LE);
                            break;
                        case 2:
                            LE.print_list();
                              std::cout<<std::endl;
                        cx = getchar();
                            break;
                    }
            }while(w!=3);
            break;

        case 3:
            do{
                system(slimpial);
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
                        system(slimpial);
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
                system(slimpial);
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
                system(slimpial);
                cout<<"Entregas de Tareas"<<endl;
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
                        if( idEntrega != -1 ){//&& idEntrega < LEntre.getSize() ){
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
            do
            {
                system(slimpial);
                cout<<"Menu de Calificaciones"<<endl;
                cout<<"1- Generar Calificaciones Por Materia"<<endl;
                cout<<"2- Ordenar Por Materia"<<endl;
                cout<<"3- Mostrar Calificaciones Por Materia/Alumno ordenadas"<<endl;

                cout<<"4- Salir"<<endl;
                cin>>x;
                cout<<endl;

                switch(x){
                    case 1:{
                        GeneraCalificacion(&LM,LP,LEntre);
                    break;
                    }
                    case 2:{
                         cout<<"Ordenando las calificaciones..."<<endl;
                         for(int c=0;c<LM.getSize();c++){
                            LM.retrieve2(c)->getCalificaciones().ordena();
                        }
                        cout<<"Listo!"<<endl;
                    break;
                    }

                    case 3:{
                        MuestraCalificacion(LM);
                    break;
                    }

                }
            } while( x != 4);
            break;
        }
    }
}while(x!=7);

    return 0;
}
