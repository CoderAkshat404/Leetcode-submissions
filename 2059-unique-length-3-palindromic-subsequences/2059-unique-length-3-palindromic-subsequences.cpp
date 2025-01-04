class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char,int> m1;
        unordered_map<char,bool> mp1;
        unordered_map<char,int> m2;
        for(int i=0;i<s.length();i++){
            if(mp1[s[i]]==false){
                m1[s[i]]=i;
                mp1[s[i]]=true;
            }
        }
        unordered_map<char,bool> mp2;
        for(int i=s.length()-1;i>=0;i--){
            if(mp2[s[i]]==false){
                m2[s[i]]=i;
                mp2[s[i]]=true;
            }
        }
        int ans=0;
        for(auto i:m1){
            if(i.second==m2[i.first]){
                ans+=0;
            }
            else{
                unordered_map<char,bool> m3;
                for(int j=i.second+1;j<m2[i.first];j++){
                    if(m3[s[j]]==false){
                        m3[s[j]]=true;
                        ans++;
                    }
                }
            }
        }
        return ans;


        
    }
};