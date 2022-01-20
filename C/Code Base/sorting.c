

// ----------- Bubble sort -----------
// check 0 & 1, change if 0 > 1.
// check 1 & 2, --- || ---
// when end is reached start from begining again.
// Not Stable

#include <stdio.h>
#include <stdbool.h>
void bubbleSort(int arr[], int n){
    
    bool swapped;
    for(int i = 0; i < n; i++){
        
        swapped = false;
        for(int j = 0 ; j < n - i - 1; j++){
            if( arr[j] > arr[j+1]){
                
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                
                swapped = true;
            }
        }
        
        if( swapped == false)
        break;
    }
}

int main(void) {
	int a[] = {2, 1, 3, 4};
	bubbleSort(a, 4);
	for(int i = 0; i < 4; i++){
	    printf("%d ", a[i]);
	}
	return 0;
}


// ----------- Selection Sort -----------
// Does less memory writes compared to quicksort, mergesort, insertion sort, etc.
// but cycle sort is optimal in terms of memory writes.
// Basic idea for Heapsort.
// Not stable.

// in-Place Implementation (does not use a temp array to write to and copy from):
void selectionSort(int arr[], int n){
    
    for(int i = 0; i < n; i++){
        int min_ind = i;
        
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[min_ind]){
                min_ind = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_ind];
        arr[min_ind] = temp;
    }
    
    
}

int main(void) {
	int a[] = {2, 1, 3, 4};
	selectionSort(a, 4);
	for(int i = 0; i < 4; i++){
	    printf("%d ", a[i]);
	}
	return 0;
}


// ----------- Insirtion Sort -----------
// In-Place and Stable
// Used in practice for small arrays (Timsort and IntroSort)

// [20, 5, 40, 10, 30]
// [5, 20, 40, 10, 30]
// [5, 20, 40, 10, 30]
// [5, 10, 20, 40, 30]
// [5, 10, 20, 30, 40]


void iSort(int arr[],int n){
    
    for(int i = 1; i < n; i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}

int main() {
	
    int arr[]={50,20,40,60,10,30};
	
	int n = sizeof(arr) / sizeof(arr[0]);
	iSort(arr, n);
	
	for(int i = 0; i < n; i++)
	    printf("%d ", arr[i]);
}


// ----------- Merge Sort -----------
// given 2 sorted arrays, merge these in a non-decreasing manner.
// Divide and Conquer Algorithm
// Stable,
// O(n log n) time and O(n) Aux space.
// Well suited for linked lists. Works in O(1) Aux space.
// Used in External Sorting.
// In general for arrays, Quicksort outperforms this.

#include <stdlib.h>
int* merge(int a1[],int m,int a2[],int n)
{
    int* finalarray= malloc((m+n) * sizeof(int));
    int i=0,j=0,k=0;
    
    while(i<m&&j<n)
    {
        if(a1[i]<a2[j])
        {
            finalarray[k]=a1[i];
            i++;
            k++;
        }
        else
        {
            finalarray[k]=a2[j];
            j++;
            k++;
        }
    }
    while(i<m)
    {
        finalarray[k]=a1[i];
        i++;
        k++;
    }
    while(j<n)
    {
        finalarray[k]=a2[j];
        j++;
        k++;
    }
    
    return finalarray;
}
  
int main() 
{
    int m, n;
    scanf("%d", &m);
    scanf("%d", &n);

    int a1[m], a2[n];    // This should be okay in todays C compilers.

    for(int i=0;i<m;i++)
    {
        scanf("%d",&a1[i]);
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a2[i]);
    }
    
    int* a3= malloc((m+n) * sizeof(int));
    a3=merge(a1,m,a2,n);
    
    for(int i=0;i<(m+n);i++)
    {
        printf("%d ",a3[i]);
    }
    
	return 0;
}

// ----------- Merge Sort Recursively: -----------
// divide array in middle and merge sort the left array.
// redo until last element found.
void merge(int arr[], int l, int m, int h){
    
    int n1 = m - l + 1, n2 = h - m;
    int left[n1], right[n2];    // This should be okay in todays C compilers.
    for(int i = 0; i < n1; i++)
        left[i] = arr[i+l];
    for(int j = 0; j < n2; j++)
        right[j] = arr[m+1+j];    
    int i = 0, j = 0, k = l;
    while(i < n1 && j < n2){
        if(left[i] <= right[j])
            arr[k++] = left[i++];
        else
            arr[k++] = right[j++];
    }
    while(i < n1)
        arr[k++] = left[i++];
    while(j < n2)
        arr[k++] = right[j++];    
}

void mergeSort(int arr[],int l,int r){
    if(r > l){
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);       // left-half
        mergeSort(arr, m + 1, r);   // right-half
        merge(arr, l, m, r);        // merge what is left
    }
}

int main() {
	
    int a[]={10,5,30,15,7};
	int l = 0, r = 4;
	
	mergeSort(a, l, r);
	for(int i = 0; i <= r; i++)
	    printf("%d ", a[i]);
}


// ----------- Naive partition -----------
// Stable
// inefficient from Lomute and Hoare.
