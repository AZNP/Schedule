/*****************************************
 ** File:    Proj1.cpp
 ** Project: CMSC 202 Project 1, Spring 2016
 ** Author:  Paul Lee
 ** Date:    02/17/16
 ** Section: 19
 ** E-mail:  ple6@umbc.edu 
 ** Description: For any given day, we have a list of event requests, 
 ** which include the events' start times, end times, and descriptions.
 ** Our goal is to schedule as many events as possible 
 **
***********************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include "sched.h"

using namespace std;

// FUNCTION PROTOTYPES -- DO NOT CHANGE!

// sort() - sorts an array of floats returning sorted indices
// On return, indx[] is an array of indices such that data[indx[0]],
// data[indx[1]], ..., data[indx[len-1]] is data[] in ascending order.
//
// Parameters
//    data[] - float array of data to be ordered
//    indx[] - int array, same length as data[], to hold indices
//    len - int specifying the length of data[] and indx[]

void sort(float data[], int indx[], int len)
{
  //copies the data of the indexs
  float info[len];
  for(int i = 0; i < len; i++){
    info[i] = data[i];
  }
  //bubble sort of sorting the endTime
  for(int i = 0; i < len; i++) {
    indx[i] = i;
  }
  float iTemp;
  for(int i = 0; i < len; i++){
    for(int j = 0; j < len-1; j++){
      if( info[j+1] < info[j]){
        //endtime sort(data)
        iTemp = info[j];
        info[j] = info[j+1];
        info[j+1] = iTemp;

	//sorts the indx
        iTemp = indx[j];
        indx[j] = indx[j+1];
        indx[j+1] = iTemp;
      }
    } 
  }
}



// sched() - schedules events given start and end times, and indx[] from sort
// Returns number of events scheduled; on return, scheduled[] contains
// indices of scheduled events (e.g. startTime[scheduled[0]] is the start
// time of the first schedled event).
//
// Parameters
//    startTime[] - float array of event start times
//    endTime[] - float array of event end times
//    indx[] - array of indices that orders the end times
//    scheduled[] - int array to hold indices of scheduled events
//    len - int specifying the length of the arrays
// Returns
//    int value specifying number of events scheduled

int sched(float startTime[], float endTime[], int indx[], int scheduled[], int len)
{
  //counter starts at 1 due to the indx of 0 already being placed so no need ot place something thats already in there.
  int counter = 1;
  scheduled[0] = indx[0];
  //the indx within the indx has takes the index of starttime and endTime is sorted by the sort function
  for(int i = 1; i < len; i++){
    if(startTime[indx[i]] >= endTime[scheduled[counter-1]]){//the index of endTime counter is -1 cause you have to check the previously added time in your schedule
      scheduled[counter] = indx[i];
      counter++;//will increment up after being added to the schedule
    }
  }
  return counter;
}



// printEvent() - prints an event to the console
// Converts float start and end times to hh:mm format and prints times
// along with description.  E.g. Study Session from 12.5 to 13.25 should
// print as "12:30 - 13:15 Study Session"
//
// Parameters
//    startTime - float event start time
//    endTime - float event end time
//    description - string event description

void printEvent(float startTime, float endTime, string description)
{
  //startTime printed
  if(startTime < 10){
    cout << "0";
  } 
  cout << (int)startTime << ":";

  if(0 < (startTime - (int)startTime)){
    float digit = 0.0;
    int num = 60.0;
    digit = ((startTime - (int)startTime));
    digit = digit * num; // this is where the percentage multiplied by 60
    //    cout << digit << "im right here" << endl;
    //    cout << setprecision(2) <<  digit;
    if( digit > 9){
      cout <<  setprecision(2) <<  digit;
    }
    else{
      cout << setprecision(2) << "0" <<  digit;
      }
  }
  else{
    cout << "00"; 
  }

  //this cout is between the 2 times of start and end
  cout << " - ";


  //endTime printed
  if(endTime < 10){
    cout << "0";
  }
  cout << (int)endTime << ":";
  if (0 < (endTime - (int)endTime)){
    float digit2 = 0.0;
    int num = 60.0;
    digit2 = ((endTime - (int)endTime));
    digit2 = digit2 * num;
    //cout << setprecision(2) << digit2 << " " << description << endl;
    if( digit2 > 9){
      cout <<  setprecision(2) <<  digit2 << " " << description << endl;
    }
    else{
      cout << setprecision(2) << "0" << digit2 << " " << description << endl;
    }
  }
  else{
    cout << "00" << " " << description << endl;
  }
} 

/*the cout statements that are commented out are for personal reasons please ignore them*/

// MAIN PROGRAM - DO NOT CHANGE!

int main() {

  int indx[NUM_EVENTS];
  int scheduledEvents[NUM_EVENTS];
  int numSched;
  
  // Sort by event ending times
  sort(endTime, indx, NUM_EVENTS);
  
  // Call greedy scheduling algorithm
  numSched = sched(startTime, endTime, indx, scheduledEvents, NUM_EVENTS);
  
  // Display scheduled events
  for (int i = 0; i < numSched; i++)
    printEvent(startTime[scheduledEvents[i]], endTime[scheduledEvents[i]],
	       description[scheduledEvents[i]]);
  
  return 0;
}

//
// FUNCTION IMPLEMENTATIONS GO HERE
//                             
