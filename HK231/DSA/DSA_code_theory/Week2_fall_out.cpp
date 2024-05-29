// Question 1

/*

To express an arithmetic expression, there are 4 following classes:
Exp: general integral arithmetic expression
BinExp: an arithmetic expression that contains one binary operators (+,-,*,/) and two operands. Constructor of BinExp: BinExp(Exp* left, char op, Exp* right)
UnExp: an arithmetic expression that contains one unary operator (+,-) and one operand
Constructor of UnExp: UnExp(char op, Exp* exp)
IntLit: an arithmetic expression that contains an integer number. Constructor of IntLit: IntLit(int v)
Define these classes in C++ (their parents, attributes, methods) such that their objects can response to eval() message by returning an object the value of the expression. For example, let variable x point to the object expressing the arithmetic expression 3 + 4 * 2, x->eval() must return 11.
Your code starts at line 11. */

class Exp{
    public:
    virtual int eval() =0;
};

class BinExp:public Exp{
    private:
    char op;
    Exp* left;
    Exp* right;
    public:
    BinExp(Exp* left, char op, Exp* right){
        this->op = op;
        this->left = left;
        this->right = right;
    };
    
    int eval(){
        int a = left->eval();
        int b = right->eval();
        
        int result;
        
        if (op == '+'){
            result = a+b;
        }
        else if (op == '-'){
            result = a-b;
        }
        else if (op == '*'){
            result = a*b;
        }
        else if (op == '/'){
            result = a/b;
        }
        return result;
        
        
    }
};

class UnExp:public Exp{
    private:
    char op;
    Exp* exp;
    public:
    UnExp(char op, Exp* exp){
       this-> op = op;
        this->exp =exp;
    };
    int eval() {
        int a = exp->eval();
        if (op == '-')
        a =a*-1;
        return a;
    }
};

class IntLit: public Exp{
    private:
    int value;
    public:
    IntLit(int v){
        value = v;
    };
    
    int eval() {return value;}
};


// Question 2

/*

Extend the contents of classes Exp, BinExp, UnExp, IntLit such that they can response to printPrefix() message to return the string corresponding to the expression in prefix format. Note that, unary operator +/- is printed as +./-. in prefix format and there is a space after each operator or operand. For example, when receiving message printPrefix(), the object expressing the expression -4 + 3 * 2 will return the string "+ -. 4 * 3 2 "  */

class Exp{
    public:
    virtual int eval() =0;
    virtual void printPrefix()=0;
};

class BinExp:public Exp{
    private:
    char op;
    Exp* left;
    Exp* right;
    public:
    BinExp(Exp* left, char op, Exp* right){
        this->op = op;
        this->left = left;
        this->right = right;
    };
    
    int eval(){
        int a = left->eval();
        int b = right->eval();
        
        int result;
        
        if (op == '+'){
            result = a+b;
        }
        else if (op == '-'){
            result = a-b;
        }
        else if (op == '*'){
            result = a*b;
        }
        else if (op == '/'){
            result = a/b;
        }
        return result;
        
        
    }
    void printPrefix(){
        cout<<op<<" ";
        left->printPrefix();
        cout<<" ";
        right->printPrefix();
    }
};

class UnExp:public Exp{
    private:
    char op;
    Exp* exp;
    public:
    UnExp(char op, Exp* exp){
       this-> op = op;
        this->exp =exp;
    };
    int eval() {
        int a = exp->eval();
        if (op == '-')
        a =a*-1;
        return a;
    }
    void printPrefix(){
        cout<<op<<". ";
        exp->printPrefix();
    }
};

class IntLit: public Exp{
    private:
    int value;
    public:
    IntLit(int v){
        value = v;
    };
    
    int eval() {return value;}
    void printPrefix(){
        cout<<value;
    }
};


// Question 3

/* 

Write function fibo that returns the nth value of the Fibonacci sequence where n is the input of the function? The time complexity of the function must be O. Remind that F0 = 0, F1 = 1 and Fn = Fn-1 + Fn-2
The prototype of the function is as follows:
unsigned int fibo(int n);
Your code starts at line 11.  */

unsigned int fibo(int n){
    if (n == 0) return 0;
    else if (n == 1)return 1;
    else {
        int f1=0;
        int f2=1;
        int f3;
        for (int i = n-1;i>0;i--){
            f3 = f2 + f1;
            f1 = f2;
            f2 = f3;
        }
        return f3;
    }
}


// Question 4

/*

Write function findMax that returns the maximum index of the maximum value in the input array. That means if the maximum value appears in many different indexes of the input array, the last index is returned. Assume that the size of the input array is always greater than 0.
The time complexity of your algorithm should be O(n).
The prototype of function findMax is as follows:
template <typename T>
int findMax(T arr[],int n); // where arr is the input array and n is the size of the array.
Your code starts at line 11.  */

template <typename T>

int findMax(T arr[],int n){
    T max = arr[0];
    int maxindex = 0;
    for (int i = 0; i <n;i++){
        if (arr[i]>=max){
            max = arr[i];
            maxindex = i;
        }
    }
    return maxindex;
}


// Question 5
/*

Write function powerSet that returns the power set of the input array? For example, if the input is ['a','b','c'], the output is [[],['a'],['b'],['a','b'],['c'],['a','c'],['b','c'],['a','b','c']]. The prototype of the function is at follows:
template <typename T>
vector<vector<T>> powerSet(vector<T> arr); // where arr is the input array
Your code starts at line 11. Write the asymptotic time complexity of your function in the comment at the beginning of your function. */

template <typename T>

vector<vector<T>> powerSet(vector<T> arr){
    int size = arr.size();
    vector<vector<T>> result;
    
    vector<T> v;
    result.push_back(v);
    
    for (int i = 0; i<size;i++){
       
         int n = result.size();
        for (int j = 0;j <n;j++){
            vector<T> v = result.at(j);             //get the previous value and add 1 more element
            v.push_back(arr.at(i));
            result.push_back(v);
        } 
    
    }
    return result;
}
