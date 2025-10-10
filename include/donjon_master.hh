#ifndef				__DONJON_MASTER_HH__
#define				__DONJON_MASTER_HH__

#include			<GL/gl.h>
#include			<GL/glu.h>
#include			<lapin.h>

#define				WIDTH		800
#define				HEIGHT		600

struct				t_zposition
{
  double			x;
  double			y;
  double			z;
};

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

    int32_t			getR(){return (r);}
    int32_t			getI(){return (i);}
    double			getX(){return (x);}
    double			getY(){return (y);}
    double			getDegat(){return degat;}
    double			getV(){return (v);}
    t_bunny_position		getPos(){return (t_bunny_position){.x = (int)x, .y = (int)y};}
    t_bunny_position		getPosDest(){return (t_bunny_position){.x = (int)x_dest, .y = (int)y_dest};}

    void			setR(int32_t		_r){r = _r;}
    void			setI(int32_t		_i){i = _i;}
    void			setX(double		_x){x = _x;}
    void			setY(double		_y){y = _y;}
    void			setDegat(double		_degat){degat = _degat;}
    void			setV(double		_v){v = _v;}
    void			setPos(double		_x,
				       double		_y){x = _x; y = _y;}
    void			setPosDest(double	_x ,
					   double	 _y){x_dest = _x; y_dest = _y;}

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

    void			setR(int32_t		_r)	{r = _r;}
    void			setI(int32_t		_i)	{i = _i;}
    void			setX(double		_x)	{x = _x;}
    void			setY(double		_y)	{y = _y;}
    void			setDest(double		_y,
					double		_x)	{y_dest = _y;
								x_dest = _x;}
    void			setV(int32_t		_v)	{v = _v;}
    void			setT(int16_t		_t)	{t = _t;}
    void			setPv(int16_t		_pv)	{pv = _pv;}
    void			setLast_shot(ssize_t	_last_shot){last_shot = _last_shot;};
    void			setMove_type(int8_t	_move_type){move_type = _move_type;};

    double			appendX(double		_x)	{x += _x; return x;};
    double			appendY(double		_y)	{y += _y; return y;};
    double			appendV(double		_v)	{v += _v; return v;};
    double			appendPv(double			_pv){pv += _pv; return pv;};

    bool			Collide(const Unit	&u,
					bool		next_move = false);
    void			move(double		_x,
				     double		_y,
				     double		_a,
				     uint32_t		_color,
				     int32_t		move,
				     t_prog		&pro);

    void			SetColor(uint32_t c) { color = c; }
    unsigned int		GetColor(void) const { return color; }

    t_bunny_position		pathfinding(t_map			*map,
					    t_bunny_pixelarray		&pix,
					    t_bunny_position		destination);

  private:
    int32_t			r;
    uint32_t			i;
    double			x;
    double			y;
    double			x_dest;
    double			y_dest;
    double			v;
    uint8_t			pos[1000];
    int16_t			t;
    double			pv;
    uint32_t			color = 0;
    int8_t			move_type = 0;
    ssize_t			last_shot;
  };
};

struct				t_prog
{
  t_bunny_window		*win;
  uint32_t			**ref;
  t_bunny_font			*ascii;
  t_bunny_music			*music[2];
  ef::Unit			me;
  ef::Unit			units[256];
  ef::Objet			objets[256];
  ef::Projectile		project[1000];
  int16_t			nb_project;
  int16_t			nb_units;
  double			rot;
  double			tilt;
  t_bunny_accurate_position	pos;
};

void				clear_img(t_bunny_color		&color);

void				move_cam(t_zposition		pos_cam,
					 t_zposition		dir_cam,
					 t_zposition		vec_cam);

void				set_triangle(t_zposition	*pos,
					     t_bunny_color	*colo);

#endif//                        __DONJON_MASTER_HH__
