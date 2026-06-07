class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        #define int long long
        vector<vector<int>> v;
        sort(intervals.begin(),intervals.end());
        
        int start=intervals[0][0];
        int last=intervals[0][1];
        for(int i=1;i<intervals.size();i++){
            if(intervals[i][0]<=last){
                last=max(last,(long long)intervals[i][1]);
            }
            else{
                v.push_back({start,last});
                start=intervals[i][0];
                last=intervals[i][1];
            }

        }
        v.push_back({start,last});
        int x=(brightness+2)/3;
        int ans=0;
        for(int i=0;i<v.size();i++){
            ans+=(v[i][1]-v[i][0]+1)*x;
        }
        return ans;
        #undef int

        
    }
};