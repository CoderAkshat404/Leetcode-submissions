class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int> m;
        map<int,int> freq;
        for(auto i:nums){
            m[i]++;
        }
        for(auto i:m){
            freq[i.second]++;
        }
       
        for(auto i:nums){
            if(freq[m[i]]==1){
                return i;
            }
        }
        return -1;
        
    }
};