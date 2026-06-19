class Solution {
public:
    int maxArea(vector<int>& a) {
        int i=0,j=a.size()-1,res=0;
        while(i<j){
            int area=min(a[i],a[j])*(j-i);
            res=max(res,area);
            if(a[i]<a[j])i++;
            else j--;
        }
        return res;
    }
};
