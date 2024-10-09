class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st;
        int ans = 0;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                st.push(s[i]);
            } else {
                // Check if the stack is not empty before accessing top
                if (!st.empty() && st.top() == '(') {
                    st.pop();  // Valid pair of '()' found, pop the stack
                } else {
                    ans++;  // Invalid ')' found, need to add '('
                }
            }
        }

        // After loop, any remaining '(' in the stack are unmatched
        return ans + st.size();
    }
};
