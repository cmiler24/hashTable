all:
	g++ -o encoder main.cpp hash.cpp
	./encoder << inputs/bertuncased.txt