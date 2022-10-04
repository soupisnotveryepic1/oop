# Object Oriented Programming Project Plan Document

## Use case and description of the project idea
In this game, the user will be able to control a character using the arrow keys to move the character and the ```SPACEBAR``` to fire arrows in the 
direction that the character is facing. The aim of this game is for the player to progress through the multitude of stages of the game that increase in 
difficulty as the player progresses through them defeating enemies along the way with the goal of defeating a final boss at the end of the game. The 
player can also receive improvements to their movement speed and arrow damage by purchasing upgrades with gold earnt from killing enemies to keep up with 
the progressively increasing difficulty of the enemies as the player progresses through the game.

## Potential classes
- ```Arrow```
- ```Boss```
- ```Character```
- ```Enemy```
- ```Game```
- ```Player```
- ```Projectile```
- ```Sword```

## Potential data and function members of classes
**Arrow**  
The ```Arrow``` class inherits all the data and variables it needs from the ```Projectile``` class.

The ```Arrow``` class has following function members:
- ```void initTexture()```
- ```void initSprite()```
- ```Arrow()```
- ```bool is_hit()```


**Boss**  
The ```Boss``` class has the following list of data and variables, and inherits the Enemy class:
- ```int sword_index```
- ```Projectile* swords```

The ```Boss``` class has following function members:
- ```void resize()```
- ```Boss()```
- ```void draw(Renderwindow* window)```
- ```void use_sword()```
- ```bool successful_hit()```
- ```~Boss()```


**Character**  
The ```Character``` class has the following list of data and variables:
- ```bool alive```
- ```float speed```
- ```int health```
- ```int damage```

The ```Character``` class has following function members:
- ```virtual void draw(Renderwindow* window) = 0```
- ```void take_damage(int damage_received)```
- ```int get_health()```
- ```int get_damage()```
- ```bool is_alive()```
- ```float get_speed()```
- ```void die()```

**Enemy**  
The ```enemy``` class has the following list of data and variables, and inherits the ```Character``` class:
- ```Sprite sprite```
- ```Texture texture```

The ```Enemy``` class has following function members:
- ```void initTexture()```
- ```void initSprite()```
- ```Enemy()```
- ```void activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed)```
- ```Vector2f get_position()```
- ```virtual void draw(Renderwindow* window)```


**Game**  
The ```Game``` class has the following list of data and variables:

The ```Game``` class has following function members:

**Player**  
The ```Player``` class has the following list of data and variables:
- ```Sprite playerSprite```
- ```Texture playerTexture```
- ```Projectile* arrows```
- ```int gold```
- ```int arrows_left```
- ```int arrow_index```
- ```bool reload_arrows```

The ```Player``` class has following function members:
- ```void initTexture()```
- ```void initSprite()```
- ```Player()```
- ```void draw(Renderwindow* window)```
- ```void move_right()```
- ```void move_left()```
- ```void move_up()```
- ```void move_down()```
- ```void upgrade_speed()```
- ```void upgrade_damage()```
- ```void reload()```
- ```void use_arrow()```
- ```void change_gold(int amount)```
- ```int no_arrows_left()```
- ```bool successful_hit(Vector2f enemy_position)```
- ```bool hit_by_enemy(Vector2f enemy_position)```
- ```int get_gold()```
- ```Vector2f get_position()```
- ```~Player()```

**Projectile**  
The ```Projectile``` class has the following list of data and variables:
- ```Texture texture```
- ```Sprite sprite```
- ```float speed```
- ```Vector2f direction```
- ```bool fired```

The ```Projectile``` class has following function members:
- ```virtual void initTexture() = 0```
- ```virtual void initSprite() = 0```
- ```void move_projectile()```
- ```void use(Vector2f firing_position)```
- ```bool is_fired()```
- ```bool hit_target()```
- ```void initTexture()```
- ```void draw(Renderwindow* window)```
- ```virtual bool is_hit(Vector2f target_position) = 0```
- ```virtual ~Projectile()```

**Sword**
The ```Sword``` class inherits all the data and variables it needs from the ```Projectile``` class.

The ```Sword``` class has following function members:
- ```void initTexture()```
- ```void initSprite()```
- ```Sword()```
- ```bool is_hit(Vector2f enemy_position)```

## Relationship between classes
The game will be run from the ‘Game’ class using the ‘run()’ function which will contain the game’s code inside it. This ‘Game’ class contains the 
‘Player’, ‘Enemy’, and ‘Boss’ data members within it, which will interact with each other to run the game. The ‘Character’ class is an abstract class that 
has the data members of a generic character within the game, with both the 'Player’ and ‘Enemy’ classes inheriting this class. These classes will both 
expand upon the ‘Character’ class to form the roles required to fulfil the constructs of an ‘Enemy’ and ‘Player’ class. The ‘Boss’ class will inherit the 
‘Enemy’ class and add on the functionality and mechanisms required for it to throw swords at the player whilst still having the abilities and attributes 
of a generic enemy. The ‘Projectile’ class is an abstract class that has the data members of a generic projectiles, with both the ‘Sword’ and ‘Arrow’ 
projectile classes inheriting this class. As the ‘Sword’ and ‘Arrow’ classes both have different sprites, textures and collision detection logic, the 
‘Projectile’ class has been designed with three pure virtual functions, allowing for the function to be redefined in the derived classes. The ‘Boss’ class 
will have a data member which allows it to throw ‘Projectile’ swords, whereas the ‘Player’ class will have a data member which allows it to shoot 
‘Projectile’ arrows.


## Tasks and timeline
1. Discussed and planned the concepts ideas and design of the game with group members (14/09/2022)
2. Delegated tasks and parts of the game to complete to each individual member (14/09/2022)
3. Added main character into the game that can be controlled by the player utilising the arrow keys to move around and the spacebar to fire arrows in the 
direction that the character is facing (16/09/2022)
4. Added enemies that approach the player from the right-side of the screen that can be killed by arrows fired by the character (20/09/2022)
5. Added collision detection so that the game can determine when the main character is hit by an enemy or an enemy is hit by an arrow alongside mechanisms 
to deal damage to the player or enemies (23/09/2022)
6. Added upgrade mechanisms to the game so that the player can choose to purchase upgrades that can enhance their movement speed or arrow damage with the 
gold collected from killing enemies (26/09/2022)
7. Added a mechanism that progressively increases the strength and difficulty of killing the enemies by increasing their movement speed, damage output and 
amounts of health as the player progresses through the game (29/09/2022)
8. Added a boss at the end of the game that has a large amount of health and can throw swords that can do deal damage to the player (3/10/2022)
9. Added a scoring system that keeps track of the number of enemies killed the amount of gold collected (5/10/2022)
10. Added an instruction screen at the start of the game that introduces the player to the game and the controls required to play the game (5/10/2022)
11. Added an ending screen that appears once the player has either died when their health bar has reached zero or has completed the game by defeating the 
final boss that displays the final statistics of the player (11/10/2022)
12. Added a feature that allows the player to replay the game once they have either died or completed the game (14/10/2022)

## User Interface and Interaction
Upon initially starting up the game, the player will be greeted by an instruction that will introduce the player to the game and the controls required to 
play the game. To play and interact with the game, the player will utilise the keyboard, using the arrow keys to move and spacebar to shoot arrows. 
Additionally, the player will also be able to purchase upgrades utilising the ‘U’ and ‘Z’ keys on the keyboard, which will be displayed at the bottom of 
the screen to remind the player.

## Unit Testing and Debugging 
During the development of the game, small parts of the code will be tested before being added to the main game, using GDB to debug and ensure that the 
snippets of code are working as required. Once a snippet of code is added to the game, a test run of the entire game will be done to see if it has 
conflicted with any other parts of the game or caused unexpected functions to occur. If this has occurred, the game will then be debugged by utilising the 
built-in GDB debugger toolset to determine the root cause of the error. After determining the source of error, changes to the code will be made and 
implemented so that the program will behave as planned. This process will be repeated until the game is completed and functions as expected.
