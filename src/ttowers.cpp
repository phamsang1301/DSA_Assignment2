#ifndef _definition_h_
#include "defs.h"
#define _definition_h_
#endif


//your code should be after that directive
KnightTree *removeAVL(KnightTree*root,KnightTree* knight, bool&shorter, bool& success);
KnightTree*leftBalance(KnightTree*root, bool &taller);
KnightTree*rightBalance(KnightTree*root, bool &taller);
KnightTree* deleteKnight(KnightTree* root, KnightTree*knight, int &t);
int getCount(KnightTree* root);
bool isCompleteTree(KnightTree* root);


bool avl  = false;
bool checkDuplicate(KnightTree* root, int key)
{   
    if (root == NULL || root->key == key)
       return root;
    
    // Key is greater than root's key
    if (root->key < key)
       return checkDuplicate(root->pRightChild, key);
 
    // Key is smaller than root's key
    return checkDuplicate(root->pLeftChild, key);
    
}

void increaseKey(KnightTree *root, int &key)
{
    while(checkDuplicate(root, key) &&  key <  999)
    {
        key++;
        if (key == 777 || key == 888)
        {
            key++;
        }
    }
        
}
// add new knight into new tree with root = 777
//  void addRoot777(KnightTree *node, KnightTree *&root)
// {
    
//     if (root == NULL)
//     {
//         KnightTree* temp = new KnightTree();
//         temp->key = node->key;
//         temp->level = node->level;
//         root = temp;
//         return;
//     }
//     if (root->key < node->key)
//     {
//         addRoot777(node, root->pRightChild); 
//     }
//     if (root->key > node->key)
//     {
//        addRoot777(node,root->pLeftChild);
//     }
    
// }
//create new tree with root = 777
// void newKnightTree(KnightTree* root, KnightTree* &newKnight777)
// {
    
//     while (root) 
//     {
//         KnightTree * pre;
//         if (root->pLeftChild == NULL)
//         {
//             addRoot777(root, newKnight777);
//             // Inorder(newKnight777);
//             // cout << root->key  << " ";
            
//             root = root->pRightChild;
        
//         }
//         else 
//         {
//             pre = root->pLeftChild;
//             while (pre->pRightChild && pre->pRightChild != root)
//             {
//                 pre = pre->pRightChild;
//             }
//             if (pre->pRightChild == NULL)
//             {
//                 pre->pRightChild = root;
//                 // cout << root->key << " ";
//                 addRoot777(root, newKnight777);
   
//                 root = root->pLeftChild;
//             }
//             else 
//             {
//                 pre->pRightChild = NULL;
//                 // addRoot777(root, newKnight777);
//                 root = root->pRightChild;
//             }
//         }
//     }
// }
// KnightTree *createKnight(int key, int lvl)
// {
//         KnightTree *newKnight = new KnightTree();
//         newKnight->key = key;
//         newKnight->level = lvl;
//         newKnight->balance = 0;
//         newKnight->pLeftChild = NULL;
//         newKnight->pRightChild = NULL;
//         return newKnight;
// }


bool checkAVL(KnightTree* root)
{
    if (root == NULL)
    {
        return 0;
    }
    while (root->pRightChild)
    {
        root = root->pRightChild;
        if (root->key == 999)
        return 1;
    }
    return 0;
}
// void addKnight(KnightTree*& knightTree, int key, int lvl)
// {


//     if (knightTree == NULL)
//     {
//         KnightTree *newKnight = new KnightTree();
//         newKnight->key = key;
//         newKnight->level = lvl;
//         newKnight->balance = 0;
//         newKnight->pLeftChild = NULL;
//         newKnight->pRightChild = NULL;
//         knightTree = newKnight;
//         return;
//     }
//     else 
//     {
   
//         if (!checkDuplicate(knightTree,key))
//         {
//             if (key != 777 )
//             {
//                 if (key > knightTree->key)
//                 {
//                     addKnight(knightTree->pRightChild, key, lvl);
//                 }
//                 else if (key < knightTree->key)
//                 {
//                     addKnight(knightTree->pLeftChild, key, lvl);
//                 }
//             }

//             else 
//             {
//                 if (checkAVL(knightTree))
//                 {
//                     if (key > knightTree->key)
//                     {
//                         addKnight(knightTree->pRightChild, key, lvl);
//                     }
//                     else if (key < knightTree->key)
//                     {
//                     addKnight(knightTree->pLeftChild, key, lvl);
//                     }
//                 }
//                 else 
//                 {
//                     KnightTree *newKnight = new KnightTree();
//                     newKnight->key = 777;
//                     newKnight->level = lvl;
//                     newKnight->pRightChild = NULL;
//                     newKnight->pLeftChild = NULL;
//                     newKnightTree(knightTree, newKnight);
//                     knightTree = newKnight;
//                 }
                
//             }
//         }
//         else 
//         {
//             increaseKey(knightTree, key);
//             if (key != 999)
//             {
//                 addKnight(knightTree, key, lvl);
//             }
//             else return;
//         }
//     }
// }

void insertAVL(KnightTree*& root, KnightTree* knight, bool &taller)
{
    KnightTree * temp = new KnightTree();
    temp->key = knight->key;
    temp->level = knight->level;
    temp->balance = knight->balance;
    if (root == NULL)
    {
        root = temp;
        taller = true;
        // root->pLeftChild = NULL;
        // root->pRightChild = NULL;
        return;
    } 
    if (knight->key < root->key)
    {
        insertAVL(root->pLeftChild, knight, taller);
        if (taller)
        {
            if (root->balance == -1)
            {
                root = leftBalance(root, taller);
            }
            else if (root->balance == 0)
            {
                root->balance = -1;
            }
            else 
            {
                root->balance = 0;
                taller = false;
            }
        }
    }
    else
    {
        insertAVL(root->pRightChild, knight, taller);
        if (taller)
        {
            if (root->balance == -1)
            {
                root->balance = 0;
                taller = false;
            }
            else if (root->balance == 0)
            {
                root->balance = 1;
            }
            else 
            {
                root = rightBalance(root, taller);
            }
        }
    }
}

// case 777 - AVL
void insertNLR_AVL(KnightTree* root, KnightTree*&newAVL)
{
        KnightTree * pre;

    while (root) 
    {
        if (root->pLeftChild == NULL)
        {
            bool taller = 1;
            insertAVL(newAVL, root, taller);
            // Inorder(newKnight777);
            // cout << root->key  << " ";
            
            root = root->pRightChild;
        
        }
        else 
        {
            pre = root->pLeftChild;
            while (pre->pRightChild && pre->pRightChild != root)
            {
                pre = pre->pRightChild;
            }
            if (pre->pRightChild == NULL)
            {
                pre->pRightChild = root;
                // cout << root->key << " ";
                bool taller = 1;
                insertAVL(newAVL, root, taller);
    
                root = root->pLeftChild;
            }
            else 
            {
                pre->pRightChild = NULL;
                // addRoot777(root, newKnight777);
                root = root->pRightChild;
            }
        }
    }
}
void insertListLNR(KnightTree*& root, KnightTree *knight)
{
    if (root == NULL)
    {
        KnightTree* newKnight = new KnightTree();
        newKnight->key = knight->key;
        newKnight->level = knight->level;
        root = newKnight;
        return;
    }
    insertListLNR(root->pRightChild, knight);

    // KnightTree* pre = root; 
    // while(pre)
    // {
    //     cout << pre->key << " ";
    //     pre = pre->pRightChild;
    // }
}
KnightTree* findMin(KnightTree* root)
{
    KnightTree *pre = root;
    if (root == NULL)
    {
        return NULL;
    }
    while(pre->pLeftChild)
    {
        pre = pre->pLeftChild;
    }
    return pre;
}

// case 888
void insertLNR_AVL(KnightTree*root, KnightTree*& newLNR)
{
//     KnightTree*pre;
//     while (root) {
//         if (root->pLeftChild==NULL)
//         {
//             // cout<< root->key << " ";
//             insertListLNR(newLNR, root);
//             root = root->pRightChild;
//         }
//         else 
//         {
//             pre = root->pLeftChild;
//             while(pre->pRightChild && pre->pRightChild != root)
//             {
//                 pre = pre->pRightChild;
//             }
//             if (pre->pRightChild == NULL)
//             {
//                 pre->pRightChild = root;
//                 root = root->pLeftChild;
//             }
//             else 
//             {
//                 pre->pRightChild = NULL;
//                 // cout << root->key;
//                 insertListLNR(newLNR, root);
//                 root = root->pRightChild;
//             }
//         }
//     }
// return newLNR;
    if (root)
    {
        insertLNR_AVL(root->pLeftChild, newLNR);
        insertListLNR(newLNR, root);
        insertLNR_AVL(root->pRightChild, newLNR);
    }
}

void insertRecursiveLeft(KnightTree*& avl_bst, KnightTree*left)
{
    if (avl_bst == NULL)
    {
        KnightTree* newKnight = new KnightTree();
        newKnight->key = left->key;
        newKnight->level = left->level;
        avl_bst = newKnight;
        return;
    }
    insertRecursiveLeft(avl_bst->pLeftChild, left);
}
void insertRecursiveRight(KnightTree*& avl_bst, KnightTree*right)
{
    if (avl_bst == NULL)
    {
        KnightTree* newKnight = new KnightTree();
        newKnight->key = right->key;
        newKnight->level = right->level;
        avl_bst = newKnight;
        return;
    }
    if (avl_bst->key <  right->key )
        insertRecursiveRight(avl_bst->pRightChild, right);


    if (avl_bst->key > right->key)
    {
        insertRecursiveRight(avl_bst->pLeftChild,right ); 
    }
   
}
void reverseList(KnightTree*& root)
{

		KnightTree* current = root;
        KnightTree *prev = NULL, *next = NULL;
 
        while (current != NULL) {
            // Store next
            next = current->pRightChild;
 
            // Reverse current node's pointer
            current->pRightChild = prev;
 
            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        root = prev;
	
}
void turnIntoAVL(KnightTree*root, KnightTree*&avl_bst, int count)
{
    if (count == 1)
    {
        return;
    }
    else if (count == 2)
    {
        KnightTree* newKnight = new KnightTree();
        newKnight->key = root->key;
        newKnight->level = root->level;
        avl_bst->pLeftChild = newKnight;
    }
    else if (count == 3)
    {
        bool taller = 1;
        insertAVL(avl_bst, root, taller);
        taller = 1;
        insertAVL(avl_bst, root->pRightChild->pRightChild, taller);
    }
    else
    {    
        KnightTree *pre = root;        
        for (int i = 0; i <= count /2; i++)
        {
            pre = pre->pRightChild;
        }
        KnightTree *right = pre;

        KnightTree* left = root;
        for (int i = 0; i < count /2  -1; i++)
        {
            root = root->pRightChild;
        }
        root->pRightChild = NULL;

        reverseList(left);
        reverseList(right);
        while(left)
        {  
            //  cout << left->key << " ";
            insertRecursiveLeft(avl_bst, left);
            left=  left->pRightChild;
        }
        // cout << endl;
        while(right)
        {
            // cout << right->key << " ";
            insertRecursiveRight(avl_bst, right);
            right  =  right->pRightChild;
        }
        // KnightTree *pre = root;
        // for (int i = 0; i < (count/2); i++ )
        // {
        //     bool taller = 1;
        //     insertAVL(avl_bst, pre, taller);
        //     pre = pre->pRightChild;
        // }
        // pre = pre->pRightChild;
        // while(pre)
        // {
        //     bool taller = 1;
        //     insertAVL(avl_bst, pre, taller);
        //     pre = pre->pRightChild;
        // }
    }
}
void normalInsert(KnightTree *&root, KnightTree *node)
{  
    if (root == NULL)
    {
        KnightTree* newKnight = new KnightTree();
        newKnight->key = node->key;
        newKnight->level = node->level;
        root = newKnight;
        return;
    }
    if (root->key < node->key)
    {
        normalInsert(root->pRightChild,node ); 
    }
    if (root->key > node->key)
    {
       normalInsert(root->pLeftChild,node);
    }
    
}
//create new tree with root = 777
void insertNLR(KnightTree* root, KnightTree* &newKnight777)
{
    if (root)
    {
        normalInsert(newKnight777, root);
        insertNLR(root->pLeftChild, newKnight777);
        insertNLR(root->pRightChild, newKnight777);
    }
}
void insertListRNL(KnightTree* &root, KnightTree*knight)
{
    if (root == NULL)
    {
        KnightTree* newKnight = new KnightTree();
        newKnight->key = knight->key;
        newKnight->level = knight->level;
        root = newKnight;
        return;
    }
    insertListRNL(root->pLeftChild, knight);
    
}
void insertRNL(KnightTree* root, KnightTree* &listRNL)
{      
    // if (root)
    // {
    //     insertRNL(root->pRightChild, listRNL);
    //     insertListRNL(listRNL, root);
    //     // cout << root->key << " ";
    //     insertRNL(root->pLeftChild, listRNL);
    // }
    KnightTree * pre;
    while( root ){
		if( root->pRightChild == NULL ){
			// cout<< root->key << " ";
            bool taller  = 1;
            insertAVL(listRNL, root, taller);
			root = root->pLeftChild;
		}
		else{
			pre = root->pRightChild;
			while(pre->pLeftChild && pre->pLeftChild != root ){
				pre = pre->pLeftChild;
			}
			if( pre->pLeftChild == NULL ){
				pre->pLeftChild = root;
				root = root->pRightChild;
			}
			else{
				pre->pLeftChild = NULL;
				// cout<< root->key << " ";
                bool taller  = 1;
                insertAVL(listRNL, root, taller);
				root = root->pLeftChild;
			}
		}
	}
    
    
}

void insertKnight(KnightTree*& root, KnightTree *knight)
{
    if (!checkDuplicate(root, knight->key))
    {

        if (knight->key == 777)
        {
            avl = false;
            // if (!checkAVL(root))
            // {
                insertNLR(root, knight);
                root = knight;
            // }
            // else
            // {
            //     insertNLR_AVL(root, knight);
            //     root = knight;
            // }
        }
        else if (knight->key == 999) //turn into AVL
        {
            avl  = true;
            insertRNL(root, knight);

            // KnightTree*  toInsertAvl = knight; 
            // toInsertAvl = toInsertAvl->pLeftChild;
            
            // while(toInsertAvl)
            // {
            //     // cout  << toInsertAvl->key << " ";
            //     bool taller = 1;
            //     insertAVL(knight, toInsertAvl, taller);
            //     toInsertAvl = toInsertAvl->pLeftChild;
            // }

            root = knight;
            
        }
        else if (knight->key == 888) //turn into AVL-BSL
        {   
            avl = false;
            normalInsert(root, knight);
            KnightTree* min = findMin(root);
            KnightTree* newLNR = new KnightTree();
            newLNR->key = min->key;
            newLNR->level = min->level;
            int t = 1;
            root = deleteKnight(root, min, t);

            insertLNR_AVL(root, newLNR);
            root = newLNR;
        //   while(newLNR)
        //   {
        //       cout << newLNR->key << " ";
        //       newLNR = newLNR-> pRightChild;
        //   }
        //   cout << endl;
            int count = getCount(root);

            KnightTree* pre  = root;
            for (int i = 0; i < count /2; i++ )
            {
                pre = pre->pRightChild;
            }
            KnightTree* avl = new KnightTree();
            avl->key=pre->key;
            avl->level = pre->level;
            turnIntoAVL(root, avl,count);
            root = avl;
        }
        else if (knight->key == 0)// knight's key = 0
        {
            if (!isCompleteTree(root))
            {
                if (avl)
                {
                    bool taller = 1;
                    insertAVL(root, knight, taller);
                }
                else
                {
                    normalInsert(root, knight);
                }           
            }
        }
        else //normal insert
        {
            if (avl)
            {
                bool taller = 1;
                insertAVL(root, knight, taller);
            }
            else
            {
                normalInsert(root, knight);
            }
        }
    }   
    else 
    {
        increaseKey(root, knight->key);
        if (knight->key != 999)
        {
            normalInsert(root, knight);
        }
    }
}
KnightTree* increaseNearestLevel(KnightTree *&root, int code)
{
    int diff = INT16_MAX;
    KnightTree* cur = root;
    KnightTree* closest = root;
    while (cur) 
    {
        if (cur->pLeftChild == NULL) {
  
            // updating diff if the current diff is
            // smaller than prev difference
            if (diff > abs(cur->key - code)) {
                diff = abs(cur->key - code);
                closest = cur;
            }
  
            cur = cur->pRightChild;
        }
  
        else {
  
            // finding the inorder predecessor
            KnightTree* pre = cur->pLeftChild;
            while (pre->pRightChild != NULL &&
                   pre->pRightChild != cur)
                pre = pre->pRightChild;
  
            if (pre->pRightChild == NULL) {
                pre->pRightChild = cur;
                cur = cur->pLeftChild;
            }
  
            // threaded link between curr and
            // its predecessor already exists
            else {
                pre->pRightChild = NULL;
  
                // if a closer Node found, then update 
                // the diff and set closest to current
                if (diff > abs(cur->key - code)) {
                    diff = abs(cur->key - code);
                    closest = cur;
                }
  
                // moving to the right child
                cur = cur->pRightChild;
            }
        }
    }
    if (closest->level < 9)
        closest->level++;
    return closest;
}  
KnightTree* findSmallest(KnightTree* root)
{
    KnightTree* current = root;
    /* loop down to find the leftmost leaf */
    while (current->pLeftChild != NULL) {
        current = current->pLeftChild;
    }
    return current;
}

KnightTree* deleteKnight(KnightTree* root, KnightTree*knight, int &t)
{
    t++;
    if (root == NULL) return root;
    else if (root->key > knight->key) root->pLeftChild = deleteKnight(root->pLeftChild, knight,t);
    else if (root->key < knight->key) root->pRightChild = deleteKnight(root->pRightChild, knight,t);
    else {
        if (root->pLeftChild == NULL) {
            KnightTree* temp = root->pRightChild;
            delete root;
            if (t == 1) {root = temp ; }
            return temp;
        }
        else if (root->pRightChild == NULL) {
            KnightTree* temp = root->pLeftChild;
            delete root;
            if (t == 1) { root = temp; }
            return temp;
        }
        else {
            KnightTree* temp = findSmallest(root->pRightChild);
            root->key = temp->key;
            root->level = temp->level;
            root->pRightChild = deleteKnight(root->pRightChild, temp,t);
        }
    }
    return root;
  
}
KnightTree *findNearestKnight(KnightTree *root, int key)
{
    int diff = INT16_MAX;
    KnightTree* cur = root;
    KnightTree* closest = root;
    while (cur) 
    {
        if (cur->pLeftChild == NULL) {
  
            // updating diff if the current diff is
            // smaller than prev difference
            if (diff > abs(cur->key - key)) {
                diff = abs(cur->key - key);
                closest = cur;
            }
  
            cur = cur->pRightChild;
        }
  
        else {
  
            // finding the inorder predecessor
            KnightTree* pre = cur->pLeftChild;
            while (pre->pRightChild != NULL &&
                   pre->pRightChild != cur)
                pre = pre->pRightChild;
  
            if (pre->pRightChild == NULL) {
                pre->pRightChild = cur;
                cur = cur->pLeftChild;
            }
  
            // threaded link between curr and
            // its predecessor already exists
            else {
                pre->pRightChild = NULL;
  
                // if a closer Node found, then update 
                // the diff and set closest to current
                if (diff > abs(cur->key - key)) {
                    diff = abs(cur->key - key);
                    closest = cur;
                }
  
                // moving to the right child
                cur = cur->pRightChild;
            }
        }
    }

    return closest;
} 
KnightTree *fightToDie(KnightTree*root, int lvl)
{
    KnightTree* closest = findNearestKnight(root, 888);
    if(closest->level >=  lvl)  return root;
    else 
       {
            if (avl)
                {
                    bool shorter = false;
                    bool success = false;
                    root = removeAVL(root, closest,shorter, success);
                }
            else 
                {
                    int t = 0;
                    root = deleteKnight(root, closest, t);
            
                }
                return fightToDie(root,lvl);
        }
   
    return root;
}
int getHeight(KnightTree* root)
{
    if (root == NULL)
        return 0;
    else 
    {
        int lHeight = getHeight(root->pLeftChild);
        int rheight = getHeight(root->pRightChild);
 
        if (lHeight > rheight)
            return (lHeight + 1);
        else
            return (rheight + 1);
    }
}
int getCount(KnightTree* root)
{
    int count = 1;
    if (root == NULL)
    {
        return 0;
    }
   
    count += getCount(root->pLeftChild);
    count += getCount(root->pRightChild);
    return count;
}
bool isCompleteTree(KnightTree* root)
{
    if (root == NULL)
    {
        return true;
    }
    int h = getHeight(root);
    int c = getCount(root);
    return c == (pow(2,h) -1);
}

//--------------------------------------------------------------------------
KnightTree* rotateLeft(KnightTree* root)
{
    KnightTree* temp = root->pRightChild;
    root->pRightChild= temp->pLeftChild;
    temp->pLeftChild = root;
    return temp;
}

KnightTree* rotateRight(KnightTree* root)
{
    KnightTree* temp = root->pLeftChild;
    root->pLeftChild= temp->pRightChild;
    temp->pRightChild = root;
    return temp;
}

KnightTree* rightBalance(KnightTree* root, bool &taller)
{
    KnightTree* rightTree = root->pRightChild;
    if (rightTree->balance == 1)
    {
        root->balance = 0;            
        root = rotateLeft(root);
        rightTree->balance = 0;
        taller =  false;
    }
    else if (rightTree->pLeftChild != NULL)
    {
        KnightTree* leftTree = rightTree->pLeftChild;
        if (leftTree->balance == -1)
        {
            root->balance = 0;
            rightTree->balance = 1;

        }
        else if (leftTree->balance == 0)
        {
            rightTree->balance = 0;
        }
        else
        {
            root->balance = -1;
            rightTree->balance = 0;
        }
        leftTree->balance = 0;
        root->pRightChild = rotateRight(rightTree);
        root = rotateLeft(root);
        taller = false;
    }
    return root;
}
KnightTree * leftBalance(KnightTree* root, bool &taller)
{
    KnightTree* leftTree = root->pLeftChild;
    if (leftTree->balance == -1)
    {
        root->balance = 0;
        root = rotateRight(root);
        leftTree->balance = 0;
        taller = 0;
    }
    else if (leftTree->pRightChild != NULL)
    {
        KnightTree* rightTree = leftTree->pRightChild;
        if (rightTree->balance == -1)
        {
            root->balance = 1;
            leftTree->balance = 0;
        }
        else if (rightTree->balance == 0)
            leftTree->balance = 0;
        else
        {
            root->balance = 0;
            leftTree->balance = -1;
        }
        rightTree->balance = 0;
        root->pLeftChild = rotateLeft(leftTree);
        root = rotateRight(root);
        taller = 0;
    }
    return root;
}
// void insertAVL(KnightTree*& root, KnightTree* knight, bool &taller)
// {

//     if (root == NULL)
//     {
//         KnightTree * temp = new KnightTree();
//         temp->key = knight->key;
//         temp->level = knight->level;
//         temp->balance = knight->balance;
//         root = temp;
//         taller = true;
//         // root->pLeftChild = NULL;
//         // root->pRightChild = NULL;
//         return;
//     } 
//     if (knight->key < root->key)
//     {
//         insertAVL(root->pLeftChild, knight, taller);
//         if (taller)
//         {
//             if (root->balance == -1)
//             {
//                 root = leftBalance(root, taller);
//             }
//             else if (root->balance == 0)
//             {
//                 root->balance = -1;
//             }
//             else 
//             {
//                 root->balance = 0;
//                 taller = false;
//             }
//         }
//     }
//     else
//     {
//         insertAVL(root->pRightChild, knight, taller);
//         if (taller)
//         {
//             if (root->balance == -1)
//             {
//                 root->balance = 0;
//                 taller = false;
//             }
//             else if (root->balance == 0)
//             {
//                 root->balance = 1;
//             }
//             else 
//             {
//                 root = rightBalance(root, taller);
//             }
//         }
//     }
// }

//Delete AVT---------------------------------------
KnightTree* deleteRightBalance(KnightTree* root, bool& shorter) {
		if (root->balance == -1) {
			root->balance = 0;
		}
		else if (root->balance == 0) {
			root->balance = 1;
			shorter = false;
		}
		else if(root->pRightChild!=NULL){
			
			KnightTree* rightTree = root->pRightChild;
			if (rightTree->balance == -1) {
				KnightTree* leftTree = rightTree->pLeftChild;
				if (leftTree->balance == -1) {
					rightTree->balance = 1;
					root->balance = 0;
				}
				else if (leftTree->balance == 0) {
					root->balance = -1;
					rightTree->balance = 0;
				}
				else {
					root->balance = -1;
					rightTree->balance = 0;
				}
				leftTree->balance = 0;
				root->pRightChild = rotateRight(rightTree);
				root = rotateLeft(root);
			}
			else {
				if (rightTree->balance != 0) {
					root->balance = 0;
					rightTree->balance = 0;
				}
				else {
					root->balance = 1;
					rightTree->balance = -1;
					shorter = false
                    ;
				}
				root = rotateLeft(root);
			}
		}
		if (root->pRightChild == NULL&& root->pLeftChild!=NULL) {
			root->pLeftChild->balance = 0;
			root->balance = 0;
			root = rotateRight(root);
		}
		
		return root;
	}
	KnightTree* deleteLeftBalance(KnightTree* root, bool& shorter) {
		
		if (root->balance == 1) 
        {
			root->balance = 0;
		}
		else if (root->balance == 0) 
        {
			root->balance = -1;
			shorter = false;
		}
		else if(root->pRightChild!=NULL) 
        {
			KnightTree* leftTree = root->pLeftChild;
			if (leftTree->balance == 1) {
				KnightTree* rightTree = leftTree->pRightChild;
				if (rightTree->balance == -1) {
					leftTree->balance = -1;
					root->balance = 0;
				}
				else if (rightTree->balance == 0) 
                {
					root->balance = 1;
					leftTree->balance = 0;
				}
				else 
                {
					root->balance = 1;
					leftTree->balance = 0;
				}
				rightTree->balance = 0;
				root->pLeftChild = rotateRight(leftTree);
				root = rotateRight(root);
			}
			else {
				if (leftTree->balance != 0) {
					root->balance = 0;
					leftTree->balance = 0;
				}
				else {
					root->balance = -1;
					leftTree->balance = 1;
					shorter = false;
				}
				root = rotateRight(root);
			}
		}
		return root;
    }
KnightTree *removeAVL(KnightTree*root,KnightTree* knight, bool&shorter, bool& success)
    {
        if (root == NULL) {
			shorter = false;
			success = false;
			return NULL;
		}
		if (knight->key < root->key) {
			root->pLeftChild = removeAVL(root->pLeftChild, knight, shorter, success);
			if (shorter) root = deleteRightBalance(root, shorter);
		}
		else if (knight->key > root->key) {
			root->pRightChild = removeAVL(root->pRightChild, knight, shorter, success);
			if (shorter)root = deleteLeftBalance(root, shorter);
		}
		else 
        {
			KnightTree* deleteNode = root;
			if (root->pRightChild == NULL) {
				KnightTree* newRoot = root->pLeftChild;
				success = true;
				shorter = true;
				delete deleteNode;
				return newRoot;
			}
			else if (root->pLeftChild == NULL) {
				KnightTree* newRoot = root->pRightChild;
				success = true;
				shorter = true;
				delete deleteNode;
				return newRoot;
			}
			else {
				KnightTree* exchPtr = root->pRightChild;
				while (exchPtr->pLeftChild != NULL) 
                {
					exchPtr = exchPtr->pLeftChild;
				}
				root->key = exchPtr->key;
                root->level = exchPtr->level;
				root->pRightChild = removeAVL(root->pRightChild, exchPtr, shorter, success);
				if (shorter) root = deleteRightBalance(root, shorter);
			}
		}
        return root;
	}
// -------------------------------------------------------------------------
// int getLevelUtil(KnightTree  *root,
//                  int monsterLevel, int level)
// {
//     if (root == NULL)
//         return 0;
 
//     if (level == monsterLevel)
//         {
//             root =
//         }
//     int downlevel = getLevelUtil(root->pLeftChild,
//                                  monsterLevel, level+1);
//     if (downlevel != 0)
//         return downlevel;
 
//     downlevel = getLevelUtil(root->pRightChild,
//                              monsterLevel, level+1);
//     return downlevel;
// }
 
// /* Returns level of given data value */
// int getLevel(KnightTree  *root, KnightTree* knight)
// {
//     return getLevelUtil(root,knight,1);
// }
void removeNguaHi(KnightTree*& root, int monsterLevel, int lvl)
{
    if (monsterLevel == 1)
    {
        root = NULL;
    }
    else
    {
        if (root)
        {
            if (lvl+1 == monsterLevel)
            {
                root->pLeftChild = NULL;
                root->pRightChild = NULL;
            }
            removeNguaHi(root->pRightChild, monsterLevel, lvl+1);
            removeNguaHi(root->pLeftChild, monsterLevel, lvl+1);
        }
    }
    // cout << endl;
}
// void *nguaHi(KnightTree* root,KnightTree*temp, int level)
// {
//     if (level == 1)
//     {
//         root = NULL;
//         return root;
//     }
//     else if (level == 2)
//     {
//         root->pRightChild = NULL;
//         root->pLeftChild = NULL;
//         return root;
//     }
//     else
//     {   
//         KnightTree* newKnight = new KnightTree();
//         newKnight->key = root->key;
//         newKnight->level = root->level;
//         cout << getLevel(temp, newKnight) << " ";
//         nguaHi(root->pLeftChild, temp, level);
//         nguaHi(root->pRightChild, temp, level);
//     }
//     return temp;
// }
int countLeaf(KnightTree* root)
{
    if(root == NULL)
    {       
        return 0;
    }
    if(root->pLeftChild == NULL && root->pRightChild==NULL)      
    {
        return 1; 
    }           
    else return countLeaf(root->pLeftChild)
                + countLeaf(root->pRightChild);      
}

int  getRingsignCount(ringsignList* ringsign)
{
    if (ringsign == NULL)
    {
        return 0;
    }
    ringsignList* pre = ringsign;
    int count = 0;
    while(pre)
    {
        count++;
        pre = pre->pNext;
    }
    return count;
}
bool isTheSame(KnightTree* listNRL, ringsignList*  ringsign)
{
    if (ringsign == NULL)
    {
        return false;
    }
    int listCount = getCount(listNRL);
    int ringsignCount = getRingsignCount(ringsign);
    if (listCount != ringsignCount)
    {
        return false;
    }
    while (listNRL && ringsign) 
    {
        if (listNRL->level != ringsign->nRingsign)
        {
            return false;
        }
        listNRL = listNRL->pRightChild;
        ringsign  =  ringsign->pNext;
    }
    return true;
}
void setZeroLevel(KnightTree*& root)
{
    KnightTree *pre;
    KnightTree* temp = root;
	while(temp)
    {
		if( temp->pRightChild == NULL ){
			// cout<< root->key << " ";
            temp->level = 0;
			temp = temp->pLeftChild;
		}
		else{
			pre = temp->pRightChild;
			while(pre->pLeftChild && pre->pLeftChild != temp ){
				pre = pre->pLeftChild;
			}
			if( pre->pLeftChild == NULL ){
				pre->pLeftChild = temp;
                temp->level = 0;
				// cout<< temp->key << " ";
				temp = temp->pRightChild;
			}
			else{
				pre->pLeftChild = NULL;
				temp = temp->pLeftChild;
			}
		}
	}
}
void insertListNRL(KnightTree*&root, KnightTree* node)
{
    if (root == NULL)
        {
            KnightTree* newKnight = new KnightTree();
            newKnight->key = node->key;
            newKnight->level = node->level;
            root = newKnight;
            return;
        }
    insertListNRL(root->pRightChild,node ); 
        
}
void insertNRL(KnightTree* root, KnightTree*& listNRL)
{
    KnightTree *pre;
    KnightTree* temp = root;
	while(temp)
    {
		if( temp->pRightChild == NULL ){
			// cout<< temp->key << " ";
            insertListNRL(listNRL, temp);
			temp = temp->pLeftChild;
		}
		else{
			pre = temp->pRightChild;
			while(pre->pLeftChild && pre->pLeftChild != temp ){
				pre = pre->pLeftChild;
			}
			if( pre->pLeftChild == NULL ){
				pre->pLeftChild = temp;
                insertListNRL(listNRL, temp);

				// cout<< temp->key << " ";
				temp = temp->pRightChild;
			}
			else{
				pre->pLeftChild = NULL;
				temp = temp->pLeftChild;
			}
		}
	} 
}
KnightTree*  siege(eventList* pEvent,ringsignList* pSarumanList)
{
	KnightTree* pTree = NULL; 
	//let's save the lady
	
	while(pEvent != NULL)
	{
		int code;
		if (pEvent->nEventCode == 5)
		{
			code = 5;
		}
		else if (pEvent->nEventCode < 0)
		{
			code = -1;
		}
		else if (pEvent->nEventCode >= 10000 && pEvent->nEventCode <= 19999) 
		{
			code = 1;
		}
		else  
		{
			code = pEvent->nEventCode / 1000;
		}

	switch (code) 
	{
		case 1:
		{
            int knightKey = (pEvent->nEventCode % 10000) / 10;
            int knightLevel = (pEvent->nEventCode % 10000) % 10;

                
            KnightTree *knight = new KnightTree();
            knight->key = knightKey;
            knight->level = knightLevel;
            insertKnight(pTree, knight);
        }
			break;
		case 2:
		{
			// Find knight who has knight's key nearest eventKey
				// min = |ABC - XYZ|
				// if more than 2 knight, chose the knight has smaller key.

				// increase chosen knight's level (max lvl = 9)

			if (pTree)
			{
				int eventKey = pEvent->nEventCode % 1000;
				increaseNearestLevel(pTree, eventKey);

			}


		}
			break;
		case 3: 
            {
                if (pTree)
                {
                    int eventKey = pEvent->nEventCode % 1000;
                    KnightTree  * meetGaladriel = findNearestKnight(pTree, eventKey);
                    meetGaladriel->level = 9;
                }
            }
			break;
		case -1:
				
				//if (tree != NULL)
					// find the kinght who has key nearest eventKey
					// if (knight's key = 777 && knight's lvl = monster's lvl)
						//pass
					// else if (monster's key = 777 && countLeaf = lvl's monster)
						// remove all kight that has the depth >= monster's lvl
					// else if momnster's key = 888
						// while monster's lvl > knight's lvl && tree != NULL
								// fight
					// else
						// if the knight's lvl >= monster's lvl 
							//knight wins
							//
						// else
							// knight loses
							// remove (kight)
								// (use in-order successor)
				if (pTree != NULL)
				{
					int monsterLevel = -(pEvent->nEventCode) % 10;
					int monsterKey = -(pEvent->nEventCode) / 10;
					if (pTree->key == 777 && pTree->level == monsterLevel)
					{
						break;
					}
					else if(monsterKey == 777)
					{
                        
                        if (countLeaf(pTree) == monsterLevel)
                        {
                            removeNguaHi(pTree, monsterLevel, 1);
                            
                        }
                        else
                        {
                            KnightTree* closest = findNearestKnight(pTree, monsterKey);
                            if (closest->level < monsterLevel)
                            {
                                // cout << "Delete\n";
                                // cout << closest->key<<endl;
                                if (avl)
                                {
                                    if (closest->key != 999)
                                    {
                                        bool shorter = false;
                                        bool success = false;
                                        pTree = removeAVL(pTree, closest, shorter, success);
                                    }
                                    else 
                                    {
                                        avl = false;
                                        int t =0;
                                        pTree = deleteKnight(pTree, closest, t);  
                                    }
                                }
                                else 
                                {
                                    int t =0;
                                    pTree = deleteKnight(pTree, closest, t);
                                }
                
                            }
                        }
                        if (!pTree)
                            {
                                return NULL;
                            }
                    }
					else if (monsterKey == 888)
					{
						pTree = fightToDie(pTree, monsterLevel);
                        if (!pTree)
                        {
                            return NULL;
                        }
					}
					else 
					{
						KnightTree* closest = findNearestKnight(pTree, monsterKey);
						if (closest->level < monsterLevel)
						{
							// cout << "Delete\n";
							// cout << closest->key<<endl;
                            if (avl)
                            {
                                if (closest->key != 999)
                                {
                                    bool shorter = false;
                                    bool success = false;
                                    pTree = removeAVL(pTree, closest, shorter, success);
                                }
                                else 
                                {
                                    avl = false;
                                    int t =0;
                                    pTree = deleteKnight(pTree, closest, t);  
                                }
                            }
                            else 
                            {
                                int t =0;
                                pTree = deleteKnight(pTree, closest, t);
                            }
							if (!pTree)
							{
								return NULL;
							}
						}
					}

				}
				
			
			break;
		case 5: 

            KnightTree *listNRL =  new KnightTree();
            listNRL->key = 0;
            listNRL->level = 0;
            insertNRL(pTree, listNRL);
            listNRL = listNRL->pRightChild;
            if (isTheSame(listNRL,pSarumanList))
            {
                setZeroLevel(pTree);
            }
            
		    break;
	}

		pEvent = pEvent->pNext;
	}
    
	return pTree;
}



//your code should be before that directive