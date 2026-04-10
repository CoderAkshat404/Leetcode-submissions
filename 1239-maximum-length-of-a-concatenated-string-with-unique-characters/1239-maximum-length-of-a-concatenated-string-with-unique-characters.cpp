class Solution {
public:
    int maxi=0;
    string s="";
    bool check(string &temp){
        unordered_set<char> st;
        for(auto i:s){
            st.insert(i);
        }
        for(auto i:temp){
            if(st.find(i)!=st.end()) return false;
            st.insert(i);
        }
        return true;

    }
    void solve(int i,vector<string>& arr){
        if(i==arr.size()){
            maxi=max(maxi,(int)s.length());
            return;
        }
        
        if(check(arr[i])){
            string temp=s;
            s+=arr[i];
            solve(i+1,arr);
            s=temp;
        } 
        solve(i+1,arr);

    }
    int maxLength(vector<string>& arr) {
        solve(0,arr);
        return maxi;
        
    }
};