int Prime(int a){
    int k=0;
    for (int i = 2; i<a;i ++){
        if (a % i == 0)
        k = k +1;
    }
    if ((k==0)&&(a>=0))
    return 1;
    else return 0;
}
int primeColumns(int arr[][1000], int row, int col) {
    int count=0;
    for (int i = 0; i < col;i++) {
        int h =1,k=0;
        for (int j =0;j <row;j++){
            k = k + arr[j][i];
        }
        if (Prime(k) == 1) count = count +1;
        
    }
    return count;
}