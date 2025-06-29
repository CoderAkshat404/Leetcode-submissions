class Solution {
public:
    int solve(string a,string b){
        int n=a.length();
        int m=b.length();
        int ans=0;
        int i=0;
        int j=0;
        while(i<n && j<m){
            if(a[i]==b[j]){
                ans++;
                i++;
                j++;
            }
            else{
                break;
            }
        }
        return ans;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        vector<int> pre;
        int n=words.size();
        if(n==1){
            return {0};
        }
        for(int i=0;i<words.size()-1;i++){
            int x=solve(words[i],words[i+1]);
            pre.push_back(x);
        }
        vector<int> v=pre;
        vector<int> ans;
        sort(v.begin(),v.end());
        // for(auto i:v){
        //     cout<<i<<" ";
        // }
        int maxi=0;
        int secondmaxi=0;
        if(pre.size()>=2){
            maxi=v.back();
            secondmaxi=v[v.size()-2];
        }
        else{
            maxi=v.back();
        }
        // cout<<secondmaxi;
       
        for(int i=0;i<n;i++){
            if(i==0){
                if(pre[i]==maxi){
                    ans.push_back(secondmaxi);
                }
                else{
                    ans.push_back(maxi);
                }
            }
            else if(i && i<n-1 && (pre[i]==maxi || pre[i-1]==maxi)){
                int x=solve(words[i-1],words[i+1]);
                ans.push_back(max(secondmaxi,x));
            }
            else if(i && i<n-1){
                int x=solve(words[i-1],words[i+1]);
                ans.push_back(max(maxi,x));
            }
            else if(i==n-1){
                if(pre.back()==maxi){
                    ans.push_back(secondmaxi);
                }
                else{
                    ans.push_back(maxi);
                }
            }
        }
        return ans;
    }
};