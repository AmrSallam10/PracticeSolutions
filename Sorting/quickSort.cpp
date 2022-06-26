#include<bits/stdc++.h>
using namespace std;

// middle as the pivot
void quickSort(int arr[], int low, int high)
{
    int idx = low + (high-low)/2;
    int pivot = arr[idx];
    int i = low;
    int j = high;

    while (i <= j)
    {  
        while(arr[i] < pivot) i++;
        while (arr[j] > pivot) j--;
        if(i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    
    if(low < j) quickSort(arr,low, j);
    if (high > i) quickSort(arr, i, high);
}


// first element as the pivot
// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[low];
//     int i = low;
//     int j = high;

//     while (i < j)
//     {  

//         while(arr[i] <= pivot)
//             i++;

//         while (arr[j] > pivot)
//             j--;

//         if(i < j)
//             swap(arr[i], arr[j]);
//     }
//     swap(arr[low], arr[j]);
//     return j;
// }


// last element as the pivot
// int partition(int arr[], int low, int high)
// {
//     int pivot = arr[high];
//     int i = low - 1;

//     for (int j = low ; j < high; j++)
//     {
//         if(arr[j] < pivot)
//         {
//             i++;
//             swap(arr[i], arr[j]);
//         }
//     }
//     swap(arr[i+1], arr[high]);
//     return (i+1);
// }

// void quickSort(int arr[], int low, int high)
// {
//     if(low >= high) return;

//     int p = partition(arr, low, high);
//     quickSort(arr, low, p-1);
//     quickSort(arr, p+1, high);
// }

int main()
{
    int arr[] = {2,3,1,5,3,6,19,0};
    int size = sizeof(arr)/sizeof(int);
    
    quickSort(arr, 0, size-1);

    for (int i = 0; i <size ; i++)   
        cout<<arr[i]<<" ";

    return 0;
}