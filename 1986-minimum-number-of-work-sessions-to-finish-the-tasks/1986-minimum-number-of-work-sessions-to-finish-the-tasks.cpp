class Solution {
public:
    int n,s;
    vector<int> tasks;
    vector<vector<int>> bt;
    int minsess;

    void solve(int i){
        if(bt.size()>=minsess) return;
        if(i>=n){
            for(auto v:bt){
                int sum = 0;
                for(int j:v){
                    sum+=j;
                }
                if(sum>s){
                    return;
                }
            }
            minsess = min((int)bt.size(),minsess);
            return;
        }
        for(int j=0;j<bt.size();j++){
            int curs=0;
            for(auto k:bt[j]) curs+=k;
            if(curs+tasks[i]<=s){
            bt[j].push_back(tasks[i]);
            solve(i+1);
            bt[j].pop_back();}
        }
        bt.push_back({tasks[i]});
        solve(i+1);
        bt.pop_back();
    }
    
    int minSessions(vector<int>& tasks, int sessionTime) {
        this->n = tasks.size();
        this->s = sessionTime;
        this->tasks = tasks;
        this->minsess = n;
        solve(0);
        return minsess;
    }
};