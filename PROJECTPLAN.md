# Object Oriented Programming Project Plan Document

## Use case and description of the project idea
In this game, the user will be able to control a character utilising the Arrow keys to move the character along with `SPACEBAR` in order to shoot arrows 
in the direction that the character is facing. The aim of this game is to progress through the multiple stages and levels of the game that increase with 
difficulty as the user progresses through them defeating enemies along the way and to eventually defeat a final boss on the last level. The player can also
receive improvements to their movement speed and arrow damage by purchasing upgrades with coins earnt by killing enemies.

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
The Arrow class inherits all the data it needs from the Projectile class.
The Arrow class has following function members:
- ```void initTexture()```
- ```void initSprite()```
- ```Arrow()```
- ```bool is_hit()```


**Boss**  
The Boss class has the following list of data, and inherits the Enemy class:
- ```int sword_index```
- ```Projectile* swords```

The Boss class has following function members:
- ```void resize()```
- ```Boss()```
- ```void draw(Renderwindow* window)```
- ```void use_sword()```
- ```bool successful_hit()```
- ```~Boss()```


**Character**  
The Character class has the following list of data:
- ```bool alive```
- ```float speed```
- ```int health```
- ```int damage```

The Character class has following function members:
- ```virtual void draw(Renderwindow* window) = 0```
- ```void take_damage(int damage_received)```
- ```int get_health()```
- ```int get_damage()```
- ```bool is_alive()```
- ```float get_speed()```
- ```void die()```

**Enemy**  
The enemy class has the following list of data, and inherits the Character class:
- ```Sprite sprite```
- ```Texture texture```

The Enemy class has following function members:
- ```void initTexture()```
- ```void initSprite()```
- ```Enemy()```
- ```void activate_enemy(Vector2f spawn_point, int max_hp, int damage, float speed)```
- ```Vector2f get_position()```
- ```virtual void draw(Renderwindow* window)```


**Game**  
The Game class has the following list of data:
The Game class has following function members:

**Player**  
The Player class has the following list of data:
- ```Sprite playerSprite```
- ```Texture playerTexture```
- ```Projectile* arrows```
- ```int gold```
- ```int arrows_left```
- ```int arrow_index```
- ```bool reload_arrows```

The Player class has following function members:
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
The Projectile class has the following list of data:
- ```Texture texture```
- ```Sprite sprite```
- ```float speed```
- ```Vector2f direction```
- ```bool fired```

The Projectile class has following function members:
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
The Sword class inherits all the data it needs from the Projectile class.
The Sword class has following function members:
- ```void initTexture()```
- ```void initSprite()```
- ```Sword()```
- ```bool is_hit(Vector2f enemy_position)```

## Relationship between classes
The game will be run from the Game class, using its run() function, which will have the game code in it.
This Game class will have the Player, Enemy, and Boss data members within it, which will interact with each other to run the game.
The Character class is an abstract class that has the data members of a generic character within the game, and the classes Player and Enemy will inherit this class.
The Enemy and Player classes will expand upon the Character class, and specialise it into the roles that the game needs.
The Boss class will further inherit the Enemy class, and add upon it so it can throw swords at the player in addition to having the abilities of a generic enemy.
The Projectile class is an abstract class that has the data members of a generic projectile, and the two types of projectiles used (Sword and Arrow) will inherit this class.
As the Sword and Arrow class have different sprites, textures and collision detection logic, which is why the Projectile class has three pure virtual functions, which allows for the function to be redefined in the derived classes.
The Boss class will have a data member which allows it to throw swords (Projectile* swords), and the Player class will have a data member which allows it to shoot arrows (Projectile* arrows).


## Tasks and timeline
1. Planned the concepts ideas and design of the game with members (Week 8 Wednesday)
2. Delegated tasks and parts of the game to each individual member to complete (Week 8 Wednesday)
4. Added character that can be controlled by user utilising the ```WASD``` keys and ```SPACEBAR``` to fire arrows (Week 8 Friday)
5. Added enemies that approach player from the rightside of the screen that can be killed by arrows fired by the player (Week 1 Holidays Tuesday)
6. Add collision detection so that the game can tell when the enemy hits the player/arrows hits enemy, and add mechanisms to deal damage to the player/enemy. (Week 1 Holidays Friday)
7. Add upgrade mechanisms to the player so that player can buy upgrades to speed/damage with gold collected from the enemies. (Week 2 Holidays Monday)
8. Add waves of enemies that progressively get stronger as time passes. (Enemies are faster, do more damage, and have more health) (Week 2 Holidays Thursday)
9. Add a boss at the end that has a large amount of health and can throw swords at the player that deal damage. (Week 9 Monday)
10. Add a score system to the game. (Week 9 Wednesday)
11. Add an instruction screen at the start of the game. (Week 9 Friday)
11. Add an ending screen when the player dies/completes the game (has killed the final boss) that shows the player's stats. (Week 10 Tuesday)
12. Add a restart game feature. (Week 10 Friday)

## User Interface and Interaction
The player will interact with the game using the keyboard, using the arrows key to move, spacebar to shoot arrows.
The player will also use the keyboard to purchase upgrades (U and Z buttons), which will be shown at the bottom of the screen to remind the player.

## Unit Testing and Debugging 
            
