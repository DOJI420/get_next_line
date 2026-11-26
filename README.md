*This project has been created as part of the 42 curriculum by yibn-yah*



cc -Wall -Wextra -Werror -D BUFFER_SIZE=5 *.c -o b && 
valgrind --leak-check=full--show-leak-kinds=all ./b text.txt