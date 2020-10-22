// you can use includes, for example:
 #include <algorithm>
 #include <numeric>
 #include <cstdlib>
 #include <iostream>
 #include <vector>
 #include <iterator>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;
int recursion(std::vector<int> &A, int& i)
{
    if(i > A.size()-1)
        return -1; // none found
    int temp;
    temp = std::accumulate(A.begin(),A.begin()+i,0)-std::accumulate(A.begin()+i+1, A.end(), 0);
    
    if(temp == 0)
        return i;
    return recursion(A,++i);
}

int solution(std::vector<int> &A){
    int i;	// used as an iterator to traverse through list
    i = 0;
    return recursion(A,i); 
}
    
int main(){
    std::vector<int> A {-7, 1, 5, 2, -4, 3, 0};
    std::cout<<solution(A);
}
