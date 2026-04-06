class Solution {
public:
    char findm(char c){
        if(c>='0' && c<='9'){
            return (('9'-c)+'0');
        }
        else{
            return (('z'-c)+'a');
        }
    }
    int mirrorFrequency(string s) {
        map<char,int> m1;
        for(auto i:s){
            m1[i]++;
        }
        set<pair<int,int>> st;
        int ans=0;
        for(auto i:s){
            char x=i;
            char y=findm(i);
            // cout<<x<<" "<<y<<endl;
            if(x>y){
                swap(x,y);
            }
            if(st.find({x,y})==st.end()){
                // cout<<"here for x="<<x<<"y="<<y<<endl;
                ans+=abs(m1[x]-m1[y]);
                st.insert({x,y});
            }

        }
        return ans;

        
    }
};