class Solution {
public:
    int maxConsecutive(int bottom, int top, vector<int>& special) {
        int ans=0;
        int prev=bottom;
        sort(special.begin(),special.end());
        for(auto i:special){
            ans=max(ans,(i-prev));
            prev=i+1;
        }
        ans=max(ans,top-prev+1);
        return ans;
        
    }
};