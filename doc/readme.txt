Compiliazioni

Windows
-------
cmake -B build --preset vs2022-static
cmake --build build --config Release


Linux
-----
sudo apt-get install build-essential cmake pkg-config python3
sudo apt-get install libevent-dev libboost-dev
sudo apt-get install libzmq3-dev
sudo apt install systemtap-sdt-dev
sudo apt-get install qtbase5-dev qttools5-dev qttools5-dev-tools
sudo apt-get install libqrencode-dev
sudo apt install libsqlite3-dev
sudo apt-get install libqrencode
sudo apt install bison cmake curl make patch pkg-config python3 xz-utils
sudo apt-get install g++-multilib binutils


cd bitcoin/
cmake -B build 
cmake --build build 


Cartella depends
--------------------------
make

make x86_64-pc-linux-gnu
make bdb
make bdb.mk (non funzionava)

bgcointest
----------
cmake -B build -DBerkeleyDB_INCLUDE_DIR:PATH="/root/Svil/bitcoin/depends/x86_64-pc-linux-gnu/include" -DENABLE_WALLET=ON -DBUILD_GUI=ON -DWITH_BDB=ON
cmake --build build 


Build windows on Linux
----------------------
sudo apt-get install mingw-w64
sudo apt install nsis

Cartella depends
--------------------------
make HOST=x86_64-w64-mingw32

Cartella bgcoin
--------------------------
gmake -C depends HOST=x86_64-w64-mingw32

cmake -B build -DBerkeleyDB_INCLUDE_DIR:PATH="/root/Svil/bgcoin/depends/x86_64-w64-mingw32/include" -DENABLE_WALLET=ON -DBUILD_GUI=ON -DWITH_BDB=ON --toolchain /root/Svil/bgcoin/depends/x86_64-w64-mingw32/toolchain.cmake

cmake -B build -DBerkeleyDB_INCLUDE_DIR:PATH="/home/tommy/Svil/bgcointest/depends/x86_64-w64-mingw32/include" -DENABLE_WALLET=ON -DBUILD_GUI=ON -DWITH_BDB=ON --toolchain /home/tommy/Svil/bgcointest/depends/x86_64-w64-mingw32/toolchain.cmake

cmake --build build --target deploy
