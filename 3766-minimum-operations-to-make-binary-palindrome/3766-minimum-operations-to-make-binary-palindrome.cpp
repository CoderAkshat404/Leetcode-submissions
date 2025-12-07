class Solution {
public:
    bool check(string s){
        int i=0;
        int j=s.length()-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    vector<int> minOperations(vector<int>& nums) {
        map<int,vector<int>> m;
        for(int i=1;i<=5000;i++){
            string s="";
            int curr=i;
            int len=0;
            while(curr>>len){
                len++;
            }
            for(int j=0;j<len;j++){
                int b=(curr>>j)&1;
                if(b==1){
                    s+='1';
                }
                else{
                    s+='0';
                }
            }
            if(check(s)){
                m[len].push_back(i);
            }
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            string s="";
            int curr=nums[i];
            int len=0;
            while(curr>>len){
                len++;
            }
            for(int j=0;j<len;j++){
                int b=(curr>>j)&1;
                if(b==1){
                    s+='1';
                }
                else{
                    s+='0';
                }
            }
            if(check(s)){
                ans[i]=0;
                
            }
            else{
                vector<int> v=m[len];
                int mini=1e9;
                for(int j=0;j<v.size();j++){
                    mini=min(mini,abs(v[j]-nums[i]));
                }
                ans[i]=mini;
            }
        }

      return ans;  
    }
};