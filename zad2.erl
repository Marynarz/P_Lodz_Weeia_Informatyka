-module(zad2).
-export([readUser/0]).

%jesli 42
readUser(42) ->
	io:format("Yes!~n");
%jesli inne
readUser(_) ->
	io:format("Try again~n"),
	readUser().
%interfejs
readUser() ->
	{_ ,[N]} = io:fread("Liczba: ","~d"),
	readUser(N).