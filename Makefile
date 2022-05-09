default: build

build: clean
    gcc -Wall -o curl main.c util.c -l curl 

clean:
    rm -rf curl 

test: build
    ./curl https://freegeoip.app/json/ 