CC = g++
CFLAGS = -g -Wall
TARGET = akinator

all: $(TARGET)

$(TARGET): main.o cNodo.o cArbol.o funciones.o
	$(CC) $(CFLAGS) -o $(TARGET) main.o cNodo.o cArbol.o funciones.o

main.o: main.cpp
	g++ -c main.cpp
cNodo.o: cNodo.cpp
	g++ -c cNodo.cpp
cArbol.o: cArbol.cpp
	g++ -c cArbol.cpp
funciones.o: funciones.cpp
	g++ -c funciones.cpp

clean:
	$(RM) $(TARGET)