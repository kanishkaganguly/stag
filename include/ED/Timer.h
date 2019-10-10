#ifndef TIMER_H
#define TIMER_H

#ifndef OS_WIN
#include <ctime>
class Timer{

private:
  std::clock_t  clk;

public:
  Timer(){}

  void Start(){
	clk = std::clock();
  }
  void Stop(){
	clk = std::clock() - clk;
  }
  double ElapsedTime(){
	return ((double)clk)/CLOCKS_PER_SEC;
  }
};
#else
#include <windows.h>
class Timer {
private:
  __int64 freq, tStart, tStop;

public:
  Timer(){
    // Get the frequency of the hi-res timer
    QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
  } //end-TimerClass

  void Start(){
    // Use hi-res timer
    QueryPerformanceCounter((LARGE_INTEGER*)&tStart);
  } //end-Start

  void Stop(){
    // Perform operations that require timing
    QueryPerformanceCounter((LARGE_INTEGER*)&tStop);
  } //end-Stop

  // Returns time in milliseconds
  double ElapsedTime(){
    // Calculate time difference in milliseconds
    return ((double)(tStop - tStart)/(double)freq)*1e3;
  } //end-Elapsed
};
#endif

#endif