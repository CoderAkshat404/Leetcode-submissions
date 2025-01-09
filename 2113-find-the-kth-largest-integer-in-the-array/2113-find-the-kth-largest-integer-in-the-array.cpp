class Solution {
public:
static bool cmp(string a,string b){
            if(a.length()==b.length()){
               return a<b;
            }
        
            else{
                return a.length()<b.length();
            }
        return a<b;
        }
    string kthLargestNumber(vector<string>& nums, int k) {
        
        sort(nums.begin(),nums.end(),cmp);
        int j=nums.size()-1;
        int c=0;
        while(c<k-1){
            j--;
            c++;
        }
        return nums[j];
        
    }
};