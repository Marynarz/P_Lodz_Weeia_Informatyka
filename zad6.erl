-module(zad6).

-export([main/0,server/0]).

main() ->
	Serv = spawn(zad6,server,[]),
	Serv ! {self(), [5,7]},
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