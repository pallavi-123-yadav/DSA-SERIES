class Solution {
public:
int  fun(int i,int n, vector<int> &dp) {
    if(i==n) return 1;
    if(i>n) return 0;
     if(dp[i]!=-1) return dp[i];

     int a1=fun(i+1,n,dp);
     int a2=fun(i+2,n,dp);
     int ans =a1+a2;

     return dp[i]=ans;

}
    int climbStairs(int n) {
        vector<int>dp(n+1,-1);
        return fun(0,n,dp);
    }
};