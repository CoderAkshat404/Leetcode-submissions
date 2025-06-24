class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char> st;
        for(int i=0;i<nums.length();i++){
            if(st.empty()){
                st.push(nums[i]);
            }
            else{
                while(!st.empty() && st.top()>nums[i] && k>0){
                    st.pop();
                    k--;
                }
                st.push(nums[i]);
            }
        }
        while(k--){
            st.pop();
        }
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        while(ans.length()>0 && ans.back()=='0'){
            ans.pop_back();
        }
        if(ans==""){
            return "0";
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};