class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        vector<pair<int,int>> z;
        int st=-1;
        int cnt=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='0'){
                if(cnt==0){
                    st=i;
                }
                cnt++;
            }
            else{
                if(cnt>0){
                    z.push_back({st,i-1});
                    cnt=0;
                }
            }
        }
        if(cnt>0){
            z.push_back({st,s.length()-1});
        }
      
        int maxi=0;
        int ones=0;
        int oc=0;
        for(auto i:s){
            if(i=='1')
            oc++;
        }
        if(!z.empty()){
            for(int i=0;i<z.size()-1;i++){
                int l=z[i].first;
                int r=z[i+1].second;
                int rn=z[i+1].first;
                int ln=z[i].second;
                ones=rn-ln-1;
                maxi=max(maxi,oc-ones+(r-l+1));
                
               
            }
        }
        
        maxi=max(maxi,oc);
      
        return  maxi;
        
    }
};