class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int count=0;
        unordered_map<int,bool> m;
        int x=0;
        sort(nums.rbegin(),nums.rend());
        for(int i=0;i<nums.size();i++){
            if(m[nums[i]]==false){
                count++;
            }
            m[nums[i]]=true;
            if(count==3){
                x=nums[i];
                break;
            }

        }
        if(count==3){
            return x;
        }
        else{
            return nums[0];
        }
        
    }
};