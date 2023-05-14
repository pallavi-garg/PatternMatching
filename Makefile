all:	
	g++ -std=c++11 main.cpp project.h reader.h kmp.cpp bmh.cpp brute.cpp rk.cpp bitap.cpp filereader.cpp -o project

clean:
	/bin/rm -rf *.o project