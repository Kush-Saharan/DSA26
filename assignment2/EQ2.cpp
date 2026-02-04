/*
Alice gives Bob a rectangular board composed of 𝑚 × 𝑛 wooden squares and asks him to determine the minimum total
cost required to break the board down into its individual squares by making cuts only along the horizontal and vertical
grid lines. Bob can perform horizontal and vertical cuts across the entire current board, where each horizontal cut has
an associated cost 𝑥𝑖 and each vertical cut has an associated cost 𝑦𝑗 . The cost of making a cut is equal to the given cut
cost multiplied by the number of board segments it crosses at that time. As the board is progressively divided, the
number of segments increases, thereby increasing the effective cost of subsequent cuts. The total cost of reducing the
board into individual squares is defined as the sum of the costs of all cuts performed in sequence. The objective is to
design a greedy strategy–based algorithm that selects the order of horizontal and vertical cuts such that the overall
cutting cost is minimized. 
[Cutting Boards | HackerRank]
E.g.:
Input: m = 3, n = 3
Output:
Horizontal cut costs (x): 2 1
Vertical cut costs (y): 3 1
*/


#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;


int main(){
    vector<int> horizontal = {2,1};
    vector<int> vertical = {3,1};

    sort(horizontal.rbegin(), horizontal.rend());
    sort(vertical.rbegin(), vertical.rend());

    int totalCost=0, i=0, j=0;
    int vseg=1, hseg=1;
    while(i<horizontal.size() && j<vertical.size()){
        if(horizontal[i]>vertical[j]){
            totalCost+=horizontal[i]*hseg;
            hseg++;
            i++;
        }
        else{
            totalCost+=vertical[i]*vseg;
            vseg++;
            j++;
        }
    }
    while(i<horizontal.size()) {
        totalCost+=horizontal[i]*vseg;
        i++;
    }

    while(j<vertical.size()) {
        totalCost+=vertical[j]*hseg;
        j++;
    }
    cout<<totalCost;

    return 0;
}