class Solution {
public:
    int buttonWithLongestTime(vector<vector<int>>& events) {
        int maxi=INT_MIN;
        int prev=0;
        int ans=INT_MAX;
        for(int i=0;i<events.size();i++){
            if(events[i][1]-prev>maxi){
                maxi=events[i][1]-prev;
                ans=events[i][0];
            }
            if(events[i][1]-prev==maxi){
                ans=min(ans,events[i][0]);
            }
            prev=events[i][1];
        }
        return ans;
        
    }
};