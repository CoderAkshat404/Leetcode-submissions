class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        for(auto i:m){
            if(pq.size()==k){
                 if(i.second>pq.top().first){
                    pq.pop();
                    pq.push({i.second,i.first});
                 }
            }
            else{
                pq.push({i.second,i.first});
            }   
        }
        nums.clear();
        while(!pq.empty()){
            nums.push_back(pq.top().second);
            pq.pop();
        }
        return nums;
        
    }
};