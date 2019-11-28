all: 	
		clear
		lex lexica.l
		yacc -d sintatica.y -v
		g++ -o glf y.tab.c -ll

		./glf < exemplo.ç
