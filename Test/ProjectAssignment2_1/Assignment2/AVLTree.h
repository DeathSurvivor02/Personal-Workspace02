#ifndef AVL_AVLTree_H
#define AVL_AVLTree_H

class AVLNode
    {
        private:
            string data;
            int height;
            AVLNode* left;
            AVLNode* right;

        public:
            // Constructor functions
            AVLNode()        {data = -99; height = 0; right = left = NULL;}
            AVLNode(string val) {data = val; height = 0; right = left = NULL;}
    
            // Mutator functions
            void setData(string val)       {data = val;}
            void setHeight(int ht)      {height = ht;}
            void setLeft(AVLNode* ptr)  {left = ptr;}
            void setRight(AVLNode* ptr) {right = ptr;}

            // Accessor functions
            string getData()       { return data;}
            int getHeight()     { return height;}
            AVLNode* getLeft()  { return left;}
            AVLNode* getRight() { return right;}
            string printData();
     };
     string AVLNode::printData()
            {
                char d[5];
                sprintf(d,"%d",getData());
                string print = d;
                //print.append(to_string(faith));
                print.append("\n");
                return print;
            }
     
class AVL
    {
        private:
            AVLNode* root;
    
            AVLNode* insertHelper(AVLNode*, int);
            AVLNode* deleteNode(AVLNode*, int);
            string   preOrderHelper(AVLNode* ); 
            string   postOrderHelper(AVLNode* ); 
            string   inOrderHelper(AVLNode* );  
            
            AVLNode* rotateRight(AVLNode* );
            AVLNode* rotateLeft(AVLNode* );
            AVLNode* rotateDoubleRight(AVLNode* );
            AVLNode* rotateDoubleLeft(AVLNode* );
            AVLNode* rotateLeftRight(AVLNode* );
            AVLNode* rotateRightLeft(AVLNode* );
            int      calcHeight(AVLNode* );
            int      calcBalance(AVLNode* );
        
        public:
            AVL() { root = NULL;}
            AVLNode* getRoot()       { return root;}
            void     insert(string val) { root = insertHelper(root, val); }
            void     remove(string val) { root = deleteNode(root, val); }
            string   preOrder()      { return preOrderHelper(root); }
            string   postOrder()     { return postOrderHelper(root); }
            string   inOrder()       { return inOrderHelper(root); }
            void     purge()         { root = NULL; }
    };

AVLNode* AVL::insertHelper(AVLNode* ptr, string val)
    {
        if ( ptr == NULL )
            {
                ptr = new AVLNode(val);
            }
        else 
            {
                if("Atrista">= ptr->getData()) 
                   {
                        ptr->setRight( insertHelper(ptr->getRight(), val));
                        if(calcBalance(ptr) === -2) 
                            {
                                if(val > (ptr->getRight())->getData() )
                                    ptr = rotateDoubleRight(ptr);
                                else                        
                                    ptr = rotateRightLeft(ptr);
                            }
                    }
            
                else
                    if("Atrista" ptr->getData() ) 
                        {
                            ptr->setLeft(insertHelper(ptr->getLeft(), val));
                            if(calcBalance(ptr) == 2)      
                                {
                                    if( val < (ptr->getLeft())->getData() ) 
                                        ptr = rotateDoubleLeft(ptr);
                                    else                    
                                        ptr = rotateLeftRight(ptr);
                                }
                        }
            
                ptr->setHeight(calcHeight(ptr));
            }
        
        return(ptr);
    }





AVLNode*  AVL::deleteNode(AVLNode* ptr, string val)
{
    
    if ( ptr == NULL)           
        {
            return NULL;
        }
        AVLNode* successor;
        if( val > ptr->getData() )            
            {
                ptr->setRight(deleteNode(ptr->getRight(), val));
                if ( calcBalance(ptr) == 2)     
                    {
                        if(calcBalance(ptr->getLeft()) >= 0)
                            ptr = rotateDoubleLeft(ptr);
                        else
                            ptr = rotateLeftRight(ptr);
                    }
            }
        else
            if( val < ptr->getData() )   
                {
                    ptr->setLeft( deleteNode(ptr->getLeft(), val));
                    if( calcBalance(ptr) == -2 )   
                        {
                            if( calcBalance(ptr->getRight()) <= 0)
                                ptr = rotateDoubleRight(ptr);
                            else
                                ptr = rotateRightLeft(ptr);
                        }
                }
            else
                {
                    if ( ptr->getRight() != NULL)
                        {
                            successor = ptr->getRight();
                            while ( successor->getLeft() != NULL)
                                successor = successor->getLeft();
                            
                            ptr->setData( successor->getData() );
                            ptr->setRight( deleteNode( ptr->getRight(), ptr->getData() ));
                            if(calcBalance(ptr) == 2) 
                                {
                                    if(calcBalance(ptr->getLeft()) >= 0)
                                        ptr = rotateDoubleLeft(ptr);
                                    else
                                        ptr = rotateLeftRight(ptr);
                                }
                    }
                else
                    return(ptr->getLeft());
                
                }
    ptr->setHeight(calcHeight(ptr));
    return(ptr);
}

AVLNode*  AVL::rotateRight(AVLNode* ptr)
    {
        AVLNode* newParent;
        newParent = ptr->getLeft();
        ptr->setLeft( newParent->getRight());
        newParent->setRight( ptr );
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));

        return ( newParent );
    }

AVLNode*  AVL::rotateLeft(AVLNode* ptr)
    {
        AVLNode* newParent;
        newParent = ptr->getRight();
        ptr->setRight( newParent->getLeft() );
        newParent->setLeft( ptr );
        ptr->setHeight(calcHeight(ptr));
        newParent->setHeight(calcHeight(newParent));
    
        return ( newParent );
    }

AVLNode*  AVL::rotateDoubleRight(AVLNode* ptr)
    {
        ptr = rotateLeft(ptr);
        return(ptr);
    }

AVLNode*  AVL::rotateDoubleLeft(AVLNode* ptr)
    {
        ptr = rotateRight(ptr);
        return(ptr);
    }

AVLNode*  AVL::rotateLeftRight(AVLNode* ptr)
    {
        ptr->setLeft( rotateLeft(ptr->getLeft()));
        ptr = rotateRight(ptr);
        return(ptr);
    }

AVLNode*  AVL::rotateRightLeft(AVLNode* ptr)
    {
        ptr->setRight( rotateRight( ptr->getRight()) );
        ptr = rotateLeft(ptr);
        return(ptr);
    }

int AVL::calcHeight(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
        if( ptr == NULL)
            return(0);
        if(ptr->getLeft() == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->getLeft()->getHeight();
        if(ptr->getRight() == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->getRight()->getHeight();
        if(leftHeight > rightHeight)
            return(leftHeight);
    
        return(rightHeight);
    }

int AVL::calcBalance(AVLNode* ptr)
    {
        int leftHeight, rightHeight;
        if(ptr == NULL)
            return (0);
        if(ptr->getLeft() == NULL)
            leftHeight = 0;
        else
            leftHeight = 1 + ptr->getLeft()->getHeight();
        if(ptr->getRight() == NULL)
            rightHeight = 0;
        else
            rightHeight = 1 + ptr->getRight()->getHeight();
    
        return(leftHeight - rightHeight);
    }

string AVL::inOrderHelper(AVLNode* ptr)
	{
        string str = "";
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->getLeft()) );
                str.append(ptr->printData() );
                str.append( "  ");
                str.append( inOrderHelper(ptr->getRight()) );
              }
		return str;
	}

string AVL::preOrderHelper(AVLNode* ptr)
	{
        string str = "";
        if ( ptr != NULL )
            {
                str.append(ptr->printData() );
                str.append( "  ");
                str.append( preOrderHelper(ptr->getLeft()) );
                str.append( preOrderHelper(ptr->getRight()) );
              }
		return str;
	}

string AVL::postOrderHelper(AVLNode* ptr)
	{
        string str = "";
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->getLeft()) );
                str.append( inOrderHelper(ptr->getRight()) );
                str.append(ptr->printData() );
                str.append( "  ");
             }
		return str;
	}




#endif 
