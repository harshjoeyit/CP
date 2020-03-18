#include<stdio.h>

int left(int i)
{
	return 2*i + 1;
}

int right(int i)
{
	return 2*i + 2;
}

void Swap(int a[], int i, int largest)
{
	int t = a[i];
	a[i] = a[largest];
	a[largest] = t;
}

void max_heapify(int a[], int n, int i)
{
	int l = left(i), r = right(i);
	int largest = i;
	
	if(l <= n && a[l] > a[largest])
		largest = l;
	if(r <= n && a[r] > a[largest])
		largest = r;
	if(largest != i)
	{
		Swap(a, i, largest);
		max_heapify(a, n, largest);
	}
}

void build_max_heap(int a[], int n)
{
	int x = (n-1)/2;
	while(x >= 0)
	{
		max_heapify(a, n, x);
		x--;
	}
}

void Print(int a[], int n)
{
	for(int i = 0; i <= n; i++)
		printf("%d ", a[i]);
	
	printf("\n");
}

void heapsort(int a[], int n)
{
	build_max_heap(a, n);
	while(n > 0)
	{
		Swap(a, 0, n);
		n--;
		max_heapify(a, n, 0);
	}
}

int main()
{
	// n is the last index
	int a[] = {3,11,15,2,7,8,21,32,0};
	int n = sizeof(a)/sizeof(int)-1;
	Print(a, n);
	heapsort(a, n);
	Print(a,n);
}


