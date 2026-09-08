class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n=nums.size();
        vector<int> prefeven(n);
        vector<int> prefodd(n);
        int oddsum=0;
        int evensum=0;
        for(int i=0;i<nums.size();i++){
            if(i%2==0){
                evensum+=nums[i];
            }
            else{
                oddsum+=nums[i];
            }
            prefeven[i]=evensum;
            prefodd[i]=oddsum;
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int beforeeven=0;
            int beforeodd=0;
            if(i-1>=0){
                beforeeven=prefeven[i-1];
                beforeodd=prefodd[i-1];
            }
            int aftereven=prefodd.back()-prefodd[i];;
            int afterodd=prefeven.back()-prefeven[i];
            if(beforeeven+aftereven==beforeodd+afterodd) ans++;
        }
        return ans;
        
    }
};