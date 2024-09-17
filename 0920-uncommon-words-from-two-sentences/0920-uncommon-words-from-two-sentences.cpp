class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        map<string,int> m;
        string s="";
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=' '){
                s+=s1[i];
            }
            else{
                 m[s]++;
                s="";
               
            }
            
        }
        m[s]++;
        s="";
        
       for(int i=0;i<s2.length();i++){
            if(s2[i]!=' '){
                s+=s2[i];
            }
            else{
                 m[s]++;
                s="";
               
            }
            
        }
        m[s]++;
        s="";

        vector<string> ans;
        for(auto i:m){
            if(i.second==1){
                ans.push_back(i.first);
            }
        }
        return ans;

        
        
    }
};