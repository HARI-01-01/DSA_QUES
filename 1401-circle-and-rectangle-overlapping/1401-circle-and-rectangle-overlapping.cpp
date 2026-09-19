class Solution {
public:
    bool checkOverlap(int r, int xC, int yC, int x1, int y1, int x2, int y2) {
        
        int cx = max(x1,min(xC,x2));
        int cy = max(y1,min(yC,y2));

        return pow(cx-xC,2) + pow(cy-yC,2) <= r*r;
    }
};