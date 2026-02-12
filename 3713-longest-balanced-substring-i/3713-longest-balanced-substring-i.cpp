class Solution {
public:
    int longestBalanced(string s) {
        int maxi=0;
        for(int i=0;i<s.length();i++){
            unordered_map<char,int> m;
            for(int j=i;j<s.length();j++){
                m[s[j]]++;
                bool flag=true;
                int x=m[s[j]];
                for(auto k:m){
                    if(k.second!=x){
                        flag=false;
                        break;
                    }
                }
                if(flag){
                    maxi=max(maxi,j-i+1);
                }

            }
        }
        return maxi;
        
    }
};