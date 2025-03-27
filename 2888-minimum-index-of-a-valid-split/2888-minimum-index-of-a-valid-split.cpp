class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        int n=nums.size();
        int x=-1;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++){
            m[nums[i]]++;
            if(m[nums[i]]>n/2){
                x=nums[i];
                break;
            }

        }
        unordered_map<int,int> m1;
        unordered_map<int,int> m2;
        vector<int> forw;
        vector<int> back;
        for(int i=0;i<n;i++){
            m1[nums[i]]++;
            if(m1[x]>(i+1)/2){
                forw.push_back(x);
            }
            else{
                forw.push_back(-1);
                
            }
        }
        reverse(nums.begin(),nums.end());
        for(int i=0;i<n;i++){
            m2[nums[i]]++;
            if(m2[x]>(i+1)/2){
                back.push_back(x);
            }
            else{
                back.push_back(-1);
                
            }
        }
        for(auto i:forw){
            cout<<i<<" ";
        }
        cout<<endl;
        for(auto i:back){
            cout<<i<<" ";
        }
        reverse(back.begin(),back.end());
        int idx=-1;
        for(int i=0;i<n-1;i++){
            if(forw[i]==x && back[i+1]==x){
                idx=i;
                break;
            }
        }
        return idx;



        
    }
};