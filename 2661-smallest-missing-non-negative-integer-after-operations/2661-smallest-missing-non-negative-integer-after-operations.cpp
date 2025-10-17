class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        unordered_map<int,int> m;
        for(auto i:nums){
            if(i>=0){
            m[abs(i%value)]++;}
            else{
                int x=(-i+value-1)/value;
                i=i+(x*value);
                m[i%value]++;
            }
        }
        int ans=0;
        for(int i=0;i<=nums.size();i++){
            if(m[i%value]>0){
                ans++;
                m[i%value]--;
            }
            else{
                break;
            }

        }
        return ans;
        
        
    }
};