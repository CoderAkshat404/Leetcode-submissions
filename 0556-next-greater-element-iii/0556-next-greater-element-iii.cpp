class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> v;
        while(n!=0){
            v.push_back(n%10);
            n=n/10;
        } 
        reverse(v.begin(),v.end());
        bool isdec=true;
        for(int i=0;i<v.size()-1;i++){
            if(v[i]<v[i+1]){
                isdec=false;
                break;
            }
        }
        if(isdec) return -1;
        next_permutation(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++){
            if(1LL*ans*10>INT_MAX) return -1;
            if((long long)ans*10+v[i]>INT_MAX) return -1;
            ans=ans*10+v[i];
        }
        return ans;
        
    }
};