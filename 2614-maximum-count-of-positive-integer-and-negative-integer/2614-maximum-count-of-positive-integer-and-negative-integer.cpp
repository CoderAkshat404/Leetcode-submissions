class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos=upper_bound(nums.begin(), nums.end(),0)-nums.begin();
        int neg=lower_bound(nums.begin(), nums.end(),0)-nums.begin()-1;
        int x=nums.size()-pos;
        int y=INT_MIN;
        if(neg>=0){
            y=neg+1;    
        }
        // cout<<x<<" "<<y<<endl;
        return max(x,y);


        
    }
};