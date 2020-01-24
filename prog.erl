-module(prog).
-export([main/0]).

main() ->
	% your code goes here
	{ok, [A]} = io:fread("","~d"),
	{ok, [B]} = io:fread("","~d"),
	io:format("~p",[A+B]),
	true.