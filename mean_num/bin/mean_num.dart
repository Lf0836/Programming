import 'dart:io';

void main() {
  List<String> arguments;
  int sum = 0;
  late int five;
  late int length;
  List<int> arrNums = [];

  stdout.write('Введите свои оценки через пробел: ');
  String? line = stdin.readLineSync();
  if (line == null) {
    print('А числа где?');
    exit(0);
  } else {
    arguments = line.split(' ');
  }

  for (String element in arguments) {
    try {
      int num = int.parse(element);
      if (num > 1 && num < 6) {
        arrNums.add(num);
      } else {
        print('$element: оценка может быть от 2 до 5');
      }
    } catch (e) {}
  }

  length = arrNums.length;
  if (length < 1) {
    exit(0);
  }
  for (int element in arrNums) {
    sum += element;
  }
  five = (9.14 * length - 2 * sum).ceil();
  five = five < 0 ? 0 : five;
  print('Средний балл ${(sum / length).toStringAsFixed(2)}');
  print('$five пятёрок ещё нужно получить до пятёрки в четверти');
  sleep(Duration(seconds: 5));
}
