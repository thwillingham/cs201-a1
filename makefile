OBJS=heapsort.c heap.c node.c linkedList.c queue.c stack.c listNode.c helpers.c
heapsort: $(OBJS)
	gcc -g $(OBJS) -o heapsort

clean:
	rm *.o

