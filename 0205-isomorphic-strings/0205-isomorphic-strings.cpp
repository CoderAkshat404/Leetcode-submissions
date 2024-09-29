class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> m;
        unordered_map<char,bool> mp;
        for(int i=0;i<s.length();i++){
            if(mp[t[i]]==false){
                m[s[i]]=t[i];
                mp[t[i]]=true;
            }
            
        }
        string x="";
        for(int i=0;i<s.length();i++){
            x+=m[s[i]];
        }
        if(t==x){
            return true;
        }
        else{
            return false;
        }
        
    }
};