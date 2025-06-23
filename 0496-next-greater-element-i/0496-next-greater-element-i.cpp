class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> m;
        stack<int> s;
        int n=nums2.size();
        for(int i=n-1;i>=0;i--){
            int ele=nums2[i];
            if(s.empty()){
                s.push(ele);
                m[ele]=-1;
            }
            else{
                while(!s.empty() && s.top()<ele){
                    s.pop();
                }
                if(!s.empty()){
                m[ele]=s.top();}
                else{
                    m[ele]=-1;
                }
                s.push(ele);
            }
        }
        vector<int> ans;
        for(auto i:nums1){
            ans.push_back(m[i]);
        }
        return ans;
        
    }
};