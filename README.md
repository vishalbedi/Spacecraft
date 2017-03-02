# Spacecraft

Implementation Details

You should separate the declaration of the class (header file), from its implementation (source file).
You are free to design the private state and behavior of your classes as you desired.
It is strongly recommended that you break up the implementation of Nasa's main loop.
The storage of the spacecrafts in the NASA class that are created during the simulation must be implemented using a list. This collection makes the most sense as it is the most efficient at removing elements from any location in the fleet.
Your program must dynamically create and destroy spacecrafts using the heap. You should not make any unnecessary extra copies.
Spacecraft

After implementing this class you can verify the signatures are correct using the supplied test_spacecraft.cpp file from above.

NASA Commands

The main loop prompts the user with > and accepts the command listed below (all interaction is done with standard input and output).

If ever a ship number is provided that is invalid, the following should be displayed:

    > copy 500
    Ship 500 not found!
If a command is entered, it is guaranteed to have the corret number of arguments and types. If a command from the list below is not entered, the following should be displayed, e.g.:

    > sdfsdf
    Unrecognized command: sdfsdf
If the enter key is pressed, the user should be reprompted.

create

The create command takes a single argument, a string for the ship name. The ship name is a single string with no spaces. If there is room in the fleet, it creates a new ship and adds it to the end of the fleet, e.g.:

    > create Lonestar
    Creating: Spacecraft(1){name=Lonestar, warp=0, velocity=0, distance=0}
If the fleet is full, it displays the following message:

    > create Apollo13
    Can't create any more ships!
copy

The copy command takes a single argument, the id of an existing ship. If the fleet is not full, it creates a copy of the ship and adds it to the end of the fleet.

    > copy 1
    Copying: Spacecraft(11){name=Lonestar copy, warp=0, velocity=0, distance=0}
If the fleet is full, a copy is not made and it displays the following message:

    > copy 1
    Can't create any more ships!
destroy

The destroy command takes a single argument, a ship number. If the ship is in the fleet it should be removed from its position and decomissioned, e.g.:

    > destroy 1
    Destroying: Spacecraft(1){name=Lonestar, warp=0, velocity=0, distance=0}
distance

The distance command takes a single argument, a ship number. If the ship is in the fleet it should have it's total distance in light years travelled displayed, e.g.:

    > distance 1
    Lonestar has flown 6.33764e-06 light years
fly

The fly command takes two arguments, a ship number and a number of seconds to fly. If the ship is in the fleet it should fly for the amount of time based on its current velocity. A message should display how many light years the ship travelled, by name, e.g.:

    > fly 1 40
    Yamato flies 40 seconds for .00342156 light years
list

The list command takes no arguments and displays each ship in the fleet from first to last, e.g.

    > list
    Spacecraft(2){name=A, warp=1, velocity=2.99792e+08, distance=2.99792e+09}
    Spacecraft(5){name=C, warp=9, velocity=2.18549e+11, distance=1.96694e+13}
print

The print command takes a single argument, a ship number. If the ship is in the fleet it is displayed, e.g.

    > print 5
    Spacecraft(5){name=C, warp=9, velocity=2.18549e+11, distance=1.96694e+13}
quit

The quit command exits the program. A message should display the total number of light years all ships (created and destroyed) have travelled. Afterwards, all remaining ships in the fleet should be decomissioned from first to last, e.g.:

    > quit
    All ships have flown a total of 4.49689e+12 light years
    Destroying: Spacecraft(1){name=Lonestar, warp=5, velocity=3.74741e+10, distance=4.49689e+12}
    Destroying: Spacecraft(2){name=A, warp=1, velocity=2.99792e+08, distance=2.99792e+09}
    Destroying: Spacecraft(5){name=C, warp=9, velocity=2.18549e+11, distance=1.96694e+13}
warp

The warp command takes two arguments, a ship number and a warp speed. If the ship is in the fleet it should set the warp speed, e.g.:

    > warp 1 5
    Enterprise set to warp speed 5
If the user sets a warp speed larger than 10, it should cap it at 10, e.g.:

    > warp 1 100
    Enterprise set to warp speed 10
The user will not enter a value less than 0 for the warp speed.

Main Program

Use the supplied ships.cpp to launch your NASA class.
