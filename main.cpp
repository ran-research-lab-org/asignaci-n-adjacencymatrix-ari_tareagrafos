#include "Graph.hpp"

using namespace std;

int main() {

  int x = 2;

  //Caso 1: Existe 1 arista y el que se compara no tiene seguidores.
  Graph G(10);
  G.addEdge(3,1);

  cout<<"CASO 1: "
      <<"Cantidad de aristas: "<<G.numEdges()<<endl
      <<"Cantidad de in-degrees: "<<G.inDegree(x)<<endl
      <<"¿Es " << x << " el nodo con más in-degrees? ";
  if(G.isInfluencer(x) == 1) { cout<<"Sí"; }
  else { cout<<"No";}
  cout<<endl<<endl;


  //Caso 2: Existen 3 aristas, un nodo tiene dos seguidores el otro uno
  G.addEdge(0,9);
  G.addEdge(4, 2);
  G.addEdge(5,2);

  cout<<"CASO 2: "
      <<"Cantidad de aristas: "<<G.numEdges()<<endl
      <<"Cantidad de in-degrees: "<<G.inDegree(x)<<endl
      <<"¿Es " << x << " el nodo con más in-degrees? ";
  if(G.isInfluencer(x) == 1) { cout<<"Sí"; }
  else { cout<<"No";}
  cout<<endl<<endl;

  //Caso 3: Existen 3 artistas pero dos nodos tienen los mismos seguidores
  G.addEdge(2,9);

  cout<<"CASO 3: "
      <<"Cantidad de aristas: "<<G.numEdges()<<endl
      <<"Cantidad de in-degrees: "<<G.inDegree(x)<<endl
      <<"¿Es " << x << " el nodo con más in-degrees? ";
  if(G.isInfluencer(x) == 1) { cout<<"Sí"; }
  else { cout<<"No";}
  cout<<endl<<endl;

  G.print();
}
