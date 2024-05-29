// Question 1

/*
Given the method merge:
template <typename T>
void merge(T arr[],int left, int mid, int right);
where arr is an array of type T, left is the index of the first element in the first half, mid is the index of the last element in the first half, right is the index of the last element in the second half. This method will merge the first sorted half (from left to mid) and the second sorted half (from mid+1 to right) into the sorted part (from left to right) of array arr.
Based on the idea of merge sort, write method mergesort(T arr[], int left, int right) to sort a part (from left to right) of the array arr?
The prototype of method mergesort is:
template <typename T>
void mergesort(T arr[],int left, int right);
Your code starts at line 11.	*/

template <typename T>
void mergesort(T arr[],int left, int right){
    if (left == right)  return;
    int mid = (left+right)/2;
    mergesort(arr,left,mid);
    mergesort(arr,mid+1,right);
    
    merge(arr,left,mid,right);
}


// Question 2

/*
Based on class List defined on page 98, write function template <typename E> int partition(List<E> &L, int low, int high,E& pivot) to partition the list L into two parts: lower and higher pivot. The return value is the index of first position of the second part. This function is used in quick sort. Function  template <typename E> void swap(List<E> &L,int i, int j) is provided for your convenience.
Your code starts from line 90.  */

template <typename E> 
int partition(List<E> &L, int low, int high,E& pivot){
    do { 
        
        L.moveToPos(++low);
        while (L.getValue()< pivot && low < high){
            low++;
            L.next();
        } 
        
        L.moveToPos(--high);
        while (L.getValue()>=pivot && low < high){
            high--;
            L.prev();
        }
        if (low < high)
            swap(L, low, high);
        
        } while (low < high);
    
    return  low;
}


// Question 3

/*

Based on class List defined on page 98, write function template <typename E> void quickSort(List<E> &L) to sort the list L in ascending order. Functions template <typename E> int partition(List<E> &L,int low, int high,E & pivot)  and  template <typename E> void swap(List<E> &L,int i, int j) are provided for your convenience.
Your code starts from line 111.    */


template <typename E> 
void quickSort(List<E> &L,int i = 0, int j =-1){
    if (j == -1) j = L.length()-1;
    if (j <= i) return; 
        
    int pivotindex = (i+j)/2;
    swap(L, pivotindex, j); 
    L.moveToPos(j);
    E temp = L.getValue();
    int k = partition(L, i-1, j, temp);
    swap(L, k, j); 
    quickSort(L, i, k-1);
    quickSort(L, k+1, j);
}