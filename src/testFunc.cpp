#include "defs.h"
#include <cmath>
#include <cstdint>
void display(KnightTree* pTree, int n)
{
	cout.flush();
	if (pTree)
	{ 
		cout << setw(3) << setfill('0') << pTree->key;
		cout << pTree->level << " "; 
		display(pTree->pLeftChild,++n);
		display(pTree->pRightChild,++n);
	}	
}
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
    while(checkDuplicate(root, key))
    {
        key++;
        if (key == 777 || key == 888)
        {
            key++;
        }
    }
        
}
// add new knight into new tree with root = 777
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
        normalInsert(node, root->pRightChild); 
    }
    if (root->key > node->key)
    {
       normalInsert(node,root->pLeftChild);
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
    // KnightTree * pre;

    // while (root) 
    // {
    //     if (root->pLeftChild == NULL)
    //     {
    //         addRoot777(root, newKnight777);
    //         // Inorder(newKnight777);
    //         // cout << root->key  << " ";
            
    //         root = root->pRightChild;
        
    //     }
    //     else 
    //     {
    //         pre = root->pLeftChild;
    //         while (pre->pRightChild && pre->pRightChild != root)
    //         {
    //             pre = pre->pRightChild;
    //         }
    //         if (pre->pRightChild == NULL)
    //         {
    //             pre->pRightChild = root;
    //             // cout << root->key << " ";
    //             addRoot777(root, newKnight777);
   
    //             root = root->pLeftChild;
    //         }
    //         else 
    //         {
    //             pre->pRightChild = NULL;
    //             // addRoot777(root, newKnight777);
    //             root = root->pRightChild;
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



void addKnight(KnightTree*& knightTree, int key, int lvl)
{

    if (knightTree == NULL)
    {
        KnightTree *newKnight = new KnightTree();
        newKnight->key = key;
        newKnight->level = lvl;
        newKnight->balance = 0;
        newKnight->pLeftChild = NULL;
        newKnight->pRightChild = NULL;
        knightTree = newKnight;
        return;
    }
    else 
    {

        if (!checkDuplicate(knightTree,key))
        {
            if (key != 777)
            {
                if (key > knightTree->key)
                {
                    addKnight(knightTree->pRightChild, key, lvl);
                }
                else if (key < knightTree->key)
                {
                    addKnight(knightTree->pLeftChild, key, lvl);
                }
            }

            else 
            {
                KnightTree *newKnight = new KnightTree();
                newKnight->key = 777;
                newKnight->level = lvl;
                newKnight->pRightChild = NULL;
                newKnight->pLeftChild = NULL;
                insertNLR(knightTree, newKnight);
                knightTree = newKnight;
                
            }
        }
        else 
        {
            increaseKey(knightTree, key);
            if (key != 999)
            {
                addKnight(knightTree, key, lvl);
            }
            else return;
        }
    }
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

int countleaf(KnightTree* root)
{
    if(root == NULL)
    {       
        return 0;
    }
    if(root->pLeftChild == NULL && root->pRightChild==NULL)      
    {
        return 1; 
    }           
    else return countleaf(root->pLeftChild)
                + countleaf(root->pRightChild);      
}
int getLevelUtil(KnightTree*root,
                 KnightTree* knight, int level)
{
    if (root == NULL)
        return 0;
 
    if (root->key == knight->key)
        return level;
 
    int downlevel = getLevelUtil(root->pLeftChild,
                                 knight, level+1);
    if (downlevel != 0)
        return downlevel;
 
    downlevel = getLevelUtil(root->pRightChild,
                             knight, level+1);
    return downlevel;
}
 
/* Returns level of given data value */
int getLevel(KnightTree* root, KnightTree* knight)
{
    return getLevelUtil(root,knight,1);
}
void removeFromHeighValue(KnightTree*&root, int height)
{
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
    int h = getHeight(root);
    int c = getCount(root);
    return c == (pow(2,h) -1);
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
KnightTree *fightToDie(KnightTree*root, int lvl )
{
    if (root->level >= lvl)
    {
        return root;
    }
    else
    {
        if (root->pLeftChild == NULL && root->pRightChild == NULL)
        {
            return NULL;
        }
        while (root)
        {
            KnightTree* closest = new KnightTree();
            if (root->pLeftChild == NULL && root->pRightChild == NULL)
            {
                closest = root;
                // system("clear");
                // cout << closest->key << "Root \n";
                // cout << closest->level << "\n";
                if (closest->level < lvl)
                {
                    // cout << "die";
                    return NULL;
                }
                else 
                {
                    break;
                }
            }
            else
            {
                closest = findNearestKnight(root, 888);
                // system("clear");
                // cout << closest->key << "\n";
                // cout << closest->level << "\n";
                if (closest->level < lvl)
                {
                    int t = 0;
                    root = deleteKnight(root, closest, t);
                }
                else 
                {
                    break;
                }
            }
           
            
        }
    }
    return root;
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
void insertRNL(KnightTree* root, KnightTree *& fangorn)
{        
    KnightTree * pre;

    while (root) 
    {
        if (root->pRightChild == NULL)
        {
            bool taller = 1;
            insertAVL(fangorn, root, taller);
            
            // cout << root->key  << " ";
            root = root->pLeftChild;
        
        }
        else 
        {
            pre = root->pRightChild;
            while (pre->pLeftChild && pre->pLeftChild != root)
            {
                pre = pre->pLeftChild;
            }
            if (pre->pLeftChild == NULL)
            {
                pre->pLeftChild = root;
                root = root->pRightChild;
            }
            else 
            {
                pre->pLeftChild = NULL;
                bool taller = 1;
                insertAVL(fangorn, root, taller);
                // cout << root->key << " ";

                root = root->pLeftChild;
            }
        }
    }

}
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
			if (shorter)root = deleteRightBalance(root, shorter);
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
void turnIntoAVL(KnightTree*root, KnightTree*&avl_bst, int count)
{
    if (count == 1)
    {
        return;
    }
    else if (count == 2)
    {
        bool taller = 1;
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
        for (int i = 0; i < count-1; i++ )
        {
            bool taller = 1;
            insertAVL(avl_bst, pre, taller);
            pre = pre->pRightChild;
        }
        pre = pre->pRightChild->pRightChild;
        while(pre)
        {
            bool taller = 1;
            insertAVL(avl_bst, pre, taller);
            pre = pre->pRightChild;
        }
    }
}
void insertKnight(KnightTree*& root, KnightTree *knight)
{
    if (!checkDuplicate(root, knight->key))
    {
        if (knight->key == 777)
        {
            if (!checkAVL(root))
            {
                insertNLR(root, knight);
                root = knight;
            }
            else
            {
                insertNLR_AVL(root, knight);
                root = knight;
            }
            
        }
        else if (knight->key == 999) //turn into AVL
        {
            insertRNL(root, knight);
            root = knight;
        }
        else if (knight->key == 888) //turn into AVL-BSL
        {
            normalInsert(root, knight);
            KnightTree* min = findMin(root);
            KnightTree* newLNR = new KnightTree();
            newLNR->key = min->key;
            newLNR->level = min->level;
            int t = 1;
            root = deleteKnight(root, min, t);
            insertLNR_AVL(root, newLNR);
            root = newLNR;
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
                normalInsert(root, knight);
            }
        }
        else //normal insert
        {
            normalInsert(root, knight);
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
int main()
{

    KnightTree *root = new KnightTree();
    root->key = 123;
    root->level =1;
    root->balance = 0;
    root->pRightChild = NULL;
    root->pLeftChild = NULL;

    // KnightTree* new1 =  createKnight(456,  5);
    
    // root->pLeftChild = new1;
    // KnightTree* new2 =  createKnight(998,  5);
    // root->pRightChild = new2;

    // addRoot777(new1, root);
    // addRoot777(new2, root);

    addKnight(root, 234, 5);
    KnightTree*fangorn = new KnightTree();
    fangorn->key = 999;
    fangorn->level = 4;
    fangorn->balance = 0;
    fangorn->pRightChild = NULL;
    fangorn->pLeftChild = NULL;
    // addKnight(root, 999, 4);
    addKnight(root, 724, 5);
    addKnight(root, 444, 3);
    addKnight(root, 723, 4); 

    // addKnight(root, 777, 5);
    // addKnight(root, 823, 2);

    // cout << checkDuplicate(root, 4);
    // int a = 998; 
    // increaseKey(root, a);
    // cout << a;
    // increaseNearestLevel(root, 333);
    int t = 1;
    // deleteKight( root, 300, t);
    //    root =  fightToDie(root, 6);
    // findNearestKnight(root, 723);
    // int t =0;
    // KnightTree*closest = findNearestKnight(root, 123);
    // root = deleteKight(root, closest, t);
    KnightTree*knight = new KnightTree();
    knight->key = 444;
    knight->level =3;


    // bool shorter = false;
    // bool success = false;
    // insertRNL(root, fangorn);
    // fangorn = removeAVL(fangorn, knight, shorter,  success);
    // while(fangorn)
    // {
    //     cout << fangorn->key << " " <<fangorn->level << "\n";
    //     fangorn = fangorn->pLeftChild;
    // }
    // cout << checkAVL(fangorn);
    // root = fangorn;
    // KnightTree* min = findMin(root);
    // KnightTree* newLNR = new KnightTree();
    // newLNR->key = min->key;
    // newLNR->level = min->level;
    // root = deleteKnight(root, min, t);
    // insertLNR_AVL(root, newLNR);
    cout << getLevel(root, knight) << " ";
    display(root,0);
    // cout << endl;
    // cout << getCount(root);
    // cout << isCompleteTree(root);
    // cout << countleaf(root);
    // cout << getHeight(root);
        delete (root);
        delete (fangorn);
        // delete(min);
        // delete(newLNR);
    // delete (new1);
    // delete (new2);
    
}