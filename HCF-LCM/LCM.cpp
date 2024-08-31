#include<iostream>
#include<vector>
using namespace std;

int gcd(int x, int y){
    int z = x % y;
    while(z){
        x = y;
        y = z;
        z = x % y;
    }
    return y;
}
int LCM(vector<int> nums){
    int n = nums.size();
    if(n == 1)  return nums[0];
    int lcm = nums[0];

    for(int i = 1; i < n; i++){
        lcm = (lcm * nums[i]) / gcd(lcm, nums[i]);
    }
    return lcm;
}

int main(){
    cout<<LCM({28, 35, 42, 56, 63, 84});
}