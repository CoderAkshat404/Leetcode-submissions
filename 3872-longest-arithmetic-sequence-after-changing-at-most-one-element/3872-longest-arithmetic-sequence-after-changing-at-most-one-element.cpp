class Solution {
public:
    
    int solve(vector<int>& nums){
        set<int> s;
        vector<int>temp=nums;
        int l=0;
        int r=l+1;
        int k=1;
        int n=nums.size();
        int ans=0;
        while(l+1<n){
            if(s.find(l+1)!=s.end() && r==l+1){
                
                k=1;
                temp[l+1]=nums[l+1];
                s.erase(l+1);
       
            }
            if(s.find(l)!=s.end() && r==l+1){
                
                k=1;
                temp[l]=nums[l];
                 s.erase(l);
            }
            
            int d=temp[l+1]-temp[l];
            while(r+1<n && ((temp[r+1]-temp[r]==d) ||(k>0))){
                r++;
                if(temp[r]-temp[r-1]!=d){
                    temp[r]=temp[r-1]+d;
                    s.insert(r);
                    
                    k=0;
                    
                }
            }
        
            ans=max(ans,r-l+1);
            if(s.find(l)!=s.end()){
                temp[l]=nums[l];
                k=1;
                s.erase(l);
            }
            l++;
        }
        return ans;
        
        
        
        
    }
    int longestArithmetic(vector<int>& nums) {
        if(nums.size()<=2){
            return nums.size();
        }
        int x=solve(nums);
        cout<<endl;
        cout<<endl;
        reverse(nums.begin(),nums.end());
        
        
        int y=solve(nums);
        return max(x,y);
        
    }
};
