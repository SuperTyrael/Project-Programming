
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/basicQuadtree
ifeq ($(task),$(1))
#for origin
#SRC= main.c buildTree.c writeTree.c destroyTree.c
#for testTask1
#SRC= testTask1.c buildTree.c writeTree.c destroyTree.c
#for testTask2
SRC= testTask2.c buildTree.c writeTree.c destroyTree.c removeChildren.c

# generic build details

CC=      cc
COPT=    -g
CFLAGS= -lm

# compile to  object code

OBJ= $(SRC:.c=.o)

.c.o:
	$(CC) $(COPT) -c -o $@ $<

# build executable

$(EXE): $(OBJ)
	$(CC) $(OBJ) $(CFLAGS) -o $(EXE) 

# clean up compilation

clean:
	rm -f $(OBJ) $(EXE) quad.out

# dependencies

main.o:  main.c
buildTree.o:  buildTree.c
writeTree.o:  writeTree.c 
#test.o:  test.c

