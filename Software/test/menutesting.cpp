#include "../src/system.h"
#include "../src/menus/mainmenu.h"

int main()
{
    System system; //create system object
    //we will call our menu class "MenuState"
    system.pushState(new MainMenu(&system));  //we want to create a pointer at the game objects address. this will enter our menu.                                        
    system.systemLoop();    //now loop our system.
    return 0;
}


// auto connect to wifi 
// save previously connected wifi info and credentials to secret 


// In weather have option to open map and select location to add to weather targets. Lets user
// add location name for it as well and any other info 
// Make it an option while using the map regularly, that the user could select a location to add
// to weather locations.