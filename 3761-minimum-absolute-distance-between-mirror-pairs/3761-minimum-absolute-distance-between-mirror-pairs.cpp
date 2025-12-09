class Solution {
public:
    int remo(int n){
        string s=to_string(n);
        reverse(s.begin(),s.end());
        string p="";
        int i=0;
        while(i<s.length()){
            if(s[i]=='0'){
                i++;
            }
            else{
                break;
            }
        }
        while(i<s.length()){
            p+=s[i];
            i++;
        }
        reverse(p.begin(),p.end());
        return stoi(p);

    }
    int get(int n){
        string s=to_string(n);
        reverse(s.begin(),s.end());
        string p="";
         int i=0;
        while(i<s.length()){
            if(s[i]=='0'){
                i++;
            }
            else{
                break;
            }
        }
        while(i<s.length()){
            p+=s[i];
            i++;
        }
        return stoi(p);
    }
    int minMirrorPairDistance(vector<int>& nums) {
        map<int,int> m;
         map<int,bool> mark;
        int mini=1e9;
        for(int i=0;i<nums.size();i++){
             string s=to_string(nums[i]);
             if(s.back()=='0'){
                mark[i]=true;
             }
            nums[i]=remo(nums[i]);
        }
        for(int i=0;i<nums.size();i++){
            int x=get(nums[i]);
            if(mark[i]){
                m[nums[i]]=i;
                continue;
            }
            if(m.find(x)!=m.end()){
                cout<<i<<" "<<m[x]<<endl;
                mini=min(mini,i-m[x]);
            }
            m[nums[i]]=i;

        }
        if(mini==1e9){
            return -1;
        }
        return mini;
        
    }
};