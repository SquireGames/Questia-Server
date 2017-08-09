# Questia Server
This is the server for the game Questia, found [here](https://github.com/SquireGames/Questia).
It is written in c++ with the SFML API for rendering, networking and audio. It relies on the Questia 
Engine library, found [here](https://github.com/SquireGames/Questia-Engine).
All of the source code is open source, so use the code in your own projects.
 
 
Building:
----------------
Questia Server currently supports Windows and Linux OS. A compilation guide is found [here](https://github.com/SquireGames/Questia-Server/wiki/Compiling-guide).

Other dependencies that are not found in this repository are the Data and Media folders, which are not open source. 
You must attain a copy of the game to have access to those files.


Arguments:
----------------

All argumants are optional

-n <server name> (defualt = "Questia Server")

-r <tick rate> (default = 32)

-c <max threads> (default = 4)

-u <udp port> (default = 7777)

-t <tcp port> (default = 7778)


License:
----------------
This project is licensed under the terms of the GNU GPLv3 license, see LICENSE.txt.
