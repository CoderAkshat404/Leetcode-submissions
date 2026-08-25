class Solution {
public:
    set<long long> st;
    int dp[100005];

    int solve(int i, string &s) {
        if (i >= s.length()) return 0;

        if (dp[i] != -1) return dp[i];

        string temp = "";
        int ans = 1e9;

        for (int j = i; j < s.length(); j++) {
            temp += s[j];

            long long sum = 0;

            for (int k = temp.length() - 1; k >= 0; k--) {
                if (temp[k] == '1') {
                    sum += (1LL << (temp.length() - 1 - k));
                }
            }

            if (st.find(sum) != st.end()) {
                if(j+1<s.length() && s[j+1]!='0')
                ans = min(ans, 1 + solve(j + 1, s));
                else if(j==s.length()-1){
                     ans = min(ans, 1 + solve(j + 1, s));

                }
            }
        }

        return dp[i] = ans;
    }

    int minimumBeautifulSubstrings(string s) {
        st.clear();

        long long curr = 1;

        while (curr <= 1e18) {
            st.insert(curr);

            if (curr > 1e18 / 5)
                break;

            curr *= 5;
        }

        memset(dp, -1, sizeof(dp));
        if(s[0]=='0') return -1;
        int ans = solve(0, s);

        if (ans >= 1e9)
            return -1;

        return ans;
    }
};