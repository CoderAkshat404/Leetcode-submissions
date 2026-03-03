class Solution {
public:
    vector<int> makeParityAlternating(vector<int>& nums) {
        int maxi=-1e9;
        int mini=1e9;
        vector<int> temp=nums;
        for(auto i:nums){
            maxi=max(maxi,i);
            mini=min(mini,i);
        }
        vector<int> ans;
        int a=0;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]%2)!=curr){
                a++;
                int x=maxi-nums[i];
                int y=nums[i]-mini;
                if(x<y){
                    nums[i]=nums[i]-1;
                }
                else{
                    nums[i]=nums[i]+1;
                }

            }
            curr=1-curr;
        }
        // for(auto i:nums){
        //     cout<<i<<" ";
        // }
        // cout<<endl;

        int nm=-1e9;
        int nmi=1e9;
        for(auto i:nums){
            nm=max(nm,i);
            nmi=min(nmi,i);
        }
        //  cout<<nm<<" "<<nmi<<endl;
        ans={a,nm-nmi};
        nums=temp;
        a=0;
        curr=0;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]%2)!=curr){
                a++;
                int x=maxi-nums[i];
                int y=nums[i]-mini;
                if(x<=y){
                    nums[i]=nums[i]-1;
                }
                else{
                    nums[i]=nums[i]+1;
                }

            }
            curr=1-curr;
        }

        nm=-1e9;
        nmi=1e9;
        for(auto i:nums){
            nm=max(nm,i);
            nmi=min(nmi,i);
        }
        if(nm-nmi<ans[1]){
            ans={a,nm-nmi};
        }
        int b=0;
        curr=1;
        nums=temp;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]%2)!=curr){
                b++;
                int x=maxi-nums[i];
                int y=nums[i]-mini;
                if(x<y){
                    nums[i]=nums[i]-1;
                }
                else{
                    nums[i]=nums[i]+1;
                }

            }
            curr=1-curr;
        }
        nm=-1e9;
        nmi=1e9;
        for(auto i:nums){
            nm=max(nm,i);
            nmi=min(nmi,i);
        }
         if(b==a){
            if(nm-nmi<ans[1]){
                ans={b,nm-nmi};
            }
        }
        if(b<a){
            ans={b,nm-nmi};

        }
        
        b=0;
        curr=1;
        nums=temp;
        for(int i=0;i<nums.size();i++){
            if(abs(nums[i]%2)!=curr){
                b++;
                int x=maxi-nums[i];
                int y=nums[i]-mini;
                if(x<=y){
                    nums[i]=nums[i]-1;
                }
                else{
                    nums[i]=nums[i]+1;
                }

            }
            curr=1-curr;
        }
       
       nm=-1e9;
       nmi=1e9;
        for(auto i:nums){
            nm=max(nm,i);
            nmi=min(nmi,i);
        }
        if(b==a){
            if(nm-nmi<ans[1]){
                ans={b,nm-nmi};
            }
        }
        if(b<a){
            ans={b,nm-nmi};

        }

        return ans;
        
    }
};