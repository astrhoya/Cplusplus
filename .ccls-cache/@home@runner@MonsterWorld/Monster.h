#include "Canvas.h"
#include <cstdlib>
#include <ctime>
#include <string>
#ifndef __MONSTER_H__
#define __MONSTER_H__

class Monster {
protected:
  string name;
  char icon;
  int x, y, nItem;

  void clip(int xMax, int yMax) {
    if (x < 0)
      x = 0;
    if (x >= xMax)
      x = xMax - 1;
    if (y < 0)
      y = 0;
    if (y >= xMax)
      y = yMax - 1;
  }

  void eat(int** map) {
    if (map[y][x] == 1) {
      map[y][x] = 0;
      nItem++;
    }
  }

public:
  Monster(string name = "괴물", char icon = '@', int x = 0, int y = 0)
      : name(name), icon(icon), x(x), y(y), nItem(0) {}

  virtual ~Monster() {
    cout << "\t" << name << icon << " 퇴장합니다~~" << endl;
  }

  void draw(Canvas &canvas) { canvas.draw(x, y, icon); }

  virtual void move(int** map, int xMax, int yMax) = 0;

  void print() { cout << "몬스터" << icon << ":" << nItem << endl; }
};

#endif