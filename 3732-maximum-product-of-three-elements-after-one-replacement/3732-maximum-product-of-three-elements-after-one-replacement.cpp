class Solution {
public:
    long long maxProduct(vector<int>& nums) {
        #define int long long
        vector<int> pos;
        vector<int> neg;
        for(auto i:nums){
            if(i>=0){
                pos.push_back(i);
            }
            else{
                neg.push_back(i);
            }
        }
        sort(pos.rbegin(),pos.rend());
        sort(neg.begin(),neg.end());
        
        int a=0;
        int b=0;
        int c=0;
        int an=0;
        int bn=0;
        int cn=0;
        
        if(pos.size()>=1){
            a=pos[0];
        }
        if(pos.size()>=2){
          
            a=pos[0];
            b=pos[1];
        }
        if(pos.size()>=3){
            a=pos[0];
            b=pos[1];
            c=pos[2];
        }
        if(neg.size()>=1){
            an=neg[0];
        }
        if(neg.size()>=2){
            an=neg[0];
            bn=neg[1];
        }
        if(neg.size()>=3){
            an=neg[0];
            bn=neg[1];
            cn=neg[2];
        }
        
        int ans=-1e9;
        int ans1=(a*b*(long long)1e5);
        ans=max(ans,ans1);
        int ans2=-1LL*(an*bn*(long long)1e5);
       
        ans=max(ans,abs(ans2));
        int ans3=-1LL*(a*an*(long long)1e5);
       
        ans=max(ans,abs(ans3));
        return ans;
        #undef int
        

        
    }
};