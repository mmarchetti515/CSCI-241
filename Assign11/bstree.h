//***************************************************************
//
//  bstree.h
//  CSCI 241 Assignment 11
//
//  Michael Marchetti z1860574
//
//***************************************************************

#ifndef BSTREE_H
#define BSTREE_H

#include <iostream>

/**
 * @brief node structure
 * 
 * @tparam K 
 * @tparam V 
 */
template<class K, class V>
struct node
{
    // data members
    K key;  // store key
    V value;  // store value    
    node<K, V>* left;  // pointer to a node<K, V> that points to the node's left subtree
    node<K, V>* right;  // pointer to a node<K, V> that points to the node's right subtree

    // constructor
    node<K, V>(const K& key = K(), const V& value = V(), node<K, V>* left = nullptr, node <K, V>* right = nullptr)
    {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }
};

/**
 * @brief bstree class
 * 
 * @tparam K 
 * @tparam V 
 */
template<class K, class V>
class bstree
{
    private:
    // data members 

        // pointer to a node<K, V> that points to the root node of the tree or nullptr if the tree is empty
        node<K, V>* root;
        // stores the number of elements or values currently stored in the binary search tree
        size_t t_size;

    // private methods

        // clone
        node<K, V>* clone(node<K, V>* p);

        // height helper function
        size_t height(node<K, V>* tree_node) const;

        // min helper function
        const K& min(node<K, V>* p) const;

        // max helper function
        const K& max(node<K, V>* p) const;
        
        // preorder helper function
        void preorder(node<K, V>* p) const;

        // inorder helper function
        void inorder(node<K, V>* p) const;

        // postorder helper function
        void postorder(node<K, V> *p) const;

        // level order helper function
        void print_level(node<K, V> *p, int level) const;

    public:    
    // member functions

        // default constructor
        bstree();

        // destructor method
        ~bstree();

        // copy constructor
        bstree(const bstree<K, V>& x);

        // assignment overload method
        bstree<K, V>& operator=(const bstree<K, V>& x);

        // clear method
        void clear();

        // destroy method
        void destroy(node<K, V>* p);

        // size method
        size_t size() const;

        // height method
        size_t height() const;

        // empty method
        bool empty() const;

        // min method
        const K& min() const;

        // max method
        const K& max() const;

        // insert method
        bool insert(const K& key, const V& value);

        // remove method
        bool remove(const K& key);

        //find method
        const node<K, V>* find(const K& key) const;

        // preorder method
        void preorder() const;

        // inorder method
        void inorder() const;

        // postorder method
        void postorder() const;

        // level order method
        void level_order() const;

};

/**
 * @brief clone function, necessary for copy
 * 
 * @tparam K 
 * @tparam V 
 * @param p 
 * @return node<K, V>* 
 */
template<class K, class V>
node<K, V>* bstree<K, V>::clone(node<K, V>* p)
{
    if(p != nullptr)
    {
        // make a copy of the node pointed to by p
        node<K, V> *new_node = new node<K, V>(p->key, p->value);

        // Recursively copy the left and right subtrees of the node pointed to by p
        new_node->left = clone(p->left);
        new_node->right = clone(p->right);

        return new_node;
    }
    else
    {
        return nullptr;
    }
}


/**
 * @brief Construct a new bstree<K, V>::bstree object, 
 * sets root pointer data member to nullptr and the tree size to 0
 * 
 * @tparam K 
 * @tparam V 
 */
template<class K, class V>
bstree<K, V>::bstree()
{
    root = nullptr;
    t_size = 0;
}

/**
 * @brief Destroy the bstree<K, V>::bstree object
 * 
 * @tparam K 
 * @tparam V 
 */
template<class K, class V> 
bstree<K, V>::~bstree()
{
    clear();
}

/**
 * @brief Construct a new bstree<K, V>::bstree object
 * 
 * @tparam K 
 * @tparam V 
 * @param x 
 */
template<class K, class V> 
bstree<K, V>::bstree(const bstree<K, V>& x)
{
    // copy the other bstree object's size
    t_size = x.t_size;

    // copy the nodes of the other bstree object
    root = clone(x.root);
}

/**
 * @brief overload assignment operator method
 * 
 * @tparam K 
 * @tparam V 
 * @param x reference to a constant bstree
 * @return bstree<K, V>& 
 */
template <class K, class V>
bstree<K, V>& bstree<K, V>::operator=(const bstree<K, V>& x)
{
    if(this != &x)
    {
        // Make the left bstree object empty
        clear();
        // Copy the other bstree object's size
        t_size = x.t_size;
        // Copy the nodes of the other bstree object
        root = clone(x.root);
    }
    return *this;
}

/**
 * @brief clear method, sets the tree back to the empty state 
 * 
 * @tparam K 
 * @tparam V 
 */
template<class K, class V>
void bstree<K, V>::clear()
{
    destroy(root);
    root = nullptr;
    t_size = 0;
}

/**
 * @brief destroy function, necessary for clear
 * 
 * @tparam K 
 * @tparam V 
 * @param p 
 */
template<class K, class V>
void bstree<K, V>::destroy(node<K, V>* p)
{
    if(p != nullptr)
    {
        // recursively destroy the left and right subtree of the node pointed to by p
        destroy(p->left);
        destroy(p->right);

        // delete the node pointed to by p
        delete[] p;
    }
}

/**
 * @brief size method, returns the tree size
 * 
 * @tparam K 
 * @tparam V 
 * @return size_t 
 */
template <class K, class V>
size_t bstree<K, V>::size() const
{
    return t_size;
}

/**
 * @brief height method, returns tree height
 * empty tree has height 0, all other are parent node height +1
 * @tparam K 
 * @tparam V 
 * @return size_t 
 */
template <class K, class V>
size_t bstree<K, V>::height() const
{
    return height(root);
}

/**
 * @brief height method necessary for height, recursively finds tree height
 * 
 * @tparam K 
 * @tparam V 
 * @param p pointer to a tree node
 * @return size_t tree height
 */
template <class K, class V>
size_t bstree<K, V>::height(node<K, V>* p) const
{
    // l_height : computed height of node's left subtree
    // r_height : computed height of node's right subtree

    if(p == nullptr)
    {
        return 0;
    }

    int l_height = height(p->left);
    int r_height = height(p->right);

    if(l_height > r_height)
    {
        return l_height + 1;
    }
    else
    {
        return r_height + 1;
    }
}


/**
 * @brief returns true if the tree size = 0, otherwise returns false
 * 
 * @tparam K 
 * @tparam V 
 * @return true - when empty 
 * @return false - when not empty
 */
template <class K, class V>
bool bstree<K, V>::empty() const
{
    return (t_size == 0);
}

/**
 * @brief min method, returns min key in bstree
 * 
 * @tparam K 
 * @tparam V 
 * @return const K& 
 */
template <class K, class V>
const K& bstree<K, V>::min() const
{
    return min(root);
}

/**
 * @brief min method, necessary for min, recursively searches the bstree for minimum key
 * searches through left side of tree - smallest value will be farthest left
 * @tparam K 
 * @tparam V 
 * @param p
 * @return const K& 
 */
template <class K, class V>
const K& bstree<K, V>::min(node<K, V>* p) const
{
    if(p->left != nullptr)
    {
        return min(p->left);
    }
    return p->key;
}

/**
 * @brief max method, returns max key in bstree
 * 
 * @tparam K 
 * @tparam V 
 * @return const K& 
 */
template <class K, class V>
const K& bstree<K, V>::max() const
{
    return max(root);
}

/**
 * @brief min method, necessary for min, recursively searches the bstree for minimum key
 * searches through right side of tree - largest value will be farthest right
 * @tparam K 
 * @tparam V 
 * @param p 
 * @return const K& 
 */
template <class K, class V>
const K& bstree<K, V>::max(node<K, V> *p) const
{
    if (p->right != nullptr)
    {
        return max(p->right);
    }
    return p->key;
}

/**
 * @brief insert method, attempts to insert a key and value into the binary search tree
 * 
 * @tparam K 
 * @tparam V 
 * @param key a key to insert
 * @param value a value to insert
 * @return true 
 * @return false 
 */
template <class K, class V>
bool bstree<K, V>::insert(const K& key, const V& value)
{
    // root     : pointer to the root node of the tree (nullptr if tree is empty)
    // t_size   : tree size  
    // p        : pointer to a tree node
    // parent   : pointer to the parent node of p (nullptr if p points to the root node)
    // new_node : pointer used to create a new tree node

    // Start at the root of the tree.
    node<K, V> *p = root;
    node<K, V> *parent = nullptr;

    // Search the tree for a null link or a duplicate key (if duplicates are disallowed).
    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    // If duplicates are disallowed, signal that insertion has failed.
    if (p != nullptr)
    {
        return false;
    }

    // Otherwise, create a tree node and insert it as a new leaf node
    node<K, V>* new_node = new node<K, V>(key, value);

    if (parent == nullptr)
    {
        root = new_node;
    }
    else
    {
        if (new_node->key < parent->key)
        {
            parent->left = new_node;
        }
        else
        {
            parent->right = new_node;
        }
    }

    t_size++;

    // If duplicates are disallowed, signal that insertion has succeeded.
    return true;
}

/**
 * @brief 
 * 
 * @tparam K 
 * @tparam V 
 * @param key key to remove from the tree 
 * @return true 
 * @return false 
 */
template <class K, class V>
bool bstree<K, V>::remove(const K& key)
{
    // root           : pointer to the root of the binary search tree
    // t_size         : tree size  
    // p              : pointer to the node to delete from the tree
    // parent         : pointer to the parent node of the node to delete from the tree (or 
    //                  nullptr if deleting the root node)
    // replace        : pointer to node that will replace the deleted node
    // replace_parent : pointer to parent of node that will replace the deleted node

    // Start at the root of the tree and search for the key to delete.
    node<K, V> *p = root;
    node<K, V> *parent = nullptr;
    while (p != nullptr && key != p->key)
    {
        parent = p;
        if (key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    // If the node to delete was not found, signal failure.
    if (p == nullptr)
    {
        return false;
    }

    // declare
    node<K, V>* replace;
    node<K, V>* replace_parent;

    if (p->left == nullptr)
    {
        // Case 1a: p has no children. Replace p with its right child
        // (which is nullptr).
        //   - or -
        // Case 1b: p has no left child but has a right child. Replace 
        // p with its right child.
        replace = p->right;
    }
    else if (p->right == nullptr)
    {
        // Case 2: p has a left child but no right child. Replace p 
        // with its left child.
        replace = p->left;
    }
    else
    {
        // Case 3: p has two children. Replace p with its inorder predecessor.

        // Go left...
        replace_parent = p;
        replace = p->left;

        // ...then all the way to the right.
        while (replace->right != nullptr)
        {
            replace_parent = replace;
            replace = replace->right;
        }

        // If we were able to go to the right, make the replacement node's
        // left child the right child of its parent. Then make the left child
        // of p the replacement's left child.
        if (replace_parent != p)
        {
            replace_parent->right = replace->left;
            replace->left = p->left;
        }

        // Make the right child of p the replacement's right child.
        replace->right = p->right;
    }

    // Connect replacement node to the parent node of p (or the root if p has no parent).
    if (parent == nullptr)
    {
        root = replace;
    }
    else
    {
        if (p->key < parent->key)
        {
            parent->left = replace;
        }
        else
        {
            parent->right = replace;
        }
    }

    // Delete the node, decrement the tree size, and signal success.
    delete[] p;
    t_size--;
    return true;
}

/**
 * @brief find method, attempts to find the specified key in the bstree
 * done iteratively
 * @tparam K 
 * @tparam V 
 * @param key a key for which to search
 * @return const node<K, V>* 
 */
template <class K, class V>
const node<K, V>* bstree<K, V>::find(const K& key) const
{
    // root   : pointer to the root node of the tree (nullptr if tree is empty)
    // p      : pointer to a tree node
    
    // Start at the root of the tree.
    node<K, V>* p = root;

    // Search the tree for a null link or a matching key.
    while(p != nullptr && key != p->key)
    {
        if(key < p->key)
        {
            p = p->left;
        }
        else
        {
            p = p->right;
        }
    }

    // p either points to the node with a matching key or is nullptr if 
    // the key is not in the tree.
    return p;
}

/**
 * @brief preorder method, preorder traversal through bstree
 * 
 * @tparam K 
 * @tparam V 
 */
template <class K, class V>
void bstree<K, V>::preorder() const
{
    preorder(root);
}

/**
 * @brief preorder method, necessary for preorder, prints key and value at each node visited
 * performs method recursively
 * @tparam K 
 * @tparam V 
 * @param p 
 */
template <class K, class V>
void bstree<K, V>::preorder(node<K, V> *p) const
{
    if(p != nullptr)
    {
        // visit the node pointed to by p, print formatting
        std::cout << p->key << ": " << p->value << std::endl;

        preorder(p->left);
        preorder(p->right);
    }
}

/**
 * @brief inorder method, inorder traversal through bstree
 * 
 * @tparam K 
 * @tparam V 
 */
template <class K, class V>
void bstree<K, V>::inorder() const
{
    inorder(root);
}

/**
 * @brief inorder method, necessary for inorder, prints key and value at each node visited
 * performs method recursively
 * @tparam K 
 * @tparam V 
 * @param p 
 */
template <class K, class V>
void bstree<K, V>::inorder(node<K, V>* p) const
{
    if(p != nullptr)
    {
        inorder(p->left);
        
        // visit the node pointed to by p
        std::cout << p->key << ": " << p->value << std::endl;
        inorder(p->right);
    }
}

/**
 * @brief postorder method, postorder traversal through bstree
 * 
 * @tparam K 
 * @tparam V 
 */
template <class K, class V>
void bstree<K, V>::postorder() const
{
    postorder(root);
}

/**
 * @brief postorder method, necessary for postorder, prints key and value at each node visited
 * performed recursively
 * @tparam K 
 * @tparam V 
 * @param p 
 */
template <class K, class V>
void bstree<K, V>::postorder(node<K, V> *p) const
{
    if (p != nullptr)
    {
        postorder(p->left);
        postorder(p->right);

        // visit the node pointed to by p
        std::cout << p->key << ": " << p->value << std::endl;
    }
}

/**
 * @brief level order method, level order traversal through bstree
 * 
 * @tparam K 
 * @tparam V 
 */
template <class K, class V>
void bstree<K, V>::level_order() const
{
    // root : pointer to the root node of the tree (nullptr if tree is empty)
    // h    : computed height of the tree (i.e., number of levels
    // i    : loop counter

    int h = height(root);
    int i = 1;

    while(i <= h)
    {
        print_level(root, i);
        i++;
    }
}

/**
 * @brief print level method, necessary to level order, prints key and value at each node visited
 * 
 * @tparam K 
 * @tparam V 
 * @param p pointer to a tree node
 * @param level number of levels
 */
template <class K, class V>
void bstree<K, V>::print_level(node<K, V>* p, int level) const
{
    if(p == nullptr)
    {
        return;
    }

    if(level == 1)
    {
        // visit the node pointed to by p
        std::cout << p->key << ": " << p->value << std::endl;
    }
    else if(level > 1)
    {
        print_level(p->left, level--);
        print_level(p->right, level--);
    }
}


#endif //BSTREE_H