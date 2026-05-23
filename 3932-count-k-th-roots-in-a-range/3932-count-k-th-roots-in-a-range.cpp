class Solution {
public:

    bool check1(int mid,int k,int l){

        long long x = 1;

        for(int i=0;i<k;i++){

            if(x > 1e9/mid){
                return true;
            }

            x = x*mid;
        }

        return (l<=x);
    }

    bool check2(int mid,int k,int r){

        long long x = 1;

        for(int i=0;i<k;i++){

            if(x > 1e9/mid){
                return false;
            }

            x = x*mid;
        }

        return (r>=x);
    }

    int countKthRoots(int l, int r, int k) {

        int n1 = -1, n2 = -1;

        int s = 0, e = 1e9;

        while(s<=e){

            int mid = s + (e-s)/2;

            if(check1(mid,k,l)){
                n1 = mid;
                e = mid-1;
            }
            else{
                s = mid+1;
            }
        }

        s = 0, e = 1e9;

        while(s<=e){

            int mid = s+(e-s)/2;

            if(check2(mid,k,r)){
                n2 = mid;
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }

        return (n2-n1+1);
    }
};