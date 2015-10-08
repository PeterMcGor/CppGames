
#include <iostream>
#include <list>
#include <vector>
#include <fstream>
using namespace std;

bool estaDentro(const vector <int>& v,int n) {
    bool ret=false;
    for (int i=0;i<v.size();i++) {
    if (v[i]==n) {
    return true;
        }


}
return false;
}
/*
public boolean hasCycle(Graph g) {

   int totalEdges = 0;
   for(Vertex v : g.getVertices()) {
     totalEdges += v.getNeighbors().size();
   }
   return totalEdges/2 > g.getVertices().size - 1;

}*/

class Edge
{
protected:
    int _coste;
    int _vertice1,_vertice2;

public:
    Edge(int coste,int vertice1,int vertice2);
    int getVert1() const {return _vertice1;}
    int getVert2() const {return _vertice2;}
    int getCoste() const {return _coste;}

};
Edge::Edge (int coste,int vertice1,int vertice2) {
    _coste=coste;
    _vertice1 = vertice1;
    _vertice2 = vertice2;
}


class Tree
{
    list <Edge*> _aristas;
    vector <int> _vertices;
public:
    Tree();
    Tree(const Tree& t);
    void mostrar()const;
    void anyad(Edge* ar);
    bool contiene(Edge* ar) const;
    void mostrarVer () const;
    int getNumVertices() const {return _vertices.size();}
    vector <int> getVertices () const {return _vertices;}
    list <Edge*> getAristas() const {return _aristas;}
    bool hasCycle() const;


};

Tree::Tree() {
}

Tree::Tree(const Tree& t) {
    _aristas = t.getAristas();
    _vertices = t.getVertices();

}

void Tree::mostrar () const {
    for (auto it = _aristas.begin(); it != _aristas.end(); it++ ) {
        cout<<  (*it)->getVert1()  << "-->" << (*it)->getCoste() << "-->" << (*it) -> getVert2()    << endl;

    }
}

void Tree::mostrarVer () const {
    for (int i=0; i<_vertices.size(); i++ ) {
        cout << _vertices[i] << endl;

    }
}

void Tree::anyad(Edge* ar) {
    _aristas.push_back(ar);

    if (!estaDentro(_vertices,ar->getVert1())) {
    _vertices.push_back(ar->getVert1());
    }
    if (!estaDentro(_vertices,ar->getVert2())) {

    _vertices.push_back(ar->getVert2());
    }
}

bool hasCycle(const Tree& t,Edge* posAris) {
    Tree posTree = t;
    posTree.anyad(posAris);
   // cout << posTree.getAristas().size() << ' ' << posTree.getNumVertices() -1<< endl;
    return posTree.getAristas().size() > posTree.getNumVertices() -1;


}

bool Tree::contiene(Edge* ar) const {
   /*if (estaDentro(_vertices,ar->getVert1())  &&  estaDentro(_vertices,ar->getVert2())){
   return true;
   } else {
   return false;
   }*/


}



bool comparaAristas(const Edge* a,const Edge* b) {
    return (a->getCoste()) < (b->getCoste());
}

int main() {

    Tree t;
    list <Edge*> aristas;
    ifstream F;
    F.open("clustering1.txt");
    int vert1,vert2,coste;
    int nNodos,k;
    char c;
  /* aristas.push_back(new Edge(16,6,7));
    aristas.push_back(new Edge(13,1,5));
    aristas.push_back(new Edge(10,2,4));
    aristas.push_back(new Edge(12,5,6));
    aristas.push_back(new Edge(6,2,3));
    aristas.push_back(new Edge(8,5,6));
    aristas.push_back(new Edge(5,5,7));
     aristas.push_back(new Edge(4,4,6));
      aristas.push_back(new Edge(2,3,4));
       aristas.push_back(new Edge(3,1,2));
        aristas.push_back(new Edge(1,3,5));*/
   cout << "(Número de nodos , clusters): ";
   cin >> nNodos >> c >> k;
   while (F >> vert1 >> vert2 >> coste ) {
        aristas.push_back(new Edge(coste,vert1,vert2));

       // cout << vert1 << ' ' << vert2 << ' ' << coste << endl;
    }
    F.close();


    aristas.sort(comparaAristas);

   /* t.anyad(new Edge(1,1,2));
      t.anyad(new Edge(2,4,5));
        t.anyad(new Edge(5,2,3));
        t.anyad(new Edge(2,2,4));
        t.anyad(new Edge(5,2,6));*/



    /*for (auto it= aristas.begin(); it != aristas.end() ;it++) {
        cout << (*it) -> getVert1() <<endl;
    }*/
   int aristasIncluidas=0;
   for (auto it = aristas.begin(); it!= aristas.end(); it++) {
        if (!hasCycle(t,(*it))) { //TODO
            t.anyad(*it);
            if (nNodos - aristasIncluidas <= k) {
                cout << (*it)->getVert1()<<' ' <<(*it)->getCoste() << ' ' << (*it)->getVert2() << endl;
            }
            aristasIncluidas++;
        }
    }

   //t.mostrar();
   // t.mostrarVer();
   // while (500 - aristasIncluidas > clusters )




}


