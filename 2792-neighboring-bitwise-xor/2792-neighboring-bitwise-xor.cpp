class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int c1=count(derived.begin(),derived.end(),1);
        if(c1&1){
            return false;
        }
        return true;
        
    }
};