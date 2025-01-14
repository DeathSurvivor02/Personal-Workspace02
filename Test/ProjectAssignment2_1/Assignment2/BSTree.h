#ifndef BST_BSTree_h
#define BST_BSTree_h


class BSTNode
    {
        private:
            string data;
            BSTNode* left;
            BSTNode* right;
            ;
        public:
            // Constructor functions
            BSTNode(){right = left = NULL; data = -99;}
            BSTNode(string val){data = val; right = left = NULL;}
    
            // Accessor functions
            BSTNode* getLeft()  {return left;};
            BSTNode* getRight() {return right;}
            string getData()       
            {
                
                return data;
                
            }
            
            
            // Mutator functions
            void setData(string val)       {data = val;}
            void setLeft(BSTNode* ptr)  {left = ptr;}
            void setRight(BSTNode* ptr) {right = ptr;}
            void copyData(BSTNode*);
            string printData();
     };


void BSTNode::copyData(BSTNode* ptr)
    {
        data = ptr->getData();
    }
    string BSTNode::printData()
            {
                char d[5];
                sprintf(d,"%d",getData());
                string print = d;
                //print.append(to_string(faith));
                print.append("\n");
                return print;
            }

class BST
    {
        private:
            BSTNode* root;         
            BSTNode* insertHelper(BSTNode*, string);
            BSTNode* deleteNode(BSTNode*, string);
            BSTNode* deleteHelper(BSTNode*, string);
    
            string preOrderHelper(BSTNode* );
    
            string postOrderHelper(BSTNode* );

            string inOrderHelper(BSTNode* );
    
        public:
            //  Constructor function
            BST() { root = NULL;}
    
            // Mutator functions
            void purge()         { root = NULL;}
            void insert(string val) { root = insertHelper(root, val); }
            void remove(string val) { root = deleteHelper(root, val);}
        
            // Accessor functions
            BSTNode* getRoot() { return root;}
            string preOrder()  { return preOrderHelper(root); }
            string postOrder() { return postOrderHelper(root); }
            string inOrder()   { return inOrderHelper(root); }
    
    };

BSTNode* BST::insertHelper(BSTNode* ptr, string val)
    {
        if ( ptr == NULL )   
            {
                ptr = new BSTNode(val);
            }
        else       
            {
                if (val >= ptr->getData()) 
                    ptr->setRight(insertHelper(ptr->getRight(), val));
                else 
                    ptr->setLeft(insertHelper(ptr->getLeft(), val));
            }
        return ptr;
    }

BSTNode* BST::deleteHelper(BSTNode* ptr, string val)
    {
        if (ptr == NULL)
            {
                return NULL;
            }
        
        BSTNode* successor;

        if (val > ptr->getData())                              
            ptr->setRight(deleteHelper(ptr->getRight(), val));
        
        else if (val < ptr->getData())                           
                ptr->setLeft(deleteHelper(ptr->getLeft(), val));
        
            else   
                {
                    if (ptr->getRight() !=  NULL)
                        {  
                            successor = ptr->getRight();   
                            while ( successor->getLeft() != NULL )       
                                successor = successor->getLeft();
                           
                           
                           ptr->copyData( successor );

                           ptr->setRight(deleteHelper( ptr->getRight(), ptr->getData() ));
                       }
                   else
                       if (ptr->getLeft() !=  NULL)        
                           {
                               ptr->copyData(ptr->getLeft());
                               ptr->setLeft(deleteHelper( ptr->getLeft(), ptr->getData() ));
                               return ptr;
                           }
                       else                     
                           return NULL;
                }
        return ptr;
    }


string BST::inOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( inOrderHelper(ptr->getLeft()) );
            
                str.append( ptr->printData() );
                str.append( "  ");
            
                str.append( inOrderHelper(ptr->getRight()) );
              }
		return str;
	}

string BST::preOrderHelper(BSTNode* ptr)
	{
        string str = "";
		
        if ( ptr != NULL )
            {
                str.append( ptr->printData() );
                str.append( "  ");
            
                str.append( preOrderHelper(ptr->getLeft()) );
                str.append( preOrderHelper(ptr->getRight()) );
              }
		return str;
	}

string BST::postOrderHelper(BSTNode* ptr)
	{
        string str = "";
		if ( ptr != NULL )
            {
                str.append( postOrderHelper(ptr->getLeft()) );
                str.append( postOrderHelper(ptr->getRight()) );
            
                str.append( ptr->printData() );
                str.append( "  ");
             }
		return str;
	}
#endif
