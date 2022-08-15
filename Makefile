%: %.cpp
	g++ -std=c++11 $^

.PHONY: clean run

run:
	./a.out

clean:
	rm -rf a.out
