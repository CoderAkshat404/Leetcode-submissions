class Solution {
public:
    bool judgeCircle(string moves) {
        int xc=0;
        int yc=0;
        for(auto i:moves){
            if(i=='L'){
                xc++;
            }
            else if(i=='R'){
                xc--;
            }
            else if(i=='U'){
                yc--;
            }
            else{
                yc++;
            }
        }
        return (xc==0 &&  yc==0);
        
    }
};