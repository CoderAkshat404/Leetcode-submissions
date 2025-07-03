class Solution {
public:
    bool checkValidString(string s) {
        stack<char> st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='*'){
                st.push(s[i]);
            }
            else{
                stack<int> a;
                while(!st.empty() && st.top()!='('){
                    a.push(st.top());
                    st.pop();
                }
                if(st.empty()){
                    while(!a.empty()){
                        st.push(a.top());
                        a.pop();
                    }
                    if(st.empty()) return false;
                    st.pop();
                }
                else{
                    st.pop();
                    while(!a.empty()){
                        st.push(a.top());
                        a.pop();
                    }
                    
                }
            }
        }
        int cnt=0;
        while(!st.empty()){
            if(st.top()=='(' && cnt==0){
                return false;
            }
            else if(st.top()=='('){
                cnt--;
            }
            else{
                cnt++;
            }
            st.pop();
        }
        return true;
        
    }
};