#include <iostream>
#include <random>

void * bubbleSort(void * arr, void (*ptrFunc) (void *, int _i, int _k), int n) {
	for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
			ptrFunc(arr,i,j);
	return arr;
}

void typeInt(void * _vector_, int _i,int _k) {
	if (((int *)_vector_)[_k] < ((int *)_vector_)[_i]) {
        // Swap elements
        int temp = ((int *)_vector_)[_i];
        ((int *)_vector_)[_i] = ((int *)_vector_)[_k];
        ((int *)_vector_)[_k] = temp;
    }
}

void typeFloat(void * _vector_, int _i,int _k) {
	if (((float *)_vector_)[_k] < ((float *)_vector_)[_i]) {
        // Swap elements
        float temp = ((float *)_vector_)[_i];
        ((float *)_vector_)[_i] = ((float *)_vector_)[_k];
        ((float *)_vector_)[_k] = temp;
    }
}

void typeDouble(void * _vector_, int _i,int _k){
	if (((double *)_vector_)[_k] < ((double *)_vector_)[_i]) {
        // Swap elements
        double temp = ((double *)_vector_)[_i];
        ((double *)_vector_)[_i] = ((double *)_vector_)[_k];
        ((double *)_vector_)[_k] = temp;
    }
}

void typeChar(void * _vector_, int _i,int _k){
	if (((char *)_vector_)[_k] < ((char *)_vector_)[_i]) {
        // Swap elements
        char temp = ((char *)_vector_)[_i];
        ((char *)_vector_)[_i] = ((char *)_vector_)[_k];
        ((char *)_vector_)[_k] = temp;
    }
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
	if (std::is_same<T, int>::value) {
		static std::uniform_int_distribution<> dist100(0, 100);
		for(int i = 0; i <= n; ++i)
			arr[i] = dist100(rng);
	} else if (std::is_same<T, char>::value) {
		static std::uniform_int_distribution<> dist26(0, 26);
		for(int i = 0; i <= n; ++i)
			arr[i] = 'a' + dist26(rng);
	} else {
		static std::uniform_real_distribution<> dist100(0, 100);
		for(int i = 0; i <= n; ++i)
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