class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0){
            return 0;
        }
        map<int,bool> m;
        int count=1;
        int maxi=1;
        sort(nums.begin(),nums.end());
        int prev=nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]!=prev){
                m[nums[i]]=true;
            }
            
        }
        for(auto i:m){
            cout<<i.first<<" "<<i.second<<endl;
        }
        cout<<prev<<endl;
        for(auto i:m){
            if(i.second==true && (prev==i.first-1)){
                count++;
                maxi=max(count,maxi);
                prev=i.first;
            }
            else{
                count=1;
                prev=i.first;
            }
        }
        return maxi;
    }
};