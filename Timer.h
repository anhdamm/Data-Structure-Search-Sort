// Timer.h

#ifndef TIMER_H
#define TIMER_H

#include <ctime>
#include "time.h"
#include <stdexcept>
#include <iostream>

using namespace std;


class Timer {
  public:
    /*Constructor
     Pre: none
     Post: Initializes the internal timer values so that the timer is ready to measure time.
     */
    Timer();
    
    /*void start()
     Pre: The clock function is working correctly.
     Post: Marks the beginning of a time interval(starts the timer).
     */
    void start() throw (runtime_error);
    
    /*void stop()
     Pre: The beginning of a time interval has been marked.
     Post: Marks the beginning of a time interval(starts the timer).
     */
    void stop() throw (logic_error);
    
    /*double getElapsedTime()
     Pre: The beginning and end of a time interval have been marked.
     Post: Returns the length of the time interval in seconds.
     */
    double getElapsedTime() const throw (logic_error);

  private:
    clock_t beginTime;
    clock_t duration;
    bool timerWasStarted;
};



/*Constructor
 Pre: none
 Post: Initializes the internal timer values so that the timer is ready to measure time.
 */
Timer::Timer()
    :beginTime(-1), duration(-1)
{
    timerWasStarted = false;
}



/*void start()
 Pre: The clock function is working correctly.
 Post: Marks the beginning of a time interval(starts the timer).
 */
void Timer::start() throw (runtime_error)
{
    beginTime = clock();
    //cout << beginTime << "Here is beginTime" << endl;
    if(beginTime == - 1)
    {
        throw runtime_error ("The clock function is not working correctly");
    }
}



/*void stop()
 Pre: The beginning of a time interval has been marked.
 Post: Marks the beginning of a time interval(starts the timer).
 */
void Timer::stop() throw (logic_error)
{
    if(beginTime == - 1)
    {
        throw logic_error("The beginning of a time interval hasn't been marked.");
    }
    duration = clock() - beginTime;
    //cout << duration << "Here is duration" << endl;
    timerWasStarted = false;
}


/*double getElapsedTime()
 Pre: The beginning and end of a time interval have been marked.
 Post: Returns the length of the time interval in seconds.
 */
double Timer::getElapsedTime() const throw (logic_error)
{
    if(beginTime == -1 || duration == -1)
    {
        throw logic_error ("The beginning and end of a time interval have not been marked.");
    }

    return (((double)duration)/ CLOCKS_PER_SEC);
}
#endif	// ifndef TIMER_H
