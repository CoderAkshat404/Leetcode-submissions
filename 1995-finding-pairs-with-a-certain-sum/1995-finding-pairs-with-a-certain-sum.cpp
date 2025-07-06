class FindSumPairs {
public:
    unordered_map<int,int> m1;
    unordered_map<int,int> m2;
    vector<int> nums1;
    vector<int> nums2;
    FindSumPairs(vector<int>& nu1, vector<int>& nu2) {
        nums1=nu1;
        nums2=nu2;
        for(int i=0;i<nums1.size();i++){
            m1[nums1[i]]++;
        }
        for(int i=0;i<nums2.size();i++){
            m2[nums2[i]]++;
        }
        
    }
    
    void add(int index, int val) {
        m2[nums2[index]]--;
        nums2[index]+=val;
        m2[nums2[index]]++;
        
    }
    
    int count(int tot) {
        int ans=0;
        for(auto i:m2){
            int target=tot-i.first;
            ans+=(i.second*m1[target]);
        }
        return ans;
        
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */