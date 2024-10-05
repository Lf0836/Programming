import 'dart:io';
import 'dart:math';

void main() {
  // Настройка игры
  int startMax = 10;
  int levels = 5;

  int allCount = 0;
  for (var i = 0; i < levels; i++) {
    bool isGuess = false;
    int count = 0;
    int max = startMax * (i + 1);
    int num = Random().nextInt(max + 1);
    print('Level ${i + 1}\nЯ загадал число от 0 до $max угадай его');
    do {
      count++;
      stdout.write('Введи число: ');
      String? inputString = stdin.readLineSync();
      if (inputString == null) {
        continue;
      }
      int? inputInt = int.tryParse(inputString);
      if (inputInt == null) {
        print('Что-то не похоже на число');
      } else {
        inputInt < num ? print('Недолёт') : {};
        inputInt > num ? print('Перелёт') : {};
        if (inputInt == num) {
          isGuess = true;
        }
      }
      allCount += count;
    } while (!isGuess);
    print('Тебе понадобилось $count попыток\n');
  }
  print('Ты прошёл все уровни!\nВсего попыток: $allCount');
  sleep(Duration(seconds: 5));
}
