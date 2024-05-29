// Question 1
/*

Assume that class AList uses an array to implement the list. The private fields of this class are declared as below:
template <typename T>
class AList :public List<T> {
    private:
       const static int MAX = 20; //the maximum members of the list
       T* data; // keep the list
       int cursor = 0; // keep the position of the cursor
       int size; // the real size of the list
   public:
       AList() { data = new T[MAX];}
...
}
Write method void insert(const T& v) that inserts the new element whose value is v into the position of cursor and moves forward all elements after the cursor. Note that the method does not change the cursor.
*/

void insert(const T& v){
    
    for (int i = size - 1;i>=cursor;i--){
        data[i+1]=data[i];
    }
    data[cursor] = v;
    size++;
}


// Question 2

/*
Assume that class AList uses an array to implement the list. The private fields of this class are declared as below:
template <typename T>
class AList {
    private:
       const static int MAXSIZE = 20; //the maximum members of the list
       T* data; // keep the list
       int cursor = 0; // keep the position of the cursor
       int listSize; // the real size of the list
   public:
...
}
Write method void insertBefore(const T& v, const T& k) that inserts the new element v before the first element in the list whose value is k. If there is no value k in the list, value v is NOT inserted into the list and the cursor is unchanged. If the value k is in the list but the current size of the list is MAX, the exception out_of_range must be thrown. If the value v is inserted successfully, the cursor becomes before the new element. For example, let L be <3,|1,4> and L.insertBefore(2,3) makes L become <|2,3,1,4>.
*/

void insertBefore(const T& v,const T& k){
    int i = 0;
    while (i<listSize){
        if (data[i]==k)
        {break;}
        i++;
    }
    if (i == listSize) return;
    else if (listSize==MAXSIZE){
        throw out_of_range("excception");}
    for (int j = listSize -1;j>=i;j--){
        data[j+1]=data[j];
    }
    data[i]=v;
    cursor = i;
    listSize++;
}

// Question 3

/*
Assume that class AList uses an array to implement the list. The private fields of this class are declared as below:
template <typename T>
class AList : public List<T>{
    private:
       const static int MAXSIZE = 20; //the maximum members of the list
      T* data; // keep the list
       int cursor = 0; // keep the position of the cursor
       int listSize; // the real size of the list
   public:
...
}
Write method void remove() that removes the element at the cursor position and moves backward all elements after the cursor. If the cursor position is after the last element, please throw exception out_of_range("Cannot remove element"). Note that the method does not change the cursor. */

void remove(){
    if (cursor == listSize) throw out_of_range("Cannot remove element");
    
    for (int i = cursor;i<listSize;i++){
        data[i] = data[i+1];
    }
    listSize--;
}


// Question 4

/*
Based on the declaration of LList given in page 107, write method void insertBefore(const E& v, const E& k) that inserts the new element v before the first element in the list whose value is k. If there is no value k in the list, value v is NOT inserted into the list and the cursor is unchanged. If the value v is inserted successfully, the cursor becomes before the new element. For example, let L be <3,|1,4> and L.insertBefore(2,3) makes L become <|2,3,1,4> */

void insertBefore(const E& v, const E& k){
    
    if (head->element == k){                                //Insert before Head
        Link<E> *newLink = new Link<E>(v,head);
        head = newLink;                                         
        curr = head;    
        return;
    }
    

    Link<E> *temp = head;                   //this method can do also insert before tail
    while (temp->next!=nullptr){
        if (temp->next->element==k){
            break;
        }
        temp=temp->next;
    }
    if ((temp->next==nullptr)&&(temp->element!=k)){return;}
    Link<E> *newLink = new Link<E>(v,nullptr);
    newLink->next=temp->next;
    temp->next=newLink;
    curr =temp;
}


// Question 5

/*
Based on the implementation of the list given in Figure 4.8, write method template <typename E> void LList<E>::print() const that prints all elements of the list together with the cursor. For example, if the list has 3 elements 3, 5 and 7 and the cursor is at the beginning, the printed result is < | 3 5 7 >. */

template <typename E>
void LList<E>::print() const {
    
    Link<E> *temp = head;
    cout<<"< ";
    if (curr== temp) cout<<"| ";
    temp=temp->next;
    while(temp!=nullptr){
        cout<<temp->element<<" ";
        if (curr== temp) cout<<"| ";
        temp=temp->next;
    }
    cout<<">"<<endl;
}

// Question 6

/* 
Given the class LList<E> implemented as Figure 4.8, write method template <typename E> void LList<E>::reverse() that reverses the list. After reversing the list, the position of the cursor is unchanged. For example, < | 3 5 7> after reversing, it becomes < | 7 5 3>, or <3 | 5 7> => < 7 | 5 3>, or <3 5 7 |> => <7  5 3 |>. */

template <typename E> 

void LList<E>::reverse(){
    int count = 0,cursor=0;                 //cursor on off to count cursor
    
    Link<E> *temp = head;
    if (curr == temp){cursor = 1;}
    else {count++;
    }
    temp = head->next;
    Link<E> *prev = nullptr;
    Link<E> *nexttemp = new Link<E>;
    tail = temp;
    while(temp!=nullptr){
        if (temp == curr){cursor =1;}
        
        if (cursor == 0){count++;}
        
        nexttemp=temp->next;
        temp->next = prev;
        prev = temp;
        temp=nexttemp;
    }
    head->next = prev;
    
     temp = head;
    while (count != 0){
        temp = temp->next;
        count--;
    }
     curr = temp;
    
}   


// Question 7

/*
Based on class List defined on page 98, write function template <typename E> int count(List<E> &L,E K) that returns number of elements in K whose value is K. Your code starts from line 79. */

template <typename E> 
int count(List<E> &L, E K){
    int count =0;
    for (L.moveToStart();L.currPos()<L.length();L.next()){
        E it = L.getValue();
        if (it == K) count++;
    }
    return count;
}

// Question 8

/*
Based on the List ADT defined on page 98, write function template <typename T> void del(List<T> &L,T k) that deletes all elements in L whose value is k? Your code starts from line 74. */

template <typename T>
void del(List<T> &L, T K){
    L.moveToStart();
    while(L.currPos()<L.length()){
       
            
        T it = L.getValue();
        
        if (it == K) {
        L.remove();
        
        if (L.currPos()==0)                 //if the cursor is at the beginning we cannot use L.prev()
        continue;
        
        L.prev();}
        
        L.next();
    }
}


// Question 9

/*
Write function template <typename T> void DuplicationKiller(List<T> &L) that removes all elements which appear more than once in the list L. For example, let L be <2,4,2,9,4,2,4>, after DuplicationKiller(L), it becomes <9> */

template <typename T> 
void DuplicationKiller(List<T> &L){
    L.moveToStart();
    while(L.currPos()<L.length()){
        T it = L.getValue();
        int dupli = 0;
        int i =L.currPos();
        L.next();
        for (L.currPos();L.currPos()<L.length();L.next()){
            if (it == L.getValue()){
                dupli = 1;
                break;
            }
        }
        if (dupli == 1){
        del(L,it);
        if ((L.length()==0)||(i>=L.length()))
        break;
        L.moveToPos(i);
        continue;
        }
        L.moveToPos(i);
        L.next();
    }
    
}
template <typename T> 
void del(List<T> &L, T K){
    L.moveToStart();
    while(L.currPos()<L.length()){
       
            
        T it = L.getValue();
        
        if (it == K) {
        L.remove();
        
        if (L.currPos()==0)                 //if the cursor is at the beginning we cannot use L.prev()
        continue;
        
        L.prev();}
        
        L.next();
    }
}


// Question 10

/*
Based on the List ADT given in Figure 4.1, write a function to merge two lists. The input lists have their elements in sorted order, from lowest to highest. The output list should also be sorted from lowest to highest. Your algorithm should run in linear time on the length of the output list. The return list must be a new list and it should be an object of LList<E> (linked list). The prototype of the function is:
template <typename E>
List<E>* merge(List<E>* in1, List<E>* in2); */

template <typename E>
List<E>* merge(List<E>*in1,List<E>*in2){
     List<E> * newList = new LList<E>;
    
     if ((in1->length()==0)&&(in2->length()==0)){
         return newList;
     }
     else if(in1->length()==0){
         newList = in2;
         return newList;
     }
     else if(in2->length()==0){
         newList = in1;
         return newList;
     }
     
    in1->moveToStart();
    in2->moveToStart();
    while ((in1->currPos()<in1->length())||(in2->currPos()<in2->length())){
        if (in1->currPos()==in1->length()){
            E it2 = in2->getValue();
            newList->insert(it2);
            newList->next();
            in2->next();
            continue;
        }
        else if (in2->currPos()==in2->length()){
            E it1 = in1->getValue();
            newList->insert(it1);
            newList->next();
            in1->next();
            continue;
        }
        
        E it1 = in1->getValue();
        E it2 = in2->getValue();
        
        
        
        if (it1 < it2){
            newList->insert(it1);
            newList->next();
            in1->next();
        }
        else {
             newList->insert(it2);
             newList->next();
            in2->next();
        }
    }
    newList->moveToPos(0);
    return newList;
}


// Question 11

/* 
As in the previous question, when a task is added into expression classes, new methods are added into these classes. Please change the way these classes are implemented in such a way that these classes do not change their contents when new tasks are added into these classes: 
- Define class Eval to calculate the value of an expression
- Define class PrintPrefix to return the string corresponding to the expression in prefix format
- Define class PrintPostfix to return the string corresponding to the expression in postfix format
Let x be a pointer to an object expressing an expression and eval, pre, pos be the pointers to an object of Eval(), PrintPrefix() PrintPostfix(), respectively, x->accept(eval) or eval->visit(x) will return the value of the expression x, x->accept(pre) or pre->visit(x) will return the expression in prefix format and x->accept(pos) or pos->visit(x) will return the expression in postfix format. 
Be careful that you are not allowed to use any function to check the type of an object when implementing this exercise 
Tip: Use Visitor pattern. */

class Exp;
class IntLit;
class BinExp;
class UnExp;

class Visitor {
    public:

    virtual int visit(BinExp *x) = 0;
    virtual int visit(UnExp *x) = 0;
    virtual int visit(IntLit *x) = 0;
};

class Exp{
    public:
    virtual int eval() =0;
    virtual int accept(Visitor *v)=0;
};

class BinExp:public Exp{
    public:
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
    int accept(Visitor *v){return v->visit(this);}
};

class UnExp:public Exp{
    public:
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
     int accept(Visitor* v){ return v->visit(this); }
};

class IntLit: public Exp{
    public:
    int value;
    public:
    IntLit(int v){
        value = v;
    };
    
    int eval() {return value;}
     int accept(Visitor* v){ return v->visit(this); }
};

class Eval:public Visitor {
    public:
    int visit(BinExp *x){
        return x->eval();
    }
    int visit(UnExp *x){
        return x->eval();
    }
    int visit(IntLit *x){
        return x->eval();
    }
};

class PrintPrefix:public Visitor {
    public:
    int visit(BinExp *x){
        cout<<x->op<<" ";
        x->left->accept(this);
        cout<<" ";
        x->right->accept(this);
        return 0;
    }
    int visit(UnExp *x){
        cout<<x->op<<"."<<" ";
        x->exp->accept(this);
        return 0;
    }
    int visit(IntLit *x){
        cout<<x->eval();
        return 0;
    }
};



class PrintPostfix:public Visitor {
    public:
    int visit(BinExp *x){
        x->left->accept(this);
        cout<<" ";
        x->right->accept(this);
        cout<<" "<<x->op;
        return 0;
    }
    int visit(UnExp *x){
        x->exp->accept(this);
        cout<<" "<<x->op<<".";
        return 0;
    }
    int visit(IntLit *x){
        cout<<x->eval();
        return 0;
    }
};