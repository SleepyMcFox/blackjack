CC = g++
CFLAGS = -I. -Wall -Wextra -Werror -g -pedantic -std=c++11 -fbounds-check -O2
DEPS = Card.h Deck.h Player.h Blackjack.h utils.h 
OBJ = Card.o Deck.o Player.o Blackjack.o
MAIN =  main.o
TEST = test.o

%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

app: $(MAIN) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

apptest: $(TEST) $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean
clean:
	rm *.o app apptest
