all:
	gcc bubblesort.c -o bubble
	gcc countsort.c -o count
	gcc selectsort.c -o select
clean:
	rm count bubble select
