comp: 	
		clear
		lex lexica.l
		yacc -d sintatica.y -v
		g++ -o glf y.tab.c -ll

		./glf < exemplo.ç

exec: 	
		clear
		lex lexica.l
		yacc -d sintatica.y -v
		g++ -o glf y.tab.c -ll

		./glf < exemplo.ç > teste.c
		gcc -o teste teste.c
		clear
		./teste
