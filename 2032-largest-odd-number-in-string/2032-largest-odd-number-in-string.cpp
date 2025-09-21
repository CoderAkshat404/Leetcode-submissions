class Solution {
public:
    string largestOddNumber(string num) {
        string s="";
        int idx=-1;
        for(int i=0;i<num.length();i++){
            if((num[i]-'0')&1){
                idx=i;
                
            }
        }
        if(idx==-1){
            return "";
        }
        return num.substr(0,idx+1);
        return s;
        
    }
};