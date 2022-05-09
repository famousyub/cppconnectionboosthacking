-module(converter).
-export([conv/2,conv_length/1,list_length/1]).


conv(M,inch ) ->
    M/2.54;

conv(M,inch)->
    M*2.54.


conv_length({centimeter,X})->
    {inch,X / 2.54 };
conv_length ({inch,X})->
    {centimeter,X*2.54}.


list_length([])->
    0;

list_length([First|Rest])->
    1+ list_length(Rest).
