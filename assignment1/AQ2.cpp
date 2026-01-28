/*
Implement Merge sort for the given array int arr[] = {12, 11, 13, 5, 6, 7}. 
After implementing Merge Sort, 
apply the same implementation to sort another array: int arr2[] = {38, 27, 43, 3, 9, 82, 10}
*/

#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int low, int mid, int high){
    int n1=mid-low+1;
    int n2=high-mid;
    vector<int> temp1, temp2;
    for(int i=0; i<n1; i++){
        temp1.push_back(arr[low+i]);
    }
    for(int i=0; i<n2; i++){
        temp2.push_back(arr[mid+i+1]);
    }
    int i=0, j=0, k=low;
    while(i<n1 && j<n2){
        if(temp1[i]<=temp2[j]){
            arr[k]=temp1[i];
            k++;
            i++;
        }
        else{
            arr[k]=temp2[j];
            j++;
            k++;
        }
    }
    while(i<n1){
        arr[k]=temp1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=temp2[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int low, int high){
    if(low>=high)return;
    
    int mid=low+(high-low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}

void dispArr(vector<int> arr){
    for(int x: arr){
        cout<<x<<" ";
    }
    cout<<endl;
}

int main(){

    vector<int> arr1={12, 11, 13, 5, 6, 7},arr2={38, 27, 43, 3, 9, 82, 10};
    cout<<"Before sorting\n";
    dispArr(arr1);
    dispArr(arr2);

    mergeSort(arr1, 0, arr1.size()-1);
    mergeSort(arr2, 0, arr2.size()-1);

    cout<<"After sorting\n";
    dispArr(arr1);
    dispArr(arr2);

    return 0;
}