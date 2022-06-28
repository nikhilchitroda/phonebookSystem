
target: main.o createList.o  deleteList.o  editList.o  findFromList.o  printList.o  sortList.o
	gcc -o output main.o createList.o  deleteList.o  editList.o  findFromList.o  printList.o  sortList.o
	mv *.o ./obj
	mv output ./bin

main.o: ./src/main.c
	gcc -c ./src/main.c

createList.o: ./src/createList.c
	gcc -c ./src/createList.c

deleteList.o: ./src/deleteList.c
	gcc -c ./src/deleteList.c

editList.o: ./src/editList.c
	gcc -c ./src/editList.c

findFromList.o: ./src/findFromList.c
	gcc -c ./src/findFromList.c

printList.o: ./src/printList.c
	gcc -c ./src/printList.c

sortList.o: ./src/sortList.c
	gcc -c ./src/sortList.c

clean:
	rm -rf ./obj/*.o
