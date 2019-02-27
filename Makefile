all:pyc.so

pyc.so:pyc.o
	gcc -o $@ $^ -shared -fPIC

pyc.o:pyc.c
	gcc -c -o $@ $^ -fPIC `python3-config --includes` `python3-config --ldflags` 

clean:
	rm pyc.o pyc.so
