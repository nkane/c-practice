set -e 

# compile program
echo "compiling program ..."
make

echo "creatig database file ..."
# create database
./ex17 db.dat c

echo "inserting record(s) ..."
./ex17 db.dat s 0 test0 test0@gmail.com
./ex17 db.dat s 1 test1 test1@gmail.com
./ex17 db.dat s 2 test2 test2@gmail.com

echo "selecting record(s) ..."
./ex17 db.dat g 0
./ex17 db.dat g 1 
./ex17 db.dat g 2

echo "listing record(s) ..."
./ex17 db.dat l

echo "deleting record(s) ..."
./ex17 db.dat d 0
./ex17 db.dat d 1
./ex17 db.dat d 2

echo "removing database file ..."
rm ./db.dat
