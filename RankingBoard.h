#ifndef __RANKING_BOARD_H__
#define __RANKING_BOARD_H__

#include <string>
#include <iostream>
#include <fstream>
#include <limits>
using namespace std;
#define NUM_MVP 5

class PlayInfo{
private:
	string name;
	int nItem;
  friend class RankingBoard;
public:
	PlayInfo(string name="XXX", int nItem=0): name(name), nItem(nItem) {}

};

class RankingBoard {
private:
	PlayInfo MVP[NUM_MVP];
	int nMVP = NUM_MVP;
public:
	void print(string title="게임 랭킹") {
		system("clear");
		cout << title << endl;
		for(int i = 0; i < NUM_MVP; i++) {
      cout << "[" << i+1 << "위]" << " " << MVP[i].name << "\t" <<        MVP[i].nItem << endl;
    }
		cout << "엔터를 입력하세요.";
		getchar();
		cout << endl;
	}
	int add(int nItem) {
		if(nItem < MVP[nMVP - 1].nItem) {
      return 0;
    }
    int rank = nMVP - 1;
    for( ; rank > 0; rank--) {
      if(nItem < MVP[rank-1].nItem) break;
      MVP[rank] = MVP[rank - 1];
    }
    
		MVP[rank].nItem = nItem;
		cout << "[" << rank+1 << "위] 이름을 입력하세요: ";
		cin >> MVP[rank].name;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		cout << endl;
		return rank+1;
	}

  void save(string filename) {
    ofstream ofs;
    ofs.open(filename);
    for(int i = 0; i < nMVP; i++) {
      ofs << MVP[i].name << "\t" << MVP[i].nItem << endl;
    }
    ofs.close();
  }

  void load(string filename) {
    ifstream ifs;
    ifs.open(filename);
    for(int i = 0; i < nMVP; i++) {
      ifs >> MVP[i].name >> MVP[i].nItem;
    }
    ifs.close();
  }
};

#endif