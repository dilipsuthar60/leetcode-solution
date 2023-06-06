class Solution {
public:
     // while (sx < tx && sy < ty)
     //        if (tx < ty) ty %= tx;
     //        else tx %= ty;
     //    return sx == tx && sy <= ty && (ty - sy) % sx == 0 ||
     //           sy == ty && sx <= tx && (tx - sx) % sy == 0;
    bool reachingPoints(int sx, int sy, int tx, int ty) 
    {
        while(sx<tx&&sy<ty)
        {
            if(tx<ty)
            {
                ty%=tx;
            }
            else
            {
                tx%=ty;
            }
        }
        if(sx==tx&&sy==ty)
        {
            return 1;
        }
        if(sx==tx&&((ty-sy)%sx==0)&&ty>=sy)
        {
            return true;
        }
        if(sy==ty&&((tx-sx)%sy==0)&&tx>=sx)
        {
            return true;
        }
        return false;
    }
};