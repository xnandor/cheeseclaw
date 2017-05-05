LIB=./lib/
BIN=./bin/
SRC=./src/
INC=./include/
SOURCEFILES=$(wildcard $(SRC)*.cpp)

PROG=cheeseclaw
PROGPATH=$(BIN)$(PROG)
CXX=clang++
CXXFLAGS=
LIBS=-lSDL2

EMACS-BUILD-FROM-SRC=make -C ../ build
EMACS-RUN-FROM-SRC=../bin/cheeseclaw
#-------------------------------------------------------------------------------------

clean:
	rm -f $(BIN)*

run: build
	$(PROGPATH)

build: $(PROGPATH)

$(PROGPATH): $(SOURCEFILES)
	$(CXX) $(CXXFLAGS) -I$(INC) -L$(LIB) $(LIBS) $^ -o $@


