/*
@author: rj
Topic: Implementation of Heap Sort and finding the min and max value
*/

#include <iostream>
using namespace std;

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

void heapSort(int arr[], int n)
{
	for (int i = n / 2 - 1; i >= 0; i--)
		heapify(arr, n, i);
	for (int i=n-1; i>=0; i--)
	{
		swap(arr[0], arr[i]);
		heapify(arr, i, 0);
	}
	
	cout << "\nSORTED ARRAY :-" <<endl;
	for(int i=0;i<n;i++)
	{
		cout << arr[i] << "\t";
	}
}
int main()
{
    int n,arr[100];
	cout<<"Enter the no. of student's marks you want to enter. :\n";
	cin>>n;
	cout<<"Enter the marks :\n";
	for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
	heapSort(arr, n);
	cout << "\nThe maximum marks are: "<<arr[n-1]<<endl;
	cout<<"\nThe minimum marks are: "<<arr[0]<<"\n";
	return 0;
}
