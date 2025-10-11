class ExamTracker {
public:
    vector<long long> v;
    vector<long long> pre;
    long long sum=0;
    ExamTracker() {
        
    }
    
    void record(int time, int score) {
        v.push_back(time);
        sum+=score;
        pre.push_back(sum);
        
    }
    
    long long totalScore(int startTime, int endTime) {
        long long ans=0;
        int idx1=lower_bound(v.begin(),v.end(),startTime)-v.begin();
        int idx2=upper_bound(v.begin(),v.end(),endTime)-v.begin();
        idx2--;
        if(idx1<=idx2){
            if(idx1-1>=0){
                ans=pre[idx2]-pre[idx1-1];
            }
            else{
                ans=pre[idx2];
            }

        }
        return ans;
        
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */