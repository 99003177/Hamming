SRC = src/hamming1.c\
Unity-master/src/unity.c\
test/test_hamming1.c\
Users/hp/Desktop/main.c

INC = -Iunity\
-Iinc\
-Itest

PROJECT_NAME = HAMMING1.exe

$(PROJECT_NAME): $(SRC)
	gcc $(SRC) $(INC) -o $(PROJECT_NAME)

run:$(PROJECT_NAME)
	./${PROJECT_NAME}
doc:
	make -C documentation
clean:
	rm -rf $(PROJECT_NAME) documentation/html