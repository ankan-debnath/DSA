// O_1 knapsack Recursive
#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>& W, vector<int>& V,  int n, int capacity){
    if(n == 0 || capacity == 0)             // possible valid input
        return 0;
    
    if(W[n-1] <= capacity)                  //choice diagram
        return max(
            V[n-1] + knapsack(W, V, n - 1, capacity - W[n-1]),     // include the item decrease capacity, decrease size
            knapsack(W, V, n - 1, capacity)                        // discard the item decrease the size
        );
    else
        return knapsack(W, V, n - 1, capacity);  //no option discard the item capacity < Weight[item]
}

int main(){
      vector<int> W = {4, 5, 1};
    vector<int> V = {1,2,3};
    int capacity = 4;
    int n = W.size();
    
    int ans = knapsack(W, V, n, capacity);
    cout<<ans;

    return 0;
}