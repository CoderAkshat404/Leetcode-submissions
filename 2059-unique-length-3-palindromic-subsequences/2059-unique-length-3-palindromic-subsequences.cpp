class Solution {
public:
    int countPalindromicSubsequence(string s) {
        map<char,int> f;
        map<char,int> l;
        map<char,int> count;
        for(int i=0;i<s.length();i++){
            if(f.find(s[i])==f.end()){
                f[s[i]]=i;
            }
            l[s[i]]=i;
            count[s[i]]++;
        }
        int ans=0;
        for(auto i:f){
            int x=i.second;
            int y=l[i.first];
            set<char> a;
            if(x!=y){
                for(int j=x+1;j<y;j++){
                    a.insert(s[j]);
                }
                ans+=a.size();
            }
        }
        return ans;
        
    }
};