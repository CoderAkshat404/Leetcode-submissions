class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans=0;
        int left=0;
        while(numBottles!=0){
            ans+=numBottles;
            int x=(left+numBottles)/numExchange;
            left=(left+numBottles)%numExchange;
            numBottles=x;



        }
        return ans;
        
    }
};