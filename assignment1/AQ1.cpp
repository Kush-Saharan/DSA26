/*
Consider an array arr[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91} and use Binary Search to find
the target 23.
*/

#include <iostream>

using namespace std;

int binarySearch(int arr[], int low, int high, int target) {
    int mid=(low+high)/2;
    if(arr[mid]==target) return mid;
    else if(arr[mid]>target) binarySearch(arr, low, mid-1, target);
    else binarySearch(arr, mid+1, high, target);
}

int main(){

    int arr[]={2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int low=0, high=sizeof(arr)/sizeof(arr[0]);
    int target=23;
    int index=binarySearch(arr, low, high, target);

    if(index) cout<<"Element found at index "<<index;
    else cout<<"Element not found";

    return 0;
}