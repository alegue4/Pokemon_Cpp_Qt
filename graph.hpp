/**
  @file graph.hpp

  @brief File header della classe graph templata

  File di dichiarazioni/definizioni della classe graph templata
*/

#ifndef GRAPH_HPP
#define GRAP_HPP

#include <cassert>
#include <ostream>
#include <iterator> // std::forward_iterator_tag
#include <cstddef>  // std::ptrdiff_t

/**
  @brief Eccezione per nodo già presente nel graph
*/
class already_existing_node_exception{};

/**
  @brief Eccezione per nodo non presente nel graph
*/
class non_existing_node_exception{};

/**
  @brief Eccezione per arco già presente nel graph
*/
class already_existing_edge_exception{};

/**
  @brief Eccezione per arco non presente nel graph
*/
class non_existing_edge_exception{};

/**
 * @brief Classe graph templata
 * 
 * La classe implementa un generico grafo orientato di oggetti T.
 * La valutazione se due dati di tipo T sono uguali è realizzata
 * tramite un secondo funtore chiamato Equal.
*/
template <typename T, typename Equal>
class graph {

public: 
    typedef unsigned int size_type; ///< Tipo di dato per la quantità di nodi e archi del grafo

private:
    size_type n_nodes; ///< Quantità di nodi presenti nel grafo
    size_type n_edges; ///< Quantità di archi presenti nel grafo
    bool **matrix; ///< Matrice di adiacenza di booleani
    T *nodes; ///< Puntatore ai dati di tipo T
    Equal _eql; ///< Funtore per l'uguaglianza tra dati T

public:

    /**
     * @brief Costruttore di default della classe graph
     * 
     * Costruttore di default di un grafo orientato
     * 
     * @post n_nodes == 0
     * @post n_edges == 0
     * @post nodes == nullptr
     * @post matrix == nullptr
    */
    graph() : n_nodes(0), n_edges(0), nodes(nullptr), matrix(nullptr) {}

    /**
     * @brief Distruttore della classe graph
     * 
     * Libera la memoria allocata per gli elementi della classe graph.
     * 
     * @post n_nodes == 0
     * @post n_edges == 0
     * @post nodes == nullptr
     * @post matrix == nullptr
    */
    ~graph() {
        empty();
    }

    /**
     * @brief Costruttore di copia della classe graph
     * 
     * Costruttore di copia che crea un oggetto graph a partire da
     * un altro oggetto graph passato come parametro
     * 
     * @param other graph orientato da cui copiare gli elementi
     * 
     * @post n_nodes == other.n_nodes
     * @post n_edges == other.n_edges
     * @post nodes[i] == other.nodes[i] 
     * @post matrix[i][j] == other.matrix[i][j]
     * 
     * @throw eccezione di allocazione
    */
    graph(const graph &other) : n_nodes(0), n_edges(0), nodes(nullptr), matrix(nullptr) {
        try {

            for (size_type i = 0; i < other.getNodeCount(); i++) {
                this->addNode(other.nodes[i]);
            }

            for (size_type i = 0; i < n_nodes; i++) {
                for (size_type j = 0; j < n_nodes; j++) {
                    if (other.matrix[i][j] == true) {
                        this->addEdge(nodes[i], nodes[j]);
                    }
                }
            }
            
        } catch(...) {
            empty();
            throw;
        }
    }

    /**
     * @brief Operatore di assegnamento della classe graph
     * 
     * Esegue un assegnamento dell'oggetto graph, copiando gli
     * elementi dell'oggetto graph fornito
     * 
     * @param other graph orientato da cui copiare gli elementi
     * 
     * @post n_nodes == other.n_nodes
     * @post n_edges == other.n_edges
     * @post nodes[i] == other.nodes[i] 
     * @post matrix[i][j] == other.matrix[i] [j]
     * 
     * @return reference a this
     * 
     * @throw eccezione di allocazione
    */
    graph& operator=(const graph &other) {
        if (this != &other) {
            graph tmp(other);
            this->swap(tmp); 
        }
        return *this;
    }

    /**
     * @brief Metodo per svuotare il grafo e deallocare le risorse
     * 
     * Metodo per svuotare il grafo e deallocare le risorse
     * 
     * @post n_nodes == 0
     * @post n_edges == 0
     * @post nodes == nullptr
     * @post matrix == nullptr
    */
    void empty(void) {
        delete[] nodes;
        nodes = nullptr;

        for (size_type i = 0; i < n_nodes; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = nullptr;

        n_nodes = 0;
        n_edges = 0;
    }

    /**
     * @brief Funzione che scambia i valori di due oggetti graph
     * 
     * Funzione che scambia lo stato tra l'istanza corrente di graph
     * e quella passata come parametro
     * 
     * @param other graph da scambiare
    */
    void swap(graph &other) {
        std::swap(n_nodes, other.n_nodes);
        std::swap(n_edges, other.n_edges);
        std::swap(nodes, other.nodes);
        std::swap(matrix, other.matrix);
        std::swap(_eql, other._eql);
    }


    /**
     * @brief Metodo per restituzione della quantità di nodi del grafo
     * 
     * Restituisce la corrente quantità di nodi presenti nel grafo
     * orientato
     * 
     * @return Numero di nodi del grafo
    */
    size_type getNodeCount() const {
        return n_nodes;
    }

    /**
     * @brief Metodo per restituzione della quantità di archi del grafo
     * 
     * Restituisce la corrente quantità di archi presenti nel grafo
     * orientato
     * 
     * @return Numero di archi del grafo
    */
    size_type getEdgeCount() const {
        return n_edges;
    }

    /**
     * @brief Metodo che verifica la presenza di un nodo nel grafo
     * 
     * Verifica se il nodo specificato come parametro è presente
     * o meno nel grafo orientato
     * 
     * @param node nodo da cercare nel grafo
     * 
     * @return true se il nodo è presente nel grafo, false altrimenti
    */
    bool existsNode(const T &node) const {
        for(size_type i = 0; i < n_nodes; ++i) {
            if(_eql(nodes[i], node))
                return true;
        }
        return false;
    }

    /**
     * @brief Metodo che verifica la presenza di un arco nel grafo
     * 
     * Verifica se è presente un arco nel grafo che collega il primo
     * nodo al secondo nodo
     * 
     * @param n1 primo nodo dal quale parte l'arco
     * @param n2 secondo nodo nel quale arriva l'arco
     * 
     * @return true se l'arco è presente nel grafo, false altrimenti
    */
    bool existsEdge(const T &n1, const T &n2) const {
        if (existsNode(n1) && existsNode(n2)) {
            size_type i1 = indexNode(n1);
            size_type i2 = indexNode(n2);
            if(matrix[i1][i2] == true) {
                return true;
            }
        }
        
        return false;
    }

    /**
     * @brief Metodo per restituzione dell'indice di un nodo del grafo
     * 
     * Restituisce l'indice di un nodo presente nel grafo orientato
     * 
     * @return Indice del nodo nel grafo   
     * 
     * @throw non_existing_node_exception() in caso in cui non esiste il nodo nel grafo
    */
    size_type indexNode(const T &node) const {
        if (!existsNode(node)) {
            throw non_existing_node_exception();
        }
        size_type index;
        for (size_type i = 0; i < n_nodes; i++) {
            if (_eql(nodes[i], node))
                index = i;
        }  
        return index;
    }

    /**
     * @brief Metodo per aggiunta di un nodo al grafo
     * 
     * Metodo per aggiungere un nodo all'interno del grafo orientato
     * 
     * @param node nodo da aggiungere al grafo
     * 
     * @post n_nodes = n_nodes + 1
     * @post nodes[n_nodes - 1] == node
     * @post dimensione matrix aumentata a (n_nodes+1) x (n_nodes+1)
     * 
     * @throw already_existing_node_excpetion() se il nodo è già presente
     * @throw eccezione di allocazione
    */
    void addNode(const T &node) {
        if(existsNode(node))
            throw already_existing_node_exception();

        if(nodes == nullptr){
            nodes = new T[1];
            nodes[0] = node;
            n_nodes++;

            matrix = new bool*[1];
            matrix[0] = new bool[1];
            matrix[0][0] = false;

            return;
        }

        T *tmp = new T[n_nodes + 1];
        bool **matrix_tmp = new bool*[n_nodes+1];
        for (size_type i = 0; i < n_nodes+1; i++) {
            matrix_tmp[i] = new bool[n_nodes+1];
            for (size_type j = 0; j < n_nodes+1; j++) {
                matrix_tmp[i][j] = false;
            }
            
        }  
        try {
            for(size_type i = 0; i < n_nodes; i++){
                tmp[i] = nodes[i];
                for (size_type j = 0; j < n_nodes; j++) {
                    matrix_tmp[i][j] = matrix[i][j];
                }
            }
        } catch (...) {
            delete[] tmp;
            tmp = nullptr;
            for (size_type i = 0; i < n_nodes+1; i++) {
                delete[] matrix_tmp[i];
                matrix_tmp[i] = nullptr;
            }
            delete[] matrix_tmp;
            matrix_tmp = nullptr;
            throw;
        }
        tmp[n_nodes] = node;
        delete[] nodes;
        nodes = tmp;

        for (size_type i = 0; i < n_nodes; i++) {
            delete[] matrix[i];
        }
        delete[] matrix;
        matrix = matrix_tmp;

        n_nodes++;
    }

    /**
     * @brief Metodo per rimozione di un nodo dal grafo
     * 
     * Metodo per rimuovere un nodo presente all'interno di un
     * grafo orientato
     * 
     * @param node nodo da rimuovere dal grafo
     * 
     * @post n_nodes = n_nodes - 1
     * @post dimensione matrix diminuita a (n_nodes-1) x (n_nodes-1)
     * 
     * @throw non_existing_node_excpetion() se il nodo non è presente
     * @throw eccezione di allocazione
    */
    void removeNode(const T &node) {
        if(!existsNode(node))
            throw non_existing_node_exception();

        size_type iNode = indexNode(node);

        if (n_nodes == 1) {
            delete[] nodes;
            nodes = nullptr;

            for (size_type i = 0; i < n_nodes; ++i) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = nullptr;
            n_edges = 0;
        } else {

            for (size_type i = 0; i < n_nodes; ++i) {
                if (matrix[iNode][i] == true) {
                    matrix[iNode][i] = false;
                    n_edges--;
                }
            }

            for (size_type i = 0; i < n_nodes; ++i) {
                if (matrix[i][iNode] == true) {
                    matrix[i][iNode] = false;
                    n_edges--;
                }
            }

            T *tmp = new T[n_nodes - 1];
            bool **matrix_tmp = new bool*[n_nodes - 1];
            try {

                for (size_type i = 0, j = 0; i < n_nodes; ++i) {
                    if (i != iNode) {
                        tmp[j] = nodes[i];
                        j++;
                    }
                }

                for (size_type i = 0; i < n_nodes - 1; ++i) {
                    matrix_tmp[i] = new bool[n_nodes - 1];
                    for (size_type j = 0, k = 0; j < n_nodes; ++j) {
                        if (j != iNode) {
                            matrix_tmp[i][k] = matrix[i+1][j];
                            k++;
                        }
                    }
                }

            } catch(...){
                delete[] tmp;
                tmp = nullptr;
                for (size_type i = 0; i < n_nodes-1; i++) {
                    delete[] matrix_tmp[i];
                    matrix_tmp[i] = nullptr;
                }
                delete[] matrix_tmp;
                matrix_tmp = nullptr;
                throw;
            }
            
            delete[] nodes;
            nodes = tmp;

            for (size_type i = 0; i < n_nodes; i++) {
                delete[] matrix[i];
            }
            delete[] matrix;
            matrix = matrix_tmp;
        }

        n_nodes--;

    }

    /**
     * @brief Metodo per aggiunta di un arco nel grafo
     * 
     * Metodo per aggiungere un arco all'interno del grafo orientato
     * 
     * @param n1 primo nodo dal quale parte l'arco
     * @param n2 secondo nodo nel quale arriva l'arco
     * 
     * @post n_edges == n_edges + 1
     * @post matrix[i1][i2] == true
     * 
     * @throw already_existing_edge_excpetion() se l'arco è già presente
    */
    void addEdge(const T &n1, const T &n2) {
        if (existsEdge(n1, n2)) {
            throw already_existing_edge_exception(); 
        }
        size_type i1 = indexNode(n1);
        size_type i2 = indexNode(n2);
        matrix[i1][i2] = true;
        n_edges++;
    }

    /**
     * @brief Metodo per rimozione di un arco nel grafo
     * 
     * Metodo per rimuovere un arco all'interno del grafo orientato
     * 
     * @param n1 primo nodo dal quale parte l'arco
     * @param n2 secondo nodo nel quale arriva l'arco
     * 
     * @post n_edges == n_edges - 1
     * @post matrix[i1][i2] == false
     * 
     * @throw non_existing_edge_excpetion() se l'arco non è presente
    */
    void removeEdge(const T &n1, const T &n2) {
        if (!existsEdge(n1, n2)) {
            throw non_existing_edge_exception(); 
        }
        size_type i1 = indexNode(n1);
        size_type i2 = indexNode(n2);
        matrix[i1][i2] = false;
        n_edges--;
    }

    /**
     * Gli iteratori devono iterare sui dati inseriti nella classe
     * principale. Siccome nel graph inseriamo dei dati di tipo T,
     * l'iteratore deve iterare sui dati di tipo T.
    */
    class const_iterator {

	public:
		typedef std::forward_iterator_tag iterator_category;
		typedef T                         value_type;
		typedef ptrdiff_t                 difference_type;
		typedef const T*                  pointer;
		typedef const T&                  reference;

	
		const_iterator() : _ptr(nullptr) {}
		
		const_iterator(const const_iterator &other) : _ptr(other._ptr) {}

		const_iterator& operator=(const const_iterator &other) {
			if (this != &other) {
                _ptr = other._ptr;
            }
            return *this;
		}

		~const_iterator() {}

        // Ritorna il dato riferito dall'iteratore (dereferenziamento)
        reference operator*() const {
            return *_ptr;
        }

        // Ritorna il puntatore al dato riferito dall'iteratore
        pointer operator->() const {
            return _ptr;
        }
		
		// Operatore di iterazione post-incremento
		const_iterator operator++(int) {
			const_iterator tmp = *this;
            ++_ptr;
            return tmp;
		}

		// Operatore di iterazione pre-incremento
		const_iterator &operator++() {
			++_ptr;
            return *this;
		}

		// Uguaglianza
		bool operator==(const const_iterator &other) const {
			return _ptr == other._ptr;
		}
		
		// Diversita'
		bool operator!=(const const_iterator &other) const {
			return _ptr != other._ptr;
		}

	private:
		//Dati membro
        const T *_ptr;
		// La classe graph deve essere messa friend dell'iteratore per poter
		// usare il costruttore di inizializzazione.
		friend class graph;

		// Costruttore privato di inizializzazione usato dalla classe graph
		// tipicamente nei metodi begin e end
		const_iterator(const T *ptr) : _ptr(ptr) {}
		
		
	}; // classe const_iterator
	
	// Ritorna l'iteratore all'inizio della sequenza dati
	const_iterator begin() const {
		return const_iterator(nodes);
	}
	
	// Ritorna l'iteratore alla fine della sequenza dati
	const_iterator end() const {
		return const_iterator(nodes + n_nodes);
	}

}; // FINE DELLA CLASSE graph

#endif