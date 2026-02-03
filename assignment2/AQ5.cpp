/*
Given a set of characters and their corresponding frequencies, write a program to construct 
the Huffman Tree and generate Huffman codes for each character such that the total 
number of bits required for encoding is minimized.
E.g.:
Input:
Characters = [a, b, c, d, e, f]
Frequencies = [5, 9, 12, 13, 16, 45]
Output:
Character Huffman Code
a 1100
b 1101
c 100
d 101
e 111
f 0
*/

#include <bits/stdc++.h>
using namespace std;

struct Node {
    char ch;
    int freq;
    Node *left, *right;

    Node(char c, int f){
        ch=c;
        freq=f;
        left=right=NULL;
    }
};

struct compare {
    bool operator()(Node* l, Node* r) {
        return l->freq>r->freq;
    }
};

void printCodes(Node* root, string code){
    if (!root)return;

    if (!root->left && !root->right)
        cout << root->ch << " : " << code << endl;

    printCodes(root->left, code+"0");
    printCodes(root->right, code+"1");
}

int main() {
    vector<char>chars={'a','b','c','d','e','f'};
    vector<int>freq={5,9,12,13,16,45};

    priority_queue<Node*, vector<Node*>, compare> pq;

    for(int i=0; i<chars.size(); i++)
        pq.push(new Node(chars[i], freq[i]));

    while(pq.size()>1){
        Node* left=pq.top(); pq.pop();
        Node* right=pq.top(); pq.pop();

        Node* merged=new Node('$', left->freq + right->freq);
        merged->left=left;
        merged->right=right;

        pq.push(merged);
    }

    Node* root=pq.top();

    cout<<"Character Huffman Code\n";
    printCodes(root, "");

    return 0;
}
