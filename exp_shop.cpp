// Alexis Sofia Ambray
// CSALGCM - N01
// P3: Exploiting Shopping Discount

#include <algorithm>  //For using sort function.
#include <iostream>
#include <string>
#include <vector>
// Above are the libraries that has been used.

using namespace std;

class Exploiting_Shopping_Discount {
 public:
  // Function starts here
  void max_discount(vector<int>& input) {
    int n = input.size();  // Size of the input array
    sort(input.rbegin(),
         input.rend());  // Sorting the input vector in Descending Order
    int maximum_discount =
        0;  // To store the total of discount Lindsay can get initially = 0
    // To get the max discount Lindsay should go with the top 3 costlier
    // process continues until she is left with 2 or less
    // take the costlier ones she can get the discount on the cheapest among the
    // costliest this will help her get the max discount
    for (int i = 2; i < input.size(); i = i + 3) {
      // starting from the second index
      // and jumping to the next third element
      maximum_discount += input[i];  // adds the Third element (discounted item
                                     // price) to the maximum_discount
    }
    cout << maximum_discount << endl;
  }
};

int main() {
  int n;
  cin >> n;
  vector<int> input;
  while (n--) {
    int Price;
    cin >> Price;
    input.push_back(Price);
  }
  Exploiting_Shopping_Discount ob;
  ob.max_discount(input);
}
