# Rational

Класс для работы с **рациональными** числами. Поддерживает неявное преобразование из int. Поддерживает все необходимые **арифметические операции** для рациональных чисел: 
- Бинарные арифметические операции (+, -, /, *) и их присваивающие версии (+=, -=, /=, *=)
- Унарные операции (+, -), а также префиксные и постфиксные инкременты и декременты (++, --)
- Операции сравнения
- Операции ввода из потока и вывода в поток (>>, <<)

Определение **рационального числа:**

![equation](https://latex.codecogs.com/png.image?\dpi{110}q&space;\in&space;\mathbb&space;Q&space;\iff&space;q&space;=&space;\frac{m}{n},&space;m&space;\in&space;\mathbb&space;Z,&space;n&space;\in&space;\mathbb&space;N,&space;gcd(n,m)&space;=&space;1&space;)

Где gcd &mdash; **наименьшее общее кратное**

## Методы класса
**Геттеры:** 
```cpp
GetNumenator();
```
Этот метод возвращает **числитель** дроби
```cpp
GetDenominator();
```
А этот &mdash; **знаменатель**

**Сеттеры:**
```cpp
SetNumenator(int numenator);
```
Установит значение **числителя** заданным **целым** числом.
```cpp
SetDenominator(int denominator);
```
Хотя по **[определению](https://ru.wikipedia.org/wiki/%D0%A0%D0%B0%D1%86%D0%B8%D0%BE%D0%BD%D0%B0%D0%BB%D1%8C%D0%BD%D0%BE%D0%B5_%D1%87%D0%B8%D1%81%D0%BB%D0%BE)** рационального числа знаменатель **натуральное число**, при установке его значения **меньше нуля** вся дробь домножится на -1 и не будет противоречить определению. Если знаменатель равен **нулю** &mdash; выбросится исключение `RationalDivisionByZero();`

## Кострукторы
**Конструктор по умолчанию:**
```cpp
Rational() {
        numenator = 0;
        denominator = 1;
}
``` 
илициализирует число **нулем**
**Конструктор от двух целых чисел**
```cpp
Rational(int n, int d) {
        numenator = n;
        denominator = d;
}
```
Инициализирует числитель и знаменатель. При этом **не обязательно**, чтобы числитель и знаменатель были взаимнопросты.
