class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> ans;
        unordered_set<int> prev;
        prev.insert(arr[0]);
        ans.insert(arr[0]);
        for(int i=1;i<arr.size();i++){
            unordered_set<int> curr;
            curr.insert(arr[i]);
            ans.insert(arr[i]);
            for(auto j:prev){
                int x= j | arr[i];
                ans.insert(x);
                curr.insert(x);
            }
            prev=curr;

        }
        return ans.size();
        
    }
};