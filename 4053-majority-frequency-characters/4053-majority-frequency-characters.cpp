class Solution {
public:
    string majorityFrequencyGroup(string s) {
        map<char,int> m;
        for(auto i:s){
            m[i]++;
        }
        map<int,string> freq;
        for(auto i:m){
            freq[i.second]+=i.first;
        }
        int maxi=0;
        string ans="";
        for(auto i:freq){
            if(i.second.length()>=maxi){
                maxi=i.second.length();
                ans=i.second;
            }
        }
        return ans;
        
    }
};