#ifndef BINHEAP_H
#define BINHEAP_H

class BinHeap
    {
        private:
                vector <int> elements;
        public:
                BinHeap(){elements.resize(1);}              
                void addMinHeap(int);               
                void minHeapify(unsigned int);      
                void deleteMinHeapVal(int);         
                void removeMinRoot();
                string displayHeap();
                string sortMinHeap();
    };

void BinHeap::addMinHeap(int val)
    {
        elements.push_back(val);
        minHeapify(elements.size() - 1);
    }

void BinHeap::minHeapify(unsigned int index)
    {
        unsigned int left, right, minn;
        left = 2*index;
        right = 2*index + 1;
        
        if (index == 0)
            return;
    
        if (left < elements.size() && elements[left] < elements[index])
            minn = left;
        else
            minn = index;
    
        if (right < elements.size() && elements[right] < elements[minn])
            minn = right;
    
        if (minn != index)
            {
                int temp = elements[minn];
                elements[minn] = elements[index];
                elements[index] = temp;
                minHeapify(minn);
            }

        minHeapify(index/2);
    }

void BinHeap::deleteMinHeapVal(int value)
    {
        
        int x = 0;
        
        while ( x <= elements.size() )
            {
                if ( value == elements[x] )
                    {
                        elements[x] = elements[ (elements.size() - 1) ];
                        
                        elements.pop_back();
                        
                        minHeapify(x);              // parent
                        minHeapify((2 * x) +1);     // left child
                        minHeapify((2 * x) +2 );    // right child
                        break;      //No need to search further
                    }
                x++;
            }
    }
    
void BinHeap::removeMinRoot()
    {
    if (elements.size() < 2)
        return;
    else
        {
            elements[1] = elements[elements.size() - 1];
            elements.resize(elements.size() - 1);
            minHeapify(1);
        }
    }
    
string BinHeap::sortMinHeap()
    {
        string str ="";
        
        while (elements.size() > 1)
        {
            str.append(to_string(elements[1]));
            str.append("\n");
            removeMinRoot();
        }
        str.append("\n");
        return str;
    }

string BinHeap::displayHeap()
{
    string str = "";
    for (int x = 1; x < elements.size(); x++)
        {
            str.append(to_string(elements[x]));
            str.append("\t");
        }
    str.append("\n");
    return str;
}
#endif
