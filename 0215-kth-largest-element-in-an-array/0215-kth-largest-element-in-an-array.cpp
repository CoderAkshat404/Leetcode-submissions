class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto i:nums){
            if(pq.size()==k){
                if(i>pq.top()){
                    pq.pop();
                    pq.push(i);
                }
            }
            else{
                pq.push(i);
            }
            
        }
        
        return pq.top();

        
    }
};