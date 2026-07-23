class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        else{
            int x=0;
            while(n>>x){
                x++;
            }
            return (1<<(x));
        }
        
    }
};