class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int> m;
        for(auto i:words){
            m[i]++;
        }
        // Debug print - can remove in final version
        // for(auto i:m){
        //     cout<<i.first<<" "<<i.second<<endl;
        // }

        int best=0;
        int counter=0;
        int best2=0;
        unordered_map<string,bool> mp;
        
        for(auto i:m){
            string s=i.first;
            string a=s;
            reverse(a.begin(),a.end());
            if(a==s){  // Palindromic word
                if(i.second%2==0){
                    best2+=i.second;
                }
                else if(i.second&1){
                    best2+=(i.second-1);
                    best++;  // Only one central word needed
                }
            }
            else if(mp.find(a)==mp.end() && m.count(a)){
                counter+=min(i.second,m[a]);
                mp[s]=true;  // Mark both s and a as visited
                mp[a]=true;
            }
        }

        // Debug print - can remove in final version
        // cout<<counter<<" "<<best2<<" "<<best;
        
        return (4*counter + 2*best2 + (best>0 ? 2 : 0));
    }
};
