#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <iostream>
#include "nodo.h"

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
	    std::cout<<std::endl;
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


#endif // LSITA_H_INCLUDED
