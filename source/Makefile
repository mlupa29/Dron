CPPFLAGS= -c -g -Wall -pedantic -std=c++17 

__start__: example.out
	./example.out

example.out: Dr3D_gnuplot_api.o example.o  Bryla.o Plaszczyzna.o  
	g++ -o example.out example.o Dr3D_gnuplot_api.o Bryla.o Plaszczyzna.o   -lpthread

example.o: example.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o example.o example.cpp

Dr3D_gnuplot_api.o: Dr3D_gnuplot_api.cpp Dr3D_gnuplot_api.hh
	g++ ${CPPFLAGS} -o Dr3D_gnuplot_api.o Dr3D_gnuplot_api.cpp

Bryla.o: Bryla.cpp Bryla.hh
	g++ ${CPPFLAGS} -o Bryla.o Bryla.cpp

Plaszczyzna.o: Plaszczyzna.cpp Plaszczyzna.hh
	g++ ${CPPFLAGS} -o Plaszczyzna.o Plaszczyzna.cpp

Dr3D_gnuplot_api.hh: Draw3D_api_interface.hh
	touch Dr3D_gnuplot_api.hh

clear:
	rm example.out example.o Dr3D_gnuplot_api.o Bryla.o Plaszczyzna.o  
