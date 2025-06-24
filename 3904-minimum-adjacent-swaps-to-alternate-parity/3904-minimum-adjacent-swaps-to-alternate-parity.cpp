class Solution {
public:
    int minSwaps(vector<int>& nums) {
        vector<int> oddpos;
        vector<int> evenpos;
        if(nums.size()==1){
            return 0;
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]&1){
                oddpos.push_back(i);
            }
            else{
                evenpos.push_back(i);
            }
        }
       
    if (abs((int)(oddpos.size() - evenpos.size())) > 1){
                return -1;
    }
                if(oddpos.size()==evenpos.size()){
                    int ans1=0;
                    int a=0;
                    for(int i=1;i<nums.size();i+=2){
                        ans1+=abs(evenpos[a]-i);
                        a++;
                    }
                    int ans2=0;
                    a=0;
                    for(int i=1;i<nums.size();i+=2){
                        ans2+=abs(oddpos[a]-i);
                        a++;
                    }
                    return min(ans1,ans2);
                    
                    
                }
                else if(oddpos.size()>evenpos.size()){
                    int ans=0;
                    int a=0;
                    for(int i=1;i<nums.size();i+=2){
                        ans+=abs(evenpos[a]-i);
                        a++;
                    }
                    return ans;
                    
                }
                else{ 
                    int ans=0;
                    int a=0;
                    for(int i=1;i<nums.size();i+=2){
                        ans+=abs(oddpos[a]-i);
                        a++;
                    }
                    return ans;
                    
                }
            
      return  -1;  
    }
};