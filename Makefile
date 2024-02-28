all:
	g++ -o encoder main.cpp hash.cpp
	./encoder < inputs/common500.txt