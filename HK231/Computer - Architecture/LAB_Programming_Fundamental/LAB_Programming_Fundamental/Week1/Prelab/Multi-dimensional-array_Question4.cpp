int diagonalDiff(int arr[][1000], int row, int col, int x, int y) {
    int sum1 =0,sum2 = 0,x1=x,y1=y;
    int k;
    while ((x != 0)&&(y != 0)) {
        x = x -1;
        y = y -1;
    }
    if (row <=col)
    k = row;
    else k = col;
    while ((x<row)&&(y<col)){
        sum1 = sum1 + arr[x][y];
        x++;
        y++;
    }
    while (x1 != 0 ){
        x1 = x1 -1;
        y1 = y1 +1;
    }
   while ((y1>=0)&&(x1<row)){
        sum2 =sum2 +arr[x1][y1];
        x1++;
        y1--;
    }
    if (sum1 >= sum2)
      return sum1-sum2;
      else return sum2 - sum1;
}
