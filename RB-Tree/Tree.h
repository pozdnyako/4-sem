#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

namespace rbt {
	const char RED = 0;
	const char BLACK = 1;

	//	------------------------------------------------------------------------------
	//	---------------------------       NODE     -----------------------------------
	//	------------------------------------------------------------------------------

	template<typename Key, typename Val>
	struct Node {
		Node<Key, Val>(const Key &k, const Val &v, bool c, Node<Key, Val>* l, Node<Key, Val>* r, Node<Key, Val> *p) :
			val(v),
			key(k),
			color(c),
			left(l),
			right(r),
			par(p) {}

		Node<Key, Val> *left, *right, *par;
		Key key;
		Val val;
		char color;
	};

	//	------------------------------------------------------------------------------
	//	---------------------------       TREE     -----------------------------------
	//	------------------------------------------------------------------------------

	template<typename Key, typename Val>
	class Tree {
	public:
		Tree<Key, Val>() :
			root((Node<Key, Val>*)&null),
			n_viz(0)
			{}

		void insert(const Key&, const Val&);
		const Val* find(const Key&) const;
		void remove(const Key&, const Val&);

		void printForGraphviz();
		void runDotty();

		friend std::ostream& operator<< (std::ostream& os, const Tree<Key, Val>& tree) {
			os << "Tree:\n{";
			if(tree.root == &(tree.null)) {
				os << "empty";
			}
			else {
				os << *(tree.root);
			}

			os << "}";
			return os;
		}

	private:
		void rotate_left(Node<Key, Val> *);
		void rotate_right(Node<Key, Val> *);

		void insert_case1(Node<Key, Val> *);
		void insert_case2(Node<Key, Val> *);
		void insert_case3(Node<Key, Val> *);
		void insert_case4(Node<Key, Val> *);
		void insert_case5(Node<Key, Val> *);

		Node<Key, Val> *root;

		Node<Key, Val> null{ Key(), Val(), BLACK, NULL, NULL, NULL };

		int n_viz;
	};


	//	------------------------------------------------------------------------------
	//	---------------------------    EXCEPTIONS  -----------------------------------
	//	------------------------------------------------------------------------------

	struct removeException : public std::exception {
		const char * what() const throw () {
			return "Removing nonexistent element from Tree";
		}
	};

	struct alreadyExistException : public std::exception {
		const char * what() const throw () {
			return "Inserting existent element to Tree";
		}
	};

	//	------------------------------------------------------------------------------
	//	--------------------------- TREE FUNCITONS -----------------------------------
	//	------------------------------------------------------------------------------

	template<typename Key, typename Val>
	void Tree<Key, Val>::insert(const Key& key, const Val &val) {
		try {
			Node<Key, Val> *par = root;

			if(par != &null) { // tree is not empty
				while(true) {
					if(key == par->key) {
						throw(alreadyExistException());
						return;
					}
					else if(key < par->key) {
						if(par->left == &null) {
							break;
						}

						par = par->left;
					}
					else {
						if(par->right == &null) {
							break;
						}

						par = par->right;
					}
				}
			}


			Node<Key, Val> *cur = new Node<Key, Val>(key, val, RED, &null, &null, par);


			if(root == &null)
				root = cur;
			else {
				if(key < par->key)
					par->left = cur;
				else
					par->right = cur;
			}
			
			insert_case1(cur);


		}
		catch(std::exception &ex) {
			//std::cerr << ex.what();
		}
	}

	template<typename Key, typename Val>
	const Val* Tree<Key, Val>::find(const Key& key) const {
		if(root == &null) { // tree is clr
			return NULL;
		}

		Node<Key, Val> *cur = root;

		while(cur->key != key) {
			if(cur->key < key) {
				if(cur->left == &null)
					return NULL;
				else
					cur = cur->left;
			}
			if(cur->key > key) {
				if(cur->right == &null)
					return NULL;
				else
					cur = cur->right;
			}
		}

		return &(cur->val);
	}


	template<typename Key, typename Val>
	void Tree<Key, Val>::remove(const Key& key, const Val& val) {
		try {

			if(root == &null) { // tree is clr
				throw(rbt::removeException());
			}

		}
		catch(std::exception &ex) {
			std::cerr << ex.what() << std::endl;
		}
	}

	//	------------------------------------------------------------------------------
	//	-------------------------- TREE INSERT CASES ---------------------------------
	//	------------------------------------------------------------------------------

	template<typename Key, typename Val>
	void Tree<Key, Val>::insert_case1(Node<Key, Val> *cur) {
		if(cur->par == &null) {
			cur->color = BLACK;
		}
		else {
			insert_case2(cur);
		}
	}

	template<typename Key, typename Val>
	void Tree<Key, Val>::insert_case2(Node<Key, Val> *cur) {
		if(cur->par->color == RED)
			insert_case3(cur);
	}

	template<typename Key, typename Val>
	void Tree<Key, Val>::insert_case3(Node<Key, Val> *cur) {
		Node<Key, Val> *uncle = NULL;

		if(cur->par->par->left == cur->par)
			uncle = cur->par->par->right;
		else
			uncle = cur->par->par->left;

		if(uncle->color == RED) {
			cur->par->color = BLACK;
			uncle->color = BLACK;

			cur->par->par->color = RED;

			insert_case1(cur->par->par);
		}
		else {
			insert_case4(cur);
		}
	}

	template<typename Key, typename Val>
	void Tree<Key, Val>::insert_case4(Node<Key, Val> *cur) {
		if(cur == cur->par->right && cur->par == cur->par->par->left) {
			rotate_left(cur->par);

			cur = cur->left;
		}
		else if(cur == cur->par->left && cur->par == cur->par->par->right) {
			rotate_right(cur->par);

			cur = cur->right;
		}
		insert_case5(cur);
	}

	template<typename Key, typename Val>
	void Tree<Key, Val>::insert_case5(Node<Key, Val> *cur) {
		cur->par->color = BLACK;
		cur->par->par->color = RED;

		if(cur == cur->par->left && cur->par == cur->par->par->left)
			rotate_right(cur->par->par);
		else
			rotate_left(cur->par->par);

	}

	//	------------------------------------------------------------------------------
	//	---------------------------- TREE ROTATION -----------------------------------
	//	------------------------------------------------------------------------------
	
	template<typename Key, typename Val>
	void Tree<Key, Val>::rotate_left(Node<Key, Val> *cur) {
		//          cur                            pivot
		//        /     \                         /     \
		//   cur->l    pivot         ->         cur    pivot->r
		//            /     \				  /     \
 		//      pivot->l  pivot->r        cur->l  pivot->l

		Node<Key, Val> *pivot = cur->right;
		
		pivot->par = cur->par;
		if(cur->par != &null) {
			if(cur->par->left == cur)
				cur->par->left = pivot;
			else
				cur->par->right = pivot;
		}
		else
			root = pivot;
		cur->right = pivot->left;
		if(pivot->left != &null)
			pivot->left->par = cur;

		cur->par = pivot;
		pivot->left = cur;
	}

	template<typename Key, typename Val>
	void Tree<Key, Val>::rotate_right(Node<Key, Val> *cur) {
		//         pivot                            cur
		//        /     \                         /     \
		//   pivot->l   cur       <-          pivot   cur->r
		//            /     \                /     \
 		//     pivot->r    cur->r       pivot->l  pivot->r

		Node<Key, Val> *pivot = cur->left;		
		
		pivot->par = cur->par;
		if(cur->par != &null) {
			if(cur->par->left == cur)
				cur->par->left = pivot;
			else
				cur->par->right = pivot;
		}
		else
			root = pivot;
		cur->left = pivot->right;
		if(pivot->right != &null)
			pivot->right->par = cur;

		cur->par = pivot;
		pivot->right= cur;

	}

	//	------------------------------------------------------------------------------
	//	--------------------------- OUTPUT FUNCITONS  --------------------------------
	//	------------------------------------------------------------------------------

	template<typename Key, typename Val>
	void printNodeForGraphviz(Node<Key, Val> * const node, std::ostream &os, Node<Key, Val> *null, int n_viz) {
		
		if(node->color == RED)
			os << "G" << n_viz << node->key << " [label=\"" << node->key << "\",shape=circle, fillcolor=red, style=filled, fontcolor=white];\n";
		if(node->color == BLACK)
			os << "G" << n_viz << node->key << " [label=\"" << node->key << "\",shape=circle, fillcolor=black, style=filled, fontcolor=white];\n";

		if(node->left != null) {
			os << "G" << n_viz << node->key << " -> "
			   << "G" << n_viz << node->left->key << ";\n";			
			printNodeForGraphviz(node->left, os, null, n_viz);
		}
		else {
			os << "G" << n_viz << "nulll" << node->key << " [label=\"null\", shape=square, fillcolor=black, style=filled, fontcolor=white];\n";
			os << "G" << n_viz << node->key << " -> "
			   << "G" << n_viz << "nulll" << node->key << ";\n";
		}

		if(node->right != null) {
			os << "G" << n_viz << node->key << " -> "
			   << "G" << n_viz << node->right->key << ";\n";
			printNodeForGraphviz(node->right, os, null, n_viz);
		}
		else {
			os << "G" << n_viz << "nullr" << node->key << " [label=\"null\", shape=square, fillcolor=black, style=filled, fontcolor=white];\n";
			os << "G" << n_viz << node->key << " -> "
			   << "G" << n_viz << "nullr" << node->key << ";\n";
		}
	}

	template<typename Key, typename Val>
	void Tree<Key, Val>::printForGraphviz() {
		std::string path = "graph.txt";

		std::ofstream *fout = NULL;
		if(n_viz == 0)
			fout = new std::ofstream(path);
		else
			fout = new std::ofstream(path, std::ofstream::app);

		printNodeForGraphviz(root, *fout, &null, n_viz);

		fout->close();

		delete fout;

		n_viz++;
	}

	template<typename Key, typename Val>
	void Tree<Key, Val>::runDotty() {
		std::string path1 = "graph.txt";
		std::string path2 = "dot.txt";

		std::ifstream file1(path1);
		std::ofstream file2(path2);

		file2 << "digraph G{\n";
		file2 << file1.rdbuf();
		file2 << "}\n";

		std::string command("D:\\libs\\graphviz\\release\\bin\\dotty.exe D:\\Users\\Admin\\Documents\\GitHub\\4-sem\\RB-Tree\\dot.txt");
		//std::string command("type D:\\Users\\Admin\\Documents\\GitHub\\4-sem\\RB-Tree\\dot.txt | clip");
		
		system(command.c_str());

	}

	template<typename Key, typename Val>
	std::ostream& operator<< (std::ostream& os, const Node<Key, Val> &node) {
		
		if(node.left == NULL && node.right == NULL) {
			os << "null";
		}
		else {
			os << "(";

			if(node.left != NULL)
				os << *(node.left);

			os << " (" << node.key << ", ";
			
			if(node.color == BLACK)
				os << "b";
			else if(node.color == RED)
				os << "r";

			os << ") ";

			if(node.right != NULL)
				os << *(node.right);
		
			os << ")";
		}

		return os;
	}
}