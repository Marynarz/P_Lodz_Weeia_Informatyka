-module(zad4).

-export([initialize/0]).

-record(person,{first_name,last_name,phone_number,city,street}).

initialize() ->
	%Pe = #person{},
	Users = [],
	initialize(Users).
	
initialize(Users) ->
	io:format("~nWhat shall I do, Master?~nA - add new user~nM - Modify user~nD - delete by last ame~nE-Delete by phone~nL-list all~nF-Find user~nQ - quit~n~n"),
	
	{_,[N]} = io:fread("Command: ","~s"),
	
	case N of
		"Q" ->done,
		erlang:halt();
		"A" -> addUser(Users);
		"L" -> listUsers(Users);
		"D" -> deleteUser(Users);
		_ -> io:format("~nTry again~n")
	end,
	initialize(Users).
	
addUser(Users) ->
	{ok,[FN,LN,PN,CI,ST]} = io:fread("FirstName LastName PhoneNumber City Street: ","~s ~s ~d ~s ~s"),
	Pe = #person{first_name = FN, last_name= LN,phone_number = PN,city = CI, street = ST},
	initialize(Users ++ [Pe]).
	
listUsers(Users)->
	io:format("~n~p~n",[Users]),
	initialize(Users).
	
%modifyUser(Users) ->
deleteUser(Users) ->
	{ok,[LN]} = io:fread("LastName: ","~s"),
	X1 = [R || R <-Users , R#person.last_name /= LN],
	io:format("~nOK!~n"),
	initialize(X1).
	