/*
Implement Quick Sort for arr[n] = { 4, 2, 6, 9, 2 }
*/

#include <iostream>
#include <vector>
using namespace std;

void dispArr(vector<int> arr){
    for(int x: arr){
        cout<<x<<" ";
    }
    cout<<endl;
}
int partition(vector<int>& arr, int low, int high){
    int pivot=arr[high];
    int i=low-1;

    for (int j=low; j<high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i+1], arr[high]);
    return i+1;
}

void quickSort(vector<int>& arr, int low, int high){
    if (low >= high)
        return;

    int p = partition(arr, low, high);

    quickSort(arr, low, p - 1);
    quickSort(arr, p + 1, high);
}

int main(){

    vector<int> arr={4, 2, 6, 9, 2};
    cout<<"Before sorting\n";
    dispArr(arr); 
    
    quickSort(arr, 0, arr.size()-1)  ;  

    cout<<"After sorting\n";
    dispArr(arr);


    return 0;
}