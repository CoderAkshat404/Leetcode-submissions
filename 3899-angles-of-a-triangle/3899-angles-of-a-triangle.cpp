class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        int a=sides[0];
        int b=sides[1];
        int c=sides[2];
        if(a+b>c && c+b>a && a+c>b){
            double x=acos((double)(b*b+c*c-a*a)/(2*b*c));
            double y=acos((double)(a*a+c*c-b*b)/(2*a*c));
            double z=acos((double)(b*b+a*a-c*c)/(2*b*a));
            double conv = 180.0/M_PI;
            vector<double> v= {x*conv,y*conv,z*conv};
            sort(v.begin(),v.end());
            return v;

        }
        return {};
        
    }
};