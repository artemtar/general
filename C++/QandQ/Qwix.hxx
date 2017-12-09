#include <assert.h> 
#include <stdio.h>     
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
QwixRow<C, Container>::QwixRow(){
    for(int i = 2; i < 13; ++i){
        row.push_back(i);
    }    
}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
bool QwixRow<C, Container>::validate(int index)
{
    //out of range
    if (index > 12 || index < 2)
        return false;
    //has input already    
    typename Container<int>::iterator it(row.begin());
    std::advance(it, index);
    if(*it <= 2) return false;    
    else
         return true;
}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
int &QwixRow<C, Container>::operator[](int index)
{
    assert(index >= 0 && index < row.size());
    typename Container<int>::iterator it(row.begin());
    std::advance(it, index);
    return *it;
}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
int &QwixRow<C, Container>::operator+=(RollOfDice &) {
int result= 0;
    typename Container<int>::iterator it(row.begin());
    while(it != row.end()){
        result += *it;
        ++it;
    }
    return result;
}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
bool QwixRow<C, Container>::checkAdd(int) {

}
template<ScoreSheet::Color C, 
template<class, class = allocator<int>> class Container>
int QwixRow<C, Container>::calcRow() {
    typename Container<int>::iterator it(row.begin());
   int counter = 0;
    while(it != row.end()){
        if(*it < 0)
        counter += 1;
        ++it;
    }
    return counter;
}

