# ENGR103Final

Game Description/Rules:
	Inspired by Night Light Fright (Mario Party Minigame) 
https://youtu.be/_X06FSGQlWQ?si=h8guy8h4gahJznNN 
This game is basically a game of chicken. Are you going to play it safe for an alright score or push your luck to win? The way I will translate this game to a Circuit Playground is by having an enemy (designated by a colored neopixel) start at the bottom of the board with a player character (designated by other colored neopixels) on the opposite end. The enemy will move toward the player at a random speed that can increase or decrease at any time. The player can stop the enemy from moving by pressing either button. The player’s score (distance between enemy and character) will then be printed in the serial monitor. 
The switch can be used to start the game.
Either button can be used to stop the enemy

User Inputs/Outputs Definition:

Outputs:
Enemy (shown by moving light)
Player Character (shown by colored light)

Inputs:
“Start game” switch
“Enemy Stop” button press
