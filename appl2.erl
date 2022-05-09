-module(appl2).
-export([start/0,double/1,fact/2,mult/2]).

start()->
    0 + 0 .

fact(1,1)->
    1;
fact(X, Y)->
    (X+ Y) * fact(X-1,Y-1).

mult(X,Y)->
    X * Y .




double (X) ->
    2 * X.
