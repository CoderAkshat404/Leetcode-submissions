class Solution {
public:
    static unordered_map<char,int> m;
    static unordered_map<char,int> mp;
    static bool cmp(char a ,char b){
        if(m[a]>m[b]){
            return true;
        }
        else if(m[a]<m[b]){
            return false;
        }
        else{
            if(mp[a]<mp[b]) return true;
            return false;
        }

    }
    string sortVowels(string s) {
        string vow="";
         m.clear();
         mp.clear();
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i'){
                vow+=s[i];
                m[s[i]]++;
                if(mp.find(s[i])==mp.end()){
                    mp[s[i]]=i;
                }
                
            }
        }
      
        sort(vow.begin(),vow.end(),cmp);
        int k=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='o' || s[i]=='u' || s[i]=='i'){
                s[i]=vow[k];
                k++;

            }
            

        }
    
return s;
    }

        
    
};
unordered_map<char,int> Solution::m;
unordered_map<char,int> Solution::mp;