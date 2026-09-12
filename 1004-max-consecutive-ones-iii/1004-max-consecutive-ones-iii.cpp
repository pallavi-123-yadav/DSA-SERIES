class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int low=0;
        int zeroes=0;
        int ans=0;
        for(int high =0; high<nums.size();high++) {
            if(nums[high]==0) {
                zeroes++;
            }
            while(zeroes>k) {
                if(nums[low]==0) {
                    zeroes--;
                }
                low++;
            }
            int len =high-low+1;
            ans =max(ans,len);
        }
        return ans;
    }
};