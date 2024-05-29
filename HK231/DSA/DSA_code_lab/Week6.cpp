// Question 1

/*

Implement Breadth-first search
Adjacency *BFS(int v);
where Adjacency is a structure to store list of number. 
#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
And Graph is a structure to store a graph (see in your answer box)		*/


class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
	Adjacency *BFS(int v)
    {
        bool * visited = new bool[V];
        for (int i = 0;i<V;i++) visited[i] = true;
        int count = 1;
        
        Adjacency * newAd = new Adjacency(V);
        newAd->push(v);
        visited[v]= false;
        int start = v;
        int i = 0;
        while(true){
            if (i == newAd->getSize()) break;
            start = newAd->getElement(i);

            for (int j = 0; j < adj[start].getSize(); j++){
                int temp = adj[start].getElement(j);
                if (visited[temp]){
                    visited[temp]=false;
                    newAd->push(temp);
                    count++;
                }
            }
            i++;
            
        }
        delete [] visited;
        return newAd;

	}
};


// Question 2

/*

Given a graph represented by an adjacency-list edges.
Request: Implement function:
int connectedComponents(vector<vector<int>>& edges);
Where edges is the adjacency-list representing the graph (this list has between 0 and 1000 lists). This function returns the number of connected components of the graph.
Example:
Given a adjacency-list: [[1], [0, 2], [1], [4], [3], []]
There are 3 connected components: [0, 1, 2], [3, 4], [5]
Note:
In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.		*/


void dfs(bool * visited,vector<vector<int>>& edges,int index){
    visited[index] = false;
    
    for (int neighbor : edges[index]) {
            if (visited[neighbor]) {
                dfs(visited,edges,neighbor);
            }
        }
}
int connectedComponents(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    bool * visited = new bool[n];
    
    for (int i = 0;i<n;i++){
        visited[i] = true;
    }
    int count = 0;
     for (int i = 0;i<n;i++){
        if (visited[i]){
            dfs(visited,edges,i);
            count++;
        }
    }
    return count;
}


// Question 3

/*

Implement Depth-first search
Adjacency *DFS(int v);
where Adjacency is a structure to store list of number. 
#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
And Graph is a structure to store a graph (see in your answer box)		*/

class Graph
{
private:
	int V;
	Adjacency *adj;

public:
	Graph(int V)
	{
		this->V = V;
		adj = new Adjacency[V];
	}
	
	void addEdge(int v, int w)
	{
		adj[v].push(w);
		adj[w].push(v);
	}
	
    void printGraph()
	{
		for (int v = 0; v < V; ++v)
		{
			cout << "\nAdjacency list of vertex " << v << "\nhead ";
			adj[v].print();
		}
	}
	
    Adjacency *DFS(int v)
    {
        // v is a vertex we start DFS
		int numVer = this->adj->getSize();
		Adjacency* traversedList = new Adjacency;
		bool* visited = new bool[numVer];
		for (int i = 0; i < numVer; ++i) {
			visited[i] = false;
		}
		this->DFSRec(v, visited, traversedList);
		delete[] visited;
		return traversedList;
	}

	void DFSRec(int v, bool* visited, Adjacency* &traversedList) {
		visited[v] = true;
		traversedList->push(v);

		int curSize = this->adj[v].getSize();
		for (int i = 0; i < curSize; ++i) {
			int adjVer = this->adj[v].getElement(i);
			if (!visited[adjVer])
				this->DFSRec(adjVer, visited, traversedList);
		}
	}
};


// Question 4

/*

Given a graph and a source vertex in the graph, find shortest paths from source to destination vertice in the given graph using Dijsktra's algorithm.
Following libraries are included: iostream, vector, algorithm, climits, queue	*/


int Dijkstra(int** graph, int src, int dst) {
	int n = 6;
    vector<int> dist(n, INT_MAX);
    dist[src] = 0;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, src});

    while (!pq.empty()) {
        int u = pq.top().second;
        pq.pop();

        for (int v = 0; v < n; v++) {
            if (graph[u][v] && dist[u] != INT_MAX && dist[u] + graph[u][v] < dist[v]) {
                dist[v] = dist[u] + graph[u][v];
                pq.push({dist[v], v});
            }
        }
    }

    return dist[dst];
	
}


// Question 5
/*

Implement function 
int foldShift(long long key, int addressSize);
int rotation(long long key, int addressSize);
to hashing key using Fold shift or Rotation algorithm. 
Review Fold shift:
The folding method for constructing hash functions begins by dividing the item into equal-size pieces (the last piece may not be of equal size). These pieces are then added together to give the resulting hash value.	*/

int foldShift(long long key, int addressSize) { 
	long long tmp = key; 
	int A[100] = {}; 
	int n = 0;
	while (tmp != 0) { 
        A[n] = tmp % 10; 
        tmp = tmp / 10; 
        n++; 
	} 
	long long sum = 0; 
	while (n>0) { 
		long long s = 0; 
		for (int i = 0; i<addressSize; i++) { 
			if (n - i - 1 >= 0) { 
				s = s * 10 + A[n - i - 1]; 
			} 
		} 
		n -= addressSize; 
		sum += s; 
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t; 
}


int rotation(long long key, int addressSize){ 
	long long tmp = key; 
	int A[100] = {};
	int n = 0; 
	while (tmp != 0){
		A[n] = tmp % 10; 
		tmp = tmp / 10; n++; 
	} 
	tmp = A[0]; 
	for (int i = 0; i<n - 1; i++) A[i] = A[i + 1]; 
	A[n - 1] = tmp; 
	long long sum = 0; 
	while (n>0){ 
		long long s = 0; 
    	for (int i = 0; i<addressSize; i++) { 
    		if (n - i - 1 >= 0) {
    		    s = s * 10 + A[n - i - 1]; 
    		} 
    	} 
    	n -= addressSize; sum += s;
	} 
	long long t = 1; 
	for (int i = 0; i<addressSize; i++) t *= 10; 
	return sum % t;
}


// Question 6

/*

The relationship between a group of people is represented by an adjacency-list friends. If friends[u] contains v, u and v are friends.Friendship is a two-way relationship. Two people are in a friend group as long as there is some path of mutual friends connecting them.
Request: Implement function:
int numberOfFriendGroups(vector<vector<int>>& friends);
Where friends is the adjacency-list representing the friendship (this list has between 0 and 1000 lists). This function returns the number of friend groups.
Example:
Given a adjacency-list: [[1], [0, 2], [1], [4], [3], []]
There are 3 friend groups: [0, 1, 2], [3, 4], [5]
Note:
In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm have been included and namespace std is used. You can write helper functions and class. Importing other libraries is allowed, but not encouraged.
*/

void dfs(bool * visited,vector<vector<int>>& edges,int index){
    visited[index] = false;
    
    for (int neighbor : edges[index]) {
            if (visited[neighbor]) {
                dfs(visited,edges,neighbor);
            }
        }
}
int numberOfFriendGroups(vector<vector<int>>& edges) {
    int n = (int)edges.size();
    bool * visited = new bool[n];
    
    for (int i = 0;i<n;i++){
        visited[i] = true;
    }
    int count = 0;
     for (int i = 0;i<n;i++){
        if (visited[i]){
            dfs(visited,edges,i);
            count++;
        }
    }
    return count;
}


// Question 7

/*

Implement function to detect a cyclic in Graph
bool isCyclic();
Graph structure is defined in the initial code.  */

#include <iostream>
#include <vector>
#include <list>
using namespace std;

class DirectedGraph 
{ 
	int V;
	vector<list<int>> adj;
public:
	DirectedGraph(int V)
	{
		this->V = V; 
		adj = vector<list<int>>(V, list<int>());
	}
	void addEdge(int v, int w)
	{
		adj[v].push_back(w);
	}
	bool DFSSearch(int u, int* color){
        color[u]++;
        int size = adj[u].size();
        
        for(int i = 0; i < size; i++){
            auto it = adj[u].begin();
            advance(it,i);
            int v = *it;
            if(color[v] == -1){
            if(DFSSearch(v,color)) ;
            else return false;
        }
        if(color[v] == 0){
            return false;
        }
        }
        color[u]++;
        return true;
    }
    bool isCyclic(){
        int* color = new int[V];
        //int count = 0;
        for(int i = 0; i < V; i++) color[i] = -1;
        for(int i = 0; i < V; i++){
            if(color[i] == -1){
            if(DFSSearch(i,color));
            else{
                return true;
            }
            }
        }
        return false;
    }
}; 


// Question 8

/*

Implement three following hashing function:
long int midSquare(long int seed);
long int moduloDivision(long int seed, long int mod);
long int digitExtraction(long int seed, int* extractDigits, int size);
Note that:
In midSquare function: we eliminate 2 last digits and get the 4 next digits.
In digitExtraction: extractDigits is a sorted array from smallest to largest index of digit in seed (index starts from 0). The array has size size.  */


long int midSquare(long int seed)
{
    int square=seed*seed;
    return (square/100)%10000;
}
long int moduloDivision(long int seed, long int mod)
{
    return seed%mod;
}
long int digitExtraction(long int seed,int* extractDigits,int size)
{
    int add=0;
	int e=0;
    int t_seed=seed;
    int s_size=0;
    while(t_seed>0){
        t_seed/=10;
        s_size++;
    }
    for(int i=0; i<size; i++){
		int modi= pow(10, s_size - extractDigits[i]);
        e= ((seed%modi)-(seed%(modi/10)))/(modi/10);
		e*=pow(10, size-i-1);
		add+=e;
    }
	return add;
}


// Question 9

/*

There are n people, each person has a number between 1 and 100000 (1 ≤ n ≤ 100000). Given a number target. Two people can be matched as a perfect pair if the sum of numbers they have is equal to target. A person can be matched no more than 1 time.
Request: Implement function:
int pairMatching(vector<int>& nums, int target);
Where nums is the list of numbers of n people, target is the given number. This function returns the number of perfect pairs can be found from the list.
Example:
The list of numbers is {1, 3, 5, 3, 7} and target = 6. Therefore, the number of perfect pairs can be found from the list is 2 (pair (1, 5) and pair (3, 3)).
Note:
In this exercise, the libraries iostream, string, cstring, climits, utility, vector, list, stack, queue, map, unordered_map, set, unordered_set, functional, algorithm has been included and namespace std are used. You can write helper functions and classes. Importing other libraries is allowed, but not encouraged, and may result in unexpected errors.		*/

int pairMatching(vector<int>& nums, int target) {
    vector<int> tmp = nums;
    sort(tmp.begin(),tmp.end());
    int size = int(tmp.size());
    int lo = 0;
    int hi = size-1;
    int count = 0;
    while(lo < hi){
        int sum = tmp[lo]+tmp[hi];
        if(sum == target){
            lo++;
            hi--;
            count++;
        }
        if(sum > target){
            hi--;
        }
        if(sum < target){
            lo++;
        }
    }
    return count;
}


// Question 10

/*

Implement topologicalSort function on a graph. (Ref here)
void topologicalSort();
where Adjacency is a structure to store list of number. Note that, the vertex index starts from 0. To match the given answer, please always traverse from 0 when performing the sorting.
#include <iostream>
#include <list>
using namespace std;

class Adjacency
{
private:
	list<int> adjList;
	int size;
public:
	Adjacency() {}
	Adjacency(int V) {}
	void push(int data)
	{
		adjList.push_back(data);
		size++;
	}
	void print()
	{
		for (auto const &i : adjList)
			cout << " -> " << i;
	}
	void printArray()
	{
		for (auto const &i : adjList)
			cout << i << " ";
	}
	int getSize() { return adjList.size(); }
	int getElement(int idx) 
	{
		auto it = adjList.begin();
		advance(it, idx);
		return *it;
	}
};
And Graph is a structure to store a graph (see in your answer box). You could write one or more helping functions.	*/


class Graph {

    int V;
    Adjacency* adj;

public:
    Graph(int V){
        this->V = V;
        adj = new Adjacency[V];
    }
    void addEdge(int v, int w){
        adj[v].push(w);
    }
    
  void topologicalSortUtil(int v, bool visited[], list<int>& Stack) { 
        visited[v] = true; 
        for (int i=0; i != adj[v].getSize(); ++i) 
        if (!visited[adj[v].getElement(i)]) 
            topologicalSortUtil(adj[v].getElement(i), visited, Stack); 
        Stack.push_back(v); 
    } 
    void topologicalSort() { 
        list<int> Stack; 
        bool* visited = new bool[V]; 
        for (int i = 0; i < V; i++) 
            visited[i] = false; 
        for (int i = 0; i < V; i++) 
            if (visited[i] == false) 
                topologicalSortUtil(i, visited, Stack); 
        while (Stack.empty() == false) { 
            cout << Stack.back() << " "; 
            Stack.pop_back(); 
        } 
    }  
};
