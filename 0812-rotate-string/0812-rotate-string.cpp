class Solution {
public:
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.length();i++){
            char c=s.back();
            s.pop_back();
            s.insert(s.begin(),c);
            if(s==goal){
                return true;
            }
        }
        return false;
        
    }
};