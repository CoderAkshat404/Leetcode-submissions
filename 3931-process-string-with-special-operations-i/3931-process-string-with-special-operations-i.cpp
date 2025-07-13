class Solution {
public:
    string processStr(string s) {
        string p;
        for(int i=0;i<s.length();i++){
            if(s[i]=='*'){
                if(p.length()>0){
                    p.pop_back();
                }
            }
            else if(s[i]=='#'){
                string x=p;
                p+=x;
            }
            else if(s[i]=='%'){
                reverse(p.begin(),p.end());
            }
            else{
                p.push_back(s[i]);
            }
        }
        return  p;
        
    }
};