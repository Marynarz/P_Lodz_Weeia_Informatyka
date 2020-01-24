-module(zad3).

-export([testCases/0]).

readUser(N) when N >= 1 ->
	{_,[S]} = io:fread("Tekst: ","~s"),
	isPali(S),
	readUser(N-1);
readUser(0) ->
	done.
	
isPali(S) ->
	Rc = lists:reverse(S),
	if
		S =:= Rc ->
			io:format("Tak~n");
		true ->
			io:format("Nie~n")
	end.
	
testCases() ->
	{_,[N]} = io:fread("Ilosc testow: ","~d"),
	readUser(N).