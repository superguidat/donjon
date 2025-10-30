#ifndef				__DONJON_MASTER_HH__
#define				__DONJON_MASTER_HH__

#include			<GL/gl.h>
#include			<GL/glu.h>
#include			<lapin.h>
#include			<tile.hh>
#include			<floor.hh>
#include			<room.hh>
#include			<SFML/Graphics.hpp>

#define				WIDTH				800
#define				HEIGHT				600
#define				GRAVITY				9.8
#define				JUMP_COOLDOWN			0.5
#define				JUMP_FORCE			5.0
#define				LIMITE_FRANCHISSEMENT		3

struct				t_map
{
  int32_t			*map;
  uint32_t			width;
  uint32_t			height;
  double			dist;
  t_bunny_position		best_pos;
};

struct				t_prog;

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

    void			draw(t_prog		*pro);
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
  class				Objet
  {
  public :
    Objet(void);
    ~Objet();// destructeur

    int32_t			getI()			{return (i);}
    double			getX()			{return (x);}
    double			getY()			{return (y);}
    double			getDegat()		{return degat;}
    t_bunny_position		getPos()		{return (t_bunny_position)
							{.x = (int)x, .y = (int)y};}

    void			setI(int32_t		_i)	{i = _i;}
    void			setX(double		_x)	{x = _x;}
    void			setY(double		_y)	{y = _y;}
    void			setDegat(double		_degat)	{degat = _degat;}
    void			setPos(double		_x,
				       double		_y)	{x = _x; y = _y;}

    void			draw(t_prog		*pro);
  private:
    int32_t			i;
    double			x;
    double			y;
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
    double			vertical_speed = 0.0;
  };
};

struct				t_prog
{
  t_bunny_window		*win;
  uint32_t			**ref;
  t_bunny_font			*ascii;
  t_bunny_music			*music[2];
  Tile				tiles[100*100];
  Tile				tiles_sup[100*100];
  int32_t			width;
  int32_t			height;
  ef::Unit			me;
  ef::Unit			units[256];
  ef::Objet			objets[256];
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
  bool				deb;
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

void				init_tiles(t_prog		*pro);
void				init_tiles_sup(t_prog		*pro);

t_bunny_response		charge_texture(const char	*file_path,
					       t_prog		*pro,
					       int32_t		i);

void				clear_img(t_bunny_color		&color);

void				move_cam(t_zposition		pos_cam,
					 t_zposition		dir_cam,
					 t_zposition		vec_cam);

void				set_triangle(t_zposition	*pos,
					     t_bunny_color	*colo);
void				set_triangle_text(t_zposition	*pos,
						  GLuint	textureID);

void				set_coord(t_coord               coo,
					  int8_t		sup);

void				set_carre(t_zposition		pos,
					  t_prog		&pro,
					  int32_t		tile_size,
					  int16_t		id);

void				set_zcarre(t_zposition		*pos,
					   t_prog		&pro,
					   int16_t		id);

void				plafond(t_prog			&pro,
					int32_t			x,
					int32_t			y);

void				sol(t_prog			&pro,
				    int32_t			x,
				    int32_t			y,
				    t_zposition			*pos);

void				saut_graviter(t_prog		&pro);


#endif//                        __DONJON_MASTER_HH__
