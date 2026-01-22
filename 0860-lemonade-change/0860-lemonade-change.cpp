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
                if(fc==0){
                    return false;
                }
                tc++;
                fc--;
            }
            else{
                if(tc>0 && fc>0){
                    tc--;
                    fc--;
                }
                else if(fc>=3){
                    fc-=3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};