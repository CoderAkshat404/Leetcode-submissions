class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        vector<int> c1=nums;
        vector<int> c2=nums;
        for(int i=0;i<nums.size()-1;i++){
            if(nums[i]>nums[i+1]){
                c1[i]=nums[i+1];
                c2[i+1]=nums[i];
                break;
            }
          


        }
        bool f1=true;
        bool f2=true;
        for(int i=0;i<c1.size()-1;i++){
            if(c1[i]>c1[i+1]){
                f1=false;
                break;
            }
        }
        for(int i=0;i<c1.size()-1;i++){
            if(c2[i]>c2[i+1]){
                f2=false;
                break;
            }
        }
        if(f1==false && f2==false){
            return false;
        }
        return true;
       
    }
};