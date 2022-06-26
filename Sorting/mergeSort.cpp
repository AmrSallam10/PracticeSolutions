#include<bits/stdc++.h>
using namespace std;

void merge(int arr[], const int l, const int mid, const int r)
{
    int sizeA = mid - l + 1;
    int sizeB = r - mid;
    int i = 0, j = 0, mergedIdx = l;

    int *a = new int[sizeA];
    int *b = new int[sizeB];

    for (int k = 0 ; k < sizeA; k++)
        a[k] = arr[l + k];

    for (int k = 0 ; k < sizeB; k++)
        b[k] = arr[mid + 1+ k];
 

    while (i < sizeA && j < sizeB)
    {
        if(a[i] < b[j])
            arr[mergedIdx++] = a[i++];
        else 
            arr[mergedIdx++] = b[j++];    
    }

    while (i < sizeA)
        arr[mergedIdx++] = a[i++];
    
    while (j < sizeB)
        arr[mergedIdx++] = b[j++];

    delete[] a;
    delete[] b;
}


void mergeSort(int arr[], const int l, const int r)
{
    if (l >= r) return;

    int mid = l + (r - l)/2;

    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    merge(arr, l, mid, r);
}

int main()
{   

    int arr[]= {2,8,5,3,9,4,1,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr, 0, size - 1);

    for (int i = 0 ; i < size ; i++)
        cout<<arr[i]<<" ";

    return 0;
}