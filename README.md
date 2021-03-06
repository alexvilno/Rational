# Rational

Класс для работы с **рациональными** числами. Поддерживает неявное преобразование из int. Поддерживает все необходимые **арифметические операции** для рациональных чисел: 

```Rational a, b;``` &mdash; создает два рациональных числа
- Бинарные арифметические операции `a + b` , `a - b`, `a * b`, `a / b`, и их присваивающие версии `a += b`, `a -= b`, `a /= b`, `a *= b`
- Унарные операции `+a`, `-a`, а также префиксные и постфиксные инкременты и декременты `a++`, `++a`, `a--`, `--a`
- Операции сравнения `a == b`, `a != b`, `a > b`, `a < b`, `a >= b`, `a <= b`.
- Операции ввода из потока и вывода в поток `out << a`, `in >> a`

Определение **рационального числа:**

![equation](https://latex.codecogs.com/gif.latex?%5Cdpi%7B200%7D%20q%20%5Cin%20%5Cmathbb%20Q%20%5Ciff%20q%20%3D%20%5Cfrac%7Bm%7D%7Bn%7D%2C%20m%20%5Cin%20%5Cmathbb%20Z%2C%20n%20%5Cin%20%5Cmathbb%20N%2C%20gcd%28m%2Cn%29%20%3D1)

Где gcd &mdash; **наибольший общий делитель**

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
  numenator_ = 0;
  denominator_ = 1;
}
``` 
илициализирует число **нулем**

**Конструктор от двух целых чисел**
```cpp
Rational(int n, int d) {
  if (!d) {
    throw RationalDivisionByZero{};
  }
  numenator_ = n;
  denominator_ = d;
  Reduction();
}
```
Инициализирует числитель и знаменатель. При этом **не обязательно**, чтобы числитель и знаменатель были взаимнопросты.

**Конструктор неявного преобразования от целых чисел**
```cpp
Rational(int n) {  // NOLINT
  numenator_ = n;
  denominator_ = 1;
}
```

Неявно преобразует тип `int` к типу `Rational`. 
