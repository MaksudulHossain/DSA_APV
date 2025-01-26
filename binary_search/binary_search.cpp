#include<bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int n, int target){
    // {1,2,3,4,5,6,7}
    int left, right;
    left = 0;
    right = n-1;
    bool found = false;
    while (left<=right)
    {
        
        int mid = (left + right)/2;
        if(arr[mid]==target){
            found = true;
            return mid;
        }
        else if(arr[mid]>target) right=mid-1;
        else left=mid+1;
    }
    if(!found) return -1;
    }


int main(int argc, char const *argv[])
{
    int arr[] = {3, 7, 11, 15, 18, 22, 27, 31, 36, 40, 45, 49, 53, 58, 62, 67, 71, 75, 80, 85};
    // int target = 13;
    int target;
    cin>>target;
    int n = sizeof(arr)/sizeof(arr[0]);
    int idx;
    idx = binary_search(arr, n, target);
    cout<<idx;
    return 0;
}


