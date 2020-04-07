# cs2100-PointerFuncs

# Work!
Los punteros función pueden ayudar a simular poli-morfismo! Vamos a divertirnos haciendo la función  /bubblesort/  usando punteros a función. 

### Structure

```
#include <iostream>
using namespace std;

void * _bubblesort_(
	void * _array_, 
	void (*_puntero_) (void *, int _i, int _k),
	int _tam_
){
	int _k = 0;
	for (int i = 0; i < _tam_ ; i ++)
		for(int k = 0; k < _tam_-1; k++)
			_puntero_(_array_,k,_k);
	return _array_;
}

void  _b_int_ (void * _vector_, int _i,int _k){
 // TODO:  QUE COSA PONGO AQUI?
}

void  _b_float_ (void * _vector_, int _i,int _k){
 // TODO:  QUE COSA PONGO AQUI?
}

void  _b_double_ (void * _vector_, int _i,int _k){
 // TODO:  QUE COSA PONGO AQUI?
}

void  _b_char_ (void * _vector_, int _i,int _k){
 // TODO:  QUE COSA PONGO AQUI?
}

int main(){
	int i = 0;
	int _array_1 [5] = {2,20,7,108,9}; // RANDOMS
	float _array_2 [5] = {4.4,5.4,9.1,7.4,2.2};
	double _array_3 [5] = {3.0,8.0,2.0,4.0,15.0};
	char _array_4 [6] = {'k','a','r','l','o','s'};

	_bubblesort_(_array_1,_b_int_,5);	
	// PRINT
	_bubblesort_(_array_2,_b_float_,5);
	// PRINT
	_bubblesort_(_array_3,_b_double_,5);
	// PRINT
	_bubblesort_(_array_4,_b_char_,6);
	// PRINT

    return 0;
}

```

