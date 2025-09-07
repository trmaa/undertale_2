#!/bin/bash

source ./scripts/make/colors.sh

ENGINE_SRC_DIR="engine_src"
GAME_SRC_DIR="game_src"
OBJECTS_DIR="objects"
GAME_DIR="UNDERTALE_2"

function compile_engine() {
        echo -e "${YELLOW}Compiling engine...$NC"

        mkdir -p $OBJECTS_DIR

	local files=$(find $ENGINE_SRC_DIR/src/ -name "*.cpp")
	local files_count=$(find $ENGINE_SRC_DIR/src/ -name "*.cpp" | wc -l)

	local index=1;
        for file in $files; do
                echo -en " * ${RED}Compiling $(basename $file)... "
		echo -e "${GREEN}[$index/$files_count]$NC"

                g++ $file -c -o $OBJECTS_DIR/eng_$(basename $file .cpp).o \
			-I$ENGINE_SRC_DIR/include

		index=$((index+1))
        done
}

function compile_game() {
	echo -e "${YELLOW}Compiling game...$NC"

	mkdir -p $OBJECTS_DIR

	local files=$(find $GAME_SRC_DIR/src/ -name "*.cpp")
	local files_count=$(find $GAME_SRC_DIR/src/ -name "*.cpp" | wc -l)

	local index=1;
        for file in $files; do
                echo -en " * ${RED}Compiling $(basename $file)... "
		echo -e "${GREEN}[$index/$files_count]$NC"

                g++ $file -c -o $OBJECTS_DIR/$(basename $file .cpp).o \
			-I$ENGINE_SRC_DIR/include -I$GAME_SRC_DIR/include

		index=$((index+1))
        done
}

function link() {
	echo -e "${YELLOW}Linking...$NC"
	g++ $OBJECTS_DIR/*.o -o $GAME_DIR/undertale_2 \
		-std=c++23 \
		-Wl,-rpath=./lib \
                -L$GAME_DIR/lib -lsfml-graphics -lsfml-window -lsfml-system
}

function build() {
        compile_game
        compile_engine
        link
}

function run() {
	cd UNDERTALE_2
	./undertale_2
	cd ..
}

function clean() {
	rm -r $OBJECTS_DIR
	rm $GAME_DIR/undertale_2
}

function main() {
	local start_time=$(date +%s)

	for callback in $@; do $callback; done

	local end_time=$(date +%s)
	local elapsed=$((end_time - start_time))

	echo -e "Done in $elapsed seconds!\n"
}

main $@
