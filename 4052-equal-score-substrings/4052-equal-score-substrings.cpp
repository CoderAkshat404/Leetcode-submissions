class Solution {
public:
    bool scoreBalance(string s) {
        int tot=0;
        for(auto i:s){
            tot+=(((int)i)%97)+1;
        }
      
        int x=0;
        for(auto i:s){
            x+=(((int)i)%97)+1;
            if(tot-x==x){
                return true;
            }
        }
        return false;
        
    }
};