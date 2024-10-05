import 'dart:html';

void main() {
void getAnswer(int num, int degree) {
  String answer = '<br>';
  int counter = 0;

  int multiply(int a, int b) {
    int result = a;
    for (var i = 1; i < b; i++) {
      answer += '${++counter}) $result + $a = ${result + a}<br>';
      result += a;
    }

    return result;
  }

  int myPow(int num, int degree) {
    int result = num;
    for (var i = 1; i < degree; i++) {
      result = multiply(result, num);
    }

    return result;
  }

  myPow(num, degree);

  querySelector('#output')?.appendHtml(answer);
}

  querySelector('#btn')!.onClick.;
}


