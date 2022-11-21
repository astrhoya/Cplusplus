#include "Canvas.h"
#include "Matrix.h"
#include "Monster.h"
#include "input.h"
#include <unistd.h>
#ifndef __MONSTERWORLD_H__
#define __MONSTERWORLD_H__
#define MAX_MONSTER 20

class MonsterWorld {
private:
  TerminalControl tc;
  Matrix<int> map;
  int xMax, yMax, nMon, nMove;
  Monster *mon[MAX_MONSTER];
  Canvas canvas;

public:
  MonsterWorld(int width, int height)
      : canvas(width, height), xMax(width), yMax(height), nMon(0), nMove(0), map(height, width) {
    for (int y = 0; y < yMax; y++)
      for (int x = 0; x < xMax; x++)
        map.elem(y, x) = 1;
  }
  ~MonsterWorld() {
    for (int i = 0; i < nMon; i++) {
      delete mon[i];
    }
  }
  void add(Monster *m) {
    if (nMon < MAX_MONSTER) {
      mon[nMon++] = m;
    }
  }
  int countItems() {
    int nItems = 0;
    for (int y = 0; y < yMax; y++) {
      for (int x = 0; x < xMax; x++) {
        if (map.elem(y, x) == 1) {
          nItems++;
        }
      }
    }
    return nItems;
  }
  void print() {
    system("clear");
    canvas.clear();
    for (int y = 0; y < yMax; y++) {
      for (int x = 0; x < xMax; x++) {
        if (map.elem(y, x) == 1) {
          canvas.draw(x, y, '.');
        }
      }
    }

    for (int i = 0; i < nMon; i++) {
      mon[i]->draw(canvas);
    }
    canvas.print("[ Monster World ]");
    cout << "전체 이동 횟수 = " << nMove << endl;
    cout << "남은 아이템 수 = " << countItems() << endl;
    for (int i = 0; i < nMon; i++) {
      mon[i]->print();
    }
  }
  void play(int maxWalk, int wait) {
    print();
    cout << "엔터를 누르세요...";
    getchar();
    tc.playModeSetting();
    for (int i = 0; i < maxWalk; i++) {
      // 몬스터 움직이기
      for (int i = 0; i < nMon; i++) {
        mon[i]->move(map.getMartix(), xMax, yMax);
      }
      nMove++;
      // 변경된 화면 출력
      print();
      if (countItems() == 0)
        break;
      // wait만큼 기다리기
      sleep(wait);
    }
    tc.defaultSetting();
  }
};

#endif