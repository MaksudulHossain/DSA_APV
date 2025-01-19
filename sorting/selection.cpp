#include <bits/stdc++.h>
using namespace std;

void myswap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void selection_sort(int arr[], int n){
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i; j<n; j++){
            if(arr[j]<arr[min_idx]) min_idx=j;
        }
        myswap(&arr[min_idx], &arr[i]);
    }
}
int main(){

    // int arr[6] = {5,7,1,0,-2,3};
    int arr[] = {15, 3, 42, 8, 23, 7, 19, 56, 11, 37, 
                   9, 29, 5, 49, 21, 33, 2, 44, 17, 26};

    int n = sizeof(arr)/sizeof(arr[0]);
    selection_sort(arr, n);
    for (int i = 0; i < n; i++) cout<<arr[i]<<",";


    return 0;
}