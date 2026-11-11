class Solution {
public:
    int divide(int div, int d) {

        if(div ==d ) return 1;
        bool t1 = true;

         if(div<=0 && d>0) t1 = false;
         if(d<0 && div>=0) t1 = false;
        long long dv = abs((long long)div);
        long long dd =abs((long long)d);
         int ans = 0;
         while(dv>=dd){
            int cnt = 0;

            while(dv>=(dd<<(cnt+1))){
                cnt++;
            }
            ans+= 1<<cnt;
            dv-=dd<<cnt;
         }

         if(ans==1<<31 && t1) return INT_MAX;
         if(ans==1<<31 && !t1) return INT_MIN;
         return t1?ans:-ans;
        
    }
};