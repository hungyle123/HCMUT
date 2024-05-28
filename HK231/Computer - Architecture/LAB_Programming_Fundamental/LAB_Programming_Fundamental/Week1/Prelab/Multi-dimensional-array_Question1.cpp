int findMaxColumn(int arr[][1000], int row, int col) {
    int t=0,k=0,max=0;
    for (int i = 0;i < col; i++){
        for (int j =0; j <row;j++){
            t = t + arr[j][i];
        }
        if (t > max){
            max = t;
            k = i;
        }
        t = 0;
    }
    return k;
}
