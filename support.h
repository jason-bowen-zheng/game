#define LAND		' '
#define HERO		'*'
// Player
#define MONS_1		'$'
// Monster 1
#define MONS_2		'%'
// Monster 2
#define MONS_3		'#'
// Monster 3
#define BOSS		'@'
// Boss

#define TOPMESSAGE	1
#define BOTTOMMESSAGE	2
#define MIDMESSAGE	3

typedef enum{
	MON_1 = 0, MON_2 = 1, MON_3 = 2, BOSS = 3
	} m_type;

typedef struct {
	int effect;
	/* Combat effectiveness */
	int hp;
	int hunger;
	/* Degree of hunger */
	int life;
	/* Life value */
	int killed;
	/* Monster killed */
} Hero;

typedef struct{
	int lethal;
	int life;
	m_type type;
	/* Monster type */
} Monster;

Monster create_monster(m_type type){
	switch(type){
		case 0:
			return Monster{3, 5, 0};
			break;
		case 1:
			return Monster{10, 50, 1};
			break;
		case 2:
			return Monster{30, 100, 2};
			break;
		case 3:
			return Monster{60, 300, 3};
			break;
	}
}
