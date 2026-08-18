class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int>ans;
        int count =0;
       int n=nums.size();
        unordered_map<int,int>mp;
        for(int i =0;i<nums.size();i++) {
          mp[nums[i]]++;
        }
        for(pair<int,int> j:mp) {
            if(j.second>n/3){
                ans.push_back(j.first);
            }

        }
        return ans;

    }
};