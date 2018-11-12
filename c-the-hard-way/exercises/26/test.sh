echo 'Building logfind'
make clean
make

echo 'Cleaning up any dump files'
rm -rf ./dump*.txt

echo 'Running logfind test'
./logfind test> dump1.txt


echo 'Running logfind test message'
./logfind test message> dump2.txt


echo 'Running logfind -o test message'
./logfind -o test message> dump3.txt
