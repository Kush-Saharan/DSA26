/*
A chef has opened a restaurant that is divided into 𝐾 distinct compartments, 
numbered from 1 to 𝐾, where each compartment can be occupied by at most one customer
 at any given time. Each of the 𝑁 customers visiting therestaurant is characterized
  by three parameters: an arrival time, a departure time, and a strongly preferred compartment
𝑝( 1 ≤ 𝑝 ≤ 𝐾 ). A customer can be seated only in their preferred compartment, 
and if that compartment is already occupied at the time of arrival, 
the customer immediately leaves the restaurant. To maximize the total number of
customers who are successfully served, the chef may choose to allow or disallow certain customers. 
Given the list ofall customers with their arrival times, departure times, 
and preferred compartments, write a program to determine the maximum number of customers 
that can dine at the restaurant without violating the compartment constraints.
 [BonAppetit Practice Coding Problem]
E.g:
Input:
K = 3, N = 6
C = [C1, C2, C3, C4, C5, C6]
Arrival = [1, 2, 3, 5, 4, 6]
Departure = [4, 5, 6, 7, 8, 9]
Preferred = [1, 1, 2, 1, 2, 3]
Output: Maximum number of customers that can dine = 4
*/

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;


int main(){
    vector<int> arrival={1,2,3,5,4,6};
    vector<int> departure={4,5,6,7,8,9};
    vector<int> preferred={1,1,2,1,2,3};
    vector<int> idx={0,1,2,3,4,5};

    vector<pair<int, int>> pr;
    for(int i=0; i<idx.size(); i++){
        pr.push_back({departure[i], idx[i]});
    }
    sort(pr.begin(), pr.end());
    int n=6;
    int count=0;
    vector<int> mp(4, 0);
    for(int i=0; i<n; i++){
        int id=pr[i].second;
        int dep=pr[i].first;
        if(mp[preferred[id]]<=arrival[id]){
            mp[preferred[id]]=dep;
            count++;
        }
    }
    cout<<count;

    return 0;
}