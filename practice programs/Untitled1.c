#include <iostream>
 #include <string>
 using namespace std;
  int main( )

{
string line;
cout << "entry a string: ";
while (getline(cin, line)){
if (line.size() > 5)
{
cout << line << endl;
}
}
}
