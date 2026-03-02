class Solution {
public:
    string mergeCharacters(string s, int k) {
        bool flag=true;
        while(flag){
        flag=false;
        for(int i=0;i<s.length();i++){
            for(int j=i+1;j<s.length();j++){
                if(s[i]==s[j] && j-i<=k){
                    s.erase(s.begin()+j);
                    flag=true;
                    break;
                }
            }
            if(flag){
                break;
            }
        }
        }
        return s;
        
    }
};