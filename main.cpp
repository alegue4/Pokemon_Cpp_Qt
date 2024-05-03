/**
  @file main.cpp

  @brief File di test per la classe graph templata
*/

#include <iostream>
#include <cassert>
#include "graph.hpp"

/**
  @brief Struct person che implementa una persona.

  Struct person che implementa una persona con nome e età.
*/
struct person {
  std::string name; ///< stringa che rappresenta il nome
  int age; ///< intero che rappresenta l'età

  person() : name(" "), age(0) {}

  person(std::string n, int a) : name(n), age(a) {}
};

/**
  @brief Funtore per il confronto di due persone.

  Funtore per l'uguaglianza di due persone. Due persone sono uguali
  se hanno lo stesso nome e la stessa età.

  Ritorna true se p1.name == p2.name e p1.age==p2.age
*/
struct equal_person {
  bool operator()(const person &p1, const person &p2) const {
    return (p1.name==p2.name) && (p1.age==p2.age);
  } 
};

/**
  @brief Funtore di uguaglianza tra tipi interi

  Valuta l'uglianza tra due interi. 
*/
struct equal_int {
  bool operator()(int a, int b) const {
    return a==b;
  }
};

/**
  @brief Funtore per l'uguaglianza tra stringhe.

  Funtore per l'ugagianza tra stringhe. La valutazione e' fatta
  lessicografica.
*/
struct equal_string {
  bool operator()(std::string a, std::string b) const {
    return a==b;
  }
};


/**
  @brief Test metodi fondamentali della classe templata graph

  Test metodi fondamentali della classe templata graph
*/
void test_metodi_fondamentali() {
    std::cout << "============ TEST_METODI_FONDAMENTALI ============="<< std::endl;

    typedef graph<int, equal_int> graphI; // ctor default

    graphI g1;

    g1.addNode(5);
    g1.addNode(8);
    g1.addNode(10);
    g1.addEdge(8, 10);

    std::cout << "Numero di nodi g1: " << g1.getNodeCount() << std::endl;
    std::cout << "Numero di archi g1: " << g1.getEdgeCount() << std::endl;
    
    graph<int, equal_int> new_graph(g1);  // copy constructor
    std::cout << "Numero di nodi new_graph: " << new_graph.getNodeCount() << std::endl;
    std::cout << "Numero di archi new_graph: " << new_graph.getEdgeCount() << std::endl;
    assert(new_graph.existsNode(8));
    assert(new_graph.existsEdge(8, 10));
    
    graph<int, equal_int> new_graph2;
    new_graph2 = g1; // operator=

    assert(new_graph2.existsNode(8));
    assert(new_graph2.existsEdge(8, 10));
    std::cout << "Numero di nodi new_graph2: " << new_graph2.getNodeCount() << std::endl;
    std::cout << "Numero di archi new_graph2: " << new_graph2.getEdgeCount() << std::endl;
    
}

/**
  @brief Test del grafo istanziato su interi

  Test del grafo istanziato su interi
*/
void test_graph_int(void) {
  std::cout << "============ TEST_GRAPH_INT ============="<< std::endl;
  typedef graph<int, equal_int> graphI;

  graphI g1;

  // Aggiunta di nodi
  g1.addNode(5);
  g1.addNode(8);
  g1.addNode(10);
  try {
      g1.addNode(8);
  }
  catch(...) {
      std::cout << "Eccezione already_existing_node_exception lanciata" << std::endl;
  }

  std::cout << "Numero di nodi: " << g1.getNodeCount() << std::endl;

  // Aggiunta di archi
  g1.addEdge(5, 8);
  g1.addEdge(8, 5);
  g1.addEdge(10, 8);
  g1.addEdge(10, 10);
  try {
      g1.addEdge(8, 5);
  }
  catch(...) {
      std::cout << "Eccezione already_existing_edge_exception lanciata" << std::endl;
  }

  std::cout << "Numero di archi: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste il nodo 5? " << (g1.existsNode(5) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste il nodo 7? " << (g1.existsNode(7) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco (8, 10)? " << (g1.existsEdge(8, 10) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco (10, 8)? " << (g1.existsEdge(10, 8) ? "Sì" : "No") << std::endl;
  std::cout << std::endl;

   // Rimozione di un nodo
  g1.removeNode(8); // Rimossi anche tutti gli archi di 8, entranti e uscenti
  try {
      g1.removeNode(8);
  }
  catch(...) {
      std::cout << "Eccezione non_existing_node_exception lanciata" << std::endl;
  }

  std::cout << "Numero di nodi dopo la rimozione: " << g1.getNodeCount() << std::endl;
  std::cout << "Numero di archi dopo la rimozione: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste il nodo 8 dopo la rimozione? " << (g1.existsNode(8) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco (8, 10) dopo la rimozione? " << (g1.existsEdge(8, 10) ? "Sì" : "No") << std::endl;

  g1.removeEdge(10, 10);
  try {
      g1.removeEdge(10, 10);
  }
  catch(...) {
      std::cout << "Eccezione non_existing_edge_exception lanciata" << std::endl;
  }

  std::cout << "Numero di archi dopo la rimozione: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste l'arco (10, 10) dopo la rimozione? " << (g1.existsEdge(10, 10) ? "Sì" : "No") << std::endl;
}

/**
  @brief Test del grafo istanziato su stringhe

  Test del grafo istanziato su stringhe
*/
void test_graph_string(void) {
  std::cout << "============ TEST_GRAPH_STRING ============="<< std::endl;
  typedef graph<std::string, equal_string> graphS;

  graphS g1;

  // Aggiunta di nodi
  g1.addNode("Ciao");
  g1.addNode("Come va?");
  g1.addNode("Tutto bene");
  try {
      g1.addNode("Come va?");
  }
  catch(...) {
      std::cout << "Eccezione already_existing_node_exception lanciata" << std::endl;
  }

  std::cout << "Numero di nodi: " << g1.getNodeCount() << std::endl;

  // Aggiunta di archi
  g1.addEdge("Ciao", "Come va?");
  g1.addEdge("Come va?", "Ciao");
  g1.addEdge("Tutto bene", "Come va?");
  g1.addEdge("Tutto bene", "Tutto bene");
  try {
      g1.addEdge("Come va?", "Ciao");
  }
  catch(...) {
      std::cout << "Eccezione already_existing_edge_exception lanciata" << std::endl;
  }

  std::cout << "Numero di archi: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste il nodo 'Ciao' ? " << (g1.existsNode("Ciao") ? "Sì" : "No") << std::endl;
  std::cout << "Esiste il nodo 'Sono occupato' ? " << (g1.existsNode("Sono occupato") ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco ('Tutto bene', 'Come va?') ? " << (g1.existsEdge("Tutto bene", "Come va?") ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco ('Come va?', 'Tutto bene')? " << (g1.existsEdge("Come va?", "Tutto bene") ? "Sì" : "No") << std::endl;
  std::cout << std::endl;

   // Rimozione di un nodo
  g1.removeNode("Come va?");
  try {
      g1.removeNode("Come va?");
  }
  catch(...) {
      std::cout << "Eccezione non_existing_node_exception lanciata" << std::endl;
  }

  std::cout << "Numero di nodi dopo la rimozione: " << g1.getNodeCount() << std::endl;
  std::cout << "Numero di archi dopo la rimozione: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste il nodo 'Come va?' dopo la rimozione? " << (g1.existsNode("Come va?") ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco ('Come va?', 'Ciao') dopo la rimozione? " << (g1.existsEdge("Come va?", "Ciao") ? "Sì" : "No") << std::endl;

  g1.removeEdge("Tutto bene", "Tutto bene");
  try {
      g1.removeEdge("Tutto bene", "Tutto bene");
  }
  catch(...) {
      std::cout << "Eccezione non_existing_edge_exception lanciata" << std::endl;
  }

  std::cout << "Numero di archi dopo la rimozione: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste l'arco ('Tutto bene', 'Tutto bene') dopo la rimozione? " << (g1.existsEdge("Tutto bene", "Tutto bene") ? "Sì" : "No") << std::endl;
}

/**
  @brief Test del grafo istanziato su oggetti di tipo person

  Test del grafo istanziato su oggetti di tipo person
*/
void test_graph_person(void) {
  std::cout << "============ TEST_GRAPH_PERSON ============="<< std::endl;
  typedef graph<person, equal_person> graphP;

  graphP g1;

  // Aggiunta di nodi
  g1.addNode(person("Alessandro", 22));
  g1.addNode(person("Alessandro", 16));
  g1.addNode(person("Nicola", 29));
  try {
      g1.addNode(person("Alessandro", 16));
  }
  catch(...) {
      std::cout << "Eccezione already_existing_node_exception lanciata" << std::endl;
  }

  std::cout << "Numero di nodi: " << g1.getNodeCount() << std::endl;

  // Aggiunta di archi
  g1.addEdge(person("Alessandro", 22), person("Alessandro", 16));
  g1.addEdge(person("Alessandro", 16), person("Alessandro", 22));
  g1.addEdge(person("Alessandro", 16), person("Nicola", 29));
  g1.addEdge(person("Nicola", 29), person("Nicola", 29));
  try {
      g1.addEdge(person("Alessandro", 16), person("Alessandro", 22));
  }
  catch(...) {
      std::cout << "Eccezione already_existing_edge_exception lanciata" << std::endl;
  }

  std::cout << "Numero di archi: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste il nodo 'Alessandro, 22' ? " << (g1.existsNode(person("Alessandro", 22)) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste il nodo 'Giuseppe, 12' ? " << (g1.existsNode(person("Giuseppe", 12)) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco ('Alessandro, 22', 'Alessandro, 16') ? " << (g1.existsEdge(person("Alessandro", 22), person("Alessandro", 16)) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco ('Alessandro, 22', 'Nicola, 29')? " << (g1.existsEdge(person("Alessandro", 22), person("Nicola", 29)) ? "Sì" : "No") << std::endl;
  std::cout << std::endl;

   // Rimozione di un nodo
  g1.removeNode(person("Alessandro", 16));
  try {
      g1.removeNode(person("Alessandro", 16));
  }
  catch(...) {
      std::cout << "Eccezione non_existing_node_exception lanciata" << std::endl;
  }

  std::cout << "Numero di nodi dopo la rimozione: " << g1.getNodeCount() << std::endl;
  std::cout << "Numero di archi dopo la rimozione: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste il nodo 'Alessandro, 16' dopo la rimozione? " << (g1.existsNode(person("Alessandro", 16)) ? "Sì" : "No") << std::endl;
  std::cout << "Esiste l'arco ('Alessandro, 16', 'Alessandro, 22') dopo la rimozione? " << (g1.existsEdge(person("Alessandro", 16), person("Alessandro", 22)) ? "Sì" : "No") << std::endl;

  g1.removeEdge(person("Nicola", 29), person("Nicola", 29));
  try {
      g1.removeEdge(person("Nicola", 29), person("Nicola", 29));
  }
  catch(...) {
      std::cout << "Eccezione non_existing_edge_exception lanciata" << std::endl;
  }

  std::cout << "Numero di archi dopo la rimozione: " << g1.getEdgeCount() << std::endl;

  std::cout << "Esiste l'arco ('Nicola, 29', 'Nicola, 29') dopo la rimozione? " << (g1.existsEdge(person("Nicola", 29), person("Nicola", 29)) ? "Sì" : "No") << std::endl;
}

/**
 * @brief Test degli iteratori sul grafo
 * 
 * Questa funzione testa le funzionalità degli iteratori all'interno
 * di un grafo di interi
*/
void test_iteratori() {
  std::cout << "============ TEST_ITERATORI_GRAPH ============="<< std::endl;
  typedef graph<int, equal_int> graphI;

  graphI g1;

  g1.addNode(5);
  g1.addNode(8);
  g1.addNode(10);
  g1.addNode(7);

  graph<int, equal_int>::const_iterator i, ie;
  std::cout << "Stampa dei valori tramite iteratori:" << std::endl;
  for (i = g1.begin(), ie = g1.end(); i != ie; ++i) {
      std::cout << *i << " ";
  }
  std::cout << std::endl;

  graph<int, equal_int>::const_iterator i1;
  i1 = g1.begin();
  i1++;
  std::cout << "Dopo primo incremento: " << *i1 << std::endl;
  i1++;
  std::cout << "Dopo secondo incremento: " << *i1 << std::endl;
  

  graph<int, equal_int>::const_iterator i2;
  i2 = g1.begin();
  i1 = g1.begin();
  assert(i1 == i2);
  i2++;
  assert(i1 != i2);
}

int main(void) {
  //test_metodi_fondamentali();
  //test_graph_int();
  //test_graph_string();
  //test_graph_person();
  test_iteratori();
  return 0;
}