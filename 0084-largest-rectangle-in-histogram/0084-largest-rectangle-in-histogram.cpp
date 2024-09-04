class Solution {
public:
    vector<int> prevsmaller(vector<int> input){
        stack<int> st;
        st.push(-1);
        vector<int> ans(input.size());
        for(int i=0;i<input.size();i++){
            while(st.top()!=-1 && input[st.top()]>=input[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);
        }
    return ans;
    }
    vector<int> nextsmaller(vector<int> input){
        stack<int> st;
        st.push(-1);
        vector<int> ans(input.size());
        for(int i=input.size()-1;i>=0;i--){
            while(st.top()!=-1 && input[st.top()]>=input[i]){
                st.pop();
            }
            ans[i]=st.top();
            st.push(i);

        }
    return ans;

    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int> prev=prevsmaller(heights);
        vector<int> next=nextsmaller(heights);
        int maxi=INT_MIN;
        for(int i=0;i<heights.size();i++){
            int l=heights[i];
            if(next[i]==-1){
                next[i]=heights.size();
            }
            int w=next[i]-prev[i]-1;
            int area=l*w;
            maxi=max(area,maxi);
            
        }
    return maxi;    
    }
};