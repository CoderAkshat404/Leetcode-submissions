class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:nums){
            pq.push(i);
        }
        while(k--){
            int x=pq.top();
            pq.pop();
            x=x+1;
            pq.push(x);
        }
        long long ans=1;
        while(!pq.empty()){
            ans=(ans*pq.top())%1000000007;
            pq.pop();
        }
        return ans%1000000007;
        
    }
};