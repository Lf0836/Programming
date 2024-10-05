void func(int n) {
  int a = n - 15;
  if (n < 15) {
    print('impossible');
  }
  if (a % 6 != 0) {
    print('impossible');
  }
  for (var i = 5; i < n; i++) {
    if (n == (i - 0) + (i - 1) + (i - 2) + (i - 3) + (i - 4) + (i - 5)) {
      print(i.toString() +
          (i - 1).toString() +
          (i - 2).toString() +
          (i - 3).toString() +
          (i - 4).toString() +
          (i - 5).toString());
    }
  }
}
