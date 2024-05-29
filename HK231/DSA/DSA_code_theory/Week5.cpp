// Question 1

/*
Based on class List defined on page 98, write function template <typename E> void bubbleSort(List<E> &L) that sorts the elements of L in ascending using Bubble sort. Your code starts from line 79.   */


template <typename E>
void bubbleSort(List<E> &L){
    if (L.length()<=1) return;
    int n = L.length();
    for (int i = 0;i<n-1;i++){
        L.moveToEnd();
        L.prev();
	    while(L.currPos()>i){
	    	E x2 = L.getValue();
		    L.prev();
	    	E x1 = L.getValue();
		
		    if (x2 < x1 ) {
		    	L.remove();
		    	L.next();
		    	L.insert(x1);
		    	L.prev();
		    }
    	}
    }
    
}


// Question 2

/*
Based on class List defined on page 98, write function template <typename E> void insertionSort(List<E> &L) that sorts the elements of L in ascending using Insertion sort. If you use the concrete class of List is LList, please change the insertion sort algorithm such that there is no call to method prev in your implementation. Your code starts from line 79.  */

template <typename E> 
void insertionSort(List<E> &L){
    if (L.length()<=1) return;
    int n = L.length();
    for (int i = 1; i<n ;i++){
        L.moveToPos(i);
        int j = i-1;
        E temp = L.getValue();
        L.moveToPos(j);
        E j2 = L.getValue();
        while (j>=0 && temp<j2){
            L.next();
            L.remove();
            L.insert(j2);
            j--;
            if (j < 0) break;
            L.moveToPos(j);
            j2 = L.getValue();
        }
        L.moveToPos(j+1);
        L.remove();
        L.insert(temp);
    }
}


// Question 3

/*
Based on class List defined on page 98, write function template <typename E> void selectionSort(List<E> &L) that sorts the elements of L in ascending using Selection sort. Your code starts from line 79.   */

template <typename E> 
void selectionSort(List<E> &L) {
    if (L.length()<=1 ) return;
    int n = L.length();
    for (int i = 0;i<n-1;i++){
        L.moveToPos(i);
        int lowindex = i;
        E temp = L.getValue();
        E minimum = L.getValue();
        L.next();
        int j = i + 1;
        int newlow = i;
        while (j<n){
            if (L.getValue() < minimum){
                minimum = L.getValue();
                newlow = j;
            }
            j++;
            L.next();
        }
        if (lowindex != newlow){
            L.moveToPos(lowindex);
            L.remove();
            L.insert(minimum);
            L.moveToPos(newlow);
            L.remove();
            L.insert(temp);
        }
    }
   
}
