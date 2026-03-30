class Solution {
public:
    struct datas{
        deque<int> dq;
        void insert(int n){
            while(!dq.empty() && dq.back()<n){
                dq.pop_back();
            }
            dq.push_back(n);
        }
        void rem(int n){
            if(dq.front()==n){
                dq.pop_front();
            }
        }
        int getmax(){
            return  dq.front();
        }
    };
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        datas ds;
        vector<int> ans;
        for(int i=0;i<k;i++){
            ds.insert(nums[i]);
        }
        ans.push_back(ds.getmax());
        int i=0;
        int j=k-1;
        while(j+1<nums.size()){
            ds.insert(nums[j+1]);
            ds.rem(nums[i]);
            ans.push_back(ds.getmax());
            i++;
            j++;
        }
        return ans;
        
    }
};