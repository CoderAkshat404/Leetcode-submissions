class Solution {
public:
    static bool cmp(vector<int> &a,vector<int> &b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int cnt=0;
        int end=-1e9;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            if(intervals[i][0]>=end){
                cnt++;
                end=intervals[i][1];
            }
        }
        return n-cnt;
        
    }
};