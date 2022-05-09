-module(apppl1).
-export([start/0]).


start()->
    inets:start(),
    Pid =inets:start(httpd,[{port,8081},{server_name,"http_test"},
        {server_root,"/tmp"},{document_root,"/tmp/datas"},
        {bind_address,"localhost"}]),io:write("~p",[Pid]).
