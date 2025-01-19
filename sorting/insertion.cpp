#include<bits/stdc++.h>
using namespace std;

void myswap(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int insertion_sort(int arr[], int n){
    for (int i = 1; i < n; i++)
    {
        int j = i;
        while(j>0 && arr[j]<arr[j-1]){
            myswap(&arr[j],&arr[j-1]);
            j--;
        }
    }
       
}
int main(){
    // int arr[6] = {5,7,1,0,-2,3};
    int arr[] = {15, 3, 42, 8, 23, 7, 19, 56, 11, 37, 
                   9, 29, 5, 49, 21, 33, 2, 44, 17, 26};
    int n = sizeof(arr)/sizeof(arr[0]);
    insertion_sort(arr, n);
    for (int i = 0; i < n; i++) cout<<arr[i]<<",";

    return 0;
}