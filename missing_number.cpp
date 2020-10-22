// you can use includes, for example:
 #include <algorithm>
 #include <cstdlib>
 #include <iostream>
 #include <vector>
 #include <iterator>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(std::vector<int> &A) {
    std::sort(A.begin(), A.end());
    
    if(A.front() > 1)
        return 1;
    for(auto it = A.begin(); it != A.end(); it++)
    { 
        auto itm = std::next(it,1);
        if(*(itm) != (*it)+1)
            return (*it)+1;
    }
    
    return 0;
}

int main(){
    
    std::vector <int> A = { 4, 7, 6, 5, 1, 3 }; 
    std::cout << solution(A);
    return 0;
}
