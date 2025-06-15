class Solution {
public:
    int maxDiff(int num) {
        int maxi = -1;
        int mini = 1e9;
        for(int i = '0'; i <= '9'; i++) {
            for(int k = '0'; k <= '9'; k++) {
                string s = to_string(num);
                for(int j = 0; j < s.length(); j++) {
                    if(s[j] == (char)k) {
                        s[j] = (char)i;
                    }
                }
                int n = stoi(s);
                if(s[0] != '0') {  
                    maxi = max(maxi, n);
                    mini = min(mini, n);
                }
            }
        }
        return maxi - mini;
    }
};
