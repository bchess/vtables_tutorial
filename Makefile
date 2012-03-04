all:	virtual virtual2 virtual3 virtual4 virtual5 virtual6

virtual: virtual.cpp
	g++ -o virtual virtual.cpp

virtual2: virtual2.cpp
	g++ -g -o virtual2 virtual2.cpp

virtual3: virtual3.cpp
	g++ -g -o virtual3 virtual3.cpp

virtual4: virtual4.cpp
	g++ -g -o virtual4 virtual4.cpp

virtual5: virtual5.cpp
	g++ -g -o virtual5 virtual5.cpp

virtual6: virtual6.cpp
	g++ -g -o virtual6 virtual6.cpp
