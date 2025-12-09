// *****     ***     ***     ***       **       ***      ********************
// ****  ******  ******  **  *****  *******  *****  *************************
// ***     ***     ***     ******  *******  *****      **********************
// **  ******  ******  *** *****  *******  *********  ***********************
// *     ***  ******  *** ***       ****  *****      ************************
// 02/12/2025 11:56:25 ******************************************************
// kenan.guidat <kenan.guidat@debian>
// - dungeon_master -
// * *** * * ***  ** * ** ** ** ** * * * *** * **  **************************

#ifndef				__DONJON_MASTER_HH__
#define				__DONJON_MASTER_HH__

#include			<GL/gl.h>
#include			<GL/glu.h>
#include			<lapin.h>
#include			<tile.hh>
#include			<floor.hh>
#include			<room.hh>
#include			<random>
#include			<poll.h>
#include			<SFML/Graphics.hpp>

#define				SIZE_TABLE			255
#define				MAX_STEP			10
#define				LIMITE				4 // max d'angle tester par boule
#define				PAS				16 // taille des angle entre les pas
#define				MAX_RAY				2 // vrai max = mini + max
#define				MINI_RAY			2
#define				MINI_VIT			0.5
#define				MAX_VIT				1.5 // vrai max = mini + max
#define				WIDTH				1920
#define				HEIGHT				1080
#define				GRAVITY				9.8
#define				JUMP_COOLDOWN			0.5
#define				JUMP_FORCE			5.0
#define				LIMITE_FRANCHISSEMENT		3

double				randDouble(double		min,
					   double		max);

struct				t_map
{
  int32_t			*map;
  uint32_t			width;
  uint32_t			height;
  double			dist;
  t_bunny_position		best_pos;
};

namespace			ef
{
  class				Projectile
  {
  public :
    Projectile(void);
    ~Projectile();// destructeur

    int32_t			getR()			{return (r);}
    int32_t			getI()			{return (i);}
    double			getX()			{return (x);}
    double			getY()			{return (y);}
    double			getDegat()		{return degat;}
    double			getV()			{return (v);}
    t_bunny_position		getPos()		{return (t_bunny_position){.x = (int)x, .y = (int)y};}
    t_bunny_position		getPosDest()		{return (t_bunny_position){.x = (int)x_dest, .y = (int)y_dest};}

    void			setR(int32_t		_r)	{r = _r;}
    void			setI(int32_t		_i)	{i = _i;}
    void			setX(double		_x)	{x = _x;}
    void			setY(double		_y)	{y = _y;}
    void			setDegat(double		_degat)	{degat = _degat;}
    void			setV(double		_v)	{v = _v;}
    void			setPos(double		_x,
				       double		_y)	{x = _x; y = _y;}
    void			setPosDest(double	_x ,
					   double	_y)	{x_dest = _x; y_dest = _y;}

  private:
    int32_t			r;
    int32_t			i;
    double			x;
    double			y;
    double			x_dest;
    double			y_dest;
    double			v;
    double			degat;
  };
  class				Unit
  {
  public :
    Unit(void);
    ~Unit();// destructeur
    //void			operator=(const Block		&other);

    int32_t			getR()			{return (r);}
    int32_t			getI()			{return (i);}
    double			getX()			{return (x);}
    double			getY()			{return (y);}
    double			getV()			{return (v);}
    double			getA()			{return (a);}
    t_bunny_position		getPos()		{return (t_bunny_position)
							{.x = (int)x, .y = (int)y};}
    t_bunny_position		getPosDest()		{return (t_bunny_position)
							{.x = (int)x_dest, .y = (int)y_dest};}
    int8_t			getMove_type()		{return move_type;}
    int8_t			getDir()		{t--; return pos[t-1];}
    int16_t			getT()			{return t;}
    double			getPv()			{return pv;}
    ssize_t			getLast_shot()		{return last_shot;}
    t_zposition			getPos_cam()		{return pos_cam;}
    t_zposition			getDir_cam()		{return dir_cam;}
    t_zposition			getVec_cam()		{return vec_cam;}

    double			getLast_jump_time()	{return last_jump_time;}
    double			getJump_cooldown()	{return jump_cooldown;}
    double			getJump_force()		{return jump_force;}
    double			getGravity()		{return gravity;}
    bool			getIs_jumping()		{return is_jumping;}
    double			getVertical_speed()	{return vertical_speed;}

    void			setR(int32_t			_r)		{r = _r;}
    void			setI(int32_t			_i)		{i = _i;}
    void			setX(double			_x)		{x = _x;}
    void			setY(double			_y)		{y = _y;}
    void			setA(double			_a)		{a = _a;}
    void			setDest(double			_y,
					double			_x)		{y_dest = _y;
										x_dest = _x;}
    void			setV(int32_t			_v)		{v = _v;}
    void			setT(int16_t			_t)		{t = _t;}
    void			setPv(int16_t			_pv)		{pv = _pv;}
    void			setLast_shot(ssize_t		_last_shot)	{last_shot = _last_shot;};
    void			setMove_type(int8_t		_move_type)	{move_type = _move_type;};
    void			setPos_cam(t_zposition		_pos_cam)	{pos_cam = _pos_cam;}
    void			setDir_cam(t_zposition		_dir_cam)	{dir_cam = _dir_cam;}
    void			setVec_cam(t_zposition		_vec_cam)	{vec_cam = _vec_cam;}
    void			setLast_jump_time(double	_last_jump_time){last_jump_time = _last_jump_time;}
    void			setJump_cooldown(double		_jump_cooldown)	{jump_cooldown = _jump_cooldown;}
    void			setJump_force(double		_jump_force)	{jump_force = _jump_force;}
     void			setGravity(double		_gravity)	{gravity = _gravity;}
     void			setIs_jumping(double		_is_jumping)	{is_jumping = _is_jumping;}
     void			setVertical_speed(double	_vertical_speed){vertical_speed = _vertical_speed;}

    double			appendX(double			_x)		{x += _x; return x;};
    double			appendY(double			_y)		{y += _y; return y;};
    double			appendV(double			_v)		{v += _v; return v;};
    t_zposition			appendPos_cam(t_zposition	_pos_cam)	{pos_cam.x += _pos_cam.x;
										pos_cam.y += _pos_cam.y;
										pos_cam.z += _pos_cam.z;
										return pos_cam;}
    t_zposition			appendDir_cam(t_zposition	_dir_cam)	{dir_cam.x += _dir_cam.x;
										dir_cam.y += _dir_cam.y;
										dir_cam.z += _dir_cam.z;
										return dir_cam;}
    t_zposition			appendVec_cam(t_zposition	_vec_cam)	{vec_cam.x += _vec_cam.x;
										vec_cam.y += _vec_cam.y;
										vec_cam.z += _vec_cam.z;
										return vec_cam;}
    double			appendPv(double			_pv)		{pv += _pv; return pv;};
    void			Init(int32_t				_x,
				     int32_t				_y){r = randDouble(MINI_RAY, MAX_RAY); x = _x; y = _y; v = randDouble(MINI_RAY, MAX_RAY); a = randDouble(0, 2 * M_PI); };

    bool			Collide(const Unit		&u,
					bool			next_move = false);
    void			move(double			_x,
				     double			_y,
				     double			_a,
				     uint32_t			_color,
				     int32_t			move,
				     t_prog			&pro);

    void			SetColor(uint32_t		c) { color = c; }
    unsigned int		GetColor(void)			const { return color; }

    bool			check_jump();
    void			jump(double			current_time,
				     double			dd);
    void			update_jump(double		deltaTime,
					    double		dd);

    t_bunny_position		pathfinding(t_map		*map,
					    t_bunny_pixelarray	&pix,
					    t_bunny_position	destination);
    bool			check_me_tile(Tile		&tuil);

  private:
    int32_t			r;
    uint32_t			i;
    double			x;
    double			y;
    double			x_dest;
    double			y_dest;
    t_zposition			pos_cam;
    t_zposition			dir_cam;
    t_zposition			vec_cam;
    double			v;
    double			a;
    uint8_t			pos[1000];
    int16_t			t;
    double			pv;
    uint32_t			color = 0;
    int8_t			move_type = 0;
    ssize_t			last_shot;
    double			last_jump_time = -1.0;
    double			jump_cooldown = JUMP_COOLDOWN;
    double			jump_force = 5.0;
    double			gravity = GRAVITY;
    bool			is_jumping = false;
    ef::Objet			objets[50];
    double			vertical_speed = 0.0;
  };
};

struct				t_reseau_ext;

struct				t_prog
{
  t_bunny_window		*win;
  t_bunny_pixelarray		*map;
  t_bunny_pixelarray *map2;
  //std::vector<t_bunny_pixelarray*>map2;
  //  std::vector<uint32_t*>	ref;
  //uint32_t			**ref;
  t_bunny_font			*ascii;
  t_bunny_music			*music[2];
  Floor				sous_bas;
  Floor				bas;
  Floor				haut;
  Floor				etage[100];
  int32_t			nb_etage;
  int32_t			etage_actuel;
  int32_t			width;
  int32_t			height;
  ef::Unit			me;
  ef::Unit			pl[10];
  ef::Unit			units[256];
  ef::Objet			def_objets[128];
  ef::Projectile		project[1000];
  int16_t			nb_project;
  int16_t			nb_units;
  double			rot;
  double			tilt;
  t_zposition			pos;
  GLuint			textureID[10];
  sf::Time			dt;
  sf::Clock			clock;
  sf::Clock			deltaClock;
  std::vector<pollfd>		client_fd;
  int32_t			nb_client = 0;
  int32_t			my_id;
  int32_t			fd_sock;
  uint32_t			tab_alea[1024*1024];
  int32_t			id_tab_alea;
  bool				hote;
  uint64_t			seed_rand;
  bool				deb;
  int8_t			ecran;
  char				ip[16];
  std::vector<t_reseau_ext>	file;
};

struct				t_colli_step
{
  int32_t			x;
  int32_t			y;
  int32_t			step;
};

struct				t_colli
{
  int32_t			x;
  int32_t			y;
  int32_t			r;
  int32_t			i;
};

struct				t_path
{
  bool				blk;
  t_bunny_accurate_position	pos;
  double			dist;
};

struct				t_dep
{
  int32_t			i5;
  int32_t			mv;
  int32_t			av_re;
};

struct				t_rec
{
  t_map				*map;
  t_bunny_position		destination;
  int32_t			i;
  int32_t			r;
  int32_t			max_step;
};

struct				t_move
{
  ef::Unit			tmp;
  ef::Unit			*pnj;
  double			ang;
  double			other_ang;
  double			speed;
  double			nx;
  double			ny;
  double			pas;
  bool				moved;
  bool				coll;
  int16_t			score;
  int32_t			i;
};

struct				t_rebond
{
  double			mini_dist;
  double			d;
  int16_t			index_mini;
  double			dx;
  double			dy;
  double			vx;
  double			vy;
  double			rx;
  double			ry;
  double			nx;
  double			ny;
  double			dot;
};

struct				t_track
{
  t_bunny_position		origin;
  t_map				nmap;
};



struct				t_connexion
{
  int32_t			id;
  t_zposition			pos_cam;
  uint64_t			seed;
};

struct				t_reseau
{
  int32_t			type;
  int32_t			id;
  t_zposition			pos_cam;
};

struct				t_reseau_ext : public t_reseau
{
  int32_t			sock_id;
};

struct				t_sol
{
  t_prog			*pro;
  Floor				*flo;
  int32_t			x;
  int32_t			y;
  t_zposition			*pos;
  int8_t			etage;
};

struct				t_coord
{
  t_prog			&pro;
  t_zposition			*pos;
  t_zposition			*p;
  int32_t			x;
  int32_t			y;
  int32_t			tile_size;
};

t_bunny_position		init_check_pos_rec(t_map	&nmap,
						   t_bunny_position &destination,
						   t_bunny_position &origin,
						   t_path	&origi);

int32_t				which_direction(int32_t		x,
						int32_t		y);

void				test_dist(t_path		tmp,
					  t_path		&pat,
					  t_map			*map);

void				init_pat(t_path			&pat,
					 t_colli		&coll,
					 t_bunny_position	&destination);

void				init_next_pas(int32_t		*next_pas);

bool				test_sorti_rec(t_rec		&rec,
					       int32_t		step,
					       t_path		&origin);


void				bouge_rec(int32_t		t,
					  uint8_t		*pos,
					  t_bunny_position	&origin);

void				init_origi(int32_t		x,
					   int32_t		y,
					   t_path		&origi);

t_rec				init_rec_path(t_bunny_position	destination,
					      int32_t		i,
					      int32_t		r,
					      t_map		*nmap);

double				index_map(int32_t		width,
					  double		x,
					  double		y);

bool				check_collide_pix(t_colli	&co,
						  t_bunny_pixelarray &pix);

bool				collision(t_bunny_pixelarray	&pix,
					  t_colli		&coll,
					  int32_t		step,
					  t_map			*map);

void				deplacement_x_rec(t_dep		dep,
						  uint8_t	*posi,
						  t_bunny_position &pos1,
						  t_map		&nmap);

void				deplacement_y_rec(t_dep		dep,
						  uint8_t	*posi,
						  t_bunny_position &pos1,
						  t_map		&nmap);

t_bunny_position		track_chemin(t_track		tr,
					     t_bunny_position	pos1,
					     uint8_t		*posi,
					     int32_t		min);

t_map				init_map(t_map			*map,
					 int32_t		i);

void				fabric_map(t_map		&map,
					   t_prog		&pro);

void				init_pos_move(t_bunny_position	&pos,
					      t_move		&mv);

bool				collision_collide(t_prog	&pro,
						  t_move	&mv);

bool				check_pos_move(t_prog		&pro,
					       t_move		&mv,
					       t_bunny_position	pos);

void				set_carre_pix(t_bunny_pixelarray *map2,
					      ef::Unit		&pnj,
					      uint32_t		i);

void				applique_deplacement(t_prog	&pro,
						     t_move	&mv,
						     t_map	&map,
						     t_bunny_position	pos);

int32_t				suit_route(t_bunny_position	&pos,
					   t_move		&mv,
					   t_prog		&pro,
					   t_map		&map);

void				move_units(t_prog		&prog);

void				rattrape_retard(t_prog		*prog);

void				partage_host(t_prog		*prog,
					     int32_t		r,
					     t_reseau_ext	&host);

bool				new_connexion(t_prog		*prog);

void				partage_info(t_prog		*prog,
					     int32_t		i,
					     t_reseau		&recu);

void				supprime_et_retransmission(t_prog	*prog,
							   int32_t	&i,
							   t_reseau	&recu);

void				reception_update(t_prog		*prog,
						 char		*buf,
						 int32_t	rd);

t_bunny_response		reseau_client_loop(t_prog	*prog);

void				init_prog_jeu(t_prog		*pro);

void				genere_tab_alea(t_prog		*pro);

t_bunny_response		init_reseau(t_prog		*pro);

t_bunny_response		init_reseau_client(t_prog	*pro);

t_bunny_response		reseau_hote_client(t_prog	*pro);

double				computeLevitation(const sf::Time &passer,
						  double	z,
						  double	speed,
						  double	amp);

double				min_dist_point(Tile		&tuil,
					       t_zposition	&cam);

void				draw_pave_texture(double	zdelt,
						  t_zposition	pos,
						  t_zposition	s,
						  GLuint	texture);

void				draw_joueur(t_prog		*prog);

void				draw_cube_texture(double	zdelt,
						  t_zposition	pos,
						  double	size,
						  GLuint	texture);

void				genere_etage(t_prog		&pro,
					     int32_t		*tab,
					     double		base_height);

void				genere_floor(int32_t		width,
					     int32_t		height,
					     Floor		&flo,
					     int32_t		*tab,
					     double		z);

double				rclamp(double			val,
				       double			min,
				       double			max);

bool				dans_champ(t_prog		&pro,
					   int32_t		x,
					   int32_t		y);

bool				check_me_first(t_zposition	&pos,
					       Tile		&tuil);

bool				collision_me(t_prog		&pro,
					     double		x,
					     double		y);

void				mouvement(t_prog		&pro);

void				init_triangle_HB(t_zposition    *posf,
						 Tile		&tuil,
						 Tile		&tuil2);

void				init_triangle_RL(t_zposition    *posf,
						 Tile		&tuil,
						 Tile		&tuil2);

void				init_triangle_LR(t_zposition    *pos,
						 t_zposition    *posi);

void				init_tiles(t_prog		*pro,
					   Floor		&flo,
					   int8_t		sup);
void				init_tiles_sup(t_prog		*pro);

void				genere_jeu(t_prog		*pro,
					   uint16_t		hauteur_sous_plafond,
					   uint16_t		nb_etage);

t_bunny_response		charge_texture(const char	*file_path,
					       t_prog		*pro,
					       int32_t		i);

t_bunny_response		charge_texture_obj(const char	*file_path,
						   GLuint	*text);

t_bunny_response		game_texture(t_prog		*pro);

void				clear_img(t_bunny_color		&color);

void				move_cam(t_zposition		pos_cam,
					 t_zposition		dir_cam,
					 t_zposition		vec_cam,
					 int			ecran);

void				set_triangle(t_zposition	*pos,
					     t_bunny_color	*colo);

void				set_triangle_text(t_zposition	*pos,
						  GLuint	textureID);

void				right_panel(t_prog		*prog);

void				set_coord(t_coord               coo,
					  int8_t		etage);

void				set_carre(t_zposition		pos,
					  t_prog		&pro,
					  int32_t		tile_size,
					  int16_t		id);

void				case_inventaire(t_prog		*pro,
						int32_t		sizex);

void				set_zcarre(t_zposition		*pos,
					   t_prog		&pro,
					   int16_t		id);

void				plafond(t_prog			&pro,
					Floor			&flo,
					int32_t			x,
					int32_t			y,
					int8_t			etage);

void				sol(t_sol			&sol,
				    int8_t			id_sol,
				    int8_t			id_mur);

void				affiche_3etage(int32_t		x,
					       int32_t		y,
					       t_prog		*prog,
					       t_zposition	*pos);

void				saut_graviter(t_prog		&pro);


#endif//                        __DONJON_MASTER_HH__
