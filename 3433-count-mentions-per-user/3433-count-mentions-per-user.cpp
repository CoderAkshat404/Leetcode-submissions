class Solution {
public:
    static bool cmp(vector<string>& v1,vector<string> & v2){
        int t1=stoi(v1[1]);
        int t2=stoi(v2[1]);
        if(t1==t2){
            if(v1[0]=="OFFLINE"){
                return true;
            }
            else if(v2[0]=="OFFLINE"){
                return false;
            }
            else{
                return true;
            }
        }
        return t1<t2;
    }
    vector<int> countMentions(int n, vector<vector<string>>& events) {
        vector<vector<int>> v(n,vector<int>(1e5+1,1));
        vector<int> ans(n,0);
        sort(events.begin(),events.end(),cmp);
        for(int i=0;i<events.size();i++){
            if(events[i][0]=="OFFLINE"){
                int time=stoi(events[i][1]);
                int user=stoi(events[i][2]);
                for(int j=time;j<time+60 && j<=1e5;j++){
                    v[user][j]=0;
                }
            }
            else{
                if(events[i][2]=="ALL"){
                    for(int j=0;j<n;j++){
                        ans[j]++;
                    }
                }
                else if(events[i][2]=="HERE"){
                    int time=stoi(events[i][1]);
                    for(int j=0;j<n;j++){
                        if(v[j][time]==1){
                            ans[j]++;
                        }
                    }
                }
                else{
                    string s=events[i][2];
                    vector<int> u;
                    int j=0;
                    while(j<s.length()){
                        j+=2;
                        string p="";
                        while(j<s.length() && s[j]!=' '){
                            p+=s[j];
                            j++;
                        }
                        u.push_back(stoi(p));
                        j++;
                    }
                    for(int k=0;k<u.size();k++){
                        ans[u[k]]++;
                    }

                }
            }
        }
        return ans;
        
    }
};