
# code details

EXE_DIR = .
EXE = $(EXE_DIR)/basicQuadtree
#for origin
SRC= main.c buildTree.c writeTree.c
#for test
#SRC= test.c buildTree.c writeTree.c

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
	rm -f $(OBJ) $(EXE)

# dependencies

main.o:  main.c
buildTree.o:  buildTree.c
writeTree.o:  writeTree.c 
#test.o:  test.c

