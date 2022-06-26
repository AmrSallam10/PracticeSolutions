#include<bits/stdc++.h>
using namespace std;

void selectionSort(int arr[], int size)
{
    for (int i =0 ; i< size -1; i++)
        for(int j = i + 1 ; j < size ; j++)
            if(arr[j]<arr[i])
            {
                arr[i] = arr[i] ^ arr[j];
                arr[j] = arr[i] ^ arr[j];
                arr[i] = arr[i] ^ arr[j];
            }
}

int main()
{
    int arr[] = {2,3,1,5,3,6,19,0};
    int size = sizeof(arr)/sizeof(int);
    
    selectionSort(arr, size);

    for (int i = 0; i <size ; i++)   
        cout<<arr[i]<<" ";

    return 0;
}