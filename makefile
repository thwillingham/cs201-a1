OBJS=heapsort.c heap.c node.c linkedList.c
heapsort: $(OBJS)
	gcc -g $(OBJS) -o heapsort

