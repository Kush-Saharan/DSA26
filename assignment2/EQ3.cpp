/*
Given a string 𝑠 consisting only of lowercase English characters and an integer 𝑘, design a greedy strategy–based
algorithm to generate the lexicographically smallest possible string after removing exactly 𝑘 characters from the string,
with the additional constraint that the value of 𝑘 must first be modified based on the length of the string. If the length
of the string is a power of 2, the value of 𝑘is reduced to 𝑘/2; otherwise, the value of 𝑘is doubled to 2𝑘. After modifying
𝑘, exactly 𝑘 characters can be removed from any positions in the string. The objective is to ensure that the resulting
string is the smallest in lexicographical order among all possible valid removals. 
[Lexicographically smallest String by removing exactly K characters - GeeksforGeeks]
E.g.:
Input: S = "fooland", k = 2
Output: "and"
Explanation: As the size of the string = 7, which is not a power of 2, hence K = 4. After removing 4 characters from
the given string, the lexicographically smallest string is "and".
*/

#include <vector>
#include <iostream>
#include <stack>
using namespace std;

int main(){
    int k=2;
    string S="fooland";
    int len=S.length();

    if((len > 0) && ((len & (len - 1)) == 0)){
        k=k/2;
    }
    else{
        k=2*k;
    }
    stack<char> st;
    for(char ch: S){
        while(!st.empty()&& k>0 && ch-'a'<st.top()-'a'){
            st.pop();
            k--;
        }
        st.push(ch);
    }
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }

    return 0;
}