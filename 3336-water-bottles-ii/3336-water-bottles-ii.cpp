class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans=numBottles;
        int left=numBottles;
        while(left>=numExchange){
            ans++;
            left-=numExchange;
            numExchange++;
            left++;
        }
        return ans;

        
    }
};