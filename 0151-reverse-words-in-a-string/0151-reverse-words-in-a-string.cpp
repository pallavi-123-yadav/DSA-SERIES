class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string word = "";

        // Push each word into stack
        for (int i = 0; i < s.size(); i++) {

            if (s[i] != ' ') {
                word += s[i];
            }
            else {
                if (word != "") {
                    st.push(word);
                    word = "";
                }
            }
        }

        // Push the last word
        if (word != "") {
            st.push(word);
        }

        // Pop words and create answer
        string res = "";

        while (!st.empty()) {
            res += st.top();
            st.pop();

            if (!st.empty()) {
                res += " ";
            }
        }

        return res;
    }
};