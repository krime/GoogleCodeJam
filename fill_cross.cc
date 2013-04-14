direction[0][0][0] = -1
direction[0][0][1] = 0
direction[0][1][0] = +1
direction[0][1][1] = 0

direction[1][0][0] = 0
direction[1][0][1] = -1
direction[1][1][0] = 0
direction[1][1][1] = +1

bool go(D, int currentx, int currenty,int minvalue)
{
    int x,y;
 for(int i=0;i<2;++i){
    x=currentx;
    y=currenty;
    while(1<=x<=N && 1<=y<=M)
    {
        x+=direction[D][i][0];
        y+=direction[D][i][1];
        if (1<=x<=N && 1<=y<=M)
       {
           if (matrix[x,y]!=min)
           {
               return false;   
           }else{
               willBeFilled[x,y]=1;
           }
       }
    }
 }
  for(int i=0;i<2;++i){
    x=currentx;
    y=currenty;
    while(1<=x<=N && 1<=y<=M)
    {
        x+=direction[D][i][0];
        y+=direction[D][i][1];
        if (1<=x<=N && 1<=y<=M)
       {
          for(int j=0;j<2;++j){
             x2 = x+direction[1-D][j][0];
             y2 = y+direction[1-D][j][1];
             if (1<=x2<=N && 1<=y2<=M){
                if (matrix[x2,y2]==minvalue)
                {
                    retuvalue= go(1-D,x2,y2,mingvalue);
                    if (!retvalue) return false;
                }
             }

          }
       }
    }
 }
 return true; 
}
bool fill_cross(matrix, int x, int y)
{
    minvalue = matrix[x,y];
    memset(willBeFilled,0,sizoef(willBeFilled));
    if (x,y  is on edge up/down){
          go(1,x,y,minvalue);
     } 
     if (x,y  is on edge left/right){
           go(0,x,y,minvalue);

     }
     fill(willBeFilled, x,y);
}
