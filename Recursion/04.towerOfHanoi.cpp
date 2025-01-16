#include <iostream>
using namespace std;

 
void towerOfHanoi(int N, char Source_Rod, char Helper_Rod, char Destination_Rod) {
    if (N == 0) {
        return; // Base case: No disks to move
    }
 
    towerOfHanoi(N - 1, Source_Rod, Destination_Rod, Helper_Rod); // STEP - 1
    cout << "Moving Disk " << N << " From ROD " << Source_Rod << " To ROD " << Destination_Rod << endl; // STEP - 2
    towerOfHanoi(N - 1, Helper_Rod, Source_Rod, Destination_Rod); // STEP - 3
}
int main(){
    int n=3;
    
     towerOfHanoi(n, 'A', 'B', 'C');
}