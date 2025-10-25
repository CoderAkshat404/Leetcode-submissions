class Solution {
public:
    string lexSmallest(string s) {
        string ans=s;
        for(int i=0;i<s.length();i++){
            reverse(s.begin(),s.begin()+i);
            ans=min(ans,s);
            reverse(s.begin(),s.begin()+i);
            
        }
        for(int i=s.length();i>=0;i--){
            reverse(s.begin()+i,s.end());
            ans=min(ans,s);
            reverse(s.begin()+i,s.end());
        }
        return ans;
        
    }
};