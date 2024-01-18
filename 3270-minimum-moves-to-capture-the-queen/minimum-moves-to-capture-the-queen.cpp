class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //rook
        if(a==e)
        {
            if(a==c)
            {
               if((d>b && d<f)||(d>f && d<b))
               {
                   return 2;
               }
               else
               {
                   return 1;
               }
            }
            else
            {
                return 1;
            }
        }
        if(b==f)
        {
            if(b==d)
            {
                if((a<c && c<e)||(c>e && c<a))
                {
                    return 2;
                }
                else
                {
                    return 1;
                }
            }
           else
           {
               return 1;
           }
        }
        //knight
        if(abs(c-e)==abs(d-f))
        {
          int kr=e-a;
          int kk=abs(e-c);
          if((a>c && a<e)||(a>e && a<c))
          {
            if(abs(a-e)==abs(b-f) && abs(a-c)==abs(b-d))
            {
                return 2;
            }
            else
            {
                return 1;
            }
          }  
          else
          {
              return 1;
          }
        }
        return 2;
    }
};