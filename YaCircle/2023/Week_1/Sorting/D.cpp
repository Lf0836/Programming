#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

struct Participant {
  int id;
  int score;
};

bool compareParticipants(Participant p1, Participant p2) {
  if (p1.score == p2.score) {
    return p1.id < p2.id;
  }
  return p1.score > p2.score;
}

int main() {
  int n;
  cin >> n;

  vector<Participant> participants;

  for (int i = 0; i < n; i++) {
    Participant p;
    cin >> p.id >> p.score;
    participants.push_back(p);
  }

  sort(participants.begin(), participants.end(), compareParticipants);

  for (const Participant& p : participants) {
    cout << p.id << " " << p.score << endl;
  }

  return 0;
}
