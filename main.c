#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctime>

using namespace std;

unsigned int ns[] = { 100, 1000, 10000, 15000, 20000, 22000, 25000 };

void fill_increasing(int *t, unsigned int n) {
    int x = 1 + rand()%10;
	t[0] = 0 + x;
	for(int i = 1; i < n ; i++)
       {
       	x = 1+ rand()%10;
        t[i] = t[i-1] + x;
        }
}

void fill_decreasing(int *t, unsigned int n) {
    int x = 1+ rand()%10;
	t[0] = (10 * n) - x;
	for(int i = 1; i < n; i++)
        {
        x = 1 + rand()%10;
        t[i] = t[i-1] - x;
        }
}

void fill_vshape(int *t, unsigned int n) {
    int x = 1 + rand()%10;
	t[0] = (10 * n) - x;
	for(int i = 1; i< n/2; i++)
        {
        x = 1 + rand()%10;
        t[i] = t[i-1] - x;
        }

	for(int i = n/2; i < n ; i++)
       {
        x = 1 + rand()%10;
        t[i] = t[i-1] + x;
        }
}

void swap(int *xp, int *yp)  
{  
    int temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}

void selection_sort(int *t, unsigned int n) {
    int i, j, min_idx;  
  
    for (i = 0; i < n-1; i++)  
    {  
        min_idx = i;  
        for (j = i+1; j < n; j++)  
        if (arr[j] < arr[min_idx])  
            min_idx = j;  
  
        swap(&arr[min_idx], &arr[i]);  
    }
}

void insertion_sort(int *t, unsigned int n) {
    int i, key, j;  
    for (i = 1; i < n; i++) 
    {  
        key = arr[i];  
        j = i - 1;  
        while (j >= 0 && arr[j] > key) 
        {  
            arr[j + 1] = arr[j];  
            j = j - 1;  
        }  
        arr[j + 1] = key;  
    } 
}

int partition(int arr[], int low, int high) 
{ 
    int pivot = arr[high]; 
    int i = (low - 1);
  
    for (int j = low; j <= high - 1; j++) { 
  
        if (arr[j] <= pivot) { 
  
            i++;
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i + 1], arr[high]); 
    return (i + 1); 
} 

void quick_sort(int *t, unsigned int n) {
    int low = 0;
    int high = n;
    if (low < high) { 
  
        int pi = partition(arr, low, high); 
  
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
}
void heapify(int arr[], int n, int i) 
{ 
    int largest = i; 
    int l = 2*i + 1;  
    int r = 2*i + 2;  
   
    if (l < n && arr[l] > arr[largest]) 
        largest = l; 
  
    if (r < n && arr[r] > arr[largest]) 
        largest = r; 
  
    if (largest != i) 
    { 
        swap(arr[i], arr[largest]); 
        heapify(arr, n, largest); 
    } 
} 

void heap_sort(int *t, unsigned int n) {
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i); 
  
    for (int i=n-1; i>=0; i--) 
    { 
        swap(arr[0], arr[i]); 

        heapify(arr, i, 0); 
    }
}

void fill_random(int *t, unsigned int n) {
    for (unsigned int i = 0; i < n; i++) {
        t[i] = rand();
    }
}

void is_random(int *t, unsigned int n) {
    return;
}

void is_increasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] > t[i - 1]);
    }
}

void is_decreasing(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] < t[i - 1]);
    }
}

void is_vshape(int *t, unsigned int n) {
    int *begin = t;
    int *end = t + n - 1;

    while (end - begin > 1) {
        assert(*begin > *end);
        begin++;
        assert(*end > *begin);
        end--;
    }
}

void is_sorted(int *t, unsigned int n) {
    for (unsigned int i = 1; i < n; i++) {
        assert(t[i] >= t[i - 1]);
    }
}

void (*fill_functions[])(int *, unsigned int) = { fill_random, fill_increasing, fill_decreasing, fill_vshape };
void (*check_functions[])(int *, unsigned int) = { is_random, is_increasing, is_decreasing, is_vshape };
void (*sort_functions[])(int *, unsigned int) = { selection_sort, insertion_sort, quick_sort, heap_sort };

char *fill_names[] = { "Random", "Increasing", "Decreasing", "V-Shape" };
char *sort_names[] = { "SelectionSort", "InsertionSort", "QuickSort", "HeapSort" };

int main() {
    srand((unsigned)time(NULL));
    for (unsigned int i = 0; i < sizeof(sort_functions) / sizeof(*sort_functions); i++) {
        void (*sort)(int *, unsigned int) = sort_functions[i];

        for (unsigned int j = 0; j < sizeof(fill_functions) / sizeof(*fill_functions); j++) {
            void (*fill)(int *, unsigned int) = fill_functions[j];
            void (*check)(int *, unsigned int) = check_functions[j];

            for (unsigned int k = 0; k < sizeof(ns) / sizeof(*ns); k++) {
                unsigned int n = ns[k];
                int *t = malloc(n * sizeof(*t));

                fill(t, n);
                check(t, n);

                clock_t begin = clock();
                sort(t, n);
                clock_t end = clock();
                is_sorted(t, n);

                printf("%s\t%s\t%u\t%f\n", sort_names[i], fill_names[j], n, (double)(end - begin) / (double) CLOCKS_PER_SEC);
                free(t);
            }
        }
    }
    return 0;
}
