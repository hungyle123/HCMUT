bool isSymmetric(int arr[][1000], int row, int col) {
      int k =1;
      for (int i = 0;i < col; i++){
          for (int j =0; j <row;j++){
              if (arr[i][j]==arr[j][i])
              k = k*1;
              else {
                  k = k*0;
                  goto end;
              }}}
  end: if ( k ==1)
  return true;
  else return false;
}
