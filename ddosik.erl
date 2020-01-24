-module(ddosik).
-export([main/1]).

main(X) ->
	{myshell,'gosia2@PL-00002127'} ! {self(), [5,7]},
	main(X-1).
