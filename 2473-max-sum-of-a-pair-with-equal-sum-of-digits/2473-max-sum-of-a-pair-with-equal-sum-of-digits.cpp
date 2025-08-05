class Solution {
public:
    int calc(int num){
        int s=0;
        while(num>0){
            s+=(num)%10;
            num=num/10;
        }
        return s;
    }
    int maximumSum(vector<int>& nums) {
        vector<multiset<int>> adj(100);
        for(auto i:nums){
            int x=calc(i);
            adj[x].insert(i);
        }
        int maxi=-1e9;
        for(int i=0;i<100;i++){
            multiset<int> s=adj[i];
            if(s.size()>=2){
                int a=*s.rbegin();
                s.erase(s.find(a));
                int b=*s.rbegin();
                maxi=max(maxi,a+b);
            }
        }
        if(maxi==-1e9){
            return -1;
        }
        return maxi;
        
    }
};