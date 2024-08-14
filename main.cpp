#include <iostream>
#include <queue>

using namespace std;

int main() {
  // n = # cows in queue
  // k = # cows fit on stage
  int n, k;

  // user input for n & k
  cout << "Insert number of cows in queue and stage size:" << endl;
  cin >> n >> k;

  // initialize dance queue
  queue<int> cowDance;

  // loop to take user input for n cow durations
  cout << "Enter dance duration for each cow:" << endl;
  for (int i = 0; i < n; i++) {
    // user input for cow dance duration then push to queue
    int d;
    cin >> d;
    cowDance.push(d);
  }

  // keep track of the show time
  int time = 0;
  // make sure queue is not empty
  while (!cowDance.empty()) {
    // stageCows= # cows on stage; sTime= current stage time
    int stageCows = k;
    int sTime = 0;

    // # cows on stage > 0 & queue not empty
    while (stageCows > 0 && !cowDance.empty()) {
      // d = current front element of the queue
      int d = cowDance.front();
      // delete front element
      cowDance.pop();
      // current stage time = largest # btwn current stage time or current front
      // element
      sTime = max(sTime, d);
    }
    // add current stage time to the total show time
    time += sTime;
  }

  // output to display the total show time
  cout << "Show ends at: " << endl;
  cout << time << endl;

   return 0;
}