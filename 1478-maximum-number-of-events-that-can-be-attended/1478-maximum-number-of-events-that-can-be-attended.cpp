class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        int day=events[0][0];
        priority_queue<int,vector<int>,greater<int>> pq;
        int i=0;
        int n=events.size();
        int ans=0;
        while(i<n || !pq.empty()){
            while(i<n && events[i][0]==day){
                pq.push(events[i][1]);
                i++;
            }
            while(!pq.empty() && pq.top()<day){
                pq.pop();
            }
            if(!pq.empty()){
                int ele=pq.top();
                pq.pop();
                ans++;
            }
            day++;

        }
        return ans;
        
    }
};