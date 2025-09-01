class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxi=INT_MIN;
        int l=0;
        int r=height.size()-1;
        while(l<r){
            int mini=min(height[l],height[r]);
            maxi=max(maxi,mini*(r-l));
            if(mini==height[l]){
                l++;
            }
            else{
                r--;
            }
        }
        return maxi;
        
    }
};