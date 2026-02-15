class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        // nums[i]-nums[j]==k
        // nums[i]-k==nums[j] || nums[j]==k-nums[i];

        map<int,int> m;
        set<pair<int,int>> s;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int target1=nums[i]-k;
            int target2=k+nums[i];
            if(m.find(target1)!=m.end()){
                pair<int,int> p={nums[i],target1};
                if(p.second<p.first){
                    p={target1,nums[i]};
                }
                
                s.insert(p);
            }
            if(m.find(target2)!=m.end()){
                pair<int,int> p={nums[i],target2};
                if(p.second<p.first){
                    p={target2,nums[i]};
                }
                
                s.insert(p);
            }
            m[nums[i]]++;

        }
        return s.size();
        
    }
};