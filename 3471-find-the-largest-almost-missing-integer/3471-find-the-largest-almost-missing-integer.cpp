class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        map<int,int> m;
        for(int i=0;i<nums.size();i++){
            if(i+k-1<nums.size()){
                set<int> s;
                for(int j=i;j<=i+k-1;j++){
                  s.insert(nums[j]);
                }
                for(auto j:s){
                    m[j]++;
                }
            }
        }
        int maxi=-1;
        for(auto i:m){
            if(i.second==1)
            maxi=max(maxi,i.first);

        }
        return maxi;
        
    }
};