#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H

template <typename T>
class Node{
public:
    T data;
    Node<T>* left;
    Node<T>* right;
    Node<T>* father;

    //Constructor of the class Node
    Node(T data){
        this->data = data;
        left = nullptr;
        right = nullptr;
        father = nullptr;
    }
};

template <typename T>
class BinaryTree{
private:
    Node<T>* root;
    Node<T>* iterator;
    int levelOfIterator;
    int weight;
    int degreeOfTheTree;

    void recursiveInsertion(Node<T>*& node,Node<T>* prevNode, T data);
    void recursiveSearch(Node<T>*& node, T data);
    void recursivePreOrder(Node<T>* node, std::string &toReturn);
public:
    //Constructor and destructor of the class
    BinaryTree();
    ~BinaryTree();

    //Manage the information
    void insert(T data);

    //Search for information
    void moveTo(T data);
    bool search(T data);

    //Iterate through the tree
    std::string preOrder();
    std::string posOrder();
    std::string inOrder();
    std::string breadthFirstSearch();

    //Functions of the teacher (buuuu)
    int getWeight();
    T parent(T data);
    std::string children(T data);
    std::string sibling(T data);
    int levelOf(T data);
    int degree();

};

//Constructor of the class
template<typename T>
BinaryTree<T>::BinaryTree() {
    root = nullptr;
    iterator=root;
    weight = 0;
    levelOfIterator = 0;
    degreeOfTheTree=0;
}

//Destructor of the class
template<typename T>
BinaryTree<T>::~BinaryTree() {

}

//Manage the information
template <typename T>
void BinaryTree<T>::insert(T data) {
    levelOfIterator = 0;
    recursiveInsertion(root, nullptr,data);
    degreeOfTheTree = (levelOfIterator>degreeOfTheTree) ? levelOfIterator : degreeOfTheTree;
    weight++;
}

template<typename T>
void BinaryTree<T>::recursiveInsertion(Node<T> *&node,Node<T> *prevNode, T data) {
    if(node== nullptr){
        node = new Node<T>(data);
        node->father = prevNode;
    } else if(data<node->data){
        levelOfIterator++;
        recursiveInsertion(node->left,node,data);
    } else {
        levelOfIterator++;
        recursiveInsertion(node->right,node, data);
    }
}

//Search for information
template<typename T>
void BinaryTree<T>::moveTo(T data) {
    iterator=root;
    levelOfIterator = 0;
    recursiveSearch(root,data);
}

template<typename T>
bool BinaryTree<T>::search(T data) {
    moveTo(data);
    return iterator != NULL;
}

template<typename T>
void BinaryTree<T>::recursiveSearch(Node<T> *&node, T data) {
    if(node==nullptr) return;
    if(data<node->data){
        iterator = iterator->left;
        levelOfIterator++;
        recursiveSearch(node->left,data);
    } else if(data>node->data){
        iterator = iterator->right;
        levelOfIterator++;
        recursiveSearch(node->right,data);
    }
}

//Iterate through the tree
template<typename T>
std::string BinaryTree<T>::preOrder() {
    iterator=root;
    std::string toReturn;
    recursivePreOrder(iterator,toReturn);
    return toReturn;
}

template<typename T>
void BinaryTree<T>::recursivePreOrder(Node<T> *node, std::string &toReturn) {
    if(node==NULL) return;
    toReturn.append(std::to_string(node->data) + " - ");
    recursivePreOrder(node->left,toReturn);
    recursivePreOrder(node->right,toReturn);
}

template<typename T>
std::string BinaryTree<T>::posOrder() {

}

template<typename T>
std::string BinaryTree<T>::inOrder() {

}

template<typename T>
std::string BinaryTree<T>::breadthFirstSearch() {

}

template<typename T>
int BinaryTree<T>::getWeight() {return weight;}

template<typename T>
T BinaryTree<T>::parent(T data) {
    moveTo(data);
    if(iterator!= nullptr && iterator->father != nullptr){
        return iterator->father->data;
    } else {
        throw std::domain_error("No");
    }
}

template<typename T>
std::string BinaryTree<T>::children(T data) {
    moveTo(data);
    std::string toReturn;
    if(iterator!= nullptr) {
        if (iterator->right != nullptr) {
            toReturn.append(std::to_string(iterator->right->data) + " ");
        }
        if (iterator->left != nullptr) {
            toReturn.append(std::to_string(iterator->left->data) + " ");
        }
        return toReturn;
    }
    return "-";
}

template<typename T>
std::string BinaryTree<T>::sibling(T data) {
    moveTo(data);
    std::string toReturn;
    if(iterator!= nullptr && iterator->father != nullptr) {
            if (iterator->father->left != iterator && iterator->father->left!= nullptr){
                return std::to_string(iterator->father->left->data);
            }
            if(iterator->father->right != iterator && iterator->father->right!= nullptr){
                return std::to_string(iterator->father->right->data);
            }
    }
    return "-";
}

template<typename T>
int BinaryTree<T>::levelOf(T data) {
    moveTo(data);
    if(iterator== nullptr) return -1;
    return levelOfIterator;
}

template<typename T>
int BinaryTree<T>::degree() {
    return degreeOfTheTree+1;
}



#endif //BINARYTREE_BINARYTREE_Hreturn