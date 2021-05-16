OUTPUT = main

all: build run

build:
	g++ ./*cpp -l sqlite3 -o $(OUTPUT)

run:
	./$(OUTPUT)

delete:
	rm $(OUTPUT)