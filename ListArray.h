#include "List.h"

template <typename T> 
class ListArray {
	private:
		T* arr;
		int max;
		int n;
		static const int MINSIZE=2;
		
		void resize(int new_size){
		//to do:
		}

	public:
		ListArray(){
			this->arr=new T[MINSIZE];
			this->max=MINSIZE;
			this->n=0;
		}
		~ListArray(){
			delete this->arr;
		}
		T operator[](int pos){
			return this->get(pos);//to do
		}
		friend std::ostream& operator<<(std::ostream &out, const ListArray<T> &list){
		//to do
		}

};

