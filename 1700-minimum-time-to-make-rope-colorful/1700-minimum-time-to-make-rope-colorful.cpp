class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int ans=0;
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<colors.size()-1;i++){
            if(colors[i]==colors[i+1]){
                pq.push(neededTime[i]);
            }
            else{
                pq.push(neededTime[i]);
                while(pq.size()>=2){
                 
                    ans+=pq.top();
                    pq.pop();
                }
                while(!pq.empty()){
                    pq.pop();
                }
                cout<<ans<<endl;
            }
            
        }
        pq.push(neededTime.back());
         while(pq.size()>=2){
                 
                    ans+=pq.top();
                    pq.pop();
                }
        return ans;
        
    }
};