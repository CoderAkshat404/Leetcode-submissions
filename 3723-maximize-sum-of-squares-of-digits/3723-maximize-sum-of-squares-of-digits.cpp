class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum) return "";
         string ans="";
        
           
            while(sum>9 && num>0){
                ans+='9';
                sum-=9;
                num--;
            }
            ans+=to_string(sum);
            num--;
            while(num>0){
                ans+='0';
                num--;
            }
        
        return ans;
        
    }
};