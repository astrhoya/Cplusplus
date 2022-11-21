#include "MonsterWorld.h"
#include "VariousMonsters.h"
#include <time.h>
#include "RankingBoard.h"

int main(void) {
  RankingBoard rank;
  rank.load("RANK_SAVE.txt");
  rank.print("[게임 랭킹] : 시작");
  
  srand((unsigned int)time(NULL));
  int width = 16, height = 8;

  Human* human = new Human("정현우", '&', rand() % width, rand() % height);
  MonsterWorld game(width, height);
  game.add(new Zombie("허접한좀비", '!', rand() % width, rand() % height));
  game.add(new Vampier("난뱀파이어", '@', rand() % width, rand() % height));
  game.add(new rkdtl("강시", '*', rand() % width, rand() % height, 0));
  game.add(human);
  game.play(5, 1);
  rank.add(human->returnItem());
  rank.print("[게임 랭킹] : 종료");
  rank.save("RANK_SAVE.txt");
  return 0;
}