/*
There are n gas stations along a circular route, where the amount of gas at the ith station is gas[i]. You have a car with
an unlimited gas tank and it costs cost[i] of gas to travel from the ith station to its next (i + 1)th station. You begin the
journey with an empty tank at one of the gas stations. Given two integer arrays gas and cost, return the starting gas
station's index if you can travel around the circuit once in the clockwise direction, otherwise return -1. If there exists a
solution, it is guaranteed to be unique. [Gas Station - LeetCode]
E.g.:
Input: gas = [1,2,3,4,5], cost = [3,4,5,1,2]
*/

#include <vector>
#include <iostream>
#include <numeric>
using namespace std;

int main(){
    vector<int>cost={3,4,5,1,2};
    vector<int> gas={1,2,3,4,5};

    int c=accumulate(cost.begin(), cost.end(), 0);
    int g=accumulate(gas.begin(), gas.end(), 0);
    if(g<c)return -1;
        
    int fuel=0;
    int start=0;

    for(int i=0; i<gas.size(); i++){
        fuel+=gas[i]-cost[i];
        if(fuel<0){
            fuel=0;
            start=i+1;
        }
    }
    cout<< start;
    return 0;
}