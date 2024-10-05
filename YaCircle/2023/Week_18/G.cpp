#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
  int m;
  cin >> m;
  vector<string> words(m);
  for (int i = 0; i < m; ++i) {
    cin >> words[i];
  }

  int k;
  cin >> k;
  vector<int> sequence(k);
  for (int i = 0; i < k; ++i) {
    cin >> sequence[i];
    --sequence[i];  // Индексы сдвигаем на 1, чтобы они соответствовали индексам
                    // в массиве слов
  }

  unordered_map<string, int> prefixCount;
  vector<int> dp(
      k,
      1);  // dp[i] - длина максимальной цепочки, заканчивающейся на i-м слове
  int maxLength = 1;
  int maxEndIndex = 0;

  // Заполняем dp и prefixCount
  for (int i = 0; i < k; ++i) {
    string word = words[sequence[i]];
    for (int j = 1; j <= word.size(); ++j) {
      string prefix = word.substr(0, j);
      if (prefixCount.count(prefix)) {
        dp[i] = max(dp[i], prefixCount[prefix] + 1);
      }
    }
    prefixCount[word] = dp[i];
    if (dp[i] > maxLength) {
      maxLength = dp[i];
      maxEndIndex = i;
    }
  }

  // Восстанавливаем ответ
  int startIndex = maxEndIndex;
  while (startIndex >= 0 && dp[startIndex] != 1) {
    --startIndex;
  }

  // Выводим ответ
  cout << startIndex + 1 << " " << maxEndIndex + 1 << endl;

  return 0;
}
