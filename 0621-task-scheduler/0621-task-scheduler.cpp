class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        map<char,int> freq;
        for(auto i:tasks){
            freq[i]++;
        }
        priority_queue<int> pq;
        for(auto i:freq){
            pq.push(i.second);
        }
        int ans=0;
        while(!pq.empty()){
            int ele=pq.top();
            pq.pop();
            vector<int> v;
            v.push_back(ele-1);
            
            for(int i=0;i<n;i++){
                if(!pq.empty()){
                    int x=pq.top();
                    pq.pop();
                    v.push_back(x-1);
                }
            }
            for(auto i:v){
                if(i>0){
                    pq.push(i);
                }
            }
            if(pq.empty()){
                ans+=v.size();
            }
            else{
                ans+=(n+1);
            }
           

           
        }
        return ans;
        

        
    }
};