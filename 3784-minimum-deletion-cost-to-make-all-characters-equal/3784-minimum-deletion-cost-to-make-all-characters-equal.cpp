class Solution {
public:
    long long minCost(string s, vector<int>& cost) {
        #define int long long
        int total=0;
        map<char,int> m;
        for(int i=0;i<s.length();i++){
            m[s[i]]+=cost[i];
            total+=cost[i];
        }
        int mini=1e18;
        for(char c='a';c<='z';c++){
            mini=min(mini,(long long)total-m[c]);
        }
        return mini;
        #undef int
        
    }
};