class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> m;
        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }
        int x;
        for(auto i:m){
            if(i.second==1){
                x=i.first;
                break;
            }
        }

    return x;
    }
      
    
};