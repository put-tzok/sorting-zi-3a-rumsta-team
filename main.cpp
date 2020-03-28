#include <iostream>
#include <cstdlib>
#include <ctime>
#include <time.h>

using namespace std;

long n = 15000; //iloœæ elementów
bool wyswietlaj = 0; //w³¹cz wyœwietlanie

int generator();
int algorytm();
void zeruj(int T[]);
void wyswietl(int T[]);
void losowe(int T[]);
void rosnace(int T[]);
void malejace(int T[]);
void vShape(int T[]);
void swap(int *xp, int *yp);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
int partition(int arr[], int low, int high);
int partition_r(int arr[], int low, int high);
void quickSort_r(int arr[], int low, int high);
void quickSort(int arr[], int low, int high);
void heapSort(int arr[], int n);
void heapify(int arr[], int n, int i);



int main(int argc, char** argv) {
	int a,b;
	int tab[n];
	
	double roznica;
	cout.setf(ios::fixed); //notacja zwykla, czyli nie wywali wyniku typu 1.175000e+003	
	cout.precision(3); //liczba miejsc po przecinku, dokladnosc naszego wyniku	
	clock_t start, koniec; //inicjacja zmiennych zegarowych	
	
	zeruj(tab);
	
	srand((unsigned)time(NULL));
	do{
		a = generator();
		switch (a)
	    {
	       case 1:
		   		cout<<"Wartosci losowe"<<endl;
				losowe(tab);
				wyswietl(tab);
		   		b = algorytm();
		   		    switch (b)
	    			{
	       			case 1:		//Selection Sort
	       				wyswietl(tab);
	       				start = clock();
						selectionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
	              		break;
			       	case 2:		//Insertion Sort
			       		wyswietl(tab);
	       				start = clock();
						insertionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 3:		//Quick Sort (Ostatnia wartoœæ w tablicy jest elementem rozdzielaj¹cym)
			       		wyswietl(tab);
	       				start = clock();
						quickSort(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;	
			       	case 4:     //Quick Sort (Losowa wartoœæ z tablicy jest elementem rozdzielaj¹cym)    
					   	wyswietl(tab);
	       				start = clock();
						quickSort_r(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 5:    //Heap Sort
			       		wyswietl(tab);
	       				start = clock();
						heapSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;    
			           }
			break;
	       case 2:
	        	cout<<"Wartosci rosnace"<<endl;
	        	rosnace(tab);
	        	wyswietl(tab);
	        	b = algorytm();
		   		    switch (b)
	    			{
	       			case 1:		//Selection Sort
	       				wyswietl(tab);
	       				start = clock();
						selectionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
	              		break;
			       	case 2:		//Insertion Sort
			       		wyswietl(tab);
	       				start = clock();
						insertionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 3:		//Quick Sort (Ostatnia wartoœæ w tablicy jest elementem rozdzielaj¹cym)
			       		wyswietl(tab);
	       				start = clock();
						quickSort(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;	
			       	case 4:     //Quick Sort (Losowa wartoœæ z tablicy jest elementem rozdzielaj¹cym)    
					   	wyswietl(tab);
	       				start = clock();
						quickSort_r(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 5:    //Heap Sort
			       		wyswietl(tab);
	       				start = clock();
						heapSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;    
			           }
			break;
	       case 3:
		   		cout<<"Wartosci malejace"<<endl;
		   		malejace(tab);
		   		wyswietl(tab);
		   		b = algorytm();
		   		    switch (b)
	    			{
	       			case 1:		//Selection Sort
	       				wyswietl(tab);
	       				start = clock();
						selectionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
	              		break;
			       	case 2:		//Insertion Sort
			       		wyswietl(tab);
	       				start = clock();
						insertionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 3:		//Quick Sort (Ostatnia wartoœæ w tablicy jest elementem rozdzielaj¹cym)
			       		wyswietl(tab);
	       				start = clock();
						quickSort(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;	
			       	case 4:     //Quick Sort (Losowa wartoœæ z tablicy jest elementem rozdzielaj¹cym)    
					   	wyswietl(tab);
	       				start = clock();
						quickSort_r(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 5:    //Heap Sort
			       		wyswietl(tab);
	       				start = clock();
						heapSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;    
			           }
		   	break;
	       case 4:
	       		cout<<"Rozklad V-ksztaltny"<<endl;
	       		vShape(tab);
	       		wyswietl(tab);
	       		b = algorytm();
		   		    switch (b)
	    			{
	       			case 1:		//Selection Sort
	       				wyswietl(tab);
	       				start = clock();
						selectionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
	              		break;
			       	case 2:		//Insertion Sort
			       		wyswietl(tab);
	       				start = clock();
						insertionSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 3:		//Quick Sort (Ostatnia wartoœæ w tablicy jest elementem rozdzielaj¹cym)
			       		wyswietl(tab);
	       				start = clock();
						quickSort(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;	
			       	case 4:     //Quick Sort (Losowa wartoœæ z tablicy jest elementem rozdzielaj¹cym)    
					   	wyswietl(tab);
	       				start = clock();
						quickSort_r(tab, 0, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;
			       	case 5:    //Heap Sort
			       		wyswietl(tab);
	       				start = clock();
						heapSort(tab, n);
						koniec=clock();//zapisanie konca mierzenia	
						roznica=(koniec-start)/(double)CLOCKS_PER_SEC;//obliczenie roznicy, czyli czasu wykonania
						wyswietl(tab);
						cout<<"Czas wykonania: "<<roznica<<endl;
			            break;    
			           }
		   break;   
	           }
	system("pause");
	system("cls");
	}while(a!=5);
	return 0;
}

int generator(){
	int x = 0; 
    while(x>5 || x<1)
    {
    cout<<"Wybierz generator liczb:"<<endl;
    cout<<endl;
    cout<<"1. Wartosci losowe"<<endl;
    cout<<"2. Wartosci rosnace"<<endl;
    cout<<"3. Wartosci malejace"<<endl;
    cout<<"4. Rozklad V-ksztaltny"<<endl;
    cout<<"5. Wylacz program"<<endl;
    cout<<endl;
    cout<<"Wybieram : ";
    cin>>x;
    system("cls");
     }
    return x;
}
int algorytm(){
	int x = 0; 
    while(x>5 || x<1)
    {
    cout<<"Wybierz algorytm:"<<endl;
    cout<<endl;
    cout<<"1. Selection Sort"<<endl;
    cout<<"2. Insertion Sort"<<endl;
    cout<<"3. Quick Sort (Ostatnia wartosc w tablicy jest elementem rozdzielajacym)"<<endl;
    cout<<"4. Quick Sort (Losowa wartosc z tablicy jest elementem rozdzielajacym)"<<endl;
    cout<<"5. Heap Sort"<<endl;
    cout<<endl;
    cout<<"Wybieram : ";
    cin>>x;
    system("cls");
     }
    return x;
}
void zeruj(int T[]){
	for(int i =0; i < n; i++){
		T[i] = 0;
	}
}
void wyswietl(int T[]){
	if(wyswietlaj==1){
		cout<<endl;
		for(int i = 0; i < n; i++){
			cout<<T[i]<<" ";
		}
	}
	cout<<endl<<endl;
}
void losowe(int T[]){
	for(int i =0; i < n; i++)
       {
        T[i] = 1 + rand() %100;
       }
}
void rosnace(int T[]){
	int x = 1 + rand()%10;
	T[0] = 0 + x;
	for(int i = 1; i < n ; i++)
       {
       	x = 1+ rand()%10;
        T[i] = T[i-1] + x;
        }
}
void malejace(int T[]){
	int x = 1+ rand()%10;
	T[0] = (10 * n) - x;
	for(int i = 1; i < n; i++)
        {
        x = 1 + rand()%10;
        T[i] = T[i-1] - x;
        }
}
void vShape(int T[]){
	int x = 1 + rand()%10;
	T[0] = (10 * n) - x;
	for(int i = 1; i< n/2; i++)
        {
        x = 1 + rand()%10;
        T[i] = T[i-1] - x;
        }

	for(int i = n/2; i < n ; i++)
       {
        x = 1 + rand()%10;
        T[i] = T[i-1] + x;
        }
}
void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void selectionSort(int arr[], int n)  
{  
    int i, j, min_idx;  
  
    // One by one move boundary of unsorted subarray  
    for (i = 0; i < n-1; i++)  
    {  
        // Find the minimum element in unsorted array  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        // Swap the found minimum element with the first element  
        swap(&arr[min_idx], &arr[i]);  
    }  
}
void insertionSort(int arr[], int n)  
{  
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
  
        /* Move elements of arr[0..i-1], that are  
        greater than key, to one position ahead  
        of their current position */
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    }  
}
/* This function takes last element as pivot, places 
  the pivot element at its correct position in sorted 
  array, and places all smaller (smaller than pivot) 
  to left of pivot and all greater elements to right 
  of pivot */
int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element 
  
    for (int j = low; j <= high - 1; j++) { 
  
        // If current element is smaller than or 
        // equal to pivot 
        if (arr[j] <= pivot) { 
  
            i++; // increment index of smaller element 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 
  
// Generates Random Pivot, swaps pivot with 
// end element and calls the partition function 
int partition_r(int arr[], int low, int high) 
{ 
    // Generate a random number in between 
    // low .. high 
    srand(time(NULL)); 
    int random = low + rand() % (high - low); 
  
    // Swap A[random] with A[high] 
    swap(arr[random], arr[high]); 
  
    return partition(arr, low, high); 
} 
  
/* The main function that implements QuickSort 
arr[] --> Array to be sorted, 
low --> Starting index, 
high --> Ending index */
void quickSort_r(int arr[], int low, int high) 
{ 
    if (low < high) { 
  
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition_r(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void quickSort(int arr[], int low, int high) 
{ 
    if (low < high) { 
  
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; // Initialize largest as root 
    int l = 2*i + 1; // left = 2*i + 1 
    int r = 2*i + 2; // right = 2*i + 2 
  
    // If left child is larger than root 
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    // If right child is larger than largest so far 
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    // If largest is not root 
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
  
        // Recursively heapify the affected sub-tree 
        heapify(arr, n, largest); 
    } 
} 
  
// main function to do heap sort 
void heapSort(int arr[], int n) 
{ 
    // Build heap (rearrange array) 
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    // One by one extract an element from heap 
    for (int i=n-1; i>=0; i--) 
    { 
        // Move current root to end 
        swap(arr[0], arr[i]); 
  
        // call max heapify on the reduced heap 
        heapify(arr, i, 0); 
    } 
}
