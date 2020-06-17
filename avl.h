
#include "inc.h"

using namespace std;

template <class T>
class AVLnode {
public:
	T key;
	int balance;
	AVLnode* left, * right, * parent;

	AVLnode(T k, AVLnode* p) : key(k), balance(0), parent(p),
		left(NULL), right(NULL) {}

	~AVLnode() 
	{
			delete left;
			delete right;
	}
};

/* AVL tree */
template <class T>
class AVL {
public:
	AVL(void);
	~AVL(void);
	bool insert(T key);
	void deleteKey(std::string key);
	void printBalance();
	void searchShfr(std::string &cphr, int &whtDo);
	void retGetBook(std::string& cphr, int &whtDo);
	void boyerMour(std::string& tmpStr);
	void clear();
private:
	AVLnode<T>* root;
	int BMSearch(string str, string substring);
	AVLnode<T>* rotateLeft(AVLnode<T>* a);
	AVLnode<T>* rotateRight(AVLnode<T>* a);
	AVLnode<T>* rotateLeftThenRight(AVLnode<T>* n);
	AVLnode<T>* rotateRightThenLeft(AVLnode<T>* n);
	void rebalance(AVLnode<T>* n);
	int height(AVLnode<T>* n);
	void setBalance(AVLnode<T>* n);
	void printBalance(AVLnode<T>* n);
	void boyerMour(AVLnode<T>* n, std::string& cphr);
	void searchShfr(AVLnode<T>* n, std::string& cphr, int &whtDo);
	void retGetBook(AVLnode<T>* n, std::string& cphr, int &whtDo);
	vector<int> prefix_func(const string& s);
	void deleteAll(const T delKey);

};

template <class T>
vector<int> AVL<T>::prefix_func(const string& s)
{
	vector<int> p(s.length());

	int k = 0;
	p[0] = 0;
	for (int i = 1; i < s.length(); ++i) 
	{
		while (k > 0 && s[k] != s[i]) 
		{
			k = p[k - 1];
		}
		if (s[k] == s[i]) 
{
			++k;
		}
		p[i] = k;
	}
	return p;
}



template <class T>
int AVL<T>::BMSearch(string s, string t)
{
	if (s.length() < t.length()) 
	{
		return -1;
	}

	if (!t.length()) 
	{
		return s.length();
	}

	typedef hash_map<char, int> TStopTable;
	typedef hash_map<int, int> TSufficsTable;
	TStopTable stop_table;
	TSufficsTable suffics_table;

	for (int i = 0; i < t.length(); ++i) 
	{
		stop_table[t[i]] = i;
	}

	string rt(t.rbegin(), t.rend());
	vector<int> p = prefix_func(t), pr = prefix_func(rt);
	for (int i = 0; i < t.length() + 1; ++i) 
	{
		suffics_table[i] = t.length() - p.back();
	}

	for (int i = 1; i < t.length(); ++i) 
	{
		int j = pr[i];
		suffics_table[j] = min(suffics_table[j], i - pr[i] + 1);
	}

	for (int shift = 0; shift <= s.length() - t.length();) 
	{
		int pos = t.length() - 1;

		while (t[pos] == s[pos + shift]) 
		{
			if (pos == 0) return shift;
			--pos;
		}

		if (pos == t.length() - 1) 
		{
			TStopTable::const_iterator stop_symbol = stop_table.find(s[pos + shift]);
			int stop_symbol_additional = pos - (stop_symbol != stop_table.end() ? stop_symbol->second : -1);
			shift += stop_symbol_additional;
		}
		else 
		{
			shift += suffics_table[t.length() - pos - 1];
		}
	}
	return -1;
}

/* AVL class definition */
template <class T>
void AVL<T>::rebalance(AVLnode<T>* n) 
{
	setBalance(n);

	if (n->balance == -2) 
	{
		if (height(n->left->left) >= height(n->left->right))
			n = rotateRight(n);
		else
			n = rotateLeftThenRight(n);
	}
	else if (n->balance == 2) 
	{
		if (height(n->right->right) >= height(n->right->left))
			n = rotateLeft(n);
		else
			n = rotateRightThenLeft(n);
	}

	if (n->parent != NULL) 
	{
		rebalance(n->parent);
	}
	else {
		root = n;
	}
}

template <class T>
AVLnode<T>* AVL<T>::rotateLeft(AVLnode<T>* a) 
{
	AVLnode<T>* b = a->right;
	b->parent = a->parent;
	a->right = b->left;

	if (a->right != NULL)
		a->right->parent = a;

	b->left = a;
	a->parent = b;

	if (b->parent != NULL) 
	{
		if (b->parent->right == a) 
		{
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template <class T>
AVLnode<T>* AVL<T>::rotateRight(AVLnode<T>* a) 
{
	AVLnode<T>* b = a->left;
	b->parent = a->parent;
	a->left = b->right;

	if (a->left != NULL)
		a->left->parent = a;

	b->right = a;
	a->parent = b;

	if (b->parent != NULL) {
		if (b->parent->right == a) 
		{
			b->parent->right = b;
		}
		else {
			b->parent->left = b;
		}
	}

	setBalance(a);
	setBalance(b);
	return b;
}

template <class T>
AVLnode<T>* AVL<T>::rotateLeftThenRight(AVLnode<T>* n) 
{
	n->left = rotateLeft(n->left);
	return rotateRight(n);
}

template <class T>
AVLnode<T>* AVL<T>::rotateRightThenLeft(AVLnode<T>* n) 
{
	n->right = rotateRight(n->right);
	return rotateLeft(n);
}

template <class T>
int AVL<T>::height(AVLnode<T>* n) 
{
	if (n == NULL)
		return -1;
	return 1 + std::max(height(n->left), height(n->right));
}

template <class T>
void AVL<T>::setBalance(AVLnode<T>* n) 
{
	n->balance = height(n->right) - height(n->left);
}

template <class T>
void AVL<T>::printBalance(AVLnode<T>* n) 
{
	if (n != NULL) 
	{
		if (n->left != NULL)
		{
			printBalance(n->left);
		}
		std::cout << n->key << " "; 
		if (n->right != NULL)
		{
			printBalance(n->right);
		}
		
	}
}

template<class T>
void AVL<T>::boyerMour(AVLnode<T>* n, std::string& cphr)
{
	if (n != NULL) {
		boyerMour(n->left, cphr);
		if((this->BMSearch(n->key.getAuthor(), cphr) != -1) || (this->BMSearch(n->key.getBkNm(), cphr) != -1))
		{
			std::cout << n->key << " ";
		}
		boyerMour(n->right, cphr);
	}
}

template <class T>
void AVL<T>::searchShfr(AVLnode<T>* n, std::string &cphr, int &whtDo)
{
	if (n != NULL) 
	{
		searchShfr(n->left, cphr, whtDo);
		if (n->key == cphr)
		{
			std::cout << n->key << " ";
			whtDo = 3;
		}
		searchShfr(n->right, cphr, whtDo);
	}
}

template<class T>
void AVL<T>::retGetBook(AVLnode<T>* n, std::string& cphr, int& whtDo)
{
	if (n != NULL) {
		this->retGetBook(n->left, cphr, whtDo);
		if (n->key == cphr)
		{
			if (whtDo == 1)
			{
				n->key.minusBook();
				whtDo == 3;
			}
			else if (whtDo == 2)
			{
				n->key.plusBook();
				whtDo == 3;
			}
		}
		this->retGetBook(n->right, cphr, whtDo);
	}
}

template<class T>
void AVL<T>::searchShfr(std::string& cphr, int& whtDo)
{
	this->searchShfr(root, cphr, whtDo);
}

template<class T>
void AVL<T>::retGetBook(std::string& cphr, int& whtDo)
{
	this->retGetBook(root, cphr, whtDo);
}

template<class T>
void AVL<T>::boyerMour(std::string& tmpStr)
{
	this->boyerMour(root, tmpStr);
}

template<class T>
inline void AVL<T>::clear()
{
	while (root != NULL)
	{
		this->deleteAll(root->key);
	}
}

template <class T>
AVL<T>::AVL(void) : root(NULL) {}

template <class T>
AVL<T>::~AVL(void) {
	delete root;
}

template <class T>
bool AVL<T>::insert(T key) {
	if (root == NULL) {
		root = new AVLnode<T>(key, NULL);
	}
	else {
		AVLnode<T>
			* n = root,
			* parent;

		while (true) 
		{
			if (n->key == key)
			{ 
				return false;
			}
			parent = n;

			bool goLeft = n->key > key;
			n = goLeft ? n->left : n->right;

			if (n == NULL) 
			{
				if (goLeft) 
				{
					parent->left = new AVLnode<T>(key, parent);
				}
				else 
				{
					parent->right = new AVLnode<T>(key, parent);
				}

				rebalance(parent);
				break;
			}
		}
	}

	return true;
}

template <class T>
void AVL<T>::deleteKey(std::string delKey) 
{
	if (root == NULL)
	{ 
		return;
	}
	AVLnode<T>
		* n = root,
		* parent = root,
		* delNode = NULL,
		* child = root;

	while (child != NULL) 
	{
		parent = n;
		n = child;
		child = n->key >= delKey ? n->right : n->left;
		if ( n->key == delKey )
			delNode = n;
	}

	if (delNode != NULL) 
	{
		delNode->key = n->key;

		child = n->left != NULL ? n->left : n->right;

		if (root->key == delKey) 
		{
			root = child;
		}
		else 
		{
			if (parent->left == n) 
			{
				parent->left = child;
			}
			else 
			{
				parent->right = child;
			}

			rebalance(parent);
		}
	}
}

template <class T>
void AVL<T>::deleteAll(const T delKey) 
{
	if (root == NULL)
		return;

	AVLnode<T>
		* n = root,
		* parent = root,
		* delNode = NULL,
		* child = root;

	while (child != NULL) 
	{
		parent = n;
		n = child;
		child = n->key >= delKey ? n->right : n->left;
		if (n->key == delKey)
			delNode = n;
	}

	if (delNode != NULL) 
	{
		delNode->key = n->key;

		child = n->left != NULL ? n->left : n->right;

		if (root->key == delKey) 
		{
			root = child;
		}
		else {
			if (parent->left == n) 
			{
				parent->left = child;
			}
			else 
			{
				parent->right = child;
			}

			rebalance(parent);
		}
	}
}

template <class T>
void AVL<T>::printBalance() {
	printBalance(root);
	std::cout << std::endl;
}
