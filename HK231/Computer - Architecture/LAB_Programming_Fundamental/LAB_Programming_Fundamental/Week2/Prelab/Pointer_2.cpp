// Question 1

int* zeros(int n) {
    if (n > 0) {
    int *array = new int[n];
    for (int i = 0;i <n;i++){
        array[i]=0;
    }
    return array;}
    else return nullptr;
}

/***************************************************************************************************/

// Question 2

void shallowCopy(int*& newArr, int*& arr) {
    newArr = arr;
}

/***************************************************************************************************/

// Question 3

int** deepCopy(int** matrix, int r, int c) {
    if ((r <= 0)||(c <= 0))
    return nullptr;
    else {
    
    int** k = new int*[r];
    for (int i =0; i<r;i++){
        k[i] = new int[c];
    }
    for (int i=0;i<r;i++){
        for(int j=0;j < c; j++){
            k[i][j]=matrix[i][j];
        }
    }
    return k;
    }
   
}

/***************************************************************************************************/

// Question 4

void deleteMatrix(int**& matrix, int r) {
    matrix = nullptr;
}

/***************************************************************************************************/

// Question 5

void insertRow(int**& matrix, int r, int c, int* rowArr, int row) {
    int** k = new int*[r+1];
    for (int i =0; i<= r; i++){
        k[i] = new int[c];
    }
    for (int i =0;i<row;i++){
        for (int j =0;j<c;j++){
            k[i][j]=matrix[i][j];
        }
    }
    for (int i =0;i<c;i++){
        k[row][i]=rowArr[i];
    }
    for (int i=row+1;i<=r;i++){
        for(int j =0;j<c;j++){
            k[i][j]=matrix[i-1][j];
        }
    }
    delete []matrix;
    matrix =k;
}