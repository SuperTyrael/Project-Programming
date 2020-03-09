
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/basicQuadtree
SRC=testTask3.c buildTree.c writeTree.c destroyTree.c removeChildren.c  nodeValue.c nodeCheckExtend.c
#SRC= testTask3.c buildTree.c writeTree.c destroyTree.c removeChildren.c nodeCheck.c nodeValue.c

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

testTask3.o:  testTask3.c
buildTree.o:  buildTree.c
writeTree.o:  writeTree.c
destroyTree.o: destroyTree.c
removeChildren.o: removeChildren.c 
nodeCheck.o: nodeCheck.c
nodeValue.o: nodeValue.c
nodeCheckExtend.o: nodeCheckExtend.c


