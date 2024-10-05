#include <iostream>
#include <vector>

using namespace std;

void Gener_sum(int reSum, vector<int>& CurrSum, int MaxVal) {
  if (reSum == 0) {
    for (int i = 0; i < CurrSum.size(); i++) {
      cout << CurrSum[i] << " ";
    }
    cout << endl;
    return;
  }
  for (int i = 1; i <= min(MaxVal, reSum); i++) {
    CurrSum.push_back(i);
    Gener_sum(reSum - i, CurrSum, i);
    CurrSum.pop_back();
  }
}

int main() {
  int sum;
  cin >> sum;
  vector<int> CurrSum;
  Gener_sum(sum, CurrSum, sum);
  return 0;
}
