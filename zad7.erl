-module(zad7).

-export([main/0,server/0]).

main() ->
	{myshell,'wojtek@PL-00001353'} ! {self(), [5,7]},
	receive
		{_Pid, Numbe} ->
			io:format("~p",[Numbe])
	end.

server() ->
	receive
		{Pid, [Head | Tail]} ->
			[X | _Y] = Tail,
			Z = Head + X,
			Pid ! {self(), Z}
	end.