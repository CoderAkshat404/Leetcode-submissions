class Solution {
public:
    map<int,char> m;
    vector<string> largestString(vector<int>& nums) {
        char ch='a';
        for(int i=0;i<=25;i++){
            m[1<<i]=ch;
            ch++;
        }
        vector<string> ans;
        for(int i=0;i<nums.size();i++){
            string temp="";
            int rem=nums[i];
            while(rem>0){
                auto it=m.upper_bound(rem);
                if (it == m.begin())
                    break;
                --it;
                temp+=it->second;
                rem-=it->first;
            }
            ans.push_back(temp);
        }
        return ans;
        
    }
};