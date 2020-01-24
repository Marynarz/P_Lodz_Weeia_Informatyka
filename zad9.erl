-module(zad9).

-export([start/0]).

-record(person,{first_name,last_name,phone_number,city,street}).

start() ->
	ets:new(persons,[set,named_table,{keypos,3}]),
	main().
	
main() ->
	io:format("~nWhat shall I do, Master?~nA - add new user~nM - Modify user~nD - delete by last ame~nE-Delete by phone~nL-list all~nF-Find user~nQ - quit~n~n"),
	
	{_,[N]} = io:fread("Command: ","~s"),
	
	case N of
		"Q" ->done,
		erlang:halt();
		"A" -> addUser();
		"L" -> listUsers();
		"D" -> deleteUser();
		"M" -> modifyUser();
		_ -> io:format("~nTry again~n")
	end,
	main().

%ready	
addUser() ->
	{ok,[FN,LN,PN,CI,ST]} = io:fread("FirstName LastName PhoneNumber City Street: ","~s ~s ~d ~s ~s"),
	ets:insert(persons,[#person{first_name = FN, last_name= LN,phone_number = PN,city = CI, street = ST}]),
	main().
%ready	
listUsers()->
	io:format("~p~n",[ets:tab2list(persons)]),
	main().
	
modifyUser() ->
	{ok,[LN]} = io:fread("LastName: ","~s"),
	io:format("~p~n",[ets:lookup(persons,LN)]),
	{ok,[FN,LN2,PN,CI,ST]} = io:fread("FirstName LastName PhoneNumber City Street: ","~s ~s ~d ~s ~s"),
	ets:insert(persons,[#person{first_name = FN, last_name= LN2,phone_number = PN,city = CI, street = ST}]),
	main().
%ready
deleteUser() ->
	{ok,[LN]} = io:fread("LastName: ","~s"),
	ets:delete(persons,LN),
	io:format("~nOK!~n"),
	main().
	