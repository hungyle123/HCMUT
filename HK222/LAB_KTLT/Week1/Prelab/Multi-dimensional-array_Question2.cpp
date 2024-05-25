int diagonalProduct(int arr[][1000], int row, int col) {
    int k =1;
    for (int i = 0; i < row;i++){
        k = k*arr[i][i];
    }
    return k;
}
