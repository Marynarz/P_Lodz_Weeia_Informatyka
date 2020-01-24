-module(zad5).

-export([int2bcd/1,bcd2int/1]).

int2bcd(X) ->
	L = integer_to_list(X),
	Lt = << << (T - $0) :4 >> || T <- L >>,
	io:format("~p",[Lt]).
	
bcd2int(X) ->
	Lt = [ T + $0 || <<T:4>> <= X ],
	W = list_to_integer(Lt),
	io:format("~p",[W]).