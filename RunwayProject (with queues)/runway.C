#include<iostream>
#include"LQueue.h"
#include<cstdlib>
#include<ctime>
using namespace std;

class runway
{
    private :
    Queue landingQueue;
    Queue takeOffQueue;
    bool runwayFree;
    int flightNo;
    int landingLength;
    int takeOffLength;
    int maxL;
    int maxT;

    public :
    runway()
    {
       runwayFree = true;
       flightNo = 1000;
       landingLength = 0;
       takeOffLength = 0;
       maxT = 0;
       maxL = 0;
    }
    
    void check(double val1, double val2, int landingRate, int takeOffRate)
    {
       double temp1 = landingRate/60.0;
       double temp2 = takeOffRate/60.0;
       
       if(val1 < temp1)
          landing();
       if(val2 < temp2)
          takeOff();
    }
    
    void landingWithoutComment()
    {
       maxL++;
       landingLength++;
       landingQueue.enqueue(flightNo);
       flightNo++;
    }

  
    void landing()
    {
       maxL++;
       landingLength++;
       std::cout<<"Flight "<<flightNo<<" wants to land;";
       landingQueue.enqueue(flightNo);
       std::cout<<" added to landing queue; ";
       std::cout<<landingLength<<" in queue\n";
       flightNo++;
    }
    
    void takeOffWithoutComment()
    {  
       maxT++;
       takeOffLength++;
       takeOffQueue.enqueue(flightNo);
       flightNo++;
    }

    
    void takeOff()
    {  
       maxT++;
       takeOffLength++;
       std::cout<<"Flight "<<flightNo<<" wants to takeOff;";
       takeOffQueue.enqueue(flightNo);
       std::cout<<" added to takeOff queue; ";
       std::cout<<takeOffLength<<" in queue\n";
       flightNo++;
    }

    bool checkRunway()
    {
       return runwayFree; 
    }
    
    void setRunway(bool val)
    {
       runwayFree = val;
    }
   
    int getLandingLength()
    {
       return landingLength;
    }

    int getTakeOffLength()
    {
       return takeOffLength;
    }

    
    void landFlight()
    {
         std::cout<<"Landing Flight : ";
         std::cout<<landingQueue.getMyFrontVal()<<"\n";
         landingLength--;
         landingQueue.dequeue();
    }
    
    void takeOffFlight()
    {
         std::cout<<"Flight : ";
         std::cout<<takeOffQueue.getMyFrontVal()<<" taking off\n";
         takeOffLength--;
         takeOffQueue.dequeue();
    }

    void summary(int time)
    {
         double avg = ((double)(time) / (double)(maxL));
         std::cout<<"\n\n\nSummary : \n";
         std::cout<<"Max number of planes in landing queue : ";
         std::cout<<maxL<<"\n";
         std::cout<<"Average minutes spent waiting to land : ";
         std::cout<<avg<<"\n";
         std::cout<<"Max number of planes in takeoff queue : ";
         std::cout<<maxT<<"\n";
         std::cout<<"Average minutes spent waiting to takeOff : ";
         avg = ((double)(time) / (double)(maxT));
         std::cout<<avg<<"\n";
    }
   
    Queue getLandingQueue()
    {
       return landingQueue;
    }

    Queue getTakeOffQueue()
    {
       return takeOffQueue;
    }

    void merge(runway r)
    {
       Queue temp = r.getLandingQueue();
       landingQueue.merge_two_queues(temp);
       landingLength += r.getLandingLength();
       std::cout<<"Updated number of planes in landing queue : "<<landingLength<<"\n";
       maxL += r.getLandingLength();
       temp = r.getTakeOffQueue();
       takeOffQueue.merge_two_queues(temp);
       takeOffLength += r.getTakeOffLength();
       std::cout<<"Updated number of planes in takeOff queue : "<<takeOffLength<<"\n";
       maxT += r.getTakeOffLength();
    }    
};

int main()
{
    
    int simulationTime;
    int timeLeft = 1;
    double randTime1 = 0.0;
    double randTime2 = 0.0;
    int landingRate;
    int takeOffRate;
    int landTime;
    int takeOffTime;
    runway r;
    bool set;
    bool land = false;
    bool takeOff = false;
    int temp = 0;

    runway r2;
    for(int i = 0; i < 5; i++)
      r2.landingWithoutComment();
    for(int i = 0; i < 3; i++)
      r2.takeOffWithoutComment();

    std::cout<<"Enter :";
    std::cout<<"\nTime for a plane to land (in minutes): ";
    std::cin>>landTime;
    std::cout<<"Time for a plane to takeOff (in minutes) : ";
    std::cin>>takeOffTime;
    std::cout<<"Landing rate (planes per hour) : ";
    std::cin>>landingRate;
    std::cout<<"TakeOff rate (planes per hour) : ";
    std::cin>>takeOffRate;
    std::cout<<"How long to run the simulation (in minutes) : ";
    std::cin>>simulationTime;

    srand(time(NULL));

    while(timeLeft <= simulationTime)
    {
        randTime1 = (double)(rand()%30 + 1);
        randTime1 /= 100.0;
        randTime2 = (double)(rand()%30 + 1);
        randTime2 /= 100.0;
        std::cout<<"\nTime : "<<timeLeft<<"\n";
        if(timeLeft == simulationTime/2)
          {
             std::cout<<"\n\n!!!!!!!!!!!!!!!!!!!Runway 2 has unfortunately shut down because of an accident on the runway!!!!!!!!!!!!!!!!!!!\nAll landings and takeOffs being moved to Runway 1\n\n\n";
             
             r.merge(r2);
          }
        r.check(randTime1, randTime2, landingRate, takeOffRate);
        if(set)
        {
           if(temp-1 > 0)
              temp--;
           else
              {
                if(land)
                {
                   std::cout<<"Landing complete; ";
                   std::cout<<r.getLandingLength();
                   std::cout<<" in queue\n";
                   land = false;
                }
                if(takeOff)
                {
                   std::cout<<"TakeOff complete; ";
                   std::cout<<r.getTakeOffLength();
                   std::cout<<" in queue\n";
                   takeOff = false;
                }
                temp = 0;
                set = false;
                r.setRunway(true);
              }
        }
        else if(r.checkRunway())
        {
           if(r.getLandingLength() != 0)
                {
                    land = true;
                    r.landFlight();
                    r.setRunway(false);
                    set = true;
                    temp = landTime;
                }
           else if(r.getTakeOffLength() != 0)
                {
                    takeOff = true;
                    r.takeOffFlight();
                    r.setRunway(false);
                    set = true;
                    temp = takeOffTime;
                }

        }
        timeLeft++;
    } 

    std::cout<<"No new landings or takeoffs will be generated!\n";

    int l = r.getLandingLength(); 
    while(l >= 0)
    {
        std::cout<<"\nTime : "<<timeLeft<<"\n";
        if(r.checkRunway())
        {
           r.landFlight();
           r.setRunway(false);
           temp = landTime;
           }
        else        
        {
           if(temp-1 > 0)
              temp--;
           else
              {
                std::cout<<"Landing complete; ";
                std::cout<<l;
                std::cout<<" in queue\n";
                l--;
                temp = 0;
                r.setRunway(true);
              }
         }
         timeLeft++;
     }

     
     set = false;
     r.setRunway(true);
     temp = 0;
     

     int t = r.getTakeOffLength();
     while(t > 0)
    {
        std::cout<<"\nTime : "<<timeLeft<<"\n";
        if(r.checkRunway())
        {
           r.takeOffFlight();
           r.setRunway(false);
           temp = takeOffTime;
           }
        else        
        {
           if(temp-1 > 0)
              temp--;
           else
              {
                std::cout<<"TakeOff complete; ";
                std::cout<<t-1;
                std::cout<<" in queue\n";
                t--;
                temp = 0;
                r.setRunway(true);
              }
         }
         timeLeft++;
     }
    
    
    r.summary(timeLeft);
    std::cout<<"End Program!\n";


    return 0;
}



