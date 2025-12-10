class Solution {
public:
    int mod=1e9+7;
    int countPermutations(vector<int>& complexity) {
        #define int long long
        map<int,int> m;
        int mini=1e9;
        for(auto i:complexity){
            m[i]++;
            mini=min(mini,(long long)i);
        }
        if(mini!=complexity[0] || m[complexity[0]]>1){
            return 0;
        }
        int ans=1;
        for(int i=1;i<=complexity.size()-1;i++){
            ans=(ans*i)%mod;
        }
        return ans;
        #undef int

    }
};