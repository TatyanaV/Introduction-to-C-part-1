#include <iostream>  //library for input and output
#include <string>    //library for stings
using namespace std; //global statm


int main()
{
  const int SIZE = 5;
  int array[SIZE];  // at this point, all elements are un-initialized

  // Ask the user for 10 double's
  for (int i = 0; i < SIZE; i++)
  {
    cout << "Enter " << i+1 << " integer: ";
    cin >> array[i];   // ith element receives value
  }

  // Now that all 10 values are in the array, we compute the sum.
  int sum = 0.0;
  for (int i = 0; i < SIZE; i++)
    sum += array[i];

  cout << "The sum of " << SIZE << " integers that you entered is: "<< sum << endl;
  return 0;
}
