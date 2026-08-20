class Solution {
public:
    int majorityElement(vector<int>& nums) {
        vector<int>ans;
        int count =0;
       int n=nums.size();
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++) {
          mp[nums[i]]++;
        }
        for(pair<int,int> j:mp) {
            if(j.second>n/2){
                return j.first;
            }

        }
        return -1;
    }
};