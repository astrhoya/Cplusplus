#ifndef __VARIOUS_MONSTERS_H__
#define __VARIOUS_MONSTERS_H__

#include "Monster.h"
#include "input.h"

class Zombie : public Monster {
public:
  Zombie(string name = "zommbie", char icon = '!', int x = 0, int y = 0)
      : Monster(name, icon, x, y) {}
  void move(int **map, int xMax, int yMax) {
    switch (rand() % 8) {
    case 0:
      y--;
      break; // up
    case 1:
      x++;
      y--;
      break; // right up
    case 2:
      x++;
      break; // right
    case 3:
      x++;
      y++;
      break; // right down
    case 4:
      y++;
      break; // down
    case 5:
      x--;
      y++;
      break; // left down
    case 6:
      x--;
      break; // left
    case 7:
      x--;
      y--;
      break; // left up
    }
    clip(xMax, yMax);
    eat(map);
  }
  ~Zombie() { cout << "[  Zombie]"; }
};

class Vampier : public Monster {
public:
  Vampier(string name = "vempire", char icon = '@', int x = 0, int y = 0)
      : Monster(name, icon, x, y) {}
  void move(int **map, int xMax, int yMax) {
    switch (rand() % 4) {
    case 0:
      y--;
      break; // up
    case 1:
      x++;
      break; // right
    case 2:
      y++;
      break; // down
    case 3:
      x--;
      break; // left
    }
    clip(xMax, yMax);
    eat(map);
  }
  ~Vampier() { cout << "[ Vampier]"; }
};

class rkdtl : public Monster {
  int isFront;

public:
  rkdtl(string name = "rkdtl", char icon = '@', int x = 0, int y = 0,
        int isFront = 1)
      : Monster(name, icon, x, y), isFront(isFront) {}
  void move(int **map, int xMax, int yMax) {
    if (isFront == 1) {
      switch (rand() % 2) {
      case 0:
        x++;
        break; // up
      case 1:
        x--;
        break; // left
      }
      clip(xMax, yMax);
      eat(map);
    } else {
      switch (rand() % 2) {
      case 0:
        y++;
        break; // up
      case 1:
        y--;
        break; // left
      }
      clip(xMax, yMax);
      eat(map);
    }
  }
  ~rkdtl() { cout << "[   rkdtl]"; }
};

class Human : public Monster {
public:
  Human(string name = "human", char icon = '&', int x = 0, int y = 0)
      : Monster(name, icon, x, y) {}
  ~Human() { cout << "[   Human]"; }
  void move(int **map, int xMax, int yMax) {
    int check = getch();
    if (check == 27) {
      int second = getch();
      int ch = getch();
      if (ch == 68) { // left
        x--;
        clip(xMax, yMax);
        eat(map);
      }
      if (ch == 67) { // right
        x++;
        clip(xMax, yMax);
        eat(map);
      }
      if (ch == 65) { // up
        y--;
        clip(xMax, yMax);
        eat(map);
      }
      if (ch == 66) { // down
        y++;
        clip(xMax, yMax);
        eat(map);
      }
    }
  }
  int returnItem() { return this->nItem; };
};

#endif