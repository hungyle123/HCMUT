// Question 1

int findMax(int *ptr, int n)
{
    int max =*ptr;
    for (int i =0;i<n;i++){
        if (*(ptr+i)>max )
        max = *(ptr+i);
    }
    return max;
}

/***************************************************************************************************/

// Question 2

void reverse(int *ptr, int n)
{
    int a;
    for (int i = 0;i<n/2;i++){
        a = *(ptr+i);
        *(ptr+i) = *(ptr+n-1-i);
        *(ptr+n-1-i) = a;
    }
}

/***************************************************************************************************/

// Question 3


bool isSymmetry(int *head, int *tail)
{
    int n = tail - head;
    if (n == 0)
    goto end2;
    for (int i = 0; i <=n;i++){
        if (*(head+i)!=*(tail-i))
        goto end;}
end2:   return true;
end:return false;
}


