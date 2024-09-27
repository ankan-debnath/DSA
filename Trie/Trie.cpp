#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    bool marked;
    unordered_map<char,Node*> next;
    Node(){
        marked = false;
    }
};
class Trie{
    Node* root;
    public:

    Trie(){ root = new Node() ; }

    void insert(string s){
        Node* curr = root;
        
        for(char ch : s){

            if(curr->next[ch] == NULL)
                curr->next[ch] = new Node();
            curr = curr->next[ch];
        }
        curr->marked = true;
    }

    bool search(string s){
        Node* curr = root;
        
        for(char ch : s){
            if(curr->next[ch] == NULL)
                return false;
            curr = curr->next[ch];
        }   
        return curr->marked;
    }
};