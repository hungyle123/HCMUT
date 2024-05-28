// Question 1

int calcSum(int *ptr, int n)
{
    int sum=0;
    for (int i = 0;i <n;i++){
        sum = sum + *(ptr+i);}
    return sum;
}

/********************************************************************************************/

// Question 2

void add(int *ptr, int n, int k)

{  /*int* newArr = new int[n+1];
    for (int i =0;i <n;i++){
        newArr[i]=ptr[i];
    }
    newArr[n]=k;
    ptr = newArr;
    n = n + 1;*/
    ptr[n]=k;
   
}