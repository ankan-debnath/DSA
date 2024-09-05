#include<iostream>
#include<unordered_map>
using namespace std;

// pair comparator 
struct cmp{
    template <class T1, class T2>
    size_t operator() (const pair<T1, T2> p) const{
        auto h1 = hash<T1>{}(p.first);
        auto h2 = hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

int main(){
    unordered_map<pair<int, int>, string,  cmp> m;

    m[{1,2}] = "First";
    m[{2,3}] = "Second";

    for(auto it : m){
        auto [x,y] = it.first;
        string s = it.second;
        cout<<'('<<x<<','<<y<<") : "<<s<<endl;
    }

}