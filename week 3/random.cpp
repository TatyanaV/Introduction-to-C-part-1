#include <iostream> // header file
#include <cstdlib> // for pseudorandom numbers
#include <ctime> //allows us to access time
using namespace std;

int main ()
{
    srand(time(0));
    for (int x = 1; x <25; x++)
    {
        cout << 1+ (rand()% 6) << endl;
    }
}
