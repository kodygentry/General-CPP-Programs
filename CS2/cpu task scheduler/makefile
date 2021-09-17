a.out: schedulerMain.o Scheduler.o
	g++ schedulerMain.o Scheduler.o

schedulerMain.o: schedulerMain.cpp Scheduler.h
	g++ -c -std=c++11 schedulerMain.cpp


Scheduler.o: Scheduler.cpp Scheduler.h PendingProcess.h
	g++ -c -std=c++11 Scheduler.cpp