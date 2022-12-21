a.out: main.o Data.o KNN.o Calculator.o 
	g++ -std=c++11 main.o Data.o KNN.o Calculator.o -o a.out

main.o: main.cpp header.h Data.h
	g++ -std=c++11 -c main.cpp

Data.o: Data.cpp Data.h header.h
	g++ -std=c++11 -c Data.cpp

KNN.o: KNN.cpp header.h
	g++ -std=c++11 -c KNN.cpp

Calculator.o: Calculator.cpp header.h
	g++ -std=c++11 -c Calculator.cpp
	
clean:
	rm *.o a.out
