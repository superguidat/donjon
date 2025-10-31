#include		"donjon_master.hh"

/*
bool			dans_champ(t_prog	&pro,
				   int32_t	x,
				   int32_t	y)
{
  double		fov_div_2 = M_PI / 1.5;
  double		ang;
  double		rot;
  int			xdiff;
  int			ydiff;

  ydiff = ((y + 0.5) * 36) - pro.pos.y;
  xdiff = ((x + 0.5) * 36) - pro.pos.x;
  ang = (atan2(ydiff, xdiff));
  rot = (pro.rot - M_PI);
  return !(ang > rot - fov_div_2 && ang < rot + fov_div_2);
}


  
  double		min;
  double		max;
  double		test;

  min = atan2(pro.pos.y + sin(pro.rot - 0.10) - pro.pos.y + sin(pro.rot),
	      pro.pos.x + cos(pro.rot - 0.10) - pro.pos.x + cos(pro.rot));

  max = atan2(pro.pos.y + sin(pro.rot + 0.10) - pro.pos.y + sin(pro.rot),
	      pro.pos.x + cos(pro.rot + 0.10) - pro.pos.x + cos(pro.rot));

  test = atan2(y - pro.pos.y + sin(pro.rot), x - pro.pos.x + cos(pro.rot));
  if (test >= min && test <= max)
    return true;
  return false;
}
*/
bool		dans_champ(t_prog &pro, int32_t x, int32_t y)
{
  const double fov_div_2 = M_PI / 3.0; // ~60° de chaque côté, soit 120° total
  const double cell_size = 36.0;

  // Calcul des différences
  double dx = ((x + 0.5) * cell_size) - pro.pos.x;
  double dy = ((y + 0.5) * cell_size) - pro.pos.y;

  // Angle du point et angle du joueur
  double ang = atan2(dy, dx);
  double rot = pro.rot;

  // Normalisation des angles entre -PI et +PI
  auto normalize = [](double a) {
    while (a < -M_PI) a += 2 * M_PI;
    while (a >  M_PI) a -= 2 * M_PI;
    return a;
  };

  ang = normalize(ang);
  rot = normalize(rot);

  // Différence d’angle
  double diff = normalize(ang - rot);

  // Si la différence est dans le champ de vision
  return fabs(diff) <= fov_div_2;
}
