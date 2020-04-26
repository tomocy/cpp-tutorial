gcc_options = -std=c++17 -Wall --pedantic-errors

run: program
	./program

program: main.cc all.h.gch all.h
	g++ $(gcc_options) -include all.h -o $@ $<

all.h.gch: all.h
	g++ $(gcc_options) -x c++-header -o $@ $<

clean:
	rm -f program
	rm -f all.h.gch

.PHONY: run clean