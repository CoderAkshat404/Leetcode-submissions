class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }
        int maxi=INT_MIN;
        for(auto i:m){
            maxi=max(maxi,i.second);
        }
        int sum=0;
        for(auto i:m){
            if(i.second==maxi){
                sum+=i.second;
            }
        }
        return sum;
        
    }
};