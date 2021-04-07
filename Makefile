link:
	gcc src/linkfuncs.c linkedlist.c -Idslibs -Iglibs -lncurses -o linkedlist
hash:
	gcc src/hashfuncs.c hash.c -Idslibs -Iglibs -lncurses -o hash
