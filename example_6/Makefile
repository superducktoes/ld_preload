TARGET = example_6

all: main.c
	@gcc main.c -g -o ${TARGET}
	@gcc -shared -g -fPIC inject.c -o inject.so -ldl
run:
	@LD_PRELOAD=./inject.so ./${TARGET}
readelf:
	readelf -h ./{$TARGET}
ldd:
	ldd ./${TARGET}
strace:
	strace ./${TARGET}
start_server:
	node server.js &
clean:
	rm -f *~
