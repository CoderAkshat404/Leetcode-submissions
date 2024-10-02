class Solution {
public:
    int solve(int n){
        int x=0;
        while(n!=0){
            int y=n%10;
            x+=y;
            n=n/10;
        }
        return x;
    }
    int minElement(vector<int>& nums) {
        vector<int> tr;
        for(int i=0;i<nums.size();i++){
            tr.push_back(solve(nums[i]));
        }
        sort(tr.begin(),tr.end());
        return tr[0];
        
    }
};