#include <iostream>
#include <queue>
using namespace std;

class threading
{

public:
    long long startTime;
    long long endTime;
    long long number;
    threading():startTime(0), endTime(0)
    {
        number++;
    }
    long long finishTime(){
        return endTime;
    }
};

struct threadingCompare
{
  bool operator()(threading& th1, threading& th2)
  {   // if the two threads are free, choose the lowest number
      // to do the job else choose the first one to be free
      if(th1.finishTime() == th2.finishTime()){
          return th1.number > th2.number;
      } else{
          return th1.finishTime() > th2.finishTime();
      }
  }
};

int main()
{
    long long thn, tin, th;
    queue<long long> jobs;

    cin >> thn >> tin;
    priority_queue<threading, vector<threading>, threadingCompare>threads;

    // creating a queue of threads
    for (long long i = 0; i < thn; i++)
    {   threading t;
        t.number = i;
        threads.push(t);
    }

    
    // creating a queue of jobs
    for (long long i = 0; i < tin; i++)
    {
        
        cin >> th;
        jobs.push(th);
    }
    
    

    while(!jobs.empty()){
        // Extract the first job to be done
        long long assignedJobEndTime = jobs.front();
        jobs.pop();


        threading t = threads.top();
        t.startTime = t.endTime;
        t.endTime = assignedJobEndTime+t.startTime;
        cout << t.number << " " << t.startTime << "\n";
        threads.pop();
        threads.push(t);
    }
    return 0;
}