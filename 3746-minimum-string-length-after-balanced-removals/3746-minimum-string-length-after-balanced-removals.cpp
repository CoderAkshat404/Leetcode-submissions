class Solution {
public:
    int minLengthAfterRemovals(string s) {
        int ac=0;
        int bc=0;
        for(auto i:s){
            if(i=='a'){
                ac++;
            }
            else{
                bc++;
            }
        }
        return abs(ac-bc);
        
    }
};