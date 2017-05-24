#include "simulation.h"
#include <conio.h>
#include <iomanip>
using namespace std;

Simulation::Simulation()
{
	cout << "input the simulation time in minutes: ";
	cin >> SimulationLength;
	cout << "input the number of tellers(2~10): ";
	cin >> numTellers;
	cout << "input the range of arrival times in minutes: ";
	cin >> arrivalLow >> arrivalHigh;
	cout << "input the range of service times in minutes: ";
	cin >> serviceLow >> serviceHigh;
	for(int i = 1; i <= numTellers; ++i)
	{
		t[i].totalCustomer = 0;
		t[i].totalService = 0;
		t[i].totalWait = 0;
	}
	PQ.Push(Event(0, 0));
}

Simulation::Simulation(int L, int nT, int aL, int aH, int sL, int sH)
{
	SimulationLength = L;
	numTellers = nT;
	arrivalLow = aL;
	arrivalHigh = aH;
	serviceLow = sL;
	serviceHigh = sH;
	for (int i = 1; i <= numTellers; ++i)
	{
		t[i].totalCustomer = 0;
		t[i].totalService = 0;
		t[i].totalWait = 0;
	}
	PQ.Push(Event(0, 0));
}

int Simulation::GetNextTeller()
{
	int i, size = Q[1].Size(), min = 1;
	for (i = 2; i <= numTellers; ++i)
		if(Q[i].Size() < size)
		{
			size = Q[i].Size();
			min = i;
		}
	return min;
}

void Simulation::Arrived(const Event & e)
{
	Service s;
	int next, i;
	s.arrivalTime = e.GetTime();
	s.serviceTime = GetServiceTime();
	i = GetNextTeller();
	Q[i].Push(s);
	if(Q[i].Size() == 1)
		PQ.Push(Event(s.arrivalTime+s.serviceTime, i));
	next = e.GetTime()+GetIntertime();
	if(next<SimulationLength)
		PQ.Push(Event(next, 0));

	cout << "ServiceTime NextTeller next\n";
	cout << setw(5) << s.serviceTime;
	cout << setw(12) << i;
	cout << setw(8) << next << endl;
}

void Simulation::Daparture(const Event & e)
{
	int i = e.GetEventType();
	Service s = Q[i].Pop();
	t[i].totalCustomer++;
	t[i].totalService+=s.serviceTime;
	t[i].totalWait+=e.GetTime()-s.arrivalTime;
	if(!Q[i].Empty())
	{
		s=Q[i].Front();
		PQ.Push(Event(e.GetTime()+s.serviceTime, i));
	}
}

void Simulation::PrintPQueue()
{
	int n = PQ.Size();
	int i = 0;
	Event e, *p = new Event[n];
	cout << "* * * * * EventQueue * * * * *\n";
	while(!PQ.Empty())
	{
		e=PQ.Pop();
		cout << '(' << e.GetTime() << " " << e.GetEventType() << ')';
		p[i++] = e;
	}
	for (i = 0; i < n; ++i)
		PQ.Push(p[i]);
	cout << endl;
	delete []p;
}

void Simulation::PrintQueue()
{
	int n;
	Service s;
	cout << "* * * * * Tellers * * * * * \n";
	for (int t = 1; t <= numTellers; t++)
	{
		cout << t << ": ";
		n = Q[t].Size();
		for (int i = 1; i <= n; ++i)
		{
			s = Q[t].Pop();
			cout << '(' << s.arrivalTime << " " << s.serviceTime << ')';
			Q[t].Push(s);
		}
		cout << endl;
	}
}

void Simulation::RunSimulation()
{
	Event e;
	PrintPQueue();
	PrintQueue();
	cout << endl;
	getch();
	while (!PQ.Empty())
	{
		e = PQ.Pop();
		if(e.GetEventType() == 0)
		{
			Arrived(e);
			PrintPQueue();
			PrintQueue();
			cout << endl;
		}
		else
		{
			Daparture(e);
			PrintPQueue();
			PrintQueue();
			cout << endl;
		}
		getch();
	}
}

void Simulation::PrintSimulationResults()
{
	int i, totalCustomers = 0, totalWait = 0;
	for (i = 1; i <= numTellers; ++i)
	{
		totalCustomers+=t[i].totalCustomer;
		totalWait+=t[i].totalWait;
	}
	cout << totalCustomers << endl;
	cout << totalWait << endl;
}
