#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

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

#endif // NODO_H_INCLUDED
