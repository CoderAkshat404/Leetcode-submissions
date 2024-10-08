class Solution {
public:
    int majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int x=0;
        for(auto i:m){
            if(i.second>(nums.size()/2)){
                x= i.first;
            }
        }
      return x; 
    }
};