CXX = g++
CXXFLAGS = -Wall -MMD -g
EXEC = cc3k
OBJECTS = boostatck.o dragon.o enemy.o human.o orcs.o small.o boostdef.o dragonhoard.o factory.o main.o player.o troll.o cell.o drow.o game.o merchant.o poisonheath.o vampire.o controller.o dwarf.o	goblin.o merchanthoard.o restorehealth.o woundatk.o display.o elf.o halfling.o normal.o shade.o wounddef.o 
DEPENDS = ${OBJECTS:.o=.d}

${EXEC}: ${OBJECTS}
	${CXX} ${CXXFLAGS} ${OBJECTS} -o ${EXEC}

-include ${DEPENDS}

.PHONY: clean

clean:
	rm ${OBJECTS} ${EXEC} ${DEPENDS}
