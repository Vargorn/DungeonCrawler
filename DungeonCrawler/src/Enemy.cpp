#include"pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string name, const int& playerLvl) {
	this->level = rand() % playerLvl + 1;
	size_t first = name.find_first_of(' ');
	size_t last = name.find_last_of(' ');
	this->monster_nickName = name.substr(0, first);
	this->monster_name = name.substr(first + 1, last - first - 1);
	this->monster_class = name.substr(last + 1, name.size() - 1);
	this->setStats();
}
Enemy::Enemy()
{
}

void Enemy::setStats()
{
	if (this->monster_name == "Goblin")
	{
		this->strength = 1 * this->level + 2;
		this->endurance = 1 * this->level + 2;
		this->agility = 3 * this->level + 2;
		this->intelligence = 2 * this->level + 2;
		this->luck = 3 * this->level + 2;
		std::cout << R"(
             ,      ,   
            /(.-""-.)\
        |\  \/      \/  /|
        | \ / =.  .= \ / |
        \( \   o\/o   / )/
         \_, '-/  \-' ,_/
           /   \__/   \
           \ \__/\__/ /
         ___\ \|--|/ /___
       /`    \      /    `\
      /       '----'       \
 )" << std::endl;
	}
	else if (this->monster_name == "Ogre")
	{
		this->strength = 3 * this->level + 2;
		this->endurance = 2 * this->level + 1;
		this->agility = 1 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 1 * this->level + 1;
		std::cout << R"(

                           __,='`````'=/__
                          '//  (o) \(o) \ `'         _,-,
                          //|     ,_)   (`\      ,-'`_,-\
                        ,-~~~\  `'==='  /-,      \==```` \__
                       /        `----'     `\     \       \/
                    ,-`                  ,   \  ,.-\       \
                   /      ,               \,-`\`_,-`\_,..--'\
                  ,`    ,/,              ,>,   )     \--`````\
                  (      `\`---'`  `-,-'`_,<   \      \_,.--'`
                   `.      `--. _,-'`_,-`  |    \
                    [`-.___   <`_,-'`------(    /
                    (`` _,-\   \ --`````````|--`
                     >-`_,-`\,-` ,          |
                   <`_,'     ,  /\          /
                    `  \/\,-/ `/  \/`\_/V\_/
                       (  ._. )    ( .__. )
                       |      |    |      |
                        \,---_|    |_---./
                        ooOO(_)    (_)OOoo
)" << std::endl;
		
	}
	else if (this->monster_name == "Orc")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 1;
		this->agility = 1 * this->level + 1;
		this->intelligence = 2 * this->level + 1;
		this->luck = 1 * this->level + 2;
		std::cout << R"(
                        _,.---''```````'-.
                    ,-'`                  `-._
                 ,-`                   __,-``,\
                /             _       /,'  ,|/ \
              ,'         ,''-<_`'.    |  ,' |   \
             /          / _    `  `.  | / \ |\  |
             |         (  |`'-,---, `'  \_|/ |  |
             |         |`  \  \|  /  __,    _ \ |
             |         |    `._\,'  '    ,-`_\ \|
             |         |        ,----      /|   )
             \         \       / --.      {/   /|
              \         | |       `.\         / |
               \        / `-.                 | /
                `.     |     `-        _,--V`)\/        _,-
                  `,   |           /``V_,.--`  \.  _,-'`
                   /`--'`._        `-'`         )`'
                  /        `-.            _,.-'`
                              `-.____,.-'`
)" << std::endl;
		
	}
	else if (this->monster_name == "Troll")
	{
		this->strength = 3 * this->level + 2;
		this->endurance = 2 * this->level;
		this->agility = 1 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 1 * this->level + 1;
		//std::cout << "" << std::endl;
	}
	else if (this->monster_name == "Banshee")
	{
		this->strength = 1 * this->level + 1;
		this->endurance = 1 * this->level + 1;
		this->agility = 2 * this->level + 2;
		this->intelligence = 3 * this->level + 2;
		this->luck = 2 * this->level + 1;
		std::cout << R"(
                    ==\\
                     || \\
                  ________\
                 |________|\
                 | .\  /. | \
                {|   ^^   |}
                  \ /||\ /
                   \|__|/
              =____||  ||____=
     \\/\    /                \    /\//
    \\/  \  /           .      \  /  \//
     /    \/                    \/    \
      \            .                 /
       \                            /
        \_                        _/
                      .
    .                                   .
                     .  .

            (         .       )
         ( (   (                ) .
      .   (       .          .     )   )
        (    (        .   .          )
 .  ( (   .     (              )  )        )
     ( .            .
   (        .              .
..       .       .                    .

                                          .
    .           .                 .)" << std::endl;
	}
	else if (this->monster_name == "Chimera")
	{
		this->strength = 2 * this->level + 3;
		this->endurance = 2 * this->level + 3;
		this->agility = 2 * this->level + 2;
		this->intelligence = 1 * this->level + 2;
		this->luck = 2 * this->level + 1;
		std::cout << R"(
       ,'.` ,,,
     (( cxOS.'.)       _-- __)
      _~ ox.O s ) --__/   ^ \ ___------_
   _//o_  ))xx. ,)       (_ø \          `-_
  /      ))oS  . ))     /   "             |\__
  ø_---\ )).. S   )                       |   `---.___
    ("" \  )I . .)                        |           `--.__
     ___/ _/ S S)   \         \          /__                `--._
      ---'( SS\      |      ___\_        \  `-_._.-----___.-'    `-
         (S..S \     |___--      \_      |   /    /¢~~             )
           (( S |   /"             \_    |  (.------_             /
              ((|   |                |   /_  `""     \     ___,--'
                 |  |                |  /   _-- ______\  |/
                 |  |               /  /           --.___/
                _| /              _/ _/
              //__/             //__/
              ``                ``
)" << std::endl;
	}
	else if (this->monster_name == "Vampire")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 1 * this->level + 2;
		this->agility = 2 * this->level + 2;
		this->intelligence = 3 * this->level + 2;
		this->luck = 2 * this->level + 2;
		std::cout << R"(
                                  _.-.
                                 ._.-.\
                    .^         _.-'=. \\
                  .'  )    .-._.-=-..' \'.
               .'   .'   _.--._-='.'   |  `.  ^.
             .'   .'    _`.-.`=-./'.-. / .-.\ `. `.
           .'    /      _.-=-=-/ | '._)`(_.'|   \  `.
          /    /|       _.--=.'  `. (.-v-.)/    |\   \
        .'    / \       _.-.' \-.' `-..-..'     / \   `.
       /     /   `-.._ .-.'      `.'  " ". _..-'  |    |
      '      |    |   /   )        \  /   \   \    \    `.
     /      /    /   /   /\                \   \   |      \
    /      /    /  .'  .'\ `.        .'     \   |   \      \
   /      /    /  /   /   \  `-    -' .`.    .  \    \     |
  |      /    / .''\.'    | `.      .'   `.   \  |    |    |
 .'     /    / /   |      |      .'/       `.- `./    /    |
 |     /    .-|   /--.    / `.    |    _.-''\   |     |    \
.'    /  .-'  |  /    `-.|       .'\_.'      `. |`.   |    |
|    |.-'     / /       /           \          \ \ `. \     \
|    /       /  |      /             \         |  `. `.|    |
|   |       /   `.     |      `   .'  \        /    \  \    /
|   |      ///.-'.\    |       \ /    `\      / /-.  \ |    |
|   /      \\\\    `    \.-     |    `-.\     |/   \\\\'.   |
 \ |        \\\|        |      / \      |          //// |  /
 | |         '''        |     /   \     |          |//  |  \
 \ |                    |.-  |     \  .-|          ''   |  /
  \|                    /    |    / ` ../               / /
                        |'   /    |    /               | /
                        \.'  |    | `./                |/
                        /    \   /    \
                        \ `. /   \    /
                         |  |     '. '
                         /  |      |  \
                        /   |      /   `.
                       | | | \   .'  `.. \
                      / / / ._`. \.'-. \`/
                      |/ / /  `'  `  |/|/
                       \|\|
)" << std::endl;
	}
	else if (this->monster_name == "Shoggoth")
	{
		this->strength = 1 * this->level + 2;
		this->endurance = 3 * this->level + 1;
		this->agility = 1 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 1 * this->level + 1;
		std::cout << R"(

)" << std::endl;
	}
	else if (this->monster_name == "Fishman")
	{
		this->strength = 1 * this->level + 2;
		this->endurance = 1 * this->level + 1;
		this->agility = 3 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 3 * this->level + 1;
		std::cout << R"()" << std::endl;
	}
	else if (this->monster_name == "Centaur")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 2;
		this->agility = 2 * this->level + 1;
		this->intelligence = 1 * this->level + 1;
		this->luck = 2 * this->level + 1;
		std::cout << R"(
                                       (_______
                                    -.__\     __\
                                   _)        /  \
                                    \_ _    ( "("
                                     _>_     \_-/
                                        )/ ,-' (-.
                                         )/ _ - - )
                                         /,'| _)_)|
                          (_____        //  |   /||
                        .___\   \----._//___/ '( \\
                         _>    /    __//    ',,,\ )\
                        _)   /|    /,-/          )'\|
                        \   ( |     ,            |
                        /_,\(  \     \-.__\  (_, /
                       (    '   \    |  |  ) |\ /
                                _) _/ _/  /, )/ )
                               _) <\ (     ) |) |
                                 ) \)_\_   / / \(
                                 /_,\ \_\   )| /_\
                                   )_\     /_,) )_\
                                            |_\
)" << std::endl;
	}
	else if (this->monster_name == "Cerberus")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 2;
		this->agility = 2 * this->level + 2;
		this->intelligence = 1 * this->level + 1;
		this->luck = 2 * this->level + 1;
		std::cout << R"(
                            /\_/\____,
                  ,___/\_/\ \  ~     /
                  \     ~  \ )   XXX
                    XXX     /    /\_/\___,
                       \o-o/-o-o/   ~    /
                        ) /     \    XXX
                       _|    / \ \_/
                    ,-/   _  \_/   \
                   / (   /____,__|  )
                  (  |_ (    )  \) _|
                 _/ _)   \   \__/   (_
                (,-(,(,(,/      \,),),) )" << std::endl;
	}
	else if (this->monster_name == "Harpy")
	{
		this->strength = 2 * this->level + 2;
		this->endurance = 2 * this->level + 2;
		this->agility = 2 * this->level + 2;
		this->intelligence = 2 * this->level + 2;
		this->luck = 2 * this->level + 2;
		std::cout << R"(
         ,                                      ,
        |\                                      /|
     ,   \'._ ,                           ,  _.'/   ,
     |\  {'. '-`\,      ,-._**_.-,      ,/`-' .'}  /|
      \`'-'-.  '.`\      \*____*/      /`.'  .-'-'`/
    ,'-'-._  '.  ) )     /`    `\     ( (  .'  _.-'-',
    |\'- _ '.   , /     /  /""\  \     \ ,  .'  _ -'/|
     \'-.   .  ; (      \_|^  ^|_/      ) ;   .  .-'/
      `'--, . ;  {`-.      \__/      .-'}  ; . ,--'`
      '--`_. ;  { ^  \    _|  |_    /  ^ }  ; ._`--'
      `,_.--  ;  { ^  `-'`      `'-`  ^ }  ;  --._,`
        ,_.-    ; {^    /        \    ^} ;    -._,
         ,_.-`), /\{^,/\\_'_/\_'_//\,^}/\ ,(`-._,
           _.'.-` /.'   \        /   `.\ `-.'._
          `  _.' `       \      /       ` '._   `
                        .-'.  .'-.
                      .'    `` ^  '.
                     /  ^ ^   ^  ^  \
                     | ^    ^   ^   |
                    /^   ^/    \  ^  \
                    \,_^_/    ^ \_,^./
                     /=/  \^   /  \=\
                 __ /=/_   | ^|   _\=\ __
               <(=,'=(==,) |  | (,==)=',=)>
                 /_/|_\    /  \    /_|\_\
                 `V (=|  .'    '.  |=) V`
                     V  / _/  \_ \  V
                       `"` \  / `"`
                            \(
)" << std::endl;
	}
	
	if (this->monster_nickName == "Sneeky") {
		this->agility += 2;
	}
	else if (this->monster_nickName == "Crazy") {
		this->agility -= 1;
		this->intelligence += 3;
	}
	else if (this->monster_nickName == "Big") {
		this->agility -= 2;
		this->endurance += 2;
		this->strength += 2;
	}
	else if (this->monster_nickName == "Fat") {
		this->agility -= 3;
		this->endurance += 5;
	}
	else if (this->monster_nickName == "Annoying") {
		this->agility += 1;
		this->intelligence += 1;
	}
	else if (this->monster_nickName == "Terrifying") {
		this->strength += 2;
		this->intelligence += 2;
	}
	else if (this->monster_nickName == "Smart") {
		this->intelligence += 3;
	}
	else if (this->monster_nickName == "Drunk") {
		this->intelligence -= 2;
		this->agility -= 2;
		this->strength += 4;
	}
	else if (this->monster_nickName == "Stinky") {
		this->intelligence -= 2;
		this->endurance += 4;
	}
	else if (this->monster_nickName == "Stinky") {
		this->agility += 2;
	}
	else if (this->monster_nickName == "Lame") {
		this->agility -= 1;
		this->endurance -= 1;
		this->intelligence -= 1;
		this->luck -= 1;
		this->strength -= 1;
	}
	else if (this->monster_nickName == "Cocky") {
		this->endurance += 1;
		this->intelligence -= 1;
		this->luck += 1;
		this->strength += 1;
	}

	if (this->monster_class == "Skirmisher") {
		this->agility += 2;
	}
	else if (this->monster_class == "Mage") {
		this->intelligence += 2;
	}
	else if (this->monster_class == "Ambusher") {
		this->agility += 1;
		this->luck += 1;
	}
	else if (this->monster_class == "Reaper") {
		this->strength += 1;
		this->endurance += 1;
	}
	else if (this->monster_class == "Leader") {
		this->strength += 1;
		this->endurance += 1;
		this->luck += 1;
		this->agility += 1;
		this->intelligence += 1;
	}
	else if (this->monster_class == "Dispoiler") {
		this->strength += 2;
		this->endurance += 1;
		this->agility -= 2;
		this->intelligence += 1;
	}
	else if (this->monster_class == "Arsonist") {
		this->endurance += 1;
		this->luck += 2;
		this->agility += 2;
		this->strength -= 2;
	}
	else if (this->monster_class == "Lunatic") {
		this->strength -= 1;
		this->endurance -= 1;
		this->agility -= 1;
		this->intelligence -= 1;
	}
	else if (this->monster_class == "Nightlord") {
		this->strength += 2;
		this->endurance += 1;
		this->agility += 2;
		this->intelligence += 1;
	}


	this->updateStats();
	this->setmsh();
	this->showStats();

}
void Enemy::showStats() {
	std::cout << "Name: " << this->monster_nickName << ' ' << this->monster_name << ' ' << this->monster_class << std::endl;
	std::cout << "Level: " << this->level << std::endl;
	std::cout << "Mana: " << this->mana << '/' << this->max_mana << std::endl;
	std::cout << "Health: " << this->health << '/' << this->max_health << std::endl;
	std::cout << "Stamina: " << this->stamina << '/' << this->max_stamina << std::endl;
	std::cout << "Strength: " << this->strength << std::endl;
	std::cout << "Endurance: " << this->endurance << std::endl;
	std::cout << "Agility: " << this->agility << std::endl;
	std::cout << "Intelligence: " << this->intelligence << std::endl;
	std::cout << "Luck: " << this->luck << std::endl;
	std::cout << "Dodge chance: " << this->dodgeChance << '%' << std::endl;
	std::cout << "Crit chance: " << this->critHit << '%' << std::endl;
	std::cout << "--------------------------" << std::endl;
}
void Enemy::attack(Creature& target) {
	this->stamina -= FATIGUE;
	this->regen();
	if (target.getStamina() >= this->agility && rand() % 100 + 1 <= target.getDodgeChance()) {
		target.setStamina(target.getStamina() - this->agility);
		std::cout << "Player has dodged" << std::endl;
		std::cout << "--------------------------" << std::endl;
		return;
	}
	int damage = rand() % this->strength + 1;
	if (this->stamina <= 0) {
		damage /= 2;
		std::cout << "Enemy has run out of stamina" << std::endl;
	}
	if (static_cast<unsigned int>(rand() % 100 + 1) <= this->luck) {
		damage *= 2;
	}
	target.setHp(target.getHp() - damage);
	std::cout << "Player recieved: " << damage << " damage" << std::endl;
	std::cout << "--------------------------" << std::endl;
}
void Enemy::takeAction(Creature& target)
{
	if (this->stamina > 0) { // or probably this->stamina >= FATIGUE
		this->attack(target);
		return;
	}
	this->wait();
	std::cout << "Enemy waits" << std::endl;
	std::cout << "--------------------------" << std::endl;
}
int Enemy::getXp()
{
	return (this->strength + this->endurance + this->agility + this->intelligence + this->luck) * 1.5;
}		  