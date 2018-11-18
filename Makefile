all:
	gcc bubblesort.c -o bubble
	gcc countsort.c -o count
clean:
	rm count bubble
