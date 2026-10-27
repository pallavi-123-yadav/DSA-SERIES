class Solution {
public:
int fun(int i,int start, vector<int>& nums, vector<int>& dp) {
        if (i < start) {
            return 0;
        }
        if (i == start) {
            return nums[start];
        }

       
        if (dp[i] != -1) {
            return dp[i];
        }

        int rob = nums[i] + fun(i - 2,start, nums, dp);

        int skip = fun(i - 1,start, nums, dp);

        return dp[i] = max(rob, skip);
    }

    int rob(vector<int>& nums) {
         int n = nums.size();
        if(n==1) {
            return nums[0];
        }
        vector<int> dp1(n, -1);

        int case1= fun(n - 2,0, nums, dp1);
        vector<int>dp2(n,-1);
        int case2=fun(n-1,1,nums,dp2);

        return max(case1,case2);
    }
    
};