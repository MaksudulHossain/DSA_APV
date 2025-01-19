#include <iostream>
using namespace std;

int main(){
    int arr[5] = {10,2,5,4,2};
    int target = 2;
    int size = sizeof(arr)/sizeof(arr[0]);
    for(int i=0; i<=size-1; i++){
        if(arr[i] == target){
            cout<<i<<endl;
            return 0;
        }
    }

    cout << "target not found" <<endl;

}