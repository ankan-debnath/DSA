#include<iostream>
#include<unordered_map>
using namespace std;

// tuple comparator 
struct cmp{
    template <class T1, class T2, class T3>
    size_t operator() (const tuple<T1, T2, T3> t) const{
        auto h1 = hash<T1>{}(get<0>(t));
        auto h2 = hash<T2>{}(get<1>(t));
        auto h3 = hash<T3>{}(get<2>(t));

        return h1 ^ h2 ^ h3;
    }
};


int main(){
    unordered_map<tuple<int,int, int>, string,  cmp> m;

    m[{1,2, 3}] = "First";
    m[{2,3,4}] = "Second";

    for(auto it : m){
        auto [x,y,z] = it.first;
        string s = it.second;
        cout<<'('<<x<<','<<z<<','<<y<<") : "<<s<<endl;
    }

}