#include <iostream>

using namespace std;
class Node
{
    int d_element;

  protected:
    Node *d_neighbour[4]{0, 0, 0, 0};

  public:
    Node(int element) : d_element(element) {}
    Node(const Node &on) : d_element(on.d_element)
    {
        for (int i = 0; i < 4; ++i)
        {
            if (on.d_neighbour[i])
                d_neighbour[i] = new Node(on.d_neighbour[i]->d_element);
        }
    }

    ~Node()
    {
        for (int i = 0; i < 4; ++i)
        {
            delete (d_neighbour + i);
        }
    }

    bool remove()
    {
    }

    bool add(Node &on)
    {
        if (d_neighbour[3] != 0)
            return false;
        d_neighbour[3] = new Node(on);
        return true;
    }

    void rotate()
    {
        Node *tmp(d_neighbour[0]);
        cout << "rot" << endl;
        for (int i = 0; i < 3; ++i)
        {
            d_neighbour[i] = d_neighbour[i + 1];
        }
        d_neighbour[3] = tmp;
        cout << "stop" << endl;
    }

    friend ostream &operator<<(ostream &os, const Node &node)
    {
        os << node.d_element << " " << endl;
        os << "neibours" << endl;
        for (auto nghbPtr : node.d_neighbour)
        {
            if (nghbPtr)
                os << *nghbPtr;
        }
        return os;
    }
    Node &operator=(const Node &n)
    {
        if (this != &n)
        {
            if (d_neighbour[3] != 0)
            {
                for (int i = 0; i < 3; ++i)
                {
                    if (d_neighbour[i])
                        delete d_neighbour[i];
                }
            }
            for (int i = 0; i < 3; ++i)
            {
                d_neighbour[i] = new Node(*n.d_neighbour[i]);
            }
            d_element = n.d_element;
        }
        return *this;
    }
    friend bool operator+=(Node &n1, Node &n2)
    {
        if (n1.d_neighbour[3] != 0)
            return false;
        auto d = n1.d_neighbour[0];
        for(int i = 0; i < 3; ++ i){
            if(n1.d_neighbour[i]) d = n1.d_neighbour[i];
        }
        ++d;
        d = new Node(n2);
        return true;
    }
};
int main() {

  Node nArray[]{ 1,2,3,4,5 };
  // NodeT<int,4> nArray[]{ 1,2,3,4,5 };  


  for (int i=0;i<4;++i) {
    nArray[0].rotate();
    nArray[0].add(nArray[i+1]);
  }
    bool i = nArray[1] += nArray[4];
 //cout << i << endl;
  cout << nArray[0] << endl;
  return 0;
}