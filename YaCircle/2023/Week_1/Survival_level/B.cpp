#include <fstream>
using namespace std;

int main() {
  int num1, num2, sum;
  ifstream FileInside("divide.in");
  if (FileInside.is_open()) {
    FileInside >> num1 >> num2;
    FileInside.close();
  }
  sum = num1 / num2;
  ofstream FileOutside("divide.out");
  if (FileOutside.is_open()) {
    FileOutside << sum;
    FileOutside.close();
  }
  return 0;
}
