#include<bits/stdc++.h>
using namespace std;

void bubbleSort(int arr[], int size)
{
    for (int i = 0 ; i < size - 1 ; i++)
        for(int j = 0 ; j < size - i - 1 ; j++)
            if(arr[j+1]<arr[j])
                swap(arr[j], arr[j+1]);
}

int main()
{
    int arr[] = {2,3,1,5,3,6,19,0};
    int size = sizeof(arr)/sizeof(int);
    
    bubbleSort(arr, size);

    for (int i = 0; i <size ; i++)   
        cout<<arr[i]<<" ";

    return 0;
}