/*
You are given N items, where each item has a value and a weight. 
You are also given a knapsack with a maximum capacity W. 
Unlike the 0/1 Knapsack problem, you are allowed to take fractions of an item. 
Write a program to maximize the total value in the knapsack without exceeding its capacity.
E.g.:
Input:
N = 3
value = [100, 60, 120]
weight = [20, 10, 40]
W = 50
Output:
Maximum value = 220
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N=3;
    int W=50;
    vector<int> value={100, 60, 120};
    vector<int> weight={20, 10, 40};
    vector<pair<int, int>> pr;

    for(int i=0; i<value.size(); i++){
        pr.push_back({value[i], weight[i]});
    }
    sort(pr.begin(), pr.end(), greater<>());
    int result=0, i=0;

    for(int i=0; i<pr.size(); i++){
        int val=pr[i].first;
        int wt=pr[i].second;
        if(wt>=W){
            result+=val;
            W-=wt;
        }
        else{
            result+=(double)(W/wt)*val;
            break;
        }
    }

    cout<<"Maximum value: "<< result;
    return 0;
}

// Solution with storing ratio
// int main(){
//     int N=3;
//     int W=50;

//     vector<int> value={100, 60, 120};
//     vector<int> weight={20, 10, 40};

//     vector<int> idx={0, 1, 2};
//     sort(idx.begin(), idx.end(), [&](int a, int b){
//         return (double)value[a]/weight[a] > (double)value[b]/weight[b];
//     });

//     double maxValue=0.0;

//     for (int i:idx){
//         if(W>=weight[i]){
//             W-=weight[i];
//             maxValue+=value[i];
//         }
//         else{
//             maxValue+=value[i]*((double)W/weight[i]);
//             break;
//         }
//     }

//     cout<<"Maximum value = "<<maxValue<<endl;
//     return 0;
// }
