# Peter Ramos, Dakota Donner
dynamic-demo: dynamic-demo.o ColorPoint.o Point.o ThreeDPoint.o
	g++ dynamic-demo.o ColorPoint.o Point.o ThreeDPoint.o -o dynamic-demo

dynamic-demo.o: dynamic-demo.cpp Point.h ColorPoint.h ThreeDPoint.h Rankable.h
	g++ -c dynamic-demo.cpp

Point.o: Point.cpp
	g++ -c Point.cpp

ColorPoint.o: ColorPoint.cpp Point.h Rankable.h
	g++ -c ColorPoint.cpp

ThreeDPoint.o: ThreeDPoint.cpp Point.h
	g++ -c ThreeDPoint.cpp

clean:
	rm *.o
