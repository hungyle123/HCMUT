// Question 1
/*
	Write function int infix_cal(const string& input) that takes a string in the format "<operand> <operator> <operand>" where <operand> is an integer and <operator> is one of "+,-,*,/". There are just two spaces  in the input string: one to separate the first operand with the operator and one to separate the operator and the second operand. For example, infix_cal("10 + 2") must return 12. */

int operand(string a){
    int x = a.length();
    int re = 0;
    int dau = 0;
    for (int i = 0; i < x;i++){
        if (a[i]=='-')
        dau = 1;
        else {
            re = re*10 + (int)(a[i]-'0');
        }
    }
    if (dau == 1)
    re = re * -1;
    return re;
}
int infix_cal(const string& input){
    int len = input.length();
    int s1 = input.find(' ');
    int s2 = input.find(' ',s1 + 1);
    string op1 = input.substr(0,s1);
    string opt = input.substr(s1+1,1);
    string op2 = input.substr(s2+1,len - s1 - 3);
    int iop1 = operand(op1);
    int iop2 = operand(op2);
    int re;
    if (opt == "+"){
        re = iop1 + iop2;
    }
    else if (opt == "-"){
        re = iop1 - iop2;
    }
    else if (opt == "*"){
        re = iop1 * iop2;
    }
    else if (opt == "/"){
        re = iop1 / iop2;
    }
    return re;
}

// Question 2
/* In the previous implementation of function infix_cal, a nested if would be used to compare the input operator with expected operators like "+", "-",... This approach requires changing the nested if when there are more operators. 
In this exercise, the function must not use such a nested if but it must use a loop over an array that contains a struct of an operator string and a function pointer.
Assume that the following definitions have been declared for your usage:
struct action {
    string op; // operator
    int (*func)(int, int); // function pointer to corresponding function
};
int myadd(int x, int y) { return x + y;}
int mymin(int x, int y) { return x - y;}
int mymul(int x, int y) { return x * y;}
int mydiv(int x, int y) { return x / y;}
Your code starts at line 20. */

int operand(string a){
    int x = a.length();
    int re = 0;
    int dau = 0;
    for (int i = 0; i < x;i++){
        if (a[i]=='-')
        dau = 1;
        else {
            re = re*10 + (int)(a[i]-'0');
        }
    }
    if (dau == 1)
    re = re * -1;
    return re;
}
int infix_cal(const string& input){
    int len = input.length();
    int s1 = input.find(' ');
    int s2 = input.find(' ',s1 + 1);
    string op1 = input.substr(0,s1);
    string opt = input.substr(s1+1,1);
    string op2 = input.substr(s2+1,len - s1 - 3);
    int iop1 = operand(op1);
    int iop2 = operand(op2);
    int result;

action array[] ={{"+",myadd},{"-",mymin},{"*",mymul},{"/",mydiv}};

   for (int i =0;i<4; i++){
       if (array[i].op == opt){
           result = array[i].func(iop1,iop2);
       }
   }
   
   
    return result;
}

// Question 3
/*

Write function string many_infix_cal(const string& input) that takes a string containing many infix expressions in the format "<operand> <operator> <operand>" separated by new lines where operand is an integer constant and operator is one of +, - , * or /. For example, a valid input string is "10 + 2\n14 * 2\n102 - 10" where there is exactly one space before or after an operator. The function returns a string containing the results of the input expressions separated by a space. For example, the function must return the string "12 28 92" for the above example.  */

int operand(string a){
    int x = a.length();
    int re = 0;
    int dau = 0;
    for (int i = 0; i < x;i++){
        if (a[i]=='-')
        dau = 1;
        else {
            re = re*10 + (int)(a[i]-'0');
        }
    }
    if (dau == 1)
    re = re * -1;
    return re;
}
int infix_cal(const string& input){
    int len = input.length();
    int s1 = input.find(' ');
    int s2 = input.find(' ',s1 + 1);
    string op1 = input.substr(0,s1);
    string opt = input.substr(s1+1,1);
    string op2 = input.substr(s2+1,len - s1 - 3);
    int iop1 = operand(op1);
    int iop2 = operand(op2);
    int re;
    if (opt == "+"){
        re = iop1 + iop2;
    }
    else if (opt == "-"){
        re = iop1 - iop2;
    }
    else if (opt == "*"){
        re = iop1 * iop2;
    }
    else if (opt == "/"){
        re = iop1 / iop2;
    }
    return re;
}
string many_infix_cal(const string& input){
    int pos1 = 0;
    int pos2 = 0;
    string cur = "";
    int len = input.length();
    for (int i = 0; i<= len;i++){
        if (input[i] == '\n'){
            pos2= i-1;
           cur = cur + to_string(infix_cal(input.substr(pos1,pos2 - pos1+1))) + " ";
            pos1 = i+1;
        }
        else if (input[i] == '\0'){
            pos2= i-1;
            cur = cur + to_string(infix_cal(input.substr(pos1,pos2 - pos1+1)));
        }
    }
    return cur;
}


// Question 4

/*
Given the following types:
typedef struct Item* ptr;
struct Item
{
    int value;
    ptr next;
}
Write function inputList() that inputs from stdin a sequence of non-negative integer numbers until meeting a negative value and returns the linked list of input values (excluding the negative value) in reversed order. 
Your code starts at line 20.  */

Item* inputList(){
    Item *head = new Item;
    head = nullptr;
    Item *ptr = new Item;
    ptr = head;
    int i;
    cin >>i;
    while (i >=0){
        Item *temp = new Item;
        temp->value = i;
        temp->next = nullptr;
        
        if (head == nullptr){
            head = temp;
            ptr = head;
        }
        else {
            ptr->next = temp;
            ptr = temp;
        }
        cin >> i;
    }
    if (head == nullptr || head->next == nullptr)
    return head;
    
    Item *current = new Item;
    current = head;
    ptr= current->next;
    
    Item *prev = new Item;
    prev =nullptr;
    
    while (current != nullptr){
        ptr = current ->next;
        current->next = prev;
        prev = current;
        current = ptr;
    }
    head = prev;
    return head;
}

// Question 5

/*

Given the following types:
typedef struct Item* ptr;
struct Item
{
    double coef; // coefficient
    int exp; // exponent
    ptr next;
}
This struct is used to keep an element aixi where coef keeps ai and exp keeps i in a polynomial Pn(x) = anxn +an-1xn-1+...+a0x0
Write function void normalizePolynomial(ptr& first) that normalizes the polynomial first and returns the linked list of normalized polynomial. The input polynomial is normalized as follows:
- if there are many elements with the same exponent, just keep the last input element whose coefficient is the sum of these coefficients and remove all other elements with the same exponent. If the sum of coefficient of the elements is zero, remove all these elements.
For example, if the input is as follows: (-1,2) (-1,1) (1,2) (1,3) (2,1) where (2,1) is the last input. The result is (1,1) (1,3) where (1,3) is the last printed value.
Your code starts at line 20.  */

void normalizePolynomial(ptr& first){
    
    int min = first->exp;
    int max = first->exp;
    
    Item *ptr = new Item;
    ptr = first;
    while (ptr != nullptr){
        if(ptr->exp > max)
        max = ptr->exp;
        
        if(ptr->exp < min)
        min = ptr->exp;
        
        ptr = ptr->next;
    }
   
   
    
    double *array = new double[max-min+1];
    for (int i = 0;i<max-min+1;i++){
        array[i]=0;
    }
    ptr = first;
    
    while (ptr != nullptr){
        array[ptr->exp-min]=array[ptr->exp-min]+ptr->coef;
        ptr = ptr->next;
    }
   
    
    ptr=first;
    Item *temp = new Item;
    temp=first->next;
    while (ptr != nullptr){
        delete ptr;
        ptr= temp;
        if (temp == nullptr)
        break;
        temp=temp->next;}

    
  Item *head = new Item;
  head = nullptr;
    for (int i = 0; i< max-min+1;i++){
        if (array[i]==0)
        continue;
        
        if (head == nullptr){
            Item *temp1 = new Item;
            temp1->exp=i+min;
            temp1->coef = array[i];
            temp1->next = nullptr;
            head = temp1;
            ptr = head;
        }
        else {
            Item *temp1 = new Item;
            temp1->exp=i+min;
            temp1->coef = array[i];
            temp1->next = nullptr;
            ptr->next =temp1;
            ptr=temp1;
        }
    }
    first = head;
    delete [] array;
}


// Question 6

/*

Given the following types:
typedef struct Item* ptr;
struct Item
{
    double coef; // coefficient
    int exp; // exponent
    ptr next;
}
This struct is used to keep an element aixi where coef keeps ai and exp keeps i in a polynomial Pn(x) = anxn +an-1xn-1+...+a0x0
Write function inputPolynomial() that inputs from stdin a polynomial and returns the linked list of input values in reversed order. Each item including the coefficient ai and the exponent i is input in one line. The input is terminated when 0 is input for the coefficient.
Your code starts at line 20.  */

Item* inputPolynomial(){
    Item *first = new Item;
    first = nullptr;
    
    Item *ptr = new Item;
    ptr = first;
    
    double d;
    int k;
    while(cin>>d){
        if (d == 0){
            cin>>k;
            continue;
        }
        Item *temp = new Item;
        temp->coef = d;
        cin >>k;
        temp->exp = k;
        temp ->next = nullptr;
        
        if (first == nullptr){
            first = temp;
            ptr = first;
        }
        else {
            ptr->next = temp;
            ptr = temp;
        }
    }
    
    if (first == nullptr)
    return first;
    
    
     Item *current = new Item;
    current = first;
    ptr= current->next;
    
    Item *prev = new Item;
    prev =nullptr;
    
    while (current != nullptr){
        ptr = current ->next;
        current->next = prev;
        prev = current;
        current = ptr;
    }
    first = prev;
    return first;
}