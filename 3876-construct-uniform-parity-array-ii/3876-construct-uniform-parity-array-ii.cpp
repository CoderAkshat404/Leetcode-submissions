class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool flag1=true;
        multiset<int> ms;
        for(auto i:nums1){
            if(i&1){
                ms.insert(i);
            }
        }
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==0){
                if(nums1[i]-(*ms.begin())<1){
                    flag1=false;
                    break;
                }
            }
        }
        bool flag2=true;
       
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]%2==1){
                if((*ms.begin()==nums1[i])){
                     flag2=false;
                    break;

                }
               
            }
            
        }
        return (flag1 || flag2);


        
    }
};