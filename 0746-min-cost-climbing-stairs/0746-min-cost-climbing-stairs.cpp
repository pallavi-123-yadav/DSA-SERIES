class Solution {
public:
int fun(int i, vector<int>&cost, vector<int>& dp){
    
    if(i>=cost.size()) return 0;
     if(dp[i]!=-1) return dp[i];

     int a1=cost[i]+fun(i+1,cost,dp);
     int a2=cost[i]+fun(i+2,cost,dp);
    return  dp[i]=min(a1,a2);

}
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
       vector<int> dp(n, -1);

    return min(fun(0, cost, dp), fun(1, cost, dp));
    }
};