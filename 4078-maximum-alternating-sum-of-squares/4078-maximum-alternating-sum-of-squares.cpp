class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        #define int long long
        priority_queue<int> pq;
        for(auto i:nums){
            pq.push(abs(i));
        }
        int n=nums.size();
        int ans=0;
        for(int i=0;i<(n+1)/2;i++){
            int x=pq.top()*pq.top();
            ans+=x;
            pq.pop();
        }
        for(int i=0;i<(n)/2;i++){
            int x=pq.top()*pq.top();
            ans-=x;
            pq.pop();
        }
        return ans;
        #undef int
        
    }
};