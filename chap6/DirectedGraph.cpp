#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "AVLSet.h"
using namespace std;

// 无权图（支持有向，无向）
class DirectedGraph{
    private:
        int V;
        int E;
        AVLSet<int> **adj;
        bool directed;
    public:
        DirectedGraph(string filename,bool directed){
            this->directed = directed;

            ifstream inFile;
            inFile.open(filename);
            if(inFile){
                inFile >> V;
                adj = new AVLSet<int>*[V];
                for(int i=0;i<V;i++){
                    adj[i] = new AVLSet<int>();
                }
                
                inFile >> E;
                int a,b;
                for(int i = 0; i < E; i++){
                    inFile >> a >> b;
                    validateVertex(a);
                    validateVertex(b);
                    if(a==b){
                        throw "self loop is detected";
                    }
                    if(adj[a]->contains(b)){
                        throw "parallel edges are detected";
                    }
                    adj[a]->add(b);
                    if(!directed){
                        adj[b]->add(a);
                    }
                }
                inFile.close();
            }else{
                cout<<"no this file"<<endl;
            }
        }
        bool isDirected(){
            return directed;
        }
        bool hasEdge(int v,int w){
            validateVertex(v);
            validateVertex(w);
            return adj[v]->contains(w);
        }

        void removeEdge(int v,int w){
            validateVertex(v);
            validateVertex(w);
            if(adj[v]->contains(w)){
                E--;
                adj[v]->remove(w);
                if(!directed)
                    adj[w]->remove(v);
            }
        }

        vector<int> adj_V(int v){
            validateVertex(v);
            AVLSet<int>* avlSet = adj[v];
            return avlSet->allElement();
        }

        /*
        int degree(int v){
            return adj_V(v).size(); 
        }
        */
        int getV(){
            return V;
        }
        int getE(){
            return E;
        }

        void validateVertex(int v){
            if(v<0 || v>=V){
                throw "vertex invalid";
            }
        }
        void print(){
            cout<<"V="<<V<<",E="<<E<<endl;
            for(int i=0;i<V;i++){
                cout<<i<<": ";
                adj[i]->print();
                cout<<endl;
            }
        }
};
int main(){
    DirectedGraph *g = new DirectedGraph("dg.txt",true);
    g->print();
    
    cout<<"----------"<<endl;
    DirectedGraph *g2 = new DirectedGraph("dg.txt",false);
    g2->print();
    return 0;
}
