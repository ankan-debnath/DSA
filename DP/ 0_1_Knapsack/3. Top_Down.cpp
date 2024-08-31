// 0/1 Knapsack top-down
#include<iostream>
#include<vector>
using namespace std;

int knapsack(vector<int>& W, vector<int>& V,  int n, int capacity) {
    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, -1));
    for(int i = 0; i <= n; i++)               // initialization dp[0][j] = 0, dp[i][j] = 0
        dp[i][0] = 0;
    for(int i = 0; i <= capacity; i++)
        dp[0][i] = 0;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= capacity; j++){

            if(W[i-1] <= j)
                dp[i][j] = max(
                    V[i-1] + dp[i-1][j - W[i-1]],
                    dp[i-1][j]
                );
            else
                dp[i][j] = dp[i-1][j];

        }
    }

    return dp[n][capacity];
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