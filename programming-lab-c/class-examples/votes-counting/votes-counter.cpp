#include <iostream>
#include <fstream>
#include <sstream>


using namespace std;

class Candidate {
public:
  int num,votes;
  string name, entourage;
  Candidate():
    num(0), votes(0), name(""), entourage("") {
  }
  Candidate(int num, string name, string entourage):
    num(num), votes(0), name(name), entourage(entourage) {
  }
  Candidate(const Candidate &cd):
    num(cd.num), votes(0), name(cd.name), entourage(cd.entourage) {
  }
  void printCandidate() {
    cout << name << " - " << votes << " votos" << endl;
  }
};

int main() {
  int num, total = 0;
  string name, entourage;
  Candidate *listCandidates;

  listCandidates = new Candidate[20];

  ifstream candArq("candidatos.txt");

  if(!candArq.is_open()) {
    return 1;
  }

  do {
    candArq >> num >> name >> entourage;
    // This "if" prevents the last line of been read twice
    if(candArq.eof()) break;
    listCandidates[num-1] = Candidate(num, name, entourage);
  } while(!candArq.eof());

  for(int i=0; i<4;i++) {
    int vote;
    ostringstream urnaName;
    urnaName << "urna" << i+1 << ".txt";
    ifstream urnaArq(urnaName.str());
    if(!urnaArq.is_open()) {
      return 2;
    }

    do {
      urnaArq >> vote;
      if(urnaArq.eof()) break;
      listCandidates[vote-1].votes++;
      total++;
    } while(true);
  }

  for(int i=0; i<20;i++) {
    listCandidates[i].printCandidate();
  }

  return 0;
}