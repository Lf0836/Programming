import 'dart:io';

void main(List<String> arguments) {
  String washer1, washer2;
  if (DateTime.now().day.isEven) {
    washer1 = 'Павел';
    washer2 = 'Фёдор';
  } else {
    washer1 = 'Фёдор';
    washer2 = 'Павел';
  }
  print('''График мытья посуды на сегодня.
  
Заврак: $washer1
Обед: $washer2
Ужин: $washer1
  ''');
  sleep(Duration(seconds: 5));
}
