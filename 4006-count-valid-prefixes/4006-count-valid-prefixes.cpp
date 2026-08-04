class Solution {
public:
    int countValidPrefixes(string s) {
        int ans=0;
        int o=0;
        int z=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                o++;
            }
            else{
                z++;
            }
            if(abs(o-z)<=1){
                ans++;
            }
        }
        return ans;
    }
};