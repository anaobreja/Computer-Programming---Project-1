
build: infinite_product gigel_and_the_checkboard simple_queries another_queries

infinite_product: infinite_product.c
	gcc infinite_product.c -o infinite_product -Wall -Wextra -lm 

gigel_and_the_checkboard: gigel_and_the_checkboard.c
	gcc gigel_and_the_checkboard.c -o gigel_and_the_checkboard -Wall -Wextra -lm

simple_queries: simple_queries.c
	gcc simple_queries.c -o simple_queries -Wall -Wextra -lm

another_queries: another_queries.c
	gcc another_queries.c -o another_queries -Wall -Wextra -lm

clean:
	rm -f infinite_product gigel_and_the_checkboard simple_queries another_queries

.PHONY: pack clean
