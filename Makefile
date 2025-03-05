PERFORMANCE_OPTIONS = -O3
OPTIONS = -std=c++14 -Wall -Wextra

all: build/utils.o build/compress.o build/decompress.o build/compressor.o build/decompressor.o

build/utils.o: include/lz77.hpp
	g++ src/utils.cpp -I include -c -o build/utils.o ${OPTIONS} ${PERFORMANCE_OPTIONS}

build/compress.o: build/utils.o include/lz77.hpp
	g++ src/compress.cpp -I include -c -o build/compress.o ${OPTIONS} ${PERFORMANCE_OPTIONS}

build/decompress.o: build/utils.o include/lz77.hpp
	g++ src/decompress.cpp -I include -c -o build/decompress.o ${OPTIONS} ${PERFORMANCE_OPTIONS}

build/compressor.o: build/utils.o build/compress.o include/lz77.hpp
	g++ tools/compressor.cpp -I include build/utils.o build/compress.o -o build/compressor ${OPTIONS} ${PERFORMANCE_OPTIONS}

build/decompressor.o: build/utils.o build/decompress.o include/lz77.hpp
	g++ tools/decompressor.cpp -I include build/utils.o build/decompress.o -o build/decompressor ${OPTIONS} ${PERFORMANCE_OPTIONS}

clean_results:
	rm -rf ./test/*_decompressed.txt

clean_build:
	rm -rf ./build/*