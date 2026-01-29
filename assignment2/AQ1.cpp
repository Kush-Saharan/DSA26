/*
You are given N activities, each having a start time and a finish time. 
A single person (or machine) can perform only one activity at a time. 
Two activities are said to be compatible if the start time of one activity
is greater than or equal to the finish time of the other activity. 
Write a program using greedy strategy to select the maximum number of non-
overlapping activities that can be performed by the person.
E.g.:
Input:
N = 6
start = [1, 3, 0, 5, 8, 5]
finish = [2, 4, 6, 7, 9, 9]
Output:
Maximum number of activities = 4
Selected activities: (1, 2), (3, 4), (5, 7), (8, 9)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n=6;
    vector<int> start={1,3,0,5,8,5};
    vector<int> finish={2,4,6,7,9,9};

    vector<pair<int, int>> activities;
    for(int i=0; i<start.size(); i++){
        activities.push_back({finish[i], start[i]});
    }

    sort(activities.begin(), activities.end());
    
    vector<pair<int, int>>result;
    int count=1;
    int first=activities[0].first;
    result.push_back({activities[0].second, activities[0].first});

    for(int i=0; i<start.size(); i++){
        if (activities[i].second >= first) {
            count++;
            first = activities[i].first;
            result.push_back({activities[i].second, activities[i].first});
        }
    }   
    
    for(auto& act: result){
        cout<<"("<<act.first<<","<<act.second<<")";
    }


    return 0;
}