#ifndef DIRECTEDWEIGHTEDGRAPH_H
#define DIRECTEDWEIGHTEDGRAPH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cassert>
#include "AVLMap.h"

using namespace std;
// 带权图（支持有向，无向）
class DirectedWeightedGraph{
    private:
        int V;
        int E;
        AVLMap<int,int> **adj;
        bool directed;
    public:
        DirectedWeightedGraph(string filename,bool directed){
            this->directed = directed;

            ifstream inFile;
            inFile.open(filename);
            if(inFile){
                inFile >> V;
                adj = new AVLMap<int,int>*[V];
                
                for(int i=0;i<V;i++){
                    adj[i] = new AVLMap<int,int>();
                }
                
                inFile >> E;
                int v,w,weight;
                for(int i = 0; i < E; i++){
                    inFile >> v >> w >> weight;
                    validateVertex(v);
                    validateVertex(w);
                    if(v==w){
                        throw "self loop is detected";
                    }
                    if(adj[v]->contains(w)){
                        throw "parallel edges are detected";
                    }

                    adj[v]->add(w,weight);
                    if(!directed)
                        adj[w]->add(v,weight);
                }
                inFile.close();
            }else{
                cout<<"no this file"<<endl;
            }
        }
        DirectedWeightedGraph(int V, bool directed){
            this->V = V;
            this->directed = directed;
            this->E = 0;

            adj = new AVLMap<int,int>*[V];    
            for(int i=0;i<V;i++){
                adj[i] = new AVLMap<int,int>();
            }
        }
        void addEdge(int v, int w, int weight){
            validateVertex(v);
            validateVertex(w);
            
            assert(v!=w);
            assert(!adj[v]->contains(w));
            adj[v]->add(w,weight);
            if(!directed){
                adj[w]->add(v,weight);
            }
        }
        void setWeight(int v, int w, int newWeight){
            validateVertex(v);
            validateVertex(w);
           assert(hasEdge(v,w));

            adj[v]->set(w,newWeight);
            if(!directed){
                adj[w]->set(v,newWeight);
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

        vector<int> adj_V(int v){
            validateVertex(v);
            AVLMap<int,int>* avlMap = adj[v];
            return avlMap->keySet();
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
        int getWeight(int v, int w){
            if(hasEdge(v,w)){
                return adj[v]->get(w);
            }
            throw "no edge";
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
#endif
