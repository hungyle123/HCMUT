// Question 1

/*
Given the declaration of the adjacent matrix implementation of a weighted directed graph as follows
class Graph {
   private:
         int nover;
         string* labels;
         int** wm; // weight matrix
   public:
        Graph(string vertices[],const int n):nover,labels(vertices) {
               wm = new int[n][n];
                for (int i = 0; i < n; i++) 
                     for (int j = 0; j < n; j++) 
                         if (i == j) wm[i][i] = 0; else wm[i][j] = INT_MAX;
        }
       void addEdge(struct edge edges[],int n) { 
              //Your code here
      }
};
Write the body of method void addEdge(struct edge edges[],int n) to put n edges into the graph where struct edge is declared as follows? T
struct edge {
     string src,dst;//labels of source and destination of the directed edge
     int weight;// weight of the edge
}
Your code starts at line 50       */



for (int i = 0; i < n; i++) {
        int index1 = -1, index2 = -1;
        for (int j = 0; j < nover; j++) {
            if (labels[j] == edges[i].src) {
                index1 = j;
            }
            if (labels[j] == edges[i].dst) {
                index2 = j;
            }
        }
        if (index1 != -1 && index2 != -1) {
            wm[index1][index2] = edges[i].weight;
        }
}


// Question 2

/*

Given the declaration of node in the adjacent list implementation  as follows,
class GEdge {
      string label; // label of the destination vertex of the edge
      int weight; // weight of the edge
      GEdge(string l,int w) { label=l;weight=w;}
};
and the declaration of the adjacent list implementation of a weighted undirected graph as follows
class Graph {
   private:
         int nover;
         Link<GEdge>* srclst; // list of source vertex of edges
   public:
        Graph(string vertices[], int n):nover {
                srclst = new Link<GEdge>[n];
                for (int i = 0; i < n; i++) srclst[i].element.label = vertices[i];
        }
       void addEdge(struct edge edges[],int n) { 
              //Your code here
      }
};
Write the body of method void addEdge(struct edge edges[],int n) to put n edges into the graph where struct edge is declared as follows? T
struct edge {
     string ver1,ver2;//labels of vertices of the edge
     int weight;// weight of the edge
}
Note that nodes in the linked list of the same vertex must be in the ascending alphabet order of the vertex label.
Your code starts at line 165  */


for (int i = 0; i < n; i++) {
        for (int j = 0; j < nover; j++) {
            if (edges[i].ver1==srclst[j].element.label) {
                Link<GEdge>* tmp = &srclst[j];
                while(!(tmp->next==nullptr||tmp->next->element.label>edges[i].ver2)) tmp = tmp->next;
                tmp->next = new Link<GEdge>(GEdge(edges[i].ver2,edges[i].weight),tmp->next);
            }
            if (edges[i].ver2==srclst[j].element.label) {
                Link<GEdge>* tmp = &srclst[j];
                while(!(tmp->next==nullptr||tmp->next->element.label>edges[i].ver1)) tmp = tmp->next;
                tmp->next = new Link<GEdge>(GEdge(edges[i].ver1,edges[i].weight),tmp->next);
            }
        }
    }


// Question 3

/*

Given the declaration of node in the adjacent list implementation  as follows,
class GEdge {
      int idx; // index of the destination vertex of the edge
      int weight; // weight of the edge
      GEdge(int l,int w): idx(l),weight(w){}
};
and the declaration of the adjacent list implementation of a weighted undirected graph as follows
class Graph {
   private:
         int nover;
         string * labels;
         Link<GEdge>* srclst; // list of source vertex of edges
   public:
        Graph(string vertices[], int n):nover,labels(vertices) {
                srclst = new Link<GEdge>[n];
        }
};
Write method void BFS(string startlabel,void (Graph::*action)(int)) to traverse all vertices of the graph in the breadth-first search manner. The traversal starts from the vertex startlabel and for each vertex, the method performs parameter action. During traversal, if a vertex has many adjacent vertices, they are pushed onto the queue in the ascending order of the vertex indexes. Inside method BFS, to call parameter action with parameter i, please write (this->*action)(i);. The Queue ADT is given in Figure 4.23 page 129 and the  provided concrete class is LQueue. 
Your code starts at line 160         */


void BFS(string startlabel,void (Graph::*action)(int)){
    
    bool* visited = new bool[nover];
    for (int i = 0; i < nover; i++) {
        visited[i] = true;
    }
    
    LQueue<int> qu;
    int index;
    for (int i = 0; i < nover; i++) {
        if (labels[i] == startlabel) {
            index = i;
            break;
        }
    }
        qu.enqueue(index);
        visited[index] = false;
    while (!qu.isEmpty()) {
        int current = qu.dequeue();
        (this->*action)(current);
        Link<GEdge>* currentList = &srclst[current];
        currentList = currentList->next;
        while (currentList != nullptr) {
            if (visited[currentList->element.idx]) {
                qu.enqueue(currentList->element.idx);
                visited[currentList->element.idx] = false;
               
            }
            currentList = currentList->next;
        }

    }
}

