int ascendingRows(int arr[][1000], int row, int col) {
    int count=0;
    for (int i = 0; i < row;i++) {
        int h =1;
        for (int j =1;j <col;j++){
            if (arr[i][j-1]<=arr[i][j])
            h=h*1;
            else h=h*0;
        }
        if (h ==1) count = count +1;
        
    }
    return count;
}