# Note: If a source file includes header files other than its own
# matching header (for example, if game.cpp includes button.hpp),
# add those headers to that object's dependency line below.

# I have included all headers for "test.cpp" and "main.cpp".
# If those later don't require all headers, adjust accordingly.

CC = g++
FLAGS = -Wall -Wno-deprecated-declarations -std=c++17 -pedantic-errors -I/opt/homebrew/include
LDFLAGS = -L/opt/homebrew/lib -lsfml-graphics -lsfml-window -lsfml-system



all: exe/game

allTest: exe/test



run: exe/game
	./exe/game

runTest: exe/test
	./exe/test



exe/game: obj/main.o obj/bubble.o obj/button.o obj/character.o obj/fastObstacle.o obj/game.o obj/controls.o obj/mediumObstacle.o obj/menu.o obj/obstacle.o obj/play.o obj/row.o obj/skins.o obj/slowObstacle.o | exe
	$(CC) $(FLAGS) $^ -o $@ $(LDFLAGS)


# exe/test: obj/button.o obj/character.o obj/game.o obj/controls.o obj/obstacle.o obj/play.o obj/menu.o obj/skins.o obj/test.o | exe
# 	$(CC) $(FLAGS) $^ -o $@ $(LDFLAGS)



obj/main.o: src/main.cpp hdr/bubble.hpp hdr/button.hpp hdr/character.hpp hdr/fastObstacle.hpp hdr/game.hpp hdr/controls.hpp hdr/mediumObstacle.hpp hdr/menu.hpp hdr/obstacle.hpp hdr/play.hpp hdr/row.hpp hdr/skins.hpp hdr/slowObstacle.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/bubble.o: src/bubble.cpp hdr/bubble.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/button.o: src/button.cpp hdr/button.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/character.o: src/character.cpp hdr/character.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/fastObstacle.o: src/fastObstacle.cpp hdr/fastObstacle.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/game.o: src/game.cpp hdr/game.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/controls.o: src/controls.cpp hdr/controls.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/mediumObstacle.o: src/mediumObstacle.cpp hdr/mediumObstacle.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/menu.o: src/menu.cpp hdr/menu.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/obstacle.o: src/obstacle.cpp hdr/obstacle.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/play.o: src/play.cpp hdr/play.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/row.o: src/row.cpp hdr/row.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/skins.o: src/skins.cpp hdr/skins.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/slowObstacle.o: src/slowObstacle.cpp hdr/slowObstacle.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@

obj/test.o: src/test.cpp hdr/button.hpp hdr/character.hpp hdr/game.hpp hdr/controls.hpp hdr/obstacle.hpp hdr/play.hpp hdr/menu.hpp hdr/skins.hpp | obj
	$(CC) $(FLAGS) -c $< -o $@




obj:
	mkdir -p obj

exe:
	mkdir -p exe



clean:
	rm -rf obj exe