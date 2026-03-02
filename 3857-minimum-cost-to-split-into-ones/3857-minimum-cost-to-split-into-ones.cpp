class Solution {
public:
    int minCost(int n) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<n;i++){
            pq.push(1);
        }
        int ans=0;
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            ans+=(x*y);
            pq.push(x+y);


        }
        return ans;
        
    }
};