/*
Given two arrays deadline[ ] and profit[ ], where deadline[i] represents the last time unit
by which the i-th job must becompleted, and profit[i] represents the profit earned from completing it. 
Each job takes exactly 1 unit of time, and onlyone job can be scheduled at a time. Write a program to 
schedule the jobs in such a way that the total profit is maximized while ensuring that each selected 
job is completed on or before its deadline. Find the number of jobs completed and maximum profit.
E.g.:
Input:
N = 5
Jobs = [J1, J2, J3, J4, J5]
deadline = [2, 1, 2, 1, 3]
profit = [100, 19, 27, 25, 15]
Output:
Selected Jobs: [J1, J3, J5]
Maximum Profit = 142
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int main(){
    vector<char> jobs={'J','K','L','M','N'};
    vector<int> deadline={2, 1, 2, 1, 3};
    vector<int> profit={100, 19, 27, 25, 15};
    vector<int>idx={0,1,2,3,4};

    vector<pair<int, int>> pr;
    for(int i=0; i<idx.size(); i++){
        pr.push_back({profit[i], idx[i]});
    }
    sort(pr.begin(), pr.end(), greater<>());

    vector<int>slot(4,-1);
    int result=0;
    cout<<"Job: ";

    for(auto p: pr){
        int i=p.second;
        int pro=p.first;
        for(int t=deadline[i]; t>0; t--){
            if(slot[t]==-1){
                slot[t]=i;
                result+=profit[i];
                cout<<jobs[i]<<", ";
                break;
            }
        }
    }
    cout<<"Maximum profit: "<<result;
    return 0;
}
