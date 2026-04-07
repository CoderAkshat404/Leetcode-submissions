class Robot {
public: 
    string dir;
    void changedir(){
        if(dir=="East"){
            dir="North";
        }
        else if(dir=="North"){
            dir="West";
        }
        else if(dir=="West"){
            dir="South";
        }
        else{
            dir="East";
        }
    }
    int currx;
    int curry;
    int n;
    int m;

    Robot(int width, int height) {
        n=height;
        m=width;
        dir="East";
        currx=0;
        curry=0;
    }
    
    void step(int num) {
        int perimeter = 2*(m+n)-4;
        if(perimeter > 0){
            num = num % perimeter;
            if(num == 0) num = perimeter;
        }

        int rem=num;


       

        while(rem>0){   

            if(dir=="East"){
                if(rem+currx<=m-1){
                    currx=currx+rem;
                    rem=0;   
                }
                else{
                    rem=rem-((m-1)-currx);
                    currx=m-1;
                    changedir();   
                }
            }

            else if(dir=="North"){  
                if(curry+rem<=n-1){
                    curry=curry+rem;
                    rem=0;  
                }
                else{
                    rem=rem-(n-1-curry);
                    curry=n-1;
                    changedir();   
                }
            }

            else if(dir=="West"){
                if(currx-rem>=0){
                    currx=currx-rem;
                    rem=0;   
                }
                else{
                    rem=rem-(currx-0);
                    currx=0;
                    changedir();   
                }
            }

            else{ 
                if(curry-rem>=0){
                    curry=curry-rem;
                    rem=0;   
                }
                else{
                    rem=rem-(curry-0);
                    curry=0;
                    changedir();   
                }
            }
        }
    }
    
    vector<int> getPos() {
        return {currx,curry};
    }
    
    string getDir() {
        return dir;
    }
};