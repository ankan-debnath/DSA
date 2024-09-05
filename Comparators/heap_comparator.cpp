#include<iostream>
#include<queue>
#include<vector>
using namespace std;

struct cmp{
    bool operator()(pair<int,int> a, pair<int,int> b){
        return (a.first < b.first ) || (a.first == b.first && a.second < b.second);   // cmp  to consturct max_heap with pair
    }
};

int main(){
    priority_queue<pair<int,int>, vector<pair<int,int>>, cmp> pq;

    pq.push({1,2});
    pq.push({2,3});
    pq.push({1,5});
    pq.push({4,1});

    while(!pq.empty()){
        auto [a,b] = pq.top(); pq.pop();
        cout<<'('<<a<<','<<b<<')'<<endl;
    }
}