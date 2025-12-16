class Solution {
public:
    long long bowlSubarrays(vector<int>& nums) {
        #define int long long
        int n=nums.size();
        vector<int> nge(nums.size());
        stack<pair<int,int>> st;
        for(int i=n-1;i>=0;i--){
            int ele=nums[i];
            if(st.empty()){
                nge[i]=-1;
                st.push({nums[i],i});
            }
            else{
                while(!st.empty() && st.top().first<ele){
                    st.pop();
                }
                if(st.empty()){
                    nge[i]=-1;
                    st.push({nums[i],i});
                }
                else{
                    nge[i]=st.top().second;
                    st.push({nums[i],i});

                }
                
            }

        }
        vector<int> pge(n);
        while(!st.empty()){
            st.pop();
        }
        for(int i=0;i<n;i++){
            int ele=nums[i];
            if(st.empty()){
                pge[i]=-1;
                st.push({nums[i],i});
            }
            else{
                while(!st.empty() && st.top().first<ele){
                    st.pop();
                }
                if(st.empty()){
                    pge[i]=-1;
                    st.push({nums[i],i});
                }
                else{
                    pge[i]=st.top().second;
                    st.push({nums[i],i});

                }
                
            }

        }
        int ans=0;
        for(int i=0;i<n;i++){
            int next=nge[i];
            int prev=pge[i];
            if(next !=-1 && prev!=-1){
                ans++;
            }
        }
        return ans;
        #undef int

        
    }
};