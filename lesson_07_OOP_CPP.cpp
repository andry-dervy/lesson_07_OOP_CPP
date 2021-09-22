//============================================================================
// Name        : lesson_07_OOP_CPP.cpp
// Author      : andry antonenko
// IDE         : Qt Creator 4.14.2 based on Qt 5.15.2
// Description : lesson 07 of the object-oriented programming on C++ course
//============================================================================
#include <QCoreApplication>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <memory>
using namespace std;
//----------------------------------------------------------------------------
//#define NDEBUG
#include <cassert>
//----------------------------------------------------------------------------
#include "card.h"
#include "hand.h"
#include "genericplayer.h"
#include "player.h"
#include "house.h"
//----------------------------------------------------------------------------
/*
1. Создайте класс Date с полями день, месяц, год и
методами доступа к этим полям.
Перегрузите оператор вывода для данного класса.
Создайте два "умных" указателя today и date.
Первому присвойте значение сегодняшней даты.
Для него вызовите по отдельности методы доступа к полям класса Date,
а также выведите на экран данные всего объекта
с помощью перегруженного оператора вывода.
Затем переместите ресурс, которым владеет
указатель today в указатель date.
Проверьте, являются ли нулевыми указатели today и date и
выведите соответствующую информацию об этом в консоль.
//*/

class Date
{
private:
  int day,month,year;
public:
  Date(int aDay = 0,int aMonth = 0,int aYear = 0)
    :day(aDay),month(aMonth),year(aYear){}
  int getDate() const {return day;}
  int getMonth() const {return month;}
  int getYear() const {return year;}

  friend std::ostream& operator<<(std::ostream& out, const Date &date);
};

std::ostream& operator<<(std::ostream& out, const Date &date)
{
  out << date.day << "."
      << date.month << "."
      << date.year;
  return out;
}

void task_1()
{
  cout << "Task 1\n" << endl;

  std::shared_ptr<Date> today = std::make_shared<Date>(21,9,2021);
  std::shared_ptr<Date> date;

  cout << "Day: " << today->getDate() << endl;
  cout << "Month: " << today->getMonth() << endl;
  cout << "Year: " << today->getYear() << endl;
  cout << "Today: " << *today << endl;

  date = std::move(today);

  if(today == nullptr)
    cout << "Pionter 'today' equals nullptr." << endl;
  else
    cout << "Pionter 'today' does not equal nullptr." << endl;

  if(date == nullptr)
    cout << "'today' pointer equals nullptr." << endl;
  else
    cout << "'date' pointer does not equal nullptr." << endl;

  cout << endl;
}

//----------------------------------------------------------------------------
/*
2. По условию предыдущей задачи создайте два умных указателя date1 и date2.
    • Создайте функцию, которая принимает в качестве параметра
два умных указателя типа Date и
сравнивает их между собой (сравнение происходит по датам).
Функция должна вернуть более позднюю дату.
    • Создайте функцию, которая обменивает ресурсами
(датами) два умных указателя, переданных в функцию в качестве параметров.
Примечание: обратите внимание,
что первая функция не должна уничтожать объекты,
переданные ей в качестве параметров.
//*/

std::shared_ptr<Date> compareDate(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2)
{
  if(date1->getYear() < date2->getYear())
    return date1;
  else if(date1->getYear() > date2->getYear())
    return date2;

  if(date1->getMonth() < date2->getMonth())
    return date1;
  else if(date1->getMonth() > date2->getMonth())
    return date2;

  if(date1->getDate() < date2->getDate())
    return date1;
  else if(date1->getDate() > date2->getDate())
    return date2;

  return date1;
}

void swapDate(std::shared_ptr<Date>& date1, std::shared_ptr<Date>& date2)
{
  std::shared_ptr<Date> tmp = std::move(date1);
  date1 = std::move(date2);
  date2 = std::move(tmp);
}

void task_2()
{
  cout << "Task 2\n" << endl;

  std::shared_ptr<Date> date1;
  std::shared_ptr<Date> date2;

  cout << "Test 1\n" << endl;

  date1 = std::make_shared<Date>(21,9,2021);
  date2 = std::make_shared<Date>(21,9,2022);

  cout << "Date1: " << *date1 << endl;
  cout << "Date2: " << *date2 << endl;

  cout << "The latest date: " << *compareDate(date1,date2) << endl;

  cout << "\nTest 2\n" << endl;

  date1 = std::make_shared<Date>(21,9,2021);
  date2 = std::make_shared<Date>(21,10,2021);

  cout << "Date1: " << *date1 << endl;
  cout << "Date2: " << *date2 << endl;

  cout << "The latest date: " << *compareDate(date1,date2) << endl;

  cout << "\nTest 3\n" << endl;

  date1 = std::make_shared<Date>(21,9,2021);
  date2 = std::make_shared<Date>(20,9,2021);

  cout << "Date1: " << *date1 << endl;
  cout << "Date2: " << *date2 << endl;

  cout << "The latest date: " << *compareDate(date1,date2) << endl;

  cout << "\nTest 4\n" << endl;

  date1 = std::make_shared<Date>(21,9,2021);
  date2 = std::make_shared<Date>(21,9,2021);

  cout << "Date1: " << *date1 << endl;
  cout << "Date2: " << *date2 << endl;

  cout << "The latest date: " << *compareDate(date1,date2) << endl;

  cout << "\nTest 5\n" << endl;

  date1 = std::make_shared<Date>(3,5,2010);
  date2 = std::make_shared<Date>(21,9,2021);

  cout << "Date1=" << *date1;
  cout << " and date2=" << *date2 << endl;

  swapDate(date1,date2);

  cout << "Date1=" << *date1;
  cout << " and date2=" << *date2
       << " after swaping." << endl;

  cout << endl;
}

//----------------------------------------------------------------------------
/*
3. Создать класс Deck,
который наследует от класса Hand и
представляет собой колоду карт.
Класс Deck имеет 4 метода:
    • vold Populate() - Создает стандартную колоду из 52 карт,
вызывается из конструктора.
    • void Shuffle() - Метод, который тасует карты,
можно использовать функцию из алгоритмов STL random_shuffle
    • vold Deal (Hand& aHand) - метод, который раздает в руку одну карту
    • void AddltionalCards (GenericPlayer& aGenerlcPlayer) -
раздает игроку дополнительные карты до тех пор,
пока он может и хочет их получать
Обратите внимание на применение полиморфизма.
В каких методах применяется этот принцип ООП?
//*/

/*
4. Реализовать класс Game,
который представляет собой основной процесс игры.
У этого класса будет 3 поля:
    • колода карт
    • рука дилера
    • вектор игроков.
Конструктор класса принимает в качестве параметра
вектор имен игроков и создает объекты самих игроков.
В конструкторе создается колода карт и затем перемешивается.
Также класс имеет один метод play().
В этом методе раздаются каждому игроку по две стартовые карты,
а первая карта дилера прячется.
Далее выводится на экран информация о картах каждого игра,
в т.ч. и для дилера. Затем раздаются игрокам дополнительные карты.
Потом показывается первая карта дилера и дилер набирает карты, если ему надо.
После этого выводится сообщение, кто победил, а кто проиграл.
В конце руки всех игроков очищаются.
//*/

/*
5. Написать функцию main() к игре Блекджек.
В этой функции вводятся имена игроков.
Создается объект класса Game и
запускается игровой процесс.
Предусмотреть возможность повторной игры.
//*/

//----------------------------------------------------------------------------
//----------------------------------------------------------------------------
int main(int argc, char *argv[])
{
  QCoreApplication a(argc, argv);
  //----------------------------------------------------------------------------
  // Task 1
  //*
  task_1();
  //*/
  //----------------------------------------------------------------------------
  // Task 2
  //*
  task_2();
  //*/
  //----------------------------------------------------------------------------
  // Task 3
  /*
  task_3();
  //*/
  //----------------------------------------------------------------------------
  return a.exec();
}
