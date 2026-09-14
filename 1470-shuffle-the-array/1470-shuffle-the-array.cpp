class Solution {
public:
  void solve( vector<int> &nums , int i ,int high,int n,vector<int> &ans) {
    if(i==n) return ;
    ans.push_back(nums[i]);
    ans.push_back(nums[high]);

    solve(nums,i+1,high+1,n,ans);
  }

    public:
  
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>ans;
       int i =0;
       int high =n;
        solve(nums,0,n,n,ans);
        return ans;
        
    
    }
};