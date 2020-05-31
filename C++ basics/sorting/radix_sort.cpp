#include <stdio.h> 
#include <time.h>

int getMax(int arr[], int n) 
{ 
    int maximum = arr[0];
    int i; 
    for (i = 1; i < n; i++) 
        if (arr[i] > maximum) 
            maximum = arr[i]; 
    return maximum; 
} 
  
void countSort(int arr[], int n, int exp) 
{ 
    int output[n]; 
    int i, count[10] = {0}; 
    
    for (i = 0; i < n; i++) 
        count[ (arr[i]/exp)%10 ]++;  //build count arrray
  
    for (i = 1; i < 10; i++) 
        count[i] += count[i - 1]; 
  
     for (i = n - 1; i >= 0; i--) 
    { 
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i]; 
        count[ (arr[i]/exp)%10 ]--; 
    } 
  
    for (i = 0; i < n; i++) 
        arr[i] = output[i]; 
} 
  
void radixsort(int arr[], int n) 
{ 
    int m = getMax(arr, n); //find max no.
  	int exponent;
    for (exponent = 1; m/exponent > 0; exponent *= 10) 
        countSort(arr, n, exponent); 
} 
 
int main() 
{ 
	int i=0,n=0;
	clock_t starttime, endtime; //to calculte exe time
 
	double totaltime; 
	int arr[1000000]; 

	FILE* fptr,*fptr1; 
	fptr = fopen("random.txt", "r"); 
    fptr1 = fopen("radix.txt", "a");

	while (fscanf(fptr, "%d", &arr[i]) == 1) 
	{ 
		n++; 
		i++; 
	} 
    
	starttime = clock(); 
	radixsort(arr,n);
	endtime = clock(); 

	totaltime = ((double)(endtime - starttime)) / CLOCKS_PER_SEC; 

	for (i = 0; i < n; i++) 
		printf("%d ", arr[i]);
		
			fprintf(fptr1, "%d ", n);
	fprintf(fptr1, "%f\n ",totaltime); 

	printf("\n\ntotal time of execution = %f", totaltime); 

	return 0; 
} 

