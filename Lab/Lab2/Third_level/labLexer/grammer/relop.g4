lexer grammar relop;

@lexer::members {/* public lexer declarations section */
void PrintRelop(const char *relop)
{
	printf("(relop,%s)", relop);
	return;
};
}

tokens {
    Equal,
    NonEqual,
    Less,
    Greater,
    LessEqual,
    GreaterEqual,
    ID,
    WS
}
fragment Other: ~[<>=\r\n] ;

Equal: '=' {PrintRelop("=");};
NonEqual: '<>' {PrintRelop("<>");};
Less: '<' {PrintRelop("<");};
Greater: '>' {PrintRelop(">");};
LessEqual: '<=' {PrintRelop("<=");};
GreaterEqual: '>=' {PrintRelop(">=");};
ID: Other+ {std::cout << "(other,"; std::cout << getText().length(); std::cout << ")";} ;
WS: [\r\n] -> skip ;
