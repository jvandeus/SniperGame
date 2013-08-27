# Sniper Game

This is a game made using SDL 2.0.0. The inspiration for this project is games such as Material Sniper. The player will shoot various as if	 They were a stationary sniper shooting from a distance. This is a small project focused on learning SDL and game programming with possible expansion in the future into a full independant game.	

The project uses the following extensions to SDL as well:
SDL2_image-2.0.0, SDL2_mixer-2.0.0, SDL2_ttf-2.0.12

There is no current functionality as of yet.

##Current goals include the following:
* Custom cursor to facilitate crosshair and/or scope. 
* Background gets a "scoped" or "zoomed" effect, in a circular shape.
* After this is acheived, other sprites and should also be zoomed in the scoped circle when hovering over location with the mouse.
* Clicking the mouse simulates firing the projectile.
* Other generally usefull effects such as outlining a sprite in a certain color to show focus or that they are behing an object.
* Possible line effect similar to Legend of Dragoon For reloading or combos of some kind. This means that lines come from outside the	screen to center in on a target.

This  has the subsystem Console by default for debug proposes.	change the subsytem for all configurations to windows when distributing.This is set to x86 architecture. Running may require the runtime to be added to the executable's directory, Found in the SDL2-2.0.0-win32-x86 folder.