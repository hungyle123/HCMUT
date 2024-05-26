#include "main.h"
enum huffmanstate{Leaf = 1,Combine=2};
/************************************************************************************************************************************************/
class countKokusen {								
	public:
	vector<vector<long long>> table;
    int maxsize;
    
	countKokusen(int maxsize){
		this->maxsize = maxsize;
	}


    int numOfWays(vector<int>& nums) {
        int m = nums.size();
        // Table of Pascal's triangle
        table.resize(m + 1);
        for(int i = 0; i < m + 1; ++i) {
            table[i] = vector<long long>(i + 1, 1);
            for(int j = 1; j < i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]);
            }
        }
        
        return dfs(nums) % maxsize;
    }
    long long dfs(vector<int> &nums){
        int m = nums.size();
        if(m < 3) {
            return 1;
        }

        vector<int> leftNodes, rightNodes;
        for(int i = 1; i < m; ++i){
            if (nums[i] < nums[0]) {
                leftNodes.push_back(nums[i]);
            } else {
                rightNodes.push_back(nums[i]);
            }
        }
		
        long long leftWays = dfs(leftNodes);
        long long rightWays = dfs(rightNodes);
		
        return (((leftWays * rightWays)) * table[m - 1][leftNodes.size()]);
    }
};


class NodeGojo{
	public:
	int value;
	NodeGojo *pLeft;
	NodeGojo *pRight;

	NodeGojo(int value){
		this->value = value;
		pLeft = nullptr;
		pRight = nullptr;
	}
};
class node_minheap{
	public:
	int index_move_to_front;
	int label;
	int num;
	node_minheap(){
		this->label = -1;
		this->num = -1;
	}
	void update_index_move_to_front(int *move_to_front,int k ){
		for (int i = 0;i<k;i++){
			if(move_to_front[i]==label){
			this->index_move_to_front = i;
			break;}
		}
	}

	// bool operator == (int a){
	// 	return this->label == a;
	// }
};

class Gojo {
	public:
	int maxsize;
	NodeGojo** arr_Gojo;
	queue<NodeGojo*>* queue_id;


	Gojo(int maxsize){
		this->maxsize = maxsize;
		arr_Gojo = new NodeGojo*[maxsize];
		for (int i = 0;i<maxsize;i++){
			arr_Gojo[i] = nullptr;
		}
		queue_id = new queue<NodeGojo*>[maxsize];
	}

	void insert_Gojo(int key,int id){				// hàm này quy ước root != nullptr trước khi nhập nhớ xét 
		if (arr_Gojo[id-1]== nullptr){
			arr_Gojo[id-1] = new NodeGojo(key);
			queue_id[id-1].push(arr_Gojo[id-1]);
			return;
		}
		NodeGojo* temp = arr_Gojo[id-1];
		while (true){
			if (key >= temp->value){
				if (temp->pRight == nullptr)
				break;
				else {
					temp = temp->pRight;
				}
			}
			else {
				if (temp->pLeft == nullptr)
				break;
				else {
					temp = temp->pLeft;
				}
			}
		}

		if (key >= temp->value){
			temp->pRight = new NodeGojo(key);
			queue_id[id-1].push(temp->pRight);
		}
		else {
			temp->pLeft = new NodeGojo(key);
			queue_id[id-1].push(temp->pLeft);
		}
	}

	void delete_Gojo(int id){
		if (arr_Gojo[id-1]==nullptr) return;
		
		NodeGojo * temp = queue_id[id-1].front();
		//cout<<temp->value<<endl;
		queue_id[id-1].pop();
		arr_Gojo[id-1] = delete_nodeGojo(arr_Gojo[id-1],temp);

		//delete temp;
	}
	NodeGojo * delete_nodeGojo(NodeGojo * root,NodeGojo * k){
		if (root == nullptr)
        return root;

		if (root != k){
			
		if (k->value < root->value ) {
			root->pLeft = delete_nodeGojo(root->pLeft, k);
			return root;
		}
		else if (k->value >= root->value) {
			root->pRight = delete_nodeGojo(root->pRight, k);
			return root;
		}
		
		}


		if (root->pLeft == nullptr) {		
			// NodeGojo* temp = root->pRight;
			// delete root;
			// return temp;

			NodeGojo* temp = root;
			root = root->pRight;
			temp->pLeft = NULL; 
			temp->pRight = NULL;
			delete temp;
			return root;
		}
		else if (root->pRight == nullptr) {
			// NodeGojo* temp = root->pLeft;
			// delete root;
			// return temp;

			NodeGojo* temp = root;
			root = root->pLeft;
			temp->pLeft = NULL; 
			temp->pRight = NULL;
			delete temp;
			return root;
		}
		else {
			NodeGojo* succParent = root;
			NodeGojo* succ = root->pRight;
			while (succ->pLeft != nullptr) {
				succParent = succ;
				succ = succ->pLeft;
			}
	
			if (succParent != root){
				succParent->pLeft = succ->pRight;
				succ->pLeft = root->pLeft;
				succ->pRight = root->pRight;
				
				root->pLeft = nullptr;
				root->pRight = nullptr;
				delete root;
				return succ;

			}
			else{
				succParent->pRight = succ->pRight;
				succ->pLeft = root->pLeft;
				root->pLeft = nullptr;
				root->pRight = nullptr;
				delete root;
				return succ;
			}

			// root->value = succ->value;

			// succ->pLeft = NULL; 
			// succ->pRight = NULL;
			// delete succ;
			// return root;
		}
		}
	

};

void clear_gojo(NodeGojo * root){
		if (root == nullptr) return;

		clear_gojo(root->pLeft);
		clear_gojo(root->pRight);
		delete root;
		
	}

/************************************************************************************************************************************************/
bool compare_arr_sukuna(node_minheap a, node_minheap b){
		if (a.num == b.num){
			return a.index_move_to_front > b.index_move_to_front;
		}
		return a.num < b.num;
	}
void reheapDown(node_minheap minheap[], int k, int index) {
		int parent = index;
		int leftChild = 2 * index + 1;
		int rightChild = 2 * index + 2;

		//bool a = (minheap[leftChild].num < minheap[parent].num )||((minheap[leftChild].num == minheap[parent].num) && (minheap[leftChild].index_move_to_front > minheap[parent].index_move_to_front));
		
		//if (minheap[leftChild].index_move_to_front > minheap[parent].index_move_to_front)
		//cout<<"A"<<a<<endl;
		if (leftChild < k  ){
			if (minheap[leftChild].num < minheap[parent].num )
			parent = leftChild;
			
			else if ((minheap[leftChild].num == minheap[parent].num) && (minheap[leftChild].index_move_to_front > minheap[parent].index_move_to_front))
			parent = leftChild;
		}
		
		if (rightChild < k  ) {
			if (minheap[rightChild].num < minheap[parent].num)
			parent = rightChild;
			else if ((minheap[rightChild].num == minheap[parent].num) && (minheap[rightChild].index_move_to_front > minheap[parent].index_move_to_front))
			parent = rightChild;
		}

		if (parent != index) {
			int temp = minheap[index].num;
			int label = minheap[index].label;
			int temp_front = minheap[index].index_move_to_front;
			minheap[index].num = minheap[parent].num;
			minheap[index].label = minheap[parent].label;
			minheap[index].index_move_to_front = minheap[parent].index_move_to_front;
			minheap[parent].num = temp;
			minheap[parent].label = label;
			minheap[parent].index_move_to_front = temp_front;
			reheapDown(minheap, k, parent);
    	}
	}
void reheapUp(node_minheap minheap[], int k, int index) {
		if (index == 0) {
			return;
		}
		int parent = (index - 1) / 2;

		if ((minheap[index].num < minheap[parent].num)){
			int temp = minheap[index].num;
			int label = minheap[index].label;
			int temp_front = minheap[index].index_move_to_front;
			minheap[index].num = minheap[parent].num;
			minheap[index].label = minheap[parent].label;
			minheap[index].index_move_to_front = minheap[parent].index_move_to_front;
			minheap[parent].num = temp;
			minheap[parent].label = label;
			minheap[parent].index_move_to_front = temp_front;
			reheapUp(minheap, k, parent);
		}
}

class Sukuna {
	public:
	int maxsize;
	int * move_to_front;
	node_minheap* minheap;
	vector<int>* qu_st_id;
	int k;

	Sukuna(int a){
		this->maxsize = a;
		minheap = new node_minheap[maxsize];
		move_to_front = new int[maxsize];

		this->k = 0;
		qu_st_id = new vector<int>[maxsize];
	}
	void insert(int label,int result){
		// cout<<"move to front:"<<endl;
		// for (int i =0;i<k;i++){
		// 	cout<<move_to_front[i]<<" ";
		// }
		// cout<<endl;
		// cout<<"minheap:"<<endl;
		// for (int i =0;i<k;i++){
		// 	cout<<minheap[i].label<<" value"<<minheap[i].num<<" ";
		// }
		// cout<<endl;

		int idx = find(move_to_front,move_to_front+k,label)-move_to_front;
		qu_st_id[label-1].push_back(result);
		
		if (idx==k){
			
			k = k+1;
			for (int i = k-1;i>=1;i--){
				move_to_front[i] = move_to_front[i-1];
			}
			move_to_front[0]=label;
			minheap[k-1].label = label;
			minheap[k-1].num = 1;
			for (int i = 0;i<k;i++){
				minheap[i].update_index_move_to_front(move_to_front,k);
			}
			reheapUp(minheap,k,k-1);
			for (int i = 0;i<k;i++){
				minheap[i].update_index_move_to_front(move_to_front,k);
			}
		}
		else{
			
			int temp = move_to_front[idx];
			for (int i = idx;i>0;i--){
				move_to_front[i] = move_to_front[i-1];
			}
			move_to_front[0] = temp;
			for (int i = 0;i<k;i++){
				minheap[i].update_index_move_to_front(move_to_front,k);
			}
			for (int i = 0;i<k;i++){
				if (minheap[i].label == label){
					minheap[i].num +=1;
					reheapDown(minheap,k,i);
					for (int i = 0;i<k;i++){
					minheap[i].update_index_move_to_front(move_to_front,k);
					}
					break;
				}
			}

		}
	}

	void setup_erase(int num){
		if (k == 0) return;

		vector<node_minheap> temp;
		for (int i = 0;i<k;i++){
			temp.push_back(minheap[i]); 
		}

		sort(temp.begin(),temp.end(),compare_arr_sukuna);
		vector<int> arrlabel;
		int newnumber = num;
		if(newnumber > k)
		newnumber = k;

		for (int i =0;i<newnumber;i++){
			arrlabel.push_back(temp[i].label);
		}
		//delete [] temp;
		erase_minheap(arrlabel,num);
	}
	void erase_minheap(vector<int> arrlabel,int num){	
		// cout<<"move to front:"<<endl;
		// for (int i =0;i<k;i++){
		// 	cout<<move_to_front[i]<<" ";
		// }
		// cout<<endl;
		// cout<<"minheap:"<<endl;
		// for (int i =0;i<k;i++){
		// 	cout<<minheap[i].label<<" value"<<minheap[i].num<<" ";
		// }
		// cout<<endl;
		if (k == 0) return;
		bool zero = false;

		int n = arrlabel.size();
		for (int i = 0;i< n;i++){

			int idx = arrlabel[i];
			int index = -1;
			zero = false;
			for (int j = 0;j<k;j++){
				if (idx == minheap[j].label){
					index = j;
					break;
				}
			}
			int len = num;
			if (len > (int)qu_st_id[idx-1].size()) len = (int)qu_st_id[idx-1].size();
			for (int j = 0;j< len;j++){
			cout<<qu_st_id[idx-1][0]<<"-"<<idx<<endl;

			minheap[index].num--;
			qu_st_id[idx-1].erase(qu_st_id[idx-1].begin());
			if (minheap[index].num == 0){
				zero = true;
				break;
			}
			}
			
			if (zero){
				int remove_front = find(move_to_front,move_to_front+k,idx)-move_to_front;
				for (int i = remove_front;i<k-1;i++){
					move_to_front[i]=move_to_front[i+1];
				}
				k--;
				minheap[index].label = minheap[k].label;
				minheap[index].num = minheap[k].num;
				minheap[index].index_move_to_front = minheap[k].index_move_to_front;
				
				for (int i = 0;i<k;i++){
					minheap[i].update_index_move_to_front(move_to_front,k);
				}
		// 		for (int i = 0;i<k;i++){
		// 			cout<<minheap[i].label<<" mo"<<minheap[i].index_move_to_front;
		// 		}
		// 		cout<<endl;
		// 		cout<<"move to front:"<<endl;
		// for (int i =0;i<k;i++){
		// 	cout<<move_to_front[i]<<" ";
		// }
		// cout<<endl;
				reheapDown(minheap,k,index);
				
				for (int i = 0;i<k;i++){
					minheap[i].update_index_move_to_front(move_to_front,k);
				}
				// for (int i = 0;i<k;i++){
				// 	cout<<minheap[i].label<<" ";
				// }
				// cout<<endl;
			}
			else {
				reheapUp(minheap,k,index);
				int remove_front = find(move_to_front,move_to_front+k,idx)-move_to_front;
				for (int i = remove_front;i>0;i--){
					move_to_front[i]=move_to_front[i-1];
				}
				move_to_front[0]= idx;
				for (int i = 0;i<k;i++){
					minheap[i].update_index_move_to_front(move_to_front,k);
				}
			}

		}
	

	}

};

/************************************************************************************************************************************************/
/************************************************************************************************************************************************/
class character{
	public:
	char key;
	int fre;

	character(char key,int fre){
		this->key = key;
		this->fre = fre;
	}

	bool operator == (char key){
		return this->key == key;
	}

};
bool comparechar(character a, character b){
		if (a.fre == b.fre){
			if (65<= a.key && a.key <=90 && 97<=b.key && b.key<=122){
				return false;
			}
			else if (65<=b.key && b.key <=90 && 97<=a.key && a.key<=122){
				return true;
			}
			return a.key < b.key;
		}
		else {
			return a.fre < b.fre;
		}
	}
/************************************************************************************************************************************************/
class huffman{
	public:
	huffmanstate state;
	char key;					//value key = ~ denote the combine
	huffman* pLeft;
	huffman* pRight;
	int fre ;
	int order;
	string bit;

	huffman(huffmanstate state,int fre,char key,int order ){
		this->key = key;
		this->state = state;
		this->fre = fre;
		pLeft = nullptr;
		pRight = nullptr;
		this->order = order;
	}
};
class Compare_huffman_minheap 
{ 
public: 
    bool operator() (huffman * a, huffman * b) 
    { 
        if (a->fre == b->fre){
			if (65<= a->key && a->key <=90 && 97<=b->key && b->key<=122){
				return true;
			}
			else if (65<=b->key && b->key <=90 && 97<=a->key && a->key<=122){
				return false;
			}
			else if (a->key != b->key)
			return a->key > b->key;

			return a->order > b->order;
		}
		else {
			return a->fre > b->fre;
		}
    } 
};  

huffman* rotateRight(huffman* root) {
	
    huffman* left = root->pLeft;
    huffman* leftr = left->pRight;
    
    left->pRight = root;
    root->pLeft = leftr;
	// huffman *temproot = root;
	// 	temproot->fre = 0;
	// if (temproot->pLeft != nullptr) temproot->fre += temproot->pLeft->fre;
	// if (temproot->pRight != nullptr) temproot->fre += temproot->pRight->fre;
	
	// huffman *temp = left;
	// temp->fre = 0;
	// if (temp->pLeft != nullptr) temp->fre += temp->pLeft->fre;
	// if (temp->pRight != nullptr) temp->fre += temp->pRight->fre;

	return left;
}

huffman* rotateLeft(huffman* root){

    huffman* right = root->pRight;
    huffman* rightl = right->pLeft;
    
    right->pLeft = root;
    root->pRight = rightl;

	// huffman *temproot = root;
	// 	temproot->fre = 0;
	// if (temproot->pLeft != nullptr) temproot->fre += temproot->pLeft->fre;
	// if (temproot->pRight != nullptr) temproot->fre += temproot->pRight->fre;

	// int left_root = (root->pLeft) ? root->pLeft->fre:0;
	// int right_root = (root->pRight) ? root->pRight->fre:0;

	// root->fre = left_root+ right_root;
    // huffman *temp = right;
	// temp->fre = 0;
	// if (temp->pLeft != nullptr) temp->fre += temp->pLeft->fre;
	// if (temp->pRight != nullptr) temp->fre += temp->pRight->fre;

	return right;
}

int heighthuffman(huffman *node) {
	if (node == NULL)
		return 0;
	int lh = heighthuffman(node->pLeft);
	int rh = heighthuffman(node->pRight);
	if (lh > rh) return lh + 1;
	else return rh + 1;
}
int getbalance(huffman *root){
	if (root == nullptr) return 0;
	return heighthuffman(root->pLeft)-heighthuffman(root->pRight);
}

/************************************************************************************************************************************************/
int countchar(string& s, char& c)
{
    int count = 0;
    for (int i=0;i<(int)s.length();i++)
        if (s[i] == c)
            count++;
 
    return count;
}
/************************************************************************************************************************************************/
string findhuffman(huffman*root,char key,string s = ""){
		if (root == nullptr){
			return "";
		}
		
		if (root->key == key){
			return s;
		}

		return findhuffman(root->pLeft,key,s + "0") + findhuffman(root->pRight,key,s +"1");
}
/************************************************************************************************************************************************/
void del(huffman *root){
	if (root == nullptr) return;

	del(root->pLeft);
	del(root->pRight);

	root->pLeft = nullptr;
	root->pRight = nullptr;
	delete root;
}
/************************************************************************************************************************************************/
void rearrange(vector<character> & arr,string name){
	int n = name.length();
	//int k = 0;
	for(int i=0;i<n;i++){
		if (find(arr.begin(), arr.end(), name[i])==arr.end()){
			arr.push_back(character(name[i],countchar(name,name[i])));
		}
	}
}
/************************************************************************************************************************************************/
void ceaser(vector<character> & arr){
	vector<character> newarr;
	int n = arr.size();
	 for(int i = 0;i <n;i++){
        if ((arr[i].key>='a')&&(arr[i].key<='z')){ 
			if (arr[i].key+arr[i].fre>122)
            arr[i].key=(arr[i].key-97+arr[i].fre)%26 +97;
        	else 
			arr[i].key = arr[i].key+arr[i].fre;
		}
        else if ((arr[i].key>='A')&&(arr[i].key<='Z')){ 
			if (arr[i].key+arr[i].fre >90)
            arr[i].key=(arr[i].key-65+arr[i].fre)%26 +65;
        	else 
			arr[i].key =arr[i].key+arr[i].fre;
		}
		vector<character>:: iterator it;
		it =find(newarr.begin(), newarr.end(), arr[i].key);

		if (it == newarr.end()){
			newarr.push_back(character(arr[i].key,arr[i].fre));
		}
		else {
			newarr[it-newarr.begin()].fre += arr[i].fre;
		}
    }

	arr.clear();
	arr = newarr;
	sort(arr.begin(),arr.end(),comparechar);
}
/************************************************************************************************************************************************/
huffman *Roll(huffman *root){
	int balance = getbalance(root);
	
    if (balance > 1 && getbalance(root->pLeft) >= 0) 
        return rotateRight(root); 
 
    if (balance > 1 && getbalance(root->pLeft) < 0) 
    { 
        root->pLeft = rotateLeft(root->pLeft); 
        return rotateRight(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && getbalance(root->pRight) <= 0) 
        return rotateLeft(root); 
 
    // Right Left Case 
    if (balance < -1 && getbalance(root->pRight) > 0) 
    { 
        root->pRight = rotateRight(root->pRight); 
        return rotateLeft(root); 
    } 
 

	return root;
}




huffman *re_balance(huffman * root, int &count_tostop,bool &is_rotate){
	if (root == nullptr) return nullptr;
	if (count_tostop == 0 || is_rotate ) return root;

	while(count_tostop > 0){

	int factor =getbalance(root);
	if (abs(factor) > 1){
		root = Roll(root);
		count_tostop--;
		is_rotate = true;

		return root;
	}
	else break;

	}

	root->pLeft = re_balance(root->pLeft,count_tostop,is_rotate);
	root->pRight = re_balance(root->pRight,count_tostop,is_rotate);
	return root;
}




huffman *turn_back_root(huffman *root,int &count_tostop){
	bool is_rotate = false;


	while(true){
		root = re_balance(root,count_tostop,is_rotate);

		if (count_tostop == 0 || is_rotate == false) break;
		else is_rotate = false;
	}
	return root;
}
/************************************************************************************************************************************************/

/************************************************************************************************************************************************/
huffman* buildhuffman(vector<character> &arr){
	priority_queue<huffman*,vector<huffman*>,Compare_huffman_minheap> heap;
	int n = arr.size();
	int order = 0;
	for (int i = 0;i<n;i++){
		heap.push(new huffman(Leaf,arr[i].fre,arr[i].key,order++));
	}
	if (n == 1){
		huffman * temp =heap.top();
		heap.pop();
		// huffman* newnode = new huffman(Leaf,temp->fre,temp->key,order++);
		return temp;
	}

	// huffman * temp1 =heap.top();
	// heap.pop();
	// huffman * temp2 =heap.top();
	// heap.pop();

	// huffman* newroot = new huffman(Combine,temp1->fre+temp2->fre,'~',order++);
	// newroot->pLeft = temp1;
	// newroot->pRight = temp2;
	// heap.push(newroot);
	while (true){
		if (heap.size()==1) break;

		huffman* temp1 =heap.top();
		heap.pop();
		huffman* temp2 =heap.top();
		heap.pop();

		huffman* newroot = new huffman(Combine,temp1->fre+temp2->fre,'~',order++);
		newroot->pLeft = temp1;
		newroot->pRight = temp2;
		
		// newroot = Roll(newroot);

		// newroot->pLeft = Roll(newroot->pLeft);

		// newroot->pRight = Roll(newroot->pRight);
		int count_tostop = 3;
		newroot = turn_back_root(newroot,count_tostop);

		newroot->order = order++;
		//cout<<newroot->fre<<endl;
		heap.push(newroot);

	}
	huffman *result = heap.top();
	heap.pop();
	return result;

}
/************************************************************************************************************************************************/
int binaryToDecimal(string& str) {
    int result = 0;
    int power = 1;

    for (int i = str.length() - 1; i >= 0; --i) {
        if (str[i] == '1') {
            result += power;
        }
        power *= 2;
    }

    return result;
}

/************************************************************************************************************************************************/
void LAPSE(string name,Gojo * restaurent_Gojo, Sukuna * restaurent_Sukuna,int maxsize,huffman *& last){
	vector<character> arr;
	vector<character> ceaserarr;
	rearrange(arr,name);
	int n = arr.size();

	if (n < 3) return;

	sort(arr.begin(),arr.end(),comparechar);
	ceaserarr = arr;
	ceaser(ceaserarr);

	// for (int i = 0;i<(int)ceaserarr.size();i++){
	// 	cout<<ceaserarr[i].key<<" "<<ceaserarr[i].fre<<endl;
	// }
	huffman* root = buildhuffman(ceaserarr);
	del(last);
	last = nullptr;
	last = root;
	int len = name.length();
	string result ="";
	// for (int i = 0;i<n;i++){
	// 	cout<<ceaserarr[i].key<<" :"<<findhuffman(root,ceaserarr[i].key,"")<<endl;}
	for (int i = 0;i<len;i++){
		char a = name[i];
		int shift = arr[find(arr.begin(),arr.end(),a)-arr.begin()].fre;
		if ((a >='a')&&(a <='z')){ 
			if (a + shift >122)
            a = (a - 97 + shift)%26 +97;
        	else 
			a = a + shift;
		}
        else if ((a >= 'A')&&(a <= 'Z')){ 
			if (a + shift >90)
            a = (a - 65 + shift)%26 +65;
        	else 
			a = a + shift;
		}

		result = result + findhuffman(root,a);
	}
	// int lent = ceaserarr.size();
	// for (int i = 0;i<lent;i++){
	// 	int temp = ceaserarr[i].fre;
	// 	while (temp > 0){
	// 		result = result + findhuffman(root,ceaserarr[i].key);
	// 		temp--;
	// 	}
	// }
	 //cout<<result<<endl;
	int lenresult = result.length();
	if (lenresult > 10) {
		string x ="";
		for (int i = lenresult-1 ;i>=lenresult-10;i--){
			x = x + result[i];
		}
		result = x;
	}
	else {
		string x ="";
		for (int i = lenresult-1 ;i >0;i++){
			x = x + result[i];
		}
		result = x;
	}
	//cout<<result<<endl;
	int result_int = binaryToDecimal(result);
	int id = result_int%maxsize + 1;
	//cout<<"RESULT: "<<result_int<<" ID: "<<id<<endl;
	if (result_int % 2 == 1){
		//cout<<"go to sukuna's restaurant"<<endl;
		restaurent_Gojo->insert_Gojo(result_int,id);
		
	}
	else {
		//cout<<"Sukuna"<<endl;
		restaurent_Sukuna->insert(id,result_int);
	}


}
/************************************************************************************************************************************************/
int countkokusen(vector<NodeGojo*> arr, NodeGojo * p){
    if (p->pLeft != nullptr) arr.push_back(p->pLeft);
    if (p->pRight != nullptr) arr.push_back(p->pRight);
    
    int n = arr.size();
    int index = -1;
    for (int i = 0;i<n;i++){
        if (arr[i]->value == p->value && arr[i]->pLeft == p->pLeft && arr[i]->pRight == p->pRight){
            index = i;
            break;
        }
    }
    
    arr.erase(index+arr.begin());
    
    n = n-1;
    if (n==0) return 1;
    int result = 0;
    for (int i =0;i<n;i++){
        result += countkokusen(arr,arr[i]);
    }
    return result;
}
void push_in(vector<int> &arr,NodeGojo * root){
	if (root == nullptr) return;
	arr.push_back(root->value);
	if (root->pLeft != nullptr) push_in(arr,root->pLeft);
	if (root->pRight!= nullptr) push_in(arr,root->pRight);
}
void inorder_limitless(NodeGojo * root){
	if (root == nullptr) return;

	if (root->pLeft != nullptr) inorder_limitless(root->pLeft);

	cout<<root->value<<endl;

	if (root->pRight != nullptr) inorder_limitless(root->pRight);

}
/************************************************************************************************************************************************/
void KOKUSEN(Gojo * restaurent_Gojo){
	//cout<<"PRINT CUSTOMERS TO BE DELETED"<<endl;
	int n = restaurent_Gojo->maxsize;
	countKokusen * counting = new countKokusen(n);
	for (int i =1;i<n+1;i++){
		//cout<<"gojo label "<<i<<endl;
		if (restaurent_Gojo->arr_Gojo[i-1]==nullptr) continue;
		
		vector<int> arr;
		push_in(arr,restaurent_Gojo->arr_Gojo[i-1]);
		int Y = counting->numOfWays(arr);			
		//cout<<"number to delete "<<Y<<endl;
		for (int j = 0;j<Y;j++){
			restaurent_Gojo->delete_Gojo(i);
			//cout<<"print inorder label "<<i<<endl;
			//inorder_limitless(restaurent_Gojo->arr_Gojo[i-1]);
		}
	}
	//cout<<"PRINT FOR GOJO IN KOKUSEN"<<endl;
	// for (int i =1;i<n+1;i++){
	// 	cout<<"gojo label "<<i<<endl;
	// 	inorder_limitless(restaurent_Gojo->arr_Gojo[i-1]);
	// }
	delete counting;
}
/************************************************************************************************************************************************/
void KEITEIKEN(int num,Sukuna * restaurent_Sukuna){
	restaurent_Sukuna->setup_erase(num);
	//cout<<"PRINT AFTER KEITEIKEN"<<endl;
	// for (int i = 0;i<(int)restaurent_Sukuna->k;i++){
	// 	for (int j = 0;j<(int)restaurent_Sukuna->minheap[i].num;j++)
	// 	cout<<restaurent_Sukuna->minheap[i].label<<"-"<<restaurent_Sukuna->qu_st_id[restaurent_Sukuna->minheap[i].label-1][j]<<endl;
	// }
}
/************************************************************************************************************************************************/
void inorder_hand(huffman * root){
	if (root == nullptr) return;

	if (root->pLeft != nullptr) inorder_hand(root->pLeft);

	if(root->state == Leaf){
	//cout<<root->key<<"-"<<root->fre<<endl;
	cout<<root->key<<endl;
	}
	else 
	cout<<root->fre<<endl;

	if (root->pRight != nullptr) inorder_hand(root->pRight);

}
/************************************************************************************************************************************************/
void HAND(huffman *& last){
	inorder_hand(last);
}
/************************************************************************************************************************************************/

/************************************************************************************************************************************************/


void LIMITLESS(int num,Gojo * restaurent_Gojo){
	if (num < 0) return;
	if (num > restaurent_Gojo->maxsize) return;
	//cout << "GOJO LABEL " << num << '\n';
	if (restaurent_Gojo->arr_Gojo[num-1]==nullptr) return;


	inorder_limitless(restaurent_Gojo->arr_Gojo[num-1]);
}

/************************************************************************************************************************************************/
void preorder_minheap(Sukuna * restaurent_Sukuna,int index,int num){
		//cout<<"Minheap is at index :"<<index<<endl;
		int size = restaurent_Sukuna->qu_st_id[restaurent_Sukuna->minheap[index].label-1].size();
		//cout<<"Size :"<<size<<" Label: "<<restaurent_Sukuna->minheap[index].label<<endl;
		int k = num;
		if (k > size) k = size;

		size--;
		for (int i = 0;i < k;i++){
			cout<<restaurent_Sukuna->minheap[index].label<<"-"<<restaurent_Sukuna->qu_st_id[restaurent_Sukuna->minheap[index].label-1][size]<<endl;

			size--;
		}

		int left = index*2+1;
		if (left < restaurent_Sukuna->k) preorder_minheap(restaurent_Sukuna,left,num);
		int right = index*2+2;
		if (right < restaurent_Sukuna->k) preorder_minheap(restaurent_Sukuna,right,num);
}



/************************************************************************************************************************************************/
void CLEAVE(int num,Sukuna * restaurent_Sukuna){
	if (num < 1) return;
	//cout<<"SUKUNA AFTER CLEAVE"<<endl;
	if (restaurent_Sukuna->k == 0) return;
	preorder_minheap(restaurent_Sukuna,0,num);
	// for (int i = 0;i<(int)restaurent_Sukuna->k;i++){
	// 	for (int j = 0;j<(int)restaurent_Sukuna->minheap[i].num;j++)
	// 	cout<<restaurent_Sukuna->minheap[i].label<<"-"<<restaurent_Sukuna->qu_st_id[restaurent_Sukuna->minheap[i].label-1][j]<<endl;
	// }

}
void thutuminheap(Sukuna * restaurent_Sukuna){
	int k = restaurent_Sukuna->k;

	for (int i = 0; i<k;i++){
		//cout<<"Thu tu : "<<i<<" "<<restaurent_Sukuna->minheap[i].label<<endl;
	}
}
/************************************************************************************************************************************************/
void simulate(string filename)
{
	ifstream ss(filename);
	string str, maxsize, name, num;
	int number;
	int MAXSIZE = 0;
	Gojo *restaurant_Gojo = nullptr;
	Sukuna *restaurant_Sukuna = nullptr;
	huffman *last =nullptr;
	string the_last;
	while(ss >> str)
	{ 

		if(str == "MAXSIZE")
		{
			//cout<<"MAXSIZE: ";
			ss >> maxsize;
			MAXSIZE = stoi(maxsize); 
			restaurant_Gojo = new Gojo(MAXSIZE);
			restaurant_Sukuna = new Sukuna(MAXSIZE);
			//cout<<MAXSIZE<<endl;
			//cout<<endl;
			//cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    	}
        else if(str == "LAPSE") 
        {
			
			//cout<<"LAPSE <";
            ss >> name;
			//cout<<name<<">"<<endl;
            LAPSE(name,restaurant_Gojo,restaurant_Sukuna,MAXSIZE,last);
			the_last = name;
			//thutuminheap(restaurant_Sukuna);
			//cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    	}
    	else if(str == "KOKUSEN") 
    	{
			
			//cout<<"KOKUSEN"<<endl;
    		KOKUSEN(restaurant_Gojo);
			//cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		}
    	else if(str == "KEITEIKEN") 
    	{
			//cout<<"KEITEIKEN <";
			ss >> num;
			number = stoi(num); 
			//cout<<number<<">"<<endl;
    		KEITEIKEN(number,restaurant_Sukuna);
			//thutuminheap(restaurant_Sukuna);
			//cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		}
		else if(str == "HAND") 
		{
			
			//cout<<"HAND"<<endl;
			//cout<<"CUSTOMER HUFFMAN TREE PRINT"<<endl;
			if(last != nullptr){
			// cout<<"CUSTOMER HUFFMAN TREE PRINT"<<endl;
			HAND(last);
			}
			//cout<<"--------------------------------------------------------------------------------------------------"<<endl;
		}
    	else if(str == "LIMITLESS")
     	{   

			ss >> num;
			number = stoi(num);
			//cout<<"LIMITLESS <"<<number<<">"<<endl;
    		LIMITLESS(number,restaurant_Gojo);
			//cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    	}
    	else if(str == "CLEAVE") 
    	{	
			ss >> num;
			number = stoi(num);
			//cout<<"CLEAVE <"<<number<<">"<<endl;
    		CLEAVE(number,restaurant_Sukuna);
			//cout<<"--------------------------------------------------------------------------------------------------"<<endl;
    	}
    }


	del(last);				//delete huffman


	int n = restaurant_Gojo->maxsize;
	for (int i = 0;i < n;i++){
		int size = restaurant_Gojo->queue_id[i].size();

		for (int j = 0;j<size;j++){
			// NodeGojo *temp =restaurant_Gojo->queue_id[i].front();
			restaurant_Gojo->queue_id[i].pop();
			//delete temp;
		}
		clear_gojo(restaurant_Gojo->arr_Gojo[i]);
		restaurant_Gojo->arr_Gojo[i]=nullptr;
	}
	delete [] restaurant_Gojo->queue_id;
	delete [] restaurant_Gojo->arr_Gojo;

	delete [] restaurant_Sukuna->minheap;
	delete [] restaurant_Sukuna->move_to_front;
	delete [] restaurant_Sukuna->qu_st_id;
	delete restaurant_Gojo;
	delete restaurant_Sukuna;
}