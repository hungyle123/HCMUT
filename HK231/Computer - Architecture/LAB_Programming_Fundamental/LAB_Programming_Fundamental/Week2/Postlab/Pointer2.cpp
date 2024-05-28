// Question 1 

int** insertCol(int**& matrix, int r, int c, int* colArr, int col) {
    int** newArr = new int*[r];
    for (int i = 0;i < r;i++){
        newArr[i] = new int[c+1];
    }
    for (int i = 0; i< r;i++){
        for (int j = 0;j<col;j++) {
            newArr[i][j] = matrix[i][j];
        }
    }
    for (int i = 0;i<r;i++){
        newArr[i][col]=colArr[i];
    }
    for (int i =0;i<r;i++){
        for (int j = col;j<c;j++){
            newArr[i][j+1]=matrix[i][j];
        }
    }
    delete [] matrix;
    matrix = newArr;
    return matrix;
}

/**************************************************************************************************/

// Question 2

bool deleteRow(int**& matrix, int r, int c, int row) {
    if ((r <= 0) || (c <= 0)||(row>=r)||(row <0))
    return false;
    else if ((r == 1)&&(row == 0) ){
      matrix = nullptr;
        delete [] matrix;
        return true;}
    else {
        int** newArr = new int*[r-1];
    for(int i = 0; i<r-1;i++){
         newArr[i] = new int[c];
    }
    for (int i = 0; i<row;i++){
        for(int j = 0;j<c;j++){
            newArr[i][j]=matrix[i][j];
        }
    }
    for (int i = row+1; i<r;i++){
        for(int j = 0;j<c;j++){
            newArr[i-1][j]=matrix[i][j];
        }
    }
    matrix = nullptr;
    matrix = newArr;
    newArr = nullptr;
    return true;
    }
}

/**************************************************************************************************/

// Question 3

bool deleteCol(int**& matrix, int r, int c, int col) {
    if ((r <= 0) || (c <= 0)||(col>=c)||(col <0))
    return false;
    else if ((c == 1)&&(col == 0) ){
      matrix = nullptr;
        delete [] matrix;
        return true;}
    else {
        int** newArr = new int*[r];
    for(int i = 0; i<r;i++){
         newArr[i] = new int[c-1];
    }
    for (int i = 0; i<r;i++){
        for(int j = 0;j<col;j++){
            newArr[i][j]=matrix[i][j];
        }
    }
    for (int i = 0; i<r;i++){
        for(int j = col+1;j<c;j++){
            newArr[i][j-1]=matrix[i][j];
        }
    }
    matrix = nullptr;
    matrix = newArr;
    newArr = nullptr;
    return true;
    }
}


