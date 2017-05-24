#ifndef SIMULATION_H_
#define SIMULATION_H_

#include "pqueue.h"
#include "queue.h"

class Event
{
	int time;
	int etype;
public:
	Event():time(0),etype(9){}
	Event(int t, int e):time(t), etype(e){}
	operator int()const{ return (time); }
	int GetTime()const{return (time); }
	int GetEventType()const {return (etype);}
};

struct Service
{
	int arrivalTime;
	int serviceTime;
};

struct TellerStats
{
	int totalCustomer;
	int totalService;
	int totalWait;
};

class Simulation
{
	int SimulationLength;
	int numTellers;
	int arrivalLow, arrivalHigh;
	int serviceLow, serviceHigh;
	TellerStats t[11];
	Queue<Service> Q[11];
	PQueue<Event> PQ;
	int GetIntertime()
	{
		return (arrivalLow+rand()%(arrivalHigh-arrivalLow+1));
	}
	int GetServiceTime()
	{
		return (serviceLow+rand()%(serviceHigh-serviceLow+1));
	}
	int GetNextTeller();
	void Arrived(const Event & e);
	void Daparture(const Event & e);
	void PrintPQueue();
	void PrintQueue();
public:
	Simulation();
	Simulation(int L, int nT, int aL, int aH, int sL, int sH);
	void RunSimulation();
	void PrintSimulationResults();
};


#endif
