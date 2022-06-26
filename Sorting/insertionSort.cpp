#include<bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int size)
{
    int i, j, key;

    for (i = 1 ; i < size ; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j+1] = arr[j];
            j--;
        } 
        arr[j+1] = key;
    }
}

int main()
{
    int arr[] = {2,3,1,5,3,6,19,0};
    int size = sizeof(arr)/sizeof(int);
    
    insertionSort(arr, size);

    for (int i = 0; i <size ; i++)   
        cout<<arr[i]<<" ";

    return 0;
}