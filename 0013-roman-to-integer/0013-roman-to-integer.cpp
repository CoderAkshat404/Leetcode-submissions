class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char,int> m;
        m['I']=1;
        m['V']=5;
        m['X']=10;
        m['L']=50;
        m['C']=100;
        m['D']=500;
        m['M']=1000;
        unordered_map<char,int> mp;
        mp['I']=1;
        mp['V']=2;
        mp['X']=3;
        mp['L']=4;
        mp['C']=5;
        mp['D']=6;
        mp['M']=7;
        int ans=0;
        int i;
        for(i=0;i<s.length()-1;i++){
            if(mp[s[i]]>=mp[s[i+1]]){
                ans+=m[s[i]];
            }
            else{
                ans+=m[s[i+1]]-m[s[i]];
                i++;
            }

        }
    if(i==s.length()-1){
        ans+=m[s[s.length()-1]];
    }

     return ans;   
    }
};