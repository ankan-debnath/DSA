// O_1 knapsack Memoization
#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>& W, vector<int>& V,  int n, int capacity,
vector<vector<int>>&dp){
    if(n == 0 || capacity == 0)             // possible valid input
        return 0;
    
    if(dp[n][capacity] > -1)
        return dp[n][capacity];
        
    if(W[n-1] <= capacity)                  //choice diagram
        return dp[n][capacity] = max(
            V[n-1] + knapsack(W, V, n - 1, capacity - W[n-1], dp),     // include the item decrease capacity, decrease size
            knapsack(W, V, n - 1, capacity, dp)                        // discard the item decrease the size
        );
    else
        return dp[n][capacity] = knapsack(W, V, n - 1, capacity, dp);  //no option discard the item capacity < Weight[item]
}

int main(){
    vector<int> W = {4, 5, 1};
    vector<int> V = {1,2,3};
    int capacity = 4;
    int n = W.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    
    int ans = knapsack(W, V, n, capacity, dp);
    cout<<ans;

    return 0;
}
