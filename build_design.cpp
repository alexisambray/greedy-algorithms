// Alexis Sofia Ambray
// CSALGCM - N01
// P3: Building Designing

#include <algorithm>  // For using sort function.
#include <cstdlib>    // For using absolute function.
#include <iostream>
#include <string>
#include <vector>
// Above are the libraries that has been used.

using namespace std;

class Building_Designing {
 public:
  // Function starts here
  void design(vector<int>& input) {
    int n = input.size();  // Size of the input array
    vector<pair<int, int>> floors;
    // vector or pairs it will store the size of floor as well as its colour
    // if 1 then colour is Blue & if -1 then the colour is Red
    for (int i = 0; i < n; i++) {
      if (input[i] >
          0) {  // if ith floor is positive it means it is Blue coloured
        floors.push_back({input[i], 1});  // so push/store the pair of size & 1
      } else if (input[i] <
                 0) {  // if ith floor is negative it means it is Red coloured
        floors.push_back(
            {abs(input[i]),
             -1});  // so we push/store the pair of absolute size & -1
      }
    }
    sort(floors.rbegin(), floors.rend());
    // Sorting the floors vector in Descending Order

    int k = 0;
    // Number of valid floors
    // It will be incremented if the valid floor is found
    // Valid floor condition is if the size of previous floor is greater than
    // the current floor and it is of opposite colour, then the condition
    // satisfied and k will be incremented.

    int prev = 0;
    // to check whether the previous floor is red or blue because the next floor
    // should be of opposite colour if prev = 0 means no floor yet means the
    // starting condition. prev = 1 means the previous floor was Blue & prev =
    // -1 means the previous floor was Red

    int floor_size = 0;
    // to store the previous floor size because the size of next floor should be
    // less than the previous one it is very important to store the previous
    // floor size.

    for (int i = 0; i < n; i++) {
      if (prev == 0) {  // starting condition will be at index i=0 only
        if (floors[i].second ==
            1) {  // if current element i.e. the max size of floor is Blue then
                  // this will satisfy if true
          prev = 1;  // prev will be initialized as 1 (i.e. Blue)
          floor_size =
              floors[i].first;  // floor_size is updated to the val of current
                                // size to be used to check next element
          k++;                  // incrememented because floor is added.
        } else if (floors[i].second ==
                   -1) {  // if all else fails (i.e. max floor is Red)
          prev = -1;      // prev will be initialized as -1 (i.e. Blue)
          floor_size =
              floors[i]
                  .first;  // floor_size is updated to the val of current size
          k++;             // floor is added
        }
      } else if (prev == 1) {  // prev element was Blue
        if (floors[i].second == -1 && floor_size > floors[i].first) {
          // if current floor is Red & its size is less than the prev floor size
          // then condition is True
          prev = -1;
          floor_size = floors[i].first;
          k++;
        }
      } else if (prev == -1) {  // prev element was Red
        if (floors[i].second == 1 && floor_size > floors[i].first) {
          // if current floor is Blue & its size is less than prev floor size
          // then condition is True
          prev = 1;
          floor_size = floors[i].first;
          k++;
        }
      }
    }
    cout << k << endl;
  }
};

int main() {
  int n;
  cin >> n;
  // Taking input of num of avail floors
  vector<int> input;
  while (n--) {
    int floor_size;
    cin >> floor_size;
    input.push_back(floor_size);
  }
  Building_Designing ob;
  ob.design(input);
  return 0;
}
