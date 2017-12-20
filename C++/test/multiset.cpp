#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;
template <typename T>
class MultiSetWithCount
{
    // map containing one instance and its associated count
    std::map<T, int> d_store;

  public:
    // returns how many times this object was inserted
    int getCount(const T &object)
    {
        auto it = d_store.find(object);
        if (it == d_store.end())
            return 0;
        else
            return it->second;
    }
    // Adds an object
    // If object is new then count starts at 1
    // If object already exists then simply increment count
    void add(const T &object)
    {
        d_store.insert(make_pair(object, 0)).first->second++;
    }
    // Remove an object. The object will be completely removed from the map
    // Returns the number of objects removed
    int remove(const T &object)
    {
        auto it = d_store.find(object);
        int numberOfDeletedObjects = 0;
        if (it != d_store.end())
        {
            pair <T, int> temp = *it;
            numberOfDeletedObjects = temp.second;
        }
        return numberOfDeletedObjects;
    }
    // Returns a vector containing the objects
    // For each object the number of copies to create for the vector
    // corresponds to the count value
    std::vector<T> toVector()
    {
        std::vector<T> v;
        for (auto iterator = d_store.begin(); iterator != d_store.end(); ++iterator)
        {
            int count = iterator->second;
            for (int i = 0; i < count; i++)
            {
                v.push_back(iterator->first);
            }
        }
        return v;
    }
    // prints all values and counts
    void
    print()
    {
        for (auto iterator = d_store.begin(); iterator != d_store.end(); ++iterator)
        {
            std::cout << iterator->first << " " << iterator->second << endl;
        }
        std::cout << std::endl;
    }
};
int main()
{
    MultiSetWithCount<std::string> ms;
    ms.add(std::string("red"));
    ms.add(std::string("red"));
    ms.add(std::string("green"));
    ms.add(std::string("green"));
    ms.add(std::string("blue"));
    ms.add(std::string("green"));
    std::cout << "green count is " << ms.getCount(std::string("green")) << std::endl;
    std::cout << ms.remove(std::string("red"));
    std::cout << std::endl;
    ms.print();
    std::vector<std::string> v = ms.toVector();
    std::cout << "vector size is " << v.size() << std::endl;
    return 0;
}