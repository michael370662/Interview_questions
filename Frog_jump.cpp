// you can use includes, for example:
 #include <algorithm>
 #include <cstdlib>
 #include <iostream>
 #include <vector>
 #include <iterator>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int D) {
    
    int count;
    count = 0;

    if(A >= B)
        return count;
    count++;
    count = solution(A+D,B,D) + count;
    
    return count;
}

int main(){
        std::cout<<solution(10,85,30);
}
//(O(n))

// you can use includes, for example:
 #include <algorithm>
 #include <cstdlib>
 #include <iostream>
 #include <vector>
 #include <iterator>
// you can write to stdout for debugging purposes, e.g.
// cout << "this is a debug message" << endl;

int solution(int A, int B, int D) {
    
    int count;
    count = 0;

    if(A >= B)
        return count;
    else if((B-A)%D != 0)
        return (B-A)/D+1;
    
    else
        return (B-A)/D;

        
    
}
int main(){
        std::cout<<solution(10,85,30);
}

//O(1)
