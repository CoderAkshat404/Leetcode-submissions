class Solution {
public:
    int minOperations(string s) {
        sort(s.begin(),s.end());
        int ans=0;
        set<char> st;
        vector<char> v;
        for(auto i:s){
            if(st.find(i)==st.end()){
                st.insert(i);
                v.push_back(i);
            }
        }
        if(v.size()>0){
        for(int i=0;i<v.size()-1;i++){
            if(v[i]=='a'){
                continue;
            }
            ans+=v[i+1]-v[i];
        }
        }
        if(v.back()!='a'){
            ans+=('a'-v.back()+26);
        }
        return ans;
        
    }
};