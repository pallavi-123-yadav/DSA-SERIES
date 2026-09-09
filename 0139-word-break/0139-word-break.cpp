class Solution {
public:
bool solve(string s,int index,vector<string>& wordDict,vector<int>&dp) {
    if(index==s.size()) return true ;
     if(dp[index] != -1)
            return dp[index];
    for(int i=index;i<s.size();i++) {
        string word = s.substr(index,i-index+1);
        if(find(wordDict.begin(),wordDict.end(),word) !=wordDict.end()) {
             if(solve(s, i + 1, wordDict,dp))
                    return dp[index]=true;
        }
      
    }
    return dp[index]=false;
}
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int> dp(s.size(), -1);
        return solve(s,0,wordDict,dp);
    }
};