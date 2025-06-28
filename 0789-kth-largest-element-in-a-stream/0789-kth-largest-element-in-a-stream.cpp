class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int sz;
    KthLargest(int k, vector<int>& nums) {
        sz=k;
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

        
    }
    
    int add(int i) {
        if(pq.size()==sz){
                if(i>pq.top()){
                    pq.pop();
                    pq.push(i);
                }
        }
        else{
                pq.push(i);
            }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */