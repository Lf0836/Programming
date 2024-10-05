import 'dart:io';
import 'dart:math';

void main() {
  int counter = 0;
  int examples = 1;
  do {
    var randomNumber1 = Random().nextInt(101);
    var randomNumber2 = Random().nextInt(101);
    var inputNumber;
    String inputString;
    stdout.write('$randomNumber1 - $randomNumber2 = ');
    inputString = stdin.readLineSync();
    inputNumber = int.tryParse(inputString) ?? 0;
    if (inputNumber == randomNumber1 - randomNumber2) {
      print('Great.');
      counter++;
    } else {
      print('Wrong. ${randomNumber1 - randomNumber2}');
    }
  } while (counter < examples);
  sleep(Duration(seconds: 5));
}
