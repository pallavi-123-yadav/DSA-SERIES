class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>st;
        for(int i=0; i<asteroids.size();i++) {
            int x=asteroids[i];

        
        while(!st.empty() && st.back()>0 && x<0) {
            if(st.back()<-x) {
                st.pop_back();
            }
            else if(st.back()==-x) {
                st.pop_back();
                x=0;
                break;
            }
            else {
                x=0;
                break;
            }
        }
        if(x!=0) {
        st.push_back(x);
        }
        }
return st;
    }
};