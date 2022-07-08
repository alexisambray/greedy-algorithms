// Alexis Sofia Ambray
// CSALGCM - N01
// P3: Naughty Student

#include <algorithm>  //For using sort function.
#include <cmath>      //For using min/max function.
#include <cstdlib>    //For using absolute function.
#include <iostream>
#include <string>
#include <vector>

// Above are the libraries that has been used.

using namespace std;

class Naughty_Student {
 public:
  // Function starts here
  void Answer(string input, int k) {
    vector<char> st;  // To store elements after erase

    int flag = 0;
    // This plays the big role as it check if 0 will come up
    // if the next elements are smaller than min element among the
    // prev elements of 0 then the erased elements are not correct.

    int mn = INT_MAX;  // stores the min element till now.

    st.push_back('0');  // add one element so we can use the 0th
                        // index if needed
    for (int i = 0; i < input.size(); i++) {
      char ch = input[i];  // ch is the ith index char in input string
      if (flag == 0) {     // This condition is true till previous element is 0
                           // and we have k in our hand.
        // If any of the conditions like
        // 1) st vector is empty or
        // 2) k = 0 or
        // 3) the last element in st is less than ith index character in
        // input string then this while loop will not run
        while (st.size() != 0 && k != 0 && st[st.size() - 1] > ch) {
          k--;  // k decreases because we are erasing elements
          st.pop_back();
        }
        if (ch != '0') {  // If ch is not 0 then this conditions is true
          mn = min(mn, ch - '0');  // checks for min elements because we
                                   // want min possible value after erasing
        } else if (k != 0) {       // If ch = 0 and we have k in hand
          k++;  // k is incremented because we have erased one element which
                // should not be deleted so we write it again
          char ad = (char)(mn + '0');
          st[0] = ad;  // Storing the minimum element at 0th index thats why 0
                       // is stored before for loop
          flag = 1;    // flag turned 0
        }
      } else {  // when flag is not 0

        int dig = ch - '0';
        if (st.size() != 0 && k != 0) {
          flag = 0;
        }
        if (mn > dig &&
            k - st.size() >= 0) {  // If current element is less than the
                                   // min element till now then the elements
                                   // stored till now are not correct
          k -= st.size();
          st.clear();
          flag = 0;
        }
      }
      st.push_back(ch);
    }
    while (k != 0) {  // If it is still k then just remove the last elements
      st.pop_back();
      k--;
    }
    string ans = "";
    int iflag = 0;

    for (int i = 0; i < st.size(); i++) {
      if (st[i] == '0' && iflag == 0)  // If there are any leading 0 then we
                                       // leave that element and move to next
        continue;                      // lines below will not be execued.
      iflag = 1;  // If this part executes, then leading 0s are ignored
      ans += st[i];
      // append the correct min possible value after erasing
    }

    if (ans.size() == 0)
      cout << "0" << endl;
    cout << ans << endl;
  }
};

int main() {
  int n, k;
  cin >> n >> k;
  string input;
  cin >> input;
  Naughty_Student ob;
  ob.Answer(input, k);
  return 0;
}
