class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fc=0;
        int tc=0;
        for(int i=0;i<bills.size();i++){
            if(bills[i]==5){
                fc++;
            }
            else if(bills[i]==10){
                tc++;
                if(fc>0){
                    fc--;
                }
                else{
                    return false;
                }
            }
            else{
                if(tc>=1 && fc>=1){
                    tc--;
                    fc--;
                }
                else if(fc>=3){
                    fc=fc-3;
                }
                
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};