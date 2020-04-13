#include <iostream>
#include <random>

void * bubbleSort(void * arr, void (*ptrFunc) (void *, int _i, int _k), int n) {
	for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
			ptrFunc(arr,i,j);
	return arr;
}

void typeInt(void * _vector_, int _i,int _k) {
	// Cast vector as an int array
	int *v = (int *)_vector_;
	
	// BubbleSort conditional
	if (v[_k] < v[_i]) {
        // Swap elements
        int temp = v[_i];
        v[_i] = v[_k];
        v[_k] = temp;
    }

	// Return changes to original vector
	_vector_ = v;
}

void typeFloat(void * _vector_, int _i,int _k) {
	// Cast vector as an float array
	float *v = (float *)_vector_;
	
	// BubbleSort conditional
	if (v[_k] < v[_i]) {
        // Swap elements
        float temp = v[_i];
        v[_i] = v[_k];
        v[_k] = temp;
    }

	// Return changes to original vector
	_vector_ = v;
}

void typeDouble(void * _vector_, int _i,int _k){
	// Cast vector as an float array
	double *v = (double *)_vector_;
	
	// BubbleSort conditional
	if (v[_k] < v[_i]) {
        // Swap elements
        double temp = v[_i];
        v[_i] = v[_k];
        v[_k] = temp;
    }

	// Return changes to original vector
	_vector_ = v;
}

void typeChar(void * _vector_, int _i,int _k){
	// Cast vector as an float array
	char *v = (char *)_vector_;
	
	// BubbleSort conditional
	if (v[_k] < v[_i]) {
        // Swap elements
        char temp = v[_i];
        v[_i] = v[_k];
        v[_k] = temp;
    }

	// Return changes to original vector
	_vector_ = v;
}

template<typename T, size_t n>
void printArray(T const(& arr)[n]) {
	for (size_t i = 0; i < n; ++i) 
		std::cout << arr[i] << ' ';
	std::cout << '\n';
}

template<typename T, size_t n>
void randomArray(T (& arr)[n]) {
	// Generate random seed
	std::random_device dev;
    std::mt19937 rng(dev());

	// Generate distribution in range [0, 100]
	if (std::is_same<T, char>::value) {
		static std::uniform_int_distribution<> dist26(0, 26);
		for(int i = 0; i < n; ++i)
			arr[i] = 'a' + dist26(rng);
	} else {
		static std::uniform_real_distribution<> dist100(0, 100);
		for(int i = 0; i < n; ++i)
			arr[i] = dist100(rng);
	}
}

int main(){
	#define SIZE1 5
	#define SIZE2 5
	#define SIZE3 5
	#define SIZE4 5
	
	int arr1[SIZE1]; randomArray(arr1);
	float arr2[SIZE2]; randomArray(arr2);
	double arr3[SIZE3]; randomArray(arr3);
	char arr4[SIZE4]; randomArray(arr4);

	bubbleSort(arr1, typeInt, SIZE1);		
	std::cout << std::endl << "BubbleSort - Int:" << std::endl; 
	printArray(arr1);
	
	bubbleSort(arr2, typeFloat, SIZE2);
	std::cout << std::endl << "BubbleSort - Float:" << std::endl;
	printArray(arr2);

	bubbleSort(arr3, typeDouble, SIZE3);
	std::cout << std::endl << "BubbleSort - Double:" << std::endl;
	printArray(arr3);

	bubbleSort(arr4, typeChar, SIZE4);
	std::cout << std::endl << "BubbleSort - Char:" << std::endl;
	printArray(arr4);

    return 0;
}