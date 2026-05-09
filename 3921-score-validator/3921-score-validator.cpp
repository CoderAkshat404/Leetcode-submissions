class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int ans=0;
        int cnt=0;
        for(int i=0;i<events.size();i++){
            if(events[i]=="W"){
                cnt++;
                if(cnt==10){
                    return {ans,cnt};
                }
            }
            else{
                if(events[i]>="0" && events[i]<="9"){
                    ans+=stoi(events[i]);
                }
                else{
                    ans+=1;
                }
            }
        }
        return {ans,cnt};
        
    }
};