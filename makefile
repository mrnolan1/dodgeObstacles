# Note: If a source file includes header files other than its own
# matching header (for example, if game.cpp includes button.hpp),
# add those headers to that object's dependency line below.

# I have included all headers for "test.cpp" and "main.cpp".
# If those later don't require all headers, adjust accordingly.

CC = g++ 
FLAGS = -Wall -std=c++17 -pedantic-errors



all: exe/game

test: exe/test



runAll: exe/game
	./exe/game

runTest: exe/test
	./exe/test



exe/game: obj/main.o obj/button.o obj/character.o obj/game.o obj/howtoplay.o obj/obstacle.o obj/play.o obj/menu.o obj/skins.o | exe
	$(CC) $(FLAGS) $^ -o $@


exe/test: obj/button.o obj/character.o obj/game.o obj/howtoplay.o obj/obstacle.o obj/play.o obj/menu.o obj/skins.o obj/test.o | exe
	$(CC) $(FLAGS) $^ -o $@



obj/main.o: src/main.cpp hdr/button.hpp hdr/character.hpp hdr/game.hpp hdr/howtoplay.hpp hdr/obstacle.hpp hdr/play.hpp hdr/skins.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/button.o: src/button.cpp hdr/button.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/character.o: src/character.cpp hdr/character.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/game.o: src/game.cpp hdr/game.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/howtoplay.o: src/howtoplay.cpp hdr/howtoplay.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/obstacle.o: src/obstacle.cpp hdr/obstacle.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/play.o: src/play.cpp hdr/play.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/menu.o: src/menu.cpp hdr/menu.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/skins.o: src/skins.cpp hdr/skins.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/test.o: src/test.cpp hdr/button.hpp hdr/character.hpp hdr/game.hpp hdr/howtoplay.hpp hdr/obstacle.hpp hdr/play.hpp hdr/menu.hpp hdr/skins.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@




obj:
	mkdir -p obj

exe:
	mkdir -p exe