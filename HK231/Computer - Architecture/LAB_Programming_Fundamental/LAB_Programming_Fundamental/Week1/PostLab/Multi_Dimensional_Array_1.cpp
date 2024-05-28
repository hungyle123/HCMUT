int Prime(int a){
    int t =1;
    for (int i=2;i<a;i++ ){
        if (a % i ==0){
            t =0;
            break;
        }
    }
    return t;
}
int specialCells(int arr[][1000], int row, int col) {
    int hang = 0,cot =0,a=0,b=0;
    for (int i =0; i<row;i++){
        for (int j =0;j <col;j++){
            a = a + arr[i][j];
        }
        if (Prime(a)==1)
        hang = hang + 1;
        a = 0;
    }
    for (int i =0; i<col;i++){
        for (int j =0;j <row;j++){
            b = b + arr[j][i];
        }
        if (Prime(b)==1)
        cot = cot + 1;
        b = 0;
    }
    return cot*hang;
}