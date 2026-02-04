/*
Chefland has a renowned university that offers 𝑁 courses, where each course is conducted over a continuous range of
days. The 𝑖 th course starts on day 𝑠𝑡𝑎𝑟𝑡𝑖 and ends on day 𝑒𝑛𝑑𝑖 . Chef wishes to enroll in the university but is unsure
about the exact duration of study and therefore considers 𝑄 different tentative study plans. Each plan is defined by a
starting day 𝑝𝑙𝑎𝑛_𝑠𝑡𝑎𝑟𝑡𝑗 and an ending day 𝑝𝑙𝑎𝑛_𝑒𝑛𝑑𝑗 . For each study plan, Chef wants to determine the maximum
number of courses he can complete if he follows that plan. Chef can attend at most one course on any given day, and a
course is considered completed only if Chef attends all its classes, meaning the entire duration of the course must lie
within the selected study plan. Design an efficient algorithm to compute the maximum number of courses that Chef
can complete for each of his study plans. [Chef and his study plans Practice Coding Problem]
E.g.:
Input:
N=6
St_i = [1, 2, 4, 6, 5, 8]
End_i = [3, 5, 6, 7, 9, 10]
Output:
Q=3
Plan_st_j = [1, 2, 4]
Plan_end_j = [6, 7, 10]
*/

#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int main(){
    int N = 6;
    vector<int> St = {1, 2, 4, 6, 5, 8};
    vector<int> End = {3, 5, 6, 7, 9, 10};

    int Q = 3;
    vector<int> plan_st = {1, 2, 4};
    vector<int> plan_end = {6, 7, 10};

    vector<pair<int,int>> courses;
    for(int i = 0; i < N; i++){
        courses.push_back({St[i], End[i]});
    }
    sort(courses.begin(), courses.end(),
         [](auto &a, auto &b){
             return a.second < b.second;
         });
    for(int i=0; i<Q; i++){
        int L=plan_st[i];
        int R=plan_end[i];
        int count=0;
        int end=0;
        for(auto c: courses){
            if(c.first>=L && c.second<=R && c.first>=end){
                end=c.second;
                count++;
            }
        }
        cout<<"For plan "<<i+1<<": "<<count<<endl;
    }

    return 0;
}