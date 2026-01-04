class Solution {
public:
    string largestEven(string s) {
        while(s.length()>0){
            if(s.back()=='1'){
                s.pop_back();
            }
            else{
                break;
            }
        }
        return s;
        
    }
};