class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string s1="";
        for(auto i:s){
            if(i=='#'){
                if(!s1.empty())
                s1.pop_back();
            }
            else{
                s1+=i;
            }
        }
        string s2="";
        for(auto i:t){
            if(i=='#'){
                if( !s2.empty())
                s2.pop_back();
            }
            else{
                s2+=i;
            }
        }
        return s1==s2;
        
    }
};