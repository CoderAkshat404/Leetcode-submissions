class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        if(n<=2){
            return n;
        }
        int l=0;
        while(n>>l){
            l++;
        }
        return (1<<l);
        
    }
};