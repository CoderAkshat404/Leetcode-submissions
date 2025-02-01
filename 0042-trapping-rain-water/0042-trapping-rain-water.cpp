class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> suff(n);
        int currm=0;
        for(int i=n-1;i>=0;i--){
            currm=max(currm,height[i]);
            suff[i]=currm;
        }
        int ans=0;
        currm=0;
        for(int i=0;i<n;i++){
            currm=max(currm,height[i]);
            if(height[i]<currm && height[i]< suff[i]){
                ans+=min(suff[i],currm)-height[i];
            }
        }
        return ans;

        
    }
};