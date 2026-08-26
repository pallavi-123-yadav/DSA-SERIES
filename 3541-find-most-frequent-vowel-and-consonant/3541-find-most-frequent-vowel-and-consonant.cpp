class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);
        for (int i = 0; i < s.length(); i++) {
            freq[s[i] - 'a']++;
        }
        int vowel =0;
        int cons =0;
        for(int i =0 ;i <26;i++) {
              char ch = 'a' + i;
            if(ch=='a' ||  ch=='e'|| ch=='i' || ch=='o' || ch=='u') {
               
                vowel =max(vowel,freq[i]);
            }
            else {
                cons =max(cons,freq[i]);
            }
        }
        return cons+vowel;
    }
};