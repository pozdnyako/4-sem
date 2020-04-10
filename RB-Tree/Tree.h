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

	template<typename T>
	struct Node {
		Node<T>(const T &v, bool c, Node<T>* l, Node<T>* r, Node<T> *p) :
			val(v),
			color(c),
			left(l),
			right(r),
			par(p) {}

		Node<T> *left, *right, *par;
		T val;
		char color;
	};

	//	------------------------------------------------------------------------------
	//	---------------------------       TREE     -----------------------------------
	//	------------------------------------------------------------------------------

	template<typename T>
	class Tree {
	public:
		Tree<T>() :
			root((Node<T>*)&null),
			n_viz(0)
			{}

		void insert(const T&);
		bool find(const T&) const;
		void remove(const T&);

		void printForGraphviz();
		void runDotty();

		friend std::ostream& operator<< (std::ostream& os, const Tree<T>& tree) {
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
		void rotate_left(Node<T> *);
		void rotate_right(Node<T> *);

		void insert_case1(Node<T> *);
		void insert_case2(Node<T> *);
		void insert_case3(Node<T> *);
		void insert_case4(Node<T> *);
		void insert_case5(Node<T> *);

		Node<T> *root;

		Node<T> null{ T(), BLACK, NULL, NULL, NULL };

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

	template<typename T>
	void Tree<T>::insert(const T& val) {
		try {
			Node<T> *par = root;

			if(par != &null) { // tree is not empty
				while(true) {
					if(val == par->val) {
						throw(alreadyExistException());
						return;
					}
					else if(val < par->val) {
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


			Node<T> *cur = new Node<T>(val, RED, &null, &null, par);


			if(root == &null)
				root = cur;
			else {
				if(val < par->val)
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

	template<typename T>
	bool Tree<T>::find(const T& val) const {
		if(root == &null) { // tree is clr
			return false;
		}

		Node<T> *cur = root;

		while(cur->val != val) {
			if(cur->val < val) {
				if(cur->left == &null)
					return false;
				else
					cur = cur->left;
			}
			if(cur->val > val) {
				if(cur->right == &null)
					return false;
				else
					cur = cur->right;
			}
		}

		return true;
	}


	template<typename T>
	void Tree<T>::remove(const T& val) {
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

	template<typename T>
	void Tree<T>::insert_case1(Node<T> *cur) {
		if(cur->par == &null) {
			cur->color = BLACK;
		}
		else {
			insert_case2(cur);
		}
	}

	template<typename T>
	void Tree<T>::insert_case2(Node<T> *cur) {
		if(cur->par->color == RED)
			insert_case3(cur);
	}

	template<typename T>
	void Tree<T>::insert_case3(Node<T> *cur) {
		Node<T> *uncle = NULL;

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

	template<typename T>
	void Tree<T>::insert_case4(Node<T> *cur) {
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

	template<typename T>
	void Tree<T>::insert_case5(Node<T> *cur) {
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
	
	template<typename T>
	void Tree<T>::rotate_left(Node<T> *cur) {
		//			cur							   pivot
		//		  /		\						  /     \
		//	cur->l	  pivot			->			cur		pivot->r
		//			 /     \				  /     \
 		//	   pivot->l	  pivot->r		  cur->l  pivot->l

		Node<T> *pivot = cur->right;
		
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

	template<typename T>
	void Tree<T>::rotate_right(Node<T> *cur) {
		//		   pivot                           cur
		//		  /		\						  /     \
		//	 pivot->l   cur			<-		  pivot	  cur->r
		//			  /     \				 /     \
 		//	    pivot->r  cur->r		pivot->l  pivot->r

		Node<T> *pivot = cur->left;		
		
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

	template<typename T>
	void printNodeForGraphviz(Node<T> * const node, std::ostream &os, Node<T> *null, int n_viz) {
		
		if(node->color == RED)
			os << "G" << n_viz << node->val << " [label=\"" << node->val << "\",shape=circle, fillcolor=red, style=filled, fontcolor=white];\n";
		if(node->color == BLACK)
			os << "G" << n_viz << node->val << " [label=\"" << node->val << "\",shape=circle, fillcolor=black, style=filled, fontcolor=white];\n";

		if(node->left != null) {
			os << "G" << n_viz << node->val << " -> "
			   << "G" << n_viz << node->left->val << ";\n";			
			printNodeForGraphviz(node->left, os, null, n_viz);
		}
		else {
			os << "G" << n_viz << "nulll" << node->val << " [label=\"null\", shape=square, fillcolor=black, style=filled, fontcolor=white];\n";
			os << "G" << n_viz << node->val << " -> "
			   << "G" << n_viz << "nulll" << node->val << ";\n";
		}

		if(node->right != null) {
			os << "G" << n_viz << node->val << " -> "
			   << "G" << n_viz << node->right->val << ";\n";
			printNodeForGraphviz(node->right, os, null, n_viz);
		}
		else {
			os << "G" << n_viz << "nullr" << node->val << " [label=\"null\", shape=square, fillcolor=black, style=filled, fontcolor=white];\n";
			os << "G" << n_viz << node->val << " -> "
			   << "G" << n_viz << "nullr" << node->val << ";\n";
		}
	}

	template<typename T>
	void Tree<T>::printForGraphviz() {
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

	template<typename T>
	void Tree<T>::runDotty() {
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

	template<typename T>
	std::ostream& operator<< (std::ostream& os, const Node<T> &node) {
		
		if(node.left == NULL && node.right == NULL) {
			os << "null";
		}
		else {
			os << "(";

			if(node.left != NULL)
				os << *(node.left);

			os << " (" << node.val << ", ";
			
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