class Solution {
public:
    void calch(int i,int sum,vector<int>&h,int lights,set<int>&s1){
        if(i>=h.size()){
            if(sum>=0 && sum<=11 && lights==0){
                s1.insert(sum);
                return ;
            }
            else{
                return ;
            }
        }
        calch(i+1,sum+h[i],h,lights-1,s1);
        calch(i+1,sum,h,lights,s1);
    }
    void calcm(int i,int sum,vector<int>&m,int lights,set<int>&s2){
        if(i>=m.size()){
            if(sum>=0 && sum<=59 && lights==0){
                s2.insert(sum);
                return;
            }
            else{
                return ;
            }
        }
        calcm(i+1,sum+m[i],m,lights-1,s2);
         calcm(i+1,sum,m,lights,s2);


    }
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        vector<int> h={8,4,2,1};
        vector<int> m={32,16,8,4,2,1};
        for(int i=0;i<=turnedOn;i++){
            set<int> s1;
            set<int> s2;
             calch(0,0,h,i,s1);
             calcm(0,0,m,turnedOn-i,s2);
             if(s1.empty() || s2.empty()){
                continue ;
             }
             for(auto j:s1){
                for(auto k:s2){
                    string a=to_string(j);
                    string b=to_string(k);
                    if(b.size()==1){
                        b.insert(b.begin(),'0');
                    }
                    string x=a+':'+b;
                    ans.push_back(x);
                }
             }

        }
        return ans;
       
        
        
    }
};