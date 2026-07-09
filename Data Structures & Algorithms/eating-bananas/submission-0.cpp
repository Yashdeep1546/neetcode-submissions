class Solution {
public:

    bool fun(int x,int &h,vector<int>& piles){
        int t=0;
        for(int i:piles){
            t+=(i+x-1)/x;

        }
        return t<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

       
        int s=0,e=1;
         for(int i:piles) e=max(e,i);

        while(e-s>1){
            int mid=s+(e-s)/2;

            if(fun(mid,h,piles)){
                e=mid;
            }
            else s=mid;
        }
        return e;

    }
};
