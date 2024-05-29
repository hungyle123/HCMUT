// Question 1

/*
Based on method remove()  given in page 118, write method removePre() for class DLList (doubly linked list)  that  removes the element before the cursor? If there is no element  before the cursor, assertion fails  and message "No element"  is printed out before termination (using function Assert in page 579)
For example, applying removePre  on the list <5  1 |  2 4  3> will remove element 1  and then if  applying  removePre again, element 5 will be removed. Calling removePre  one  more  time will  cause Assertion fail. */

E removePre() {
    Assert(curr != head,"No element");
    E it = curr->element; 
    Link<E>* ltemp = curr; 
    curr->prev->next = curr->next;
    curr->next->prev = curr->prev; 
    curr = curr->prev;
    delete ltemp; 
    cnt--; 
    return it;
}

// Question 2

/*
Based on the Stack ADT given in Figure 4.17 page 121, write function dec2bin to return a binary string of the positive decimal input.
The prototype of the function is:
string dec2bin(const unsigned int& x);  */

string dec2bin(const unsigned int& x){
    Stack<int> * st = new AStack<int>;
    int a = x;
    while (a != 0){
        int remainder = a%2;
        st->push(remainder);
        a = (a-remainder)/2;
    }
    string result = "";
    while (st->length()!=0){
        result = result + to_string(st->pop());
    }
    return result;
}


// Question 3

/*
Remind that Fibonacci number is defined as follows:

Using a stack (AStack), write function Fib(int n) to return the Fibonacci nth number? The algorithm must have time complexity of O( n ) and space complexity of O(1).
Your code starts at line 85.   */

int Fib(int n){
    if ((n==1)||(n==0)) return 1;
    Stack<int> * st = new AStack<int>;
    st->push(1);
    st->push(1);
    while (n>1){
        int x1 = st->pop();
        int x2 = st->pop();
        int a = x1+x2;
        st->push(x1);
        st->push(a);
        n--;
    }
    int result = st->pop();
    delete st;
    return result;
}


// Question 4

/*
A common problem for compilers and text editors is to determine if the parentheses (or other brackets) in a string are balanced and properly nested. For example, the string “((())())()” contains properly nested pairs of parentheses, but the string “)()(” does not, and the string “())” does not contain properly matching parentheses. 
Based on Stack ADT given in Figure 4.17 page 121, write function parentheses to check if a string contains properly nested pairs of parentheses. Remind that C++ method string::length can be used to get the length of the string.
The prototype of the function is:
bool parentheses(const string &L);   */

bool parentheses(const string &L){
    Stack<char> * st = new AStack<char>;
    int len = L.length();
    for (int i =0;i<len;i++){
        if (L[i]=='(') st->push(L[i]);
        else {
            if (st->length()==0) return false;
            else st->pop();
        }
    }
    if (st->length()!=0){
        delete st;
        return false;
    }
    else{
        delete st;
        return true;
    }
}


// Question 5

/*
Based on Stack ADT given in Figure 4.17 page 121, write function postfix that calculates a postfix expression and returns its value. The postfix expression is given by an array of string whose element is operand or operator. For example, for postfix expression 10 6 -, the array is {"10","6","-"} and its calculated value is 4. 
Assume that the operators in the expression are only binary + and binary - and the expression includes only operators and operands, not parentheses and it is always correct. 
Remind that the c++ method used to convert a string into int is string::stoi . The prototype of the function is:
template <typename T>
int postfix(string* L, int n);//L is the array containing the postfix expression and n is the size of the array.      */

int postfix(string* L, int n){
    Stack<int> * st = new AStack<int>;
    for (int i = 0;i<n;i++){
        if (L[i]=="+") {
            int x2 = st->pop();
            int x1 = st->pop();
            st->push(x1+x2);
        }
        else if (L[i]=="-"){
            int x2 = st->pop();
            int x1 = st->pop();
            st->push(x1-x2);
        }
        else {
            st->push(stoi(L[i]));
        }
    }
    int result = st->pop();
    delete st;
    return result;
}


// Question 6
/*
Based on the Stack ADT given in Figure 4.17 page 121, write a part of function reverse using a stack to reverse an array.
template <typename E>
void reverse(E* L, int n) { //L is the array of E and n is the size of the array
    Stack<E>* S = new AStack<E>();
    //Your work is from here (line 65)
   ...
   //until here
}  */

for (int i = 0;i<n;i++){
    S->push(L[i]);
}
for (int i = 0;i<n;i++){
    L[i]=S->pop();
}
delete S;
return;


// Question 7

/*

Based  on the Queue ADT given in Figure 4.23 page 129, implement method enqueue of the concrete class AQueue.
The prototype of the method is:
void enqueue(const E& it);   */

void enqueue(const E& it) { 
Assert(((rear+2) % maxSize) != front, "Queue is full");
rear = (rear+1) % maxSize; 
listArray[rear] = it;
}



// Question 8

/*
Based  on the Queue ADT given in Figure 4.23 page 129, write function prefix to return the value of a prefix expression passed to the function as an array of string. For example, 
string x[] = {"+","3","-","5","4"};
cout << prefix(x,5); //where 5 is the length of the array
=> the printed result is 4.
Assume that the operator used on the prefix expression just is binary + or binary - and the prefix expression just includes operators and numbers without any parentheses. The prefix expression is always correct.
The prototype of the function is:
int prefix(const string * L,int n);  */

bool Digit(string a){
    if ((a !="+")&&(a != "-")) return true;
    else return false;
}


int prefix(const string * L,int n){
    
    Queue<string> *in = new LQueue<string>;
    Queue<string> *out = new LQueue<string>;
    
    for (int i = 0;i<n;i++){                        //store array in out first
        out->enqueue(L[i]);
    }               
    
    while (out->length()!=1){
        while (out->length()!= 0){
            in->enqueue(out->dequeue());            //convert out to in
        }
        
        while(in->length()!=0){
            string a = in->dequeue();
            if (Digit(a)){
                out->enqueue(a);
            }
            else {
                if (Digit(in->frontValue())){
                    string b = in->dequeue();       //we gradually find a operator followed by 2 operand
                                                    // to compute it
                    if (Digit(in->frontValue())){
                        string c = in->dequeue();
                        if (a=="+") out->enqueue(to_string(stoi(b)+stoi(c)));
                        else  out->enqueue(to_string(stoi(b)-stoi(c)));
                    }
                    else {
                        out->enqueue(a);
                        out->enqueue(b);
                    }
                }
                else{
                    out->enqueue(a);
                }
            }
        }
    }
    int result = stoi(out->dequeue());
    delete out;
    delete in;
    return result;
}