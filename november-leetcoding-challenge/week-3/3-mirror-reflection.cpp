class Solution {
public:
    float func (int x, float a) {
        return 1.0 * x * a;
    }
    int mirrorReflection(int p, int q) {
        float a = (float) q/p;
        int x = p;
        
        while (func(x, a) / p != floor(func(x, a) / p)) {
            x += p;
        }
        
        bool vertical = ((int) func(x, a) / p) % 2;
        bool horizontal = (x / p) % 2;
        
        if (vertical) {
            if (horizontal) return 1;
            else return 2;
        } else {
            if (horizontal) return 0;
            else return -1;
        }
    }
};