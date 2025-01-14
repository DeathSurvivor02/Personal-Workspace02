#ifndef SET_H
#define SET_H

class Set 
       {
		private:
		vector <int> elements;     
        
	    public: 
	    Set(void); 		      	       
	    Set(int n); 		     
        int getNumElements () const;            
        int getElement (int ) const;        
        bool find (const int ) const;  	      
        void add (const int );
        void remove (const int ); 
        }; 

    Set::Set (void)
        {
            elements.resize(0); 
        } 

    Set::Set (int n)
        {
            elements.resize (0);
            elements.push_back (n); 
        } 

    int Set::getNumElements () const 
        { 
            return elements.size(); 
        } 

    int Set::getElement (int index) const  
        { 
            if (index <= elements.size ( ) ) 
                return elements[index-1]; 
            else 
            {            	
            cout << "Set index is out of range." << endl;   
                    exit (1);     
            } 
        } 

        bool Set:: find (const int  elem ) const 
            {
                for (int x = 0;  x < elements.size( );  x++)      
        if (elements[x] == elem)   
                    return true;
                return false;
            }

        void Set::add (const int elem)
            {   
                if ( find ( elem ) )
                    return;
                else 
            { 
                elements.push_back (elem);          
            } 
                return; 
            } 
        void Set::remove (const int elem)    
            {     
                int x;
        
            for (x = 0; x < elements.size() && elements[x] != elem; x++);

                    if ( x == elements.size()) 	
                    return; 
                    else	         
        for (int y = x; y < elements.size(); y++)
                            { 
                            elements[y] = elements[y+1];         	          
                            }
                    elements.resize( elements.size() -1);
                    return; 
            } 
        void Set::intersect(const Set *setA,  const Set *setB)
            {
                    int x, y;

                elements.resize(0);
                    for (x = 0;  x  <  setA->getNumElements();  x++)
                    for (y = 0;  y  <  setB->getNumElements();  y++)
                        {
                                if ( setA->elements[x] == setB->elements[y] )
                                {
                                elements.push_back ( setA->elements[x] );
                        }
                            }
            }
        void Set::union(const Set *setA,  const Set *setB)
            {
                    int x, y;
                elements.resize(0);
                elements = setA->elements;    

                for (x = 0;  x < setB->numElements;  x++)
                            if ( SetA->find ( SetB->elements[x])  == false ) )
                        {
                        elements.push_back ( setB->elements[x] );
                    }
            }
            
