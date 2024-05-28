// Question 1

int** readArray()
{
   int** Arr = new int*[10];
   for (int i = 0;i <10;i++){
        Arr[i] = new int[10];
   }
   for (int i = 0; i < 10;i++){
       for (int j =0; j<10;j++){
           cin >> Arr[i][j];
           if (Arr[i][j]==0){
               for (int k = j; k <10;k++){
                   Arr[i][k];
               }
            break;
           }
       }
   }
   return Arr;
}

/*************************************************************************************************/

// Question 2

void addElement(int*& arr, int n, int val, int index) {
    int* newArr = new int[n+1];
    for (int i = 0;i <index;i++){
        newArr[i]=arr[i];
    }
    newArr[index]=val;
    for (int i = index+1;i <=n;i++){
        newArr[i]=arr[i-1];
    }
    arr = newArr;
}

/************************************************************************************************/

// Question 3

int* flatten(int** matrix, int r, int c) {
    int size = r*c;
    int* Arr = new int[size];
    int turn = 0;
    for (int i =0;i<r;i++){
        for (int j = 0;j<c;j++){
            Arr[turn]=matrix[i][j];
            turn++;
        }}
    return Arr;
}

/************************************************************************************************/

// Question 4

int strLen(char* str,int t = 0)     
{ 
    if (str[t] == '\0')
    return t;
    else return strLen(str,t + 1);
}
char* concatStr(char* str1, char* str2) {
    
    int a = strLen(str1);
    int b = strLen(str2);
    int size = a + b;
    
    char* newStr = new char[size];
    for (int i = 0;i<a;i++){
        newStr[i]=str1[i];
    }
    for (int i=0;i<b;i++){
        newStr[i+a]=str2[i];
    }
    newStr[size]='\0';
    return newStr;
}

/************************************************************************************************/

// Question 5

int** transposeMatrix(int** matrix, int r, int c) {
    if ((r == 0)||(c == 0)) 
    return nullptr;
    else{
    int** newArr = new int*[c];
    for (int i =0 ; i <c; i++){
        newArr[i]=new int[r];
    }
    for (int i =0;i <c;i++){
        for (int j =0;j<r;j++){
            newArr[i][j]=matrix[j][i];
        }
    }
    return newArr;}
}
